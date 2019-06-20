//
//  Cpu.cpp
//  emucore
//
//  Created by Gareth Evans on 16/06/2019.
//  Copyright © 2019 Gareth Evans. All rights reserved.
//

#include <map>
#include <functional>
#include <sstream>
#include <assert.h>
#include "Cpu.hpp"

static const std::map<int, struct Opcode> g_Instructions
{
#include "CallbackTable.txt"
};

Cpu::Cpu()
{
	/* Initialize registers */
	m_Registers.AF = 0x01;
	m_Registers.F = 0xb0;
	m_Registers.BC = 0x0013;
	m_Registers.DE = 0x00d8;
	m_Registers.HL = 0x014d;
	m_Registers.SP = 0xfffe;
	
	m_Registers.PC = 0x100;
	
}

void
Cpu::Run(void)
{
	Clock::Run();
}

std::string
Cpu::FormatDebugString(
   std::string DebugString
   )
{
	std::size_t found = DebugString.find("a16");
	if( found == std::string::npos )
		found = DebugString.find("d16");
	if( found == std::string::npos )
		found = DebugString.find("r16");
	if ( found != std::string::npos ){
		std::stringstream stream;
		stream << "0x" << std::hex << (int)IMM16();
		DebugString.replace(found, 3, stream.str());
	}
	found = DebugString.find("a8");
	if( found == std::string::npos )
		found = DebugString.find("d8");
	if( found == std::string::npos )
		found = DebugString.find("r8");
	if ( found != std::string::npos ){
		std::stringstream stream;
		stream << "0x" << std::hex << (int)IMM8();
		DebugString.replace(found, 2, stream.str());
	}
	return DebugString;
}

void
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
		Read the new op and reset the counters */
		assert(m_Registers.PC >= 0 && m_Registers.PC < 0x8000);
		startingPC = m_Registers.PC;
		uint8_t nextOpcode = m_Memory[m_Registers.PC].Get();
		opcode = g_Instructions.at(nextOpcode);
		
		ticksTaken = 0;
		ticksInCurrentOp = opcode.TickCount;
		ticksUsed = 0;
		assert(opcode.TickCount <= opcode.BranchTickCount);
		
#ifdef DEBUG
		/* Patch up the debug string */
//		std::cout << FormatDebugString(opcode.DebugString) << std::endl;
#endif
	}
	
	if( ticksTaken < ticksInCurrentOp )
	{
		auto callable = opcode.Callback;
		/* We pass in ticksInCurrentOp byref as it can change if a branch is taken */
		ticksTaken += callable(this, opcode, ticksTaken, ticksInCurrentOp);
		assert(ticksTaken <= ticksInCurrentOp);
	}

	ticksUsed++;
	
	if( ticksUsed == ticksInCurrentOp &&
	   startingPC == m_Registers.PC )
	{
		/* Tick on the instruction pointer. ONLY if it didnt change in the instruction */
		m_Registers.PC += opcode.InstructionWidth;
	}
}


