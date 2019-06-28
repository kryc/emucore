//
//  Cpu.cpp
//  emucore
//
//  Created by Gareth Evans on 16/06/2019.
//  Copyright © 2019 Gareth Evans. All rights reserved.
//

#include <memory>
#include <map>
#include <functional>
#include <sstream>
#include <assert.h>
#include "Common.hpp"
#include "Cpu.hpp"
#include "Gpu.hpp"

static const std::map<int, struct Opcode> g_Instructions
{
#include "CallbackTable.txt"
};

Cpu::Cpu(void)
{
	/* Initialize registers */
	m_Registers.AF = 0x01;
	m_Registers.F = 0xb0;
	m_Registers.BC = 0x0013;
	m_Registers.DE = 0x00d8;
	m_Registers.HL = 0x014d;
	m_Registers.SP = 0xfffe;
	
	m_Registers.PC = 0x100;

	/* Register interrupt handlers */
	RegisterInterrupt(INTERRUPT_VBLANK, std::bind(&Cpu::OnInterrupt, this, std::placeholders::_1));
}

std::map<std::string, register_t>
Cpu::GetRegisters(void)
{
	std::map<std::string, register_t> ret;
	ret["A"] = m_Registers.A;
	ret["F"] = m_Registers.F;
	ret["B"] = m_Registers.B;
	ret["C"] = m_Registers.C;
	ret["D"] = m_Registers.D;
	ret["E"] = m_Registers.E;
	ret["HL"] = m_Registers.HL;
	ret["SP"] = m_Registers.SP;
	ret["PC"] = m_Registers.PC;
	return ret;
}

uint8_t
Cpu::ReadMemory(
	register_t Address
	)
{
	return m_Memory[Address].Get();
}

std::vector<uint8_t>
Cpu::ReadMemoryRange(
	register_t StartAddress, size_t Length
	)
{
	std::vector<uint8_t> ret;
	for( size_t i=StartAddress; i<StartAddress+Length; i++ )
	{
		ret.push_back(ReadMemory(i));
	}
	return ret;
}

void
Cpu::Push(
	uint16_t Value
	)
{
	m_Memory[m_Registers.SP-1] = (Value >> 8);
	m_Memory[m_Registers.SP-2] = (Value & 0xff);
	m_Registers.SP -= 2;
}

void
Cpu::Push(
	uint8_t Value
	)
{
	m_Memory[m_Registers.SP-1] = (Value & 0xff);
	m_Registers.SP -= 1;
}

uint16_t
Cpu::Pop(void)
{
	uint16_t value = m_Memory[m_Registers.SP].Get();
	value |= (m_Memory[m_Registers.SP+1].Get() << 8);
	m_Registers.SP += 2;
	return value;
}

uint8_t
Cpu::Pop8(void)
{
	uint8_t value;
	value = m_Memory[m_Registers.SP].Get();
	m_Registers.SP += 1;
	return value;
}

uint8_t
Cpu::Immediate8(uint16_t Pc)
{
	return m_Memory[Pc+1].Get();
}

uint8_t
Cpu::Immediate8(void)
{
	return Immediate8(m_Registers.PC);
}

uint16_t
Cpu::Immediate16(uint16_t Pc)
{
	return m_Memory.Get16(Pc+1);
}

uint16_t
Cpu::Immediate16(void)
{
	return Immediate16(m_Registers.PC);
}

void
Cpu::OnInterrupt(int Interrupt)
/*++
 The deal here is that for most interrupts, the Id is the address of the
 handler. Therefore we can just push the current PC and read the handler
 straight from memory
 --*/
{
	std::string enabled = m_InterruptState == Enabled ? "(E)" : "(D)";
	std::cout << "Interrupt raised " << enabled << ": " << std::hex << (int)Interrupt << std::dec << std::endl;
	m_Memory[0xff0f] = m_Memory[0xff0f].Get() | Interrupt;
}

void
Cpu::Run(void)
{
	/* Initialise the GPU */
	if( m_Gpu == nullptr )
	{
		m_Gpu = std::make_shared<Gpu>(shared_from_this(), m_Memory);
	}

	/* Start executing instructions! */
#ifdef NOCLOCK
	for( ;; )
	{
		if( !Tick() )
		{
			/* Hit a breakpoint */
			break;
		}
	}
#else
	Clock::Run();
#endif
}

void
Cpu::Step(void)
{
	/* Initialise the GPU */
	if( m_Gpu == nullptr )
	{
		m_Gpu = std::make_shared<Gpu>(shared_from_this(), m_Memory);
	}
	
	size_t startingOperations = m_OperationsExecuted;
	while( m_OperationsExecuted == startingOperations )
	{
		Tick();
	}
}

