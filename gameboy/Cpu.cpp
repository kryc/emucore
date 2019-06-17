//
//  Cpu.cpp
//  emucore
//
//  Created by Gareth Evans on 16/06/2019.
//  Copyright © 2019 Gareth Evans. All rights reserved.
//

#include <map>
#include <functional>
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
	static ssize_t  ticksRemaining = 0;
	static uint16_t startingPC = 0;
	static struct Opcode opcode{};
	
	if( ticksRemaining == 0 )
	{
		/* We have completed the previous operation (or it is the first op).
		Read the new op and reset the counters */
		assert(m_Registers.PC > 0 && m_Registers.PC < 0x8000);
		std::cout << m_Registers.PC << "[" << (int)m_Memory[m_Registers.PC].Get() << "]" << std::endl;
		startingPC = m_Registers.PC;
		uint8_t nextOpcode = m_Memory[m_Registers.PC].Get();
		opcode = g_Instructions.at(nextOpcode);
		
		ticksTaken = 0;
		ticksInCurrentOp = opcode.TickCount;
		ticksRemaining = ticksInCurrentOp;
		
		std::cout << opcode.DebugString << std::endl;
	}
	
	if( ticksTaken < ticksInCurrentOp )
	{
		auto callable = opcode.Callback;
		/* We pass in ticksInCurrentOp byref as it can change if a branch is taken */
		ticksTaken += callable(this, opcode, ticksTaken, ticksInCurrentOp);
		assert(ticksTaken <= ticksInCurrentOp);
	}

	ticksRemaining--;
	
	if( ticksRemaining == 0 &&
	   startingPC == m_Registers.PC )
	{
		/* Tick on the instruction pointer. ONLY if it didnt change in the instruction */
		m_Registers.PC += opcode.InstructionWidth;
	}
}


