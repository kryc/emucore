//
//  Cpu.hpp
//  emucore
//
//  Created by Gareth Evans on 16/06/2019.
//  Copyright © 2019 Gareth Evans. All rights reserved.
//

#ifndef Cpu_hpp
#define Cpu_hpp

#include <cstdint>
#include "ProcessingCore.hpp"
#include "Memory.hpp"

typedef struct __attribute__((__packed__)){
	union{
		struct{
			union{
				uint8_t f;
				uint8_t F;
			};
			union{
				uint8_t a;
				uint8_t A;
			};
		};
		union{
			uint16_t af;
			uint16_t AF;
		};
	};
	/* B, C */
	union{
		struct{
			union{
				uint8_t c;
				uint8_t C;
			};
			union{
				uint8_t b;
				uint8_t B;
			};
		};
		union{
			uint16_t bc;
			uint16_t BC;
		};
	};
	/* D, E */
	union{
		struct{
			union{
				uint8_t e;
				uint8_t E;
			};
			union{
				uint8_t d;
				uint8_t D;
			};
		};
		union{
			uint16_t de;
			uint16_t DE;
		};
	};
	/* H, L */
	union{
		struct{
			union{
				uint8_t l;
				uint8_t L;
			};
			union{
				uint8_t h;
				uint8_t H;
			};
		};
		union{
			uint16_t hl;
			uint16_t HL;
		};
	};
	union{
		uint16_t sp;
		uint16_t SP;
	};
	union{
		uint16_t pc;
		uint16_t PC;
	};
} REGISTERS;

class Cpu;

using OpcodeCallback = std::function<ssize_t(Cpu*, const struct Opcode&, ssize_t, ssize_t&)>;

struct Opcode
{
	std::string 	DebugString;
	OpcodeCallback 	Callback;
	size_t 			InstructionWidth;
	size_t			BranchTickCount;
	size_t			TickCount;
};

#define OPCODE_CALLBACK_NAME(OpcodeNum) Callback##OpcodeNum
#define OPCODE_CALLBACK(OpcodeNum) ssize_t Callback##OpcodeNum(uint8_t* PC, ssize_t Ticks)
#define OPCODE_PROTO(OpcodeNum)ssize_t Cpu::Callback##OpcodeNum(uint8_t* PC, ssize_t Ticks)

#define FLAG_Z (1 << 7) //result is zero or two values match in CP op
#define FLAG_N (1 << 6) //subtraction performed in last operation
#define FLAG_H (1 << 5) //set if carry occured from lower nibble in last op
#define FLAG_C (1 << 4) //set if carry occurred or if reg A is smaller during CP op

#define SET_FLAG_H() (m_Registers.F |= (FLAG_H))
#define SET_FLAG_C() (m_Registers.F |= (FLAG_C))
#define SET_FLAG_N() (m_Registers.F |= (FLAG_N))
#define SET_FLAG_Z() (m_Registers.F |= (FLAG_Z))

#define FLAG_IS_SET_H() ((m_Registers.F & FLAG_H) == (FLAG_H))
#define FLAG_IS_SET_C() ((m_Registers.F & FLAG_C) == (FLAG_C))
#define FLAG_IS_SET_N() ((m_Registers.F & FLAG_N) == (FLAG_N))
#define FLAG_IS_SET_Z() ((m_Registers.F & FLAG_Z) == (FLAG_Z))

#define FLAG_NOT_SET_H() ((m_Registers.F & FLAG_H) != (FLAG_H))
#define FLAG_NOT_SET_C() ((m_Registers.F & FLAG_C) != (FLAG_C))
#define FLAG_NOT_SET_N() ((m_Registers.F & FLAG_N) != (FLAG_N))
#define FLAG_NOT_SET_Z() ((m_Registers.F & FLAG_Z) != (FLAG_Z))

#define RESET_FLAG_H() (m_Registers.F &= ~(FLAG_H))
#define RESET_FLAG_C() (m_Registers.F &= ~(FLAG_C))
#define RESET_FLAG_N() (m_Registers.F &= ~(FLAG_N))
#define RESET_FLAG_Z() (m_Registers.F &= ~(FLAG_Z))

#define PUSH_16(val) m_Memory[m_Registers.SP-1] = (val) >> 8; \
						m_Memory[m_Registers.SP-2] = (val) & 0x0f; \
						m_Registers.SP -= 2; \

#define PUSH_8(val) m_Memory[m_Registers.SP-1] = (val) & 0xf; \
						m_Registers.SP -= 1; \

#define IMM8() (m_Memory[m_Registers.PC+1].Get())
#define IMM16() (m_Memory.Get16(m_Registers.PC+1))

#define CHK_SET_FLAG_C(before,opnd,after) ((((before ^ opnd ^ after) & 0x100) == 0x100) ? (SET_FLAG_C()) : (RESET_FLAG_C()))
#define CHK_SET_FLAG_H(before,opnd,after) ((((before ^ opnd ^ after) & 0x10) == 0x10) ? (SET_FLAG_H()) : (RESET_FLAG_H()))
#define CHK_SET_FLAG_Z(after) ((after==0)? (SET_FLAG_Z()) : (RESET_FLAG_Z()))

#define CHK_SET_FLAG_C_16(before,opnd,after) (((( after & 0x10000) > 0) ? (SET_FLAG_C()) : (RESET_FLAG_C()))
#define CHK_SET_FLAG_H_16(before,opnd,after) ((((before ^ opnd ^ after) & 0x1000) == 0x1000) ? (SET_FLAG_H()) : (RESET_FLAG_H()))

class Cpu : public ProcessingCore
{
public:
	Cpu();
	void 		Run(void);
	void 		Tick(void) override;
	void 		LoadRom(std::string RomFile) { m_Memory.LoadRom(RomFile); };
	Memory&		GetMemory(void) { return m_Memory; };
	
	/* The following are the opcode callback routines */
#include "ClassOperations.txt"
private:
	std::string FormatDebugString(std::string DebugString);
	REGISTERS 	m_Registers{};
	Memory 		m_Memory;
};

#endif /* Cpu_hpp */