std::string
Cpu::FormatDebugString(
   const uint32_t Pc,
   size_t *InstructionWidth
   )
{
	uint32_t address = (Pc == 0x10000 ? m_Registers.PC : (uint16_t)Pc);
	auto opcode = g_Instructions.at(m_Memory[address].Get());
	std::string DebugString = opcode.DebugString;

	std::size_t found = DebugString.find("a16");
	if( found == std::string::npos )
		found = DebugString.find("d16");
	if( found == std::string::npos )
		found = DebugString.find("r16");
	if ( found != std::string::npos ){
		std::stringstream stream;
		int immediate16 = Immediate16((uint16_t)address);
		stream << "0x" << std::hex << immediate16;
		DebugString.replace(found, 3, stream.str());
	}
	found = DebugString.find("a8");
	if( found == std::string::npos )
		found = DebugString.find("d8");
	if( found == std::string::npos )
		found = DebugString.find("r8");
	if ( found != std::string::npos ){
		std::stringstream stream;
		int immediate8 = Immediate8((uint16_t)address);
		stream << "0x" << std::hex << immediate8;
		DebugString.replace(found, 2, stream.str());
	}

	if( InstructionWidth != nullptr )
	{
		*InstructionWidth = opcode.InstructionWidth;
	}

	return DebugString;
}

bool
Cpu::Tick(void)
/*++
 This gets called automatically by the underlying Clock.
 It counts the number of ticks spent in the current instruction and calls
 the callback with the current cycle until it is complete.
 This way we can spread multiple operations over several cycles if we are
 struggling to meet our tick (which is unlikely for gameboy!)
 --*/
{
	static ssize_t  ticksTaken = 0;
	static ssize_t	ticksInCurrentOp = 0;
	static ssize_t  ticksUsed = 0;
	static uint16_t startingPC = 0;
	static struct Opcode opcode{};
	
	if( ticksUsed == ticksInCurrentOp )
	{
		/* We have completed the previous operation (or it is the first op).
			we do a number of things now.
			1) Check to see if we need to break for a debugger
			2) Service any interrupts
			3) Fetch a new operation to execute and reset the counters
		 */
		if( ShouldBreak(m_Registers.PC) )
		{
			return false;
		}

		if( m_InterruptState == Enabled )
		{
			/* read IF register to determine which interrupts fired */
			uint8_t ints = m_Memory[0xFF0F].GetNoHook();
			uint8_t ie = m_Memory[0xFFFF].GetNoHook();

			m_InterruptState = DisableRequested;
			if((ints & INTERRUPT_VBLANK) && (ie & INTERRUPT_VBLANK))
			{
				/* VBLANK */
				Push(m_Registers.PC);
				/* jump to ISR*/
				m_Registers.PC = VBLANK_ISR;

			}
			if((ints & INTERRUPT_LCDC) && (ie & INTERRUPT_LCDC))
			{
				/* LCDC (STAT) */
				Push(m_Registers.PC);
				/* jump to ISR*/
				m_Registers.PC = LCDC_ISR;

				
			}
			if((ints & INTERRUPT_TIMA) && (ie & INTERRUPT_TIMA))
			{
				/* TIMA */
				Push(m_Registers.PC);
				/* jump to ISR*/
				m_Registers.PC = TIMA_ISR;
				
			}
			if((ints & INTERRUPT_SERIAL) && (ie & INTERRUPT_SERIAL))
			{
				/* SERIAL I/O */
				Push(m_Registers.PC);
				/* jump to ISR*/
				m_Registers.PC = SERIAL_ISR;

			}
			if((ints & INTERRUPT_INPUT) && (ie & INTERRUPT_INPUT))
			{
				/* INPUT */
				Push(m_Registers.PC);
				/* jump to ISR*/
				m_Registers.PC = INPUT_ISR;
			}

			m_Memory[0xFF0F] = 0;

			m_InterruptState = EnableRequested;
		}
		
		startingPC = m_Registers.PC;
		uint8_t nextOpcode = m_Memory[m_Registers.PC].Get();
		opcode = g_Instructions.at(nextOpcode);
		
		ticksTaken = 0;
		ticksInCurrentOp = opcode.TickCount;
		ticksUsed = 0;
		assert(opcode.TickCount <= opcode.BranchTickCount);
		
#ifdef DEBUG
		/* Patch up the debug string */
		std::cout << std::hex << "[" << m_Registers.PC << "] " << std::dec << FormatDebugString() << std::endl;
#endif
	}
	
	/* Make the operation callback */
	if( ticksTaken < ticksInCurrentOp )
	{
		auto callable = opcode.Callback;
		/* We pass in ticksInCurrentOp byref as it can change if a branch is taken */
		ticksTaken += callable(this, opcode, ticksTaken, ticksInCurrentOp);
		assert(ticksTaken <= ticksInCurrentOp);
	}

	ticksUsed++;
	
	/* End of the instruction */
	if( ticksUsed == ticksInCurrentOp )
	{
		/* Handle interrupt state */
		switch( m_InterruptState )
		{
			case DisableRequested:
				m_InterruptState = DisablePending;
				break;
			case DisablePending:
				m_InterruptState = Disabled;
				break;
			case EnableRequested:
				m_InterruptState = EnablePending;
				break;
			case EnablePending:
				m_InterruptState = Enabled;
				break;
			case Enabled:
			case Disabled:
				/* No special handling required */
				break;
			default:
				throw std::runtime_error("Invalid CPU interrupt state");
				break;
		}


		/* Tick on the instruction pointer. ONLY if it didnt change in the instruction */
		if ( startingPC == m_Registers.PC )
		{
			m_Registers.PC += opcode.InstructionWidth;
		}

		m_OperationsExecuted++;
	}

	/* Tick the GPU */
	m_Gpu->Tick();

	return true;
}


