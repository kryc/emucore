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
#include <string>
#include <map>
#include "ProcessingCore.hpp"
#include "DebuggableCore.hpp"
#include "Memory.hpp"
#include "Gpu.hpp"

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
class Gpu;

using OpcodeCallback = std::function<ssize_t(Cpu*, const struct Opcode&, ssize_t, ssize_t&)>;

struct Opcode
{
	std::string 	DebugString;
	OpcodeCallback 	Callback;
	size_t 			InstructionWidth;
	size_t			BranchTickCount;
	size_t			TickCount;
};

typedef enum{
	Enabled,
	DisableRequested,
	DisablePending,
	Disabled,
	EnableRequested,
	EnablePending,
} InterruptState;

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

#define CHK_SET_FLAG_C(before,opnd,after) ((((before ^ opnd ^ after) & 0x100) == 0x100) ? (SET_FLAG_C()) : (RESET_FLAG_C()))
#define CHK_SET_FLAG_H(before,opnd,after) ((((before ^ opnd ^ after) & 0x10) == 0x10) ? (SET_FLAG_H()) : (RESET_FLAG_H()))
#define CHK_SET_FLAG_Z(after) ((after==0)? (SET_FLAG_Z()) : (RESET_FLAG_Z()))

#define CHK_SET_FLAG_C_16(before,opnd,after) ((( after & 0x10000) > 0) ? (SET_FLAG_C()) : (RESET_FLAG_C()))
#define CHK_SET_FLAG_H_16(before,opnd,after) ((((before ^ opnd ^ after) & 0x1000) == 0x1000) ? (SET_FLAG_H()) : (RESET_FLAG_H()))

#define VBLANK_ISR 	0x40
#define LCDC_ISR 	0x48
#define TIMA_ISR 	0x50
#define SERIAL_ISR 	0x58
#define INPUT_ISR 	0x60

class Cpu : 
	public ProcessingCore,
	public DebuggableCore,
	public std::enable_shared_from_this<Cpu>
{
public:
	Cpu();
	void 		Run(void);
	void		Step(void) override;
	bool 		Tick(void) override;
	void 		LoadRom(std::string RomFile) { m_Memory.LoadRom(RomFile); };
	Memory&		GetMemory(void) { return m_Memory; };
	std::map<std::string, register_t> GetRegisters(void) override;
	std::string FormatDebugString(const uint32_t Pc = 0x10000, size_t *InstructionWidth = nullptr);
	uint8_t ReadMemory(register_t Address) override;
	std::vector<uint8_t> ReadMemoryRange(register_t StartAddress, size_t Length) override;
	
	/* The following are the opcode callback routines */
#include "ClassOperations.txt"
private:
	/* Utility functions for opcode emulation */
	void 		Push(uint16_t Value);
	void 		Push(uint8_t Value);
	uint16_t	Pop(void);
	uint8_t		Pop8(void);
	uint8_t 	Immediate8(uint16_t Pc);
	uint8_t 	Immediate8(void);
	uint16_t 	Immediate16(uint16_t Pc);
	uint16_t 	Immediate16(void);

	void 		OnInterrupt(int Interrupt);

	/* Private functions */

	/* Private variables */
	REGISTERS 				m_Registers{};
	Memory 					m_Memory;
	std::shared_ptr<Gpu>	m_Gpu;
	InterruptState 			m_InterruptState = Disabled;
	size_t 					m_OperationsExecuted = 0;
};

#endif /* Cpu_hpp */
