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

using OpcodeCallback = std::function<ssize_t(Cpu*, const struct Opcode&, ssize_t)>;

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

enum
{
	FLAG_ZERO = 0x80,
	FLAG_SUB =  0x40,
	FLAG_HALF = 0x20,
	FLAG_CARR = 0x10
};

class Cpu : public ProcessingCore
{
public:
	Cpu();
	void 		Run(void);
	void 		Tick(void) override;
	void 		LoadRom(std::string RomFile) { m_Memory.LoadRom(RomFile); };
	Memory&		GetMemory(void) { return m_Memory; };
	
	/* The following are the opcode callback routines */
#include "ClassOperations.txt";
private:
	REGISTERS 	m_Registers{};
	Memory 		m_Memory;
};

#endif /* Cpu_hpp */
