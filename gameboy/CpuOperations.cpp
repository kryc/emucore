#include "Cpu.hpp"

ssize_t
Cpu::NOP(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	NOP
 Opcode:	0x0
 Width:		1
 Cycles:	4/4
 --*/
{
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_BC_d16(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD BC,d16
 Opcode:	0x1
 Width:		3
 Cycles:	12/12
 --*/
{
	throw std::runtime_error("Instruction LD BC,d16 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD__BC__A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD (BC),A
 Opcode:	0x2
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction LD (BC),A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::INC_BC(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	INC BC
 Opcode:	0x3
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction INC BC not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::INC_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	INC B
 Opcode:	0x4
 Width:		1
 Cycles:	4/4
 --*/
{
	uint8_t before = m_Registers.B;
	uint8_t operand = 1;
	uint8_t after = m_Registers.B + operand;
	
	RESET_FLAG_N();
	CHK_SET_FLAG_Z(after);
	CHK_SET_FLAG_H(before, operand, after);
	
	m_Registers.B = after;
	
	return Opcode.TickCount;
}

ssize_t
Cpu::DEC_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	DEC B
 Opcode:	0x5
 Width:		1
 Cycles:	4/4
 --*/
{
	uint8_t before = m_Registers.B;
	int8_t operand = -1;
	uint8_t after = m_Registers.B + operand;
	
	SET_FLAG_N();
	CHK_SET_FLAG_Z(after);
	CHK_SET_FLAG_H(before, operand, after);
	
	m_Registers.B = after;
	
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_B_d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD B,d8
 Opcode:	0x6
 Width:		2
 Cycles:	8/8
 --*/
{
	m_Registers.B = IMM8();
	
	/* Flags not affected */
	
	return Opcode.TickCount;
}

ssize_t
Cpu::RLCA(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RLCA
 Opcode:	0x7
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction RLCA not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD__a16__SP(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD (a16),SP
 Opcode:	0x8
 Width:		3
 Cycles:	20/20
 --*/
{
	throw std::runtime_error("Instruction LD (a16),SP not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADD_HL_BC(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	ADD HL,BC
 Opcode:	0x9
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction ADD HL,BC not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_A__BC_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD A,(BC)
 Opcode:	0xa
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction LD A,(BC) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::DEC_BC(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	DEC BC
 Opcode:	0xb
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction DEC BC not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::INC_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	INC C
 Opcode:	0xc
 Width:		1
 Cycles:	4/4
 --*/
{
	uint8_t before = m_Registers.C;
	uint8_t operand = 1;
	uint8_t after = m_Registers.C + operand;
	
	RESET_FLAG_N();
	CHK_SET_FLAG_Z(after);
	CHK_SET_FLAG_H(before, operand, after);
	
	m_Registers.C = after;
	
	return Opcode.TickCount;
}

ssize_t
Cpu::DEC_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	DEC C
 Opcode:	0xd
 Width:		1
 Cycles:	4/4
 --*/
{
	uint8_t before = m_Registers.C;
	int8_t operand = -1;
	uint8_t after = m_Registers.C + operand;
	
	SET_FLAG_N();
	CHK_SET_FLAG_Z(after);
	CHK_SET_FLAG_H(before, operand, after);
	
	m_Registers.C = after;
	
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_C_d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD C,d8
 Opcode:	0xe
 Width:		2
 Cycles:	8/8
 --*/
{
	m_Registers.C = IMM8();
	
	/* Flags not affected */
	
	return Opcode.TickCount;
}

ssize_t
Cpu::RRCA(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RRCA
 Opcode:	0xf
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction RRCA not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::STOP_0(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	STOP 0
 Opcode:	0x10
 Width:		2
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction STOP 0 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_DE_d16(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD DE,d16
 Opcode:	0x11
 Width:		3
 Cycles:	12/12
 --*/
{
	throw std::runtime_error("Instruction LD DE,d16 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD__DE__A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD (DE),A
 Opcode:	0x12
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction LD (DE),A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::INC_DE(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	INC DE
 Opcode:	0x13
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction INC DE not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::INC_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	INC D
 Opcode:	0x14
 Width:		1
 Cycles:	4/4
 --*/
{
	uint8_t before = m_Registers.D;
	uint8_t operand = 1;
	uint8_t after = m_Registers.D + operand;
	
	RESET_FLAG_N();
	CHK_SET_FLAG_Z(after);
	CHK_SET_FLAG_H(before, operand, after);
	
	m_Registers.D = after;
	
	return Opcode.TickCount;
}

ssize_t
Cpu::DEC_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	DEC D
 Opcode:	0x15
 Width:		1
 Cycles:	4/4
 --*/
{
	uint8_t before = m_Registers.D;
	int8_t operand = -1;
	uint8_t after = m_Registers.D + operand;
	
	SET_FLAG_N();
	CHK_SET_FLAG_Z(after);
	CHK_SET_FLAG_H(before, operand, after);
	
	m_Registers.D = after;
	
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_D_d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD D,d8
 Opcode:	0x16
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction LD D,d8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RLA(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RLA
 Opcode:	0x17
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction RLA not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::JR_r8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	JR r8
 Opcode:	0x18
 Width:		2
 Cycles:	12/12
 --*/
{
	throw std::runtime_error("Instruction JR r8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADD_HL_DE(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	ADD HL,DE
 Opcode:	0x19
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction ADD HL,DE not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_A__DE_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD A,(DE)
 Opcode:	0x1a
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction LD A,(DE) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::DEC_DE(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	DEC DE
 Opcode:	0x1b
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction DEC DE not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::INC_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	INC E
 Opcode:	0x1c
 Width:		1
 Cycles:	4/4
 --*/
{
	uint8_t before = m_Registers.E;
	uint8_t operand = 1;
	uint8_t after = m_Registers.E + operand;
	
	RESET_FLAG_N();
	CHK_SET_FLAG_Z(after);
	CHK_SET_FLAG_H(before, operand, after);
	
	m_Registers.E = after;
	
	return Opcode.TickCount;
}

ssize_t
Cpu::DEC_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	DEC E
 Opcode:	0x1d
 Width:		1
 Cycles:	4/4
 --*/
{
	uint8_t before = m_Registers.E;
	int8_t operand = -1;
	uint8_t after = m_Registers.E + operand;
	
	SET_FLAG_N();
	CHK_SET_FLAG_Z(after);
	CHK_SET_FLAG_H(before, operand, after);
	
	m_Registers.E = after;
	
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_E_d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD E,d8
 Opcode:	0x1e
 Width:		2
 Cycles:	8/8
 --*/
{
	m_Registers.E = IMM8();
	
	/* Flags not affected */
	
	return Opcode.TickCount;
}

ssize_t
Cpu::RRA(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RRA
 Opcode:	0x1f
 Width:		1
 Cycles:	4/4
 --*/
{
	uint8_t carry = FLAG_IS_SET_C() ? 0 : 0x80;
	uint8_t result = m_Registers.A;
	if ((result & 0x1) != 0)
	{
		SET_FLAG_C();
	}
	else
	{
		RESET_FLAG_C();
	}
	
	result >>= 1;
	result |= carry;
	
	CHK_SET_FLAG_Z(result);
	RESET_FLAG_N();
	RESET_FLAG_H();
	
	m_Registers.A = result;
	
	return Opcode.TickCount;
}

ssize_t
Cpu::JR_NZ_r8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	JR NZ,r8
 Opcode:	0x20
 Width:		2
 Cycles:	12/8
 --*/
{
	if( FLAG_NOT_SET_Z() )
	{
		int8_t immediate = (int8_t)IMM8();
		m_Registers.PC += immediate + Opcode.InstructionWidth;
		TickCount = Opcode.BranchTickCount;
		return Opcode.BranchTickCount;
	}
	
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_HL_d16(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD HL,d16
 Opcode:	0x21
 Width:		3
 Cycles:	12/12
 --*/
{
	m_Registers.HL = m_Memory.Get16(m_Registers.PC+1);
	
	/* No flags affected */
	
	return Opcode.TickCount;
}

ssize_t
Cpu::LD__HLpls__A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD (HL+),A
 Opcode:	0x22
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction LD (HL+),A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::INC_HL(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	INC HL
 Opcode:	0x23
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction INC HL not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::INC_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	INC H
 Opcode:	0x24
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction INC H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::DEC_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	DEC H
 Opcode:	0x25
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction DEC H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_H_d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD H,d8
 Opcode:	0x26
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction LD H,d8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::DAA(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	DAA
 Opcode:	0x27
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction DAA not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::JR_Z_r8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	JR Z,r8
 Opcode:	0x28
 Width:		2
 Cycles:	12/8
 --*/
{
	throw std::runtime_error("Instruction JR Z,r8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADD_HL_HL(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	ADD HL,HL
 Opcode:	0x29
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction ADD HL,HL not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_A__HLpls_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD A,(HL+)
 Opcode:	0x2a
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction LD A,(HL+) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::DEC_HL(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	DEC HL
 Opcode:	0x2b
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction DEC HL not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::INC_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	INC L
 Opcode:	0x2c
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction INC L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::DEC_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	DEC L
 Opcode:	0x2d
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction DEC L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_L_d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD L,d8
 Opcode:	0x2e
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction LD L,d8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::CPL(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	CPL
 Opcode:	0x2f
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction CPL not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::JR_NC_r8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	JR NC,r8
 Opcode:	0x30
 Width:		2
 Cycles:	12/8
 --*/
{
	throw std::runtime_error("Instruction JR NC,r8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_SP_d16(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD SP,d16
 Opcode:	0x31
 Width:		3
 Cycles:	12/12
 --*/
{
	throw std::runtime_error("Instruction LD SP,d16 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD__HLmin__A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD (HL-),A
 Opcode:	0x32
 Width:		1
 Cycles:	8/8
 --*/
{
	m_Memory[m_Registers.HL] = m_Registers.A;
	m_Registers.HL--;
	
	/* Flags not affected */
	
	return Opcode.TickCount;
}

ssize_t
Cpu::INC_SP(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	INC SP
 Opcode:	0x33
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction INC SP not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::INC__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	INC (HL)
 Opcode:	0x34
 Width:		1
 Cycles:	12/12
 --*/
{
	throw std::runtime_error("Instruction INC (HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::DEC__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	DEC (HL)
 Opcode:	0x35
 Width:		1
 Cycles:	12/12
 --*/
{
	throw std::runtime_error("Instruction DEC (HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD__HL__d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD (HL),d8
 Opcode:	0x36
 Width:		2
 Cycles:	12/12
 --*/
{
	throw std::runtime_error("Instruction LD (HL),d8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SCF(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SCF
 Opcode:	0x37
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction SCF not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::JR_C_r8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	JR C,r8
 Opcode:	0x38
 Width:		2
 Cycles:	12/8
 --*/
{
	throw std::runtime_error("Instruction JR C,r8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADD_HL_SP(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	ADD HL,SP
 Opcode:	0x39
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction ADD HL,SP not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_A__HLmin_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD A,(HL-)
 Opcode:	0x3a
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction LD A,(HL-) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::DEC_SP(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	DEC SP
 Opcode:	0x3b
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction DEC SP not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::INC_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	INC A
 Opcode:	0x3c
 Width:		1
 Cycles:	4/4
 --*/
{
	uint8_t before = m_Registers.A;
	uint8_t operand = 1;
	uint8_t after = m_Registers.A + operand;
	
	RESET_FLAG_N();
	CHK_SET_FLAG_Z(after);
	CHK_SET_FLAG_H(before, operand, after);
	
	m_Registers.A = after;
	
	return Opcode.TickCount;
}

ssize_t
Cpu::DEC_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	DEC A
 Opcode:	0x3d
 Width:		1
 Cycles:	4/4
 --*/
{
	uint8_t before = m_Registers.A;
	int8_t operand = -1;
	uint8_t after = m_Registers.A + operand;
	
	SET_FLAG_N();
	CHK_SET_FLAG_Z(after);
	CHK_SET_FLAG_H(before, operand, after);
	
	m_Registers.A = after;
	
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_A_d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD A,d8
 Opcode:	0x3e
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction LD A,d8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::CCF(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	CCF
 Opcode:	0x3f
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction CCF not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_B_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD B,B
 Opcode:	0x40
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD B,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_B_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD B,C
 Opcode:	0x41
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD B,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_B_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD B,D
 Opcode:	0x42
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD B,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_B_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD B,E
 Opcode:	0x43
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD B,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_B_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD B,H
 Opcode:	0x44
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD B,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_B_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD B,L
 Opcode:	0x45
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD B,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_B__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD B,(HL)
 Opcode:	0x46
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction LD B,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_B_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD B,A
 Opcode:	0x47
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD B,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_C_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD C,B
 Opcode:	0x48
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD C,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_C_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD C,C
 Opcode:	0x49
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD C,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_C_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD C,D
 Opcode:	0x4a
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD C,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_C_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD C,E
 Opcode:	0x4b
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD C,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_C_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD C,H
 Opcode:	0x4c
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD C,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_C_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD C,L
 Opcode:	0x4d
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD C,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_C__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD C,(HL)
 Opcode:	0x4e
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction LD C,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_C_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD C,A
 Opcode:	0x4f
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD C,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_D_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD D,B
 Opcode:	0x50
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD D,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_D_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD D,C
 Opcode:	0x51
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD D,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_D_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD D,D
 Opcode:	0x52
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD D,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_D_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD D,E
 Opcode:	0x53
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD D,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_D_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD D,H
 Opcode:	0x54
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD D,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_D_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD D,L
 Opcode:	0x55
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD D,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_D__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD D,(HL)
 Opcode:	0x56
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction LD D,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_D_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD D,A
 Opcode:	0x57
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD D,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_E_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD E,B
 Opcode:	0x58
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD E,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_E_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD E,C
 Opcode:	0x59
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD E,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_E_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD E,D
 Opcode:	0x5a
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD E,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_E_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD E,E
 Opcode:	0x5b
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD E,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_E_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD E,H
 Opcode:	0x5c
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD E,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_E_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD E,L
 Opcode:	0x5d
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD E,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_E__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD E,(HL)
 Opcode:	0x5e
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction LD E,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_E_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD E,A
 Opcode:	0x5f
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD E,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_H_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD H,B
 Opcode:	0x60
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD H,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_H_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD H,C
 Opcode:	0x61
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD H,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_H_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD H,D
 Opcode:	0x62
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD H,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_H_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD H,E
 Opcode:	0x63
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD H,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_H_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD H,H
 Opcode:	0x64
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD H,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_H_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD H,L
 Opcode:	0x65
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD H,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_H__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD H,(HL)
 Opcode:	0x66
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction LD H,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_H_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD H,A
 Opcode:	0x67
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD H,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_L_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD L,B
 Opcode:	0x68
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD L,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_L_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD L,C
 Opcode:	0x69
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD L,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_L_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD L,D
 Opcode:	0x6a
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD L,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_L_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD L,E
 Opcode:	0x6b
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD L,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_L_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD L,H
 Opcode:	0x6c
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD L,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_L_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD L,L
 Opcode:	0x6d
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD L,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_L__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD L,(HL)
 Opcode:	0x6e
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction LD L,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_L_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD L,A
 Opcode:	0x6f
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD L,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD__HL__B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD (HL),B
 Opcode:	0x70
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction LD (HL),B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD__HL__C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD (HL),C
 Opcode:	0x71
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction LD (HL),C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD__HL__D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD (HL),D
 Opcode:	0x72
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction LD (HL),D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD__HL__E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD (HL),E
 Opcode:	0x73
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction LD (HL),E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD__HL__H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD (HL),H
 Opcode:	0x74
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction LD (HL),H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD__HL__L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD (HL),L
 Opcode:	0x75
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction LD (HL),L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::HALT(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	HALT
 Opcode:	0x76
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction HALT not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD__HL__A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD (HL),A
 Opcode:	0x77
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction LD (HL),A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_A_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD A,B
 Opcode:	0x78
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD A,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_A_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD A,C
 Opcode:	0x79
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD A,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_A_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD A,D
 Opcode:	0x7a
 Width:		1
 Cycles:	4/4
 --*/
{
	m_Registers.A = m_Registers.D;
	
	/* Flags not affected */
	
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_A_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD A,E
 Opcode:	0x7b
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD A,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_A_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD A,H
 Opcode:	0x7c
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD A,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_A_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD A,L
 Opcode:	0x7d
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD A,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_A__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD A,(HL)
 Opcode:	0x7e
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction LD A,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_A_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD A,A
 Opcode:	0x7f
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction LD A,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADD_A_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	ADD A,B
 Opcode:	0x80
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction ADD A,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADD_A_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	ADD A,C
 Opcode:	0x81
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction ADD A,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADD_A_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	ADD A,D
 Opcode:	0x82
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction ADD A,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADD_A_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	ADD A,E
 Opcode:	0x83
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction ADD A,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADD_A_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	ADD A,H
 Opcode:	0x84
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction ADD A,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADD_A_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	ADD A,L
 Opcode:	0x85
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction ADD A,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADD_A__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	ADD A,(HL)
 Opcode:	0x86
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction ADD A,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADD_A_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	ADD A,A
 Opcode:	0x87
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction ADD A,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADC_A_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	ADC A,B
 Opcode:	0x88
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction ADC A,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADC_A_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	ADC A,C
 Opcode:	0x89
 Width:		1
 Cycles:	4/4
 --*/
{
	uint8_t operand = m_Registers.A;
	if( FLAG_IS_SET_C() )
		operand +=1;
	
	uint8_t before = m_Registers.A;
	uint8_t after = m_Registers.A + operand;
	
	m_Registers.F = 0;
	CHK_SET_FLAG_C(before, operand, after);
	CHK_SET_FLAG_H(before, operand, after);
	CHK_SET_FLAG_Z(after);
	
	m_Registers.A = after;
	
	return Opcode.TickCount;
}

ssize_t
Cpu::ADC_A_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	ADC A,D
 Opcode:	0x8a
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction ADC A,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADC_A_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	ADC A,E
 Opcode:	0x8b
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction ADC A,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADC_A_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	ADC A,H
 Opcode:	0x8c
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction ADC A,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADC_A_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	ADC A,L
 Opcode:	0x8d
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction ADC A,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADC_A__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	ADC A,(HL)
 Opcode:	0x8e
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction ADC A,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADC_A_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	ADC A,A
 Opcode:	0x8f
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction ADC A,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SUB_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SUB B
 Opcode:	0x90
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction SUB B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SUB_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SUB C
 Opcode:	0x91
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction SUB C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SUB_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SUB D
 Opcode:	0x92
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction SUB D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SUB_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SUB E
 Opcode:	0x93
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction SUB E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SUB_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SUB H
 Opcode:	0x94
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction SUB H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SUB_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SUB L
 Opcode:	0x95
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction SUB L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SUB__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SUB (HL)
 Opcode:	0x96
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SUB (HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SUB_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SUB A
 Opcode:	0x97
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction SUB A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SBC_A_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SBC A,B
 Opcode:	0x98
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction SBC A,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SBC_A_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SBC A,C
 Opcode:	0x99
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction SBC A,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SBC_A_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SBC A,D
 Opcode:	0x9a
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction SBC A,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SBC_A_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SBC A,E
 Opcode:	0x9b
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction SBC A,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SBC_A_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SBC A,H
 Opcode:	0x9c
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction SBC A,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SBC_A_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SBC A,L
 Opcode:	0x9d
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction SBC A,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SBC_A__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SBC A,(HL)
 Opcode:	0x9e
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SBC A,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SBC_A_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SBC A,A
 Opcode:	0x9f
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction SBC A,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::AND_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	AND B
 Opcode:	0xa0
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction AND B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::AND_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	AND C
 Opcode:	0xa1
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction AND C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::AND_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	AND D
 Opcode:	0xa2
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction AND D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::AND_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	AND E
 Opcode:	0xa3
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction AND E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::AND_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	AND H
 Opcode:	0xa4
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction AND H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::AND_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	AND L
 Opcode:	0xa5
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction AND L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::AND__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	AND (HL)
 Opcode:	0xa6
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction AND (HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::AND_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	AND A
 Opcode:	0xa7
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction AND A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::XOR_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	XOR B
 Opcode:	0xa8
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction XOR B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::XOR_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	XOR C
 Opcode:	0xa9
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction XOR C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::XOR_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	XOR D
 Opcode:	0xaa
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction XOR D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::XOR_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	XOR E
 Opcode:	0xab
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction XOR E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::XOR_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	XOR H
 Opcode:	0xac
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction XOR H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::XOR_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	XOR L
 Opcode:	0xad
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction XOR L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::XOR__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	XOR (HL)
 Opcode:	0xae
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction XOR (HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::XOR_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	XOR A
 Opcode:	0xaf
 Width:		1
 Cycles:	4/4
 --*/
{
	m_Registers.A ^= m_Registers.A;
	m_Registers.F = 0;
	
	CHK_SET_FLAG_Z(m_Registers.A);
	
	return Opcode.TickCount;
}

ssize_t
Cpu::OR_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	OR B
 Opcode:	0xb0
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction OR B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::OR_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	OR C
 Opcode:	0xb1
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction OR C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::OR_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	OR D
 Opcode:	0xb2
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction OR D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::OR_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	OR E
 Opcode:	0xb3
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction OR E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::OR_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	OR H
 Opcode:	0xb4
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction OR H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::OR_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	OR L
 Opcode:	0xb5
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction OR L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::OR__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	OR (HL)
 Opcode:	0xb6
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction OR (HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::OR_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	OR A
 Opcode:	0xb7
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction OR A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::CP_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	CP B
 Opcode:	0xb8
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction CP B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::CP_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	CP C
 Opcode:	0xb9
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction CP C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::CP_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	CP D
 Opcode:	0xba
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction CP D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::CP_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	CP E
 Opcode:	0xbb
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction CP E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::CP_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	CP H
 Opcode:	0xbc
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction CP H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::CP_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	CP L
 Opcode:	0xbd
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction CP L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::CP__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	CP (HL)
 Opcode:	0xbe
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction CP (HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::CP_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	CP A
 Opcode:	0xbf
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction CP A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RET_NZ(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RET NZ
 Opcode:	0xc0
 Width:		1
 Cycles:	20/8
 --*/
{
	throw std::runtime_error("Instruction RET NZ not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::POP_BC(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	POP BC
 Opcode:	0xc1
 Width:		1
 Cycles:	12/12
 --*/
{
	throw std::runtime_error("Instruction POP BC not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::JP_NZ_a16(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	JP NZ,a16
 Opcode:	0xc2
 Width:		3
 Cycles:	16/12
 --*/
{
	throw std::runtime_error("Instruction JP NZ,a16 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::JP_a16(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	JP a16
 Opcode:	0xc3
 Width:		3
 Cycles:	16/16
 --*/
{
	uint16_t address = m_Memory.Get16(m_Registers.PC+1);
	m_Registers.PC = address;
	return Opcode.TickCount;
}

ssize_t
Cpu::CALL_NZ_a16(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	CALL NZ,a16
 Opcode:	0xc4
 Width:		3
 Cycles:	24/12
 --*/
{
	throw std::runtime_error("Instruction CALL NZ,a16 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::PUSH_BC(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	PUSH BC
 Opcode:	0xc5
 Width:		1
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction PUSH BC not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADD_A_d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	ADD A,d8
 Opcode:	0xc6
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction ADD A,d8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RST_00H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RST 00H
 Opcode:	0xc7
 Width:		1
 Cycles:	16/16
 --*/
{
	PUSH_16(m_Registers.PC);
	m_Registers.PC = 0x00;
	
	/* Flags not affected */
	
	return Opcode.TickCount;
}

ssize_t
Cpu::RET_Z(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RET Z
 Opcode:	0xc8
 Width:		1
 Cycles:	20/8
 --*/
{
	throw std::runtime_error("Instruction RET Z not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RET(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RET
 Opcode:	0xc9
 Width:		1
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction RET not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::JP_Z_a16(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	JP Z,a16
 Opcode:	0xca
 Width:		3
 Cycles:	16/12
 --*/
{
	throw std::runtime_error("Instruction JP Z,a16 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::PREFIX_CB(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	PREFIX CB
 Opcode:	0xcb
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction PREFIX CB not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::CALL_Z_a16(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	CALL Z,a16
 Opcode:	0xcc
 Width:		3
 Cycles:	24/12
 --*/
{
	throw std::runtime_error("Instruction CALL Z,a16 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::CALL_a16(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	CALL a16
 Opcode:	0xcd
 Width:		3
 Cycles:	24/24
 --*/
{
	throw std::runtime_error("Instruction CALL a16 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADC_A_d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	ADC A,d8
 Opcode:	0xce
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction ADC A,d8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RST_08H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RST 08H
 Opcode:	0xcf
 Width:		1
 Cycles:	16/16
 --*/
{
	PUSH_16(m_Registers.PC);
	m_Registers.PC = 0x08;
	
	/* Flags not affected */
	
	return Opcode.TickCount;
}

ssize_t
Cpu::RET_NC(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RET NC
 Opcode:	0xd0
 Width:		1
 Cycles:	20/8
 --*/
{
	throw std::runtime_error("Instruction RET NC not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::POP_DE(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	POP DE
 Opcode:	0xd1
 Width:		1
 Cycles:	12/12
 --*/
{
	throw std::runtime_error("Instruction POP DE not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::JP_NC_a16(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	JP NC,a16
 Opcode:	0xd2
 Width:		3
 Cycles:	16/12
 --*/
{
	throw std::runtime_error("Instruction JP NC,a16 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::CALL_NC_a16(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	CALL NC,a16
 Opcode:	0xd4
 Width:		3
 Cycles:	24/12
 --*/
{
	throw std::runtime_error("Instruction CALL NC,a16 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::PUSH_DE(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	PUSH DE
 Opcode:	0xd5
 Width:		1
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction PUSH DE not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SUB_d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SUB d8
 Opcode:	0xd6
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SUB d8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RST_10H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RST 10H
 Opcode:	0xd7
 Width:		1
 Cycles:	16/16
 --*/
{
	PUSH_16(m_Registers.PC);
	m_Registers.PC = 0x10;
	
	/* Flags not affected */
	
	return Opcode.TickCount;
}

ssize_t
Cpu::RET_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RET C
 Opcode:	0xd8
 Width:		1
 Cycles:	20/8
 --*/
{
	throw std::runtime_error("Instruction RET C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RETI(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RETI
 Opcode:	0xd9
 Width:		1
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction RETI not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::JP_C_a16(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	JP C,a16
 Opcode:	0xda
 Width:		3
 Cycles:	16/12
 --*/
{
	throw std::runtime_error("Instruction JP C,a16 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::CALL_C_a16(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	CALL C,a16
 Opcode:	0xdc
 Width:		3
 Cycles:	24/12
 --*/
{
	throw std::runtime_error("Instruction CALL C,a16 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SBC_A_d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SBC A,d8
 Opcode:	0xde
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SBC A,d8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RST_18H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RST 18H
 Opcode:	0xdf
 Width:		1
 Cycles:	16/16
 --*/
{
	PUSH_16(m_Registers.PC);
	m_Registers.PC = 0x18;
	
	/* Flags not affected */
	
	return Opcode.TickCount;
}

ssize_t
Cpu::LDH__a8__A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LDH (a8),A
 Opcode:	0xe0
 Width:		2
 Cycles:	12/12
 --*/
{
	throw std::runtime_error("Instruction LDH (a8),A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::POP_HL(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	POP HL
 Opcode:	0xe1
 Width:		1
 Cycles:	12/12
 --*/
{
	throw std::runtime_error("Instruction POP HL not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD__C__A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD (C),A
 Opcode:	0xe2
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction LD (C),A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::PUSH_HL(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	PUSH HL
 Opcode:	0xe5
 Width:		1
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction PUSH HL not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::AND_d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	AND d8
 Opcode:	0xe6
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction AND d8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RST_20H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RST 20H
 Opcode:	0xe7
 Width:		1
 Cycles:	16/16
 --*/
{
	PUSH_16(m_Registers.PC);
	m_Registers.PC = 0x20;
	
	/* Flags not affected */
	
	return Opcode.TickCount;
}

ssize_t
Cpu::ADD_SP_r8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	ADD SP,r8
 Opcode:	0xe8
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction ADD SP,r8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::JP__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	JP (HL)
 Opcode:	0xe9
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction JP (HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD__a16__A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD (a16),A
 Opcode:	0xea
 Width:		3
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction LD (a16),A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::XOR_d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	XOR d8
 Opcode:	0xee
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction XOR d8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RST_28H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RST 28H
 Opcode:	0xef
 Width:		1
 Cycles:	16/16
 --*/
{
	PUSH_16(m_Registers.PC);
	m_Registers.PC = 0x28;
	
	/* Flags not affected */
	
	return Opcode.TickCount;
}

ssize_t
Cpu::LDH_A__a8_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LDH A,(a8)
 Opcode:	0xf0
 Width:		2
 Cycles:	12/12
 --*/
{
	throw std::runtime_error("Instruction LDH A,(a8) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::POP_AF(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	POP AF
 Opcode:	0xf1
 Width:		1
 Cycles:	12/12
 --*/
{
	throw std::runtime_error("Instruction POP AF not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_A__C_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD A,(C)
 Opcode:	0xf2
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction LD A,(C) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::DI(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	DI
 Opcode:	0xf3
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction DI not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::PUSH_AF(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	PUSH AF
 Opcode:	0xf5
 Width:		1
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction PUSH AF not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::OR_d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	OR d8
 Opcode:	0xf6
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction OR d8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RST_30H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RST 30H
 Opcode:	0xf7
 Width:		1
 Cycles:	16/16
 --*/
{
	PUSH_16(m_Registers.PC);
	m_Registers.PC = 0x30;
	
	/* Flags not affected */
	
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_HL_SPplsr8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD HL,SP+r8
 Opcode:	0xf8
 Width:		2
 Cycles:	12/12
 --*/
{
	throw std::runtime_error("Instruction LD HL,SP+r8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_SP_HL(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD SP,HL
 Opcode:	0xf9
 Width:		1
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction LD SP,HL not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_A__a16_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	LD A,(a16)
 Opcode:	0xfa
 Width:		3
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction LD A,(a16) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::EI(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	EI
 Opcode:	0xfb
 Width:		1
 Cycles:	4/4
 --*/
{
	throw std::runtime_error("Instruction EI not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::CP_d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	CP d8
 Opcode:	0xfe
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction CP d8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RST_38H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RST 38H
 Opcode:	0xff
 Width:		1
 Cycles:	16/16
 --*/
{
	PUSH_16(m_Registers.PC);
	m_Registers.PC = 0x38;
	
	/* Flags not affected */
	
	return Opcode.TickCount;
}

ssize_t
Cpu::RLC_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RLC B
 Opcode:	0xcb00
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RLC B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RLC_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RLC C
 Opcode:	0xcb01
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RLC C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RLC_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RLC D
 Opcode:	0xcb02
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RLC D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RLC_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RLC E
 Opcode:	0xcb03
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RLC E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RLC_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RLC H
 Opcode:	0xcb04
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RLC H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RLC_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RLC L
 Opcode:	0xcb05
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RLC L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RLC__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RLC (HL)
 Opcode:	0xcb06
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction RLC (HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RLC_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RLC A
 Opcode:	0xcb07
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RLC A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RRC_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RRC B
 Opcode:	0xcb08
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RRC B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RRC_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RRC C
 Opcode:	0xcb09
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RRC C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RRC_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RRC D
 Opcode:	0xcb0a
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RRC D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RRC_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RRC E
 Opcode:	0xcb0b
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RRC E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RRC_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RRC H
 Opcode:	0xcb0c
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RRC H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RRC_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RRC L
 Opcode:	0xcb0d
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RRC L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RRC__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RRC (HL)
 Opcode:	0xcb0e
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction RRC (HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RRC_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RRC A
 Opcode:	0xcb0f
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RRC A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RL_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RL B
 Opcode:	0xcb10
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RL B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RL_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RL C
 Opcode:	0xcb11
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RL C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RL_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RL D
 Opcode:	0xcb12
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RL D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RL_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RL E
 Opcode:	0xcb13
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RL E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RL_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RL H
 Opcode:	0xcb14
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RL H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RL_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RL L
 Opcode:	0xcb15
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RL L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RL__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RL (HL)
 Opcode:	0xcb16
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction RL (HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RL_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RL A
 Opcode:	0xcb17
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RL A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RR_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RR B
 Opcode:	0xcb18
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RR B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RR_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RR C
 Opcode:	0xcb19
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RR C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RR_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RR D
 Opcode:	0xcb1a
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RR D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RR_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RR E
 Opcode:	0xcb1b
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RR E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RR_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RR H
 Opcode:	0xcb1c
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RR H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RR_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RR L
 Opcode:	0xcb1d
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RR L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RR__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RR (HL)
 Opcode:	0xcb1e
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction RR (HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RR_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RR A
 Opcode:	0xcb1f
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RR A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SLA_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SLA B
 Opcode:	0xcb20
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SLA B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SLA_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SLA C
 Opcode:	0xcb21
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SLA C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SLA_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SLA D
 Opcode:	0xcb22
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SLA D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SLA_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SLA E
 Opcode:	0xcb23
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SLA E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SLA_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SLA H
 Opcode:	0xcb24
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SLA H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SLA_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SLA L
 Opcode:	0xcb25
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SLA L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SLA__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SLA (HL)
 Opcode:	0xcb26
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction SLA (HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SLA_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SLA A
 Opcode:	0xcb27
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SLA A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SRA_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SRA B
 Opcode:	0xcb28
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SRA B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SRA_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SRA C
 Opcode:	0xcb29
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SRA C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SRA_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SRA D
 Opcode:	0xcb2a
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SRA D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SRA_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SRA E
 Opcode:	0xcb2b
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SRA E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SRA_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SRA H
 Opcode:	0xcb2c
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SRA H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SRA_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SRA L
 Opcode:	0xcb2d
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SRA L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SRA__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SRA (HL)
 Opcode:	0xcb2e
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction SRA (HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SRA_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SRA A
 Opcode:	0xcb2f
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SRA A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SWAP_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SWAP B
 Opcode:	0xcb30
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SWAP B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SWAP_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SWAP C
 Opcode:	0xcb31
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SWAP C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SWAP_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SWAP D
 Opcode:	0xcb32
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SWAP D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SWAP_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SWAP E
 Opcode:	0xcb33
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SWAP E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SWAP_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SWAP H
 Opcode:	0xcb34
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SWAP H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SWAP_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SWAP L
 Opcode:	0xcb35
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SWAP L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SWAP__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SWAP (HL)
 Opcode:	0xcb36
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction SWAP (HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SWAP_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SWAP A
 Opcode:	0xcb37
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SWAP A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SRL_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SRL B
 Opcode:	0xcb38
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SRL B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SRL_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SRL C
 Opcode:	0xcb39
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SRL C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SRL_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SRL D
 Opcode:	0xcb3a
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SRL D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SRL_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SRL E
 Opcode:	0xcb3b
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SRL E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SRL_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SRL H
 Opcode:	0xcb3c
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SRL H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SRL_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SRL L
 Opcode:	0xcb3d
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SRL L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SRL__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SRL (HL)
 Opcode:	0xcb3e
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction SRL (HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SRL_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SRL A
 Opcode:	0xcb3f
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SRL A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_0_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 0,B
 Opcode:	0xcb40
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 0,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_0_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 0,C
 Opcode:	0xcb41
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 0,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_0_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 0,D
 Opcode:	0xcb42
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 0,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_0_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 0,E
 Opcode:	0xcb43
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 0,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_0_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 0,H
 Opcode:	0xcb44
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 0,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_0_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 0,L
 Opcode:	0xcb45
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 0,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_0__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 0,(HL)
 Opcode:	0xcb46
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction BIT 0,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_0_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 0,A
 Opcode:	0xcb47
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 0,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_1_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 1,B
 Opcode:	0xcb48
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 1,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_1_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 1,C
 Opcode:	0xcb49
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 1,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_1_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 1,D
 Opcode:	0xcb4a
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 1,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_1_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 1,E
 Opcode:	0xcb4b
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 1,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_1_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 1,H
 Opcode:	0xcb4c
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 1,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_1_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 1,L
 Opcode:	0xcb4d
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 1,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_1__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 1,(HL)
 Opcode:	0xcb4e
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction BIT 1,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_1_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 1,A
 Opcode:	0xcb4f
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 1,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_2_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 2,B
 Opcode:	0xcb50
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 2,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_2_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 2,C
 Opcode:	0xcb51
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 2,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_2_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 2,D
 Opcode:	0xcb52
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 2,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_2_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 2,E
 Opcode:	0xcb53
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 2,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_2_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 2,H
 Opcode:	0xcb54
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 2,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_2_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 2,L
 Opcode:	0xcb55
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 2,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_2__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 2,(HL)
 Opcode:	0xcb56
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction BIT 2,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_2_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 2,A
 Opcode:	0xcb57
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 2,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_3_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 3,B
 Opcode:	0xcb58
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 3,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_3_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 3,C
 Opcode:	0xcb59
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 3,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_3_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 3,D
 Opcode:	0xcb5a
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 3,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_3_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 3,E
 Opcode:	0xcb5b
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 3,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_3_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 3,H
 Opcode:	0xcb5c
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 3,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_3_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 3,L
 Opcode:	0xcb5d
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 3,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_3__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 3,(HL)
 Opcode:	0xcb5e
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction BIT 3,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_3_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 3,A
 Opcode:	0xcb5f
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 3,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_4_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 4,B
 Opcode:	0xcb60
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 4,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_4_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 4,C
 Opcode:	0xcb61
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 4,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_4_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 4,D
 Opcode:	0xcb62
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 4,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_4_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 4,E
 Opcode:	0xcb63
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 4,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_4_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 4,H
 Opcode:	0xcb64
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 4,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_4_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 4,L
 Opcode:	0xcb65
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 4,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_4__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 4,(HL)
 Opcode:	0xcb66
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction BIT 4,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_4_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 4,A
 Opcode:	0xcb67
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 4,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_5_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 5,B
 Opcode:	0xcb68
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 5,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_5_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 5,C
 Opcode:	0xcb69
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 5,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_5_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 5,D
 Opcode:	0xcb6a
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 5,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_5_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 5,E
 Opcode:	0xcb6b
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 5,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_5_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 5,H
 Opcode:	0xcb6c
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 5,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_5_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 5,L
 Opcode:	0xcb6d
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 5,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_5__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 5,(HL)
 Opcode:	0xcb6e
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction BIT 5,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_5_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 5,A
 Opcode:	0xcb6f
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 5,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_6_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 6,B
 Opcode:	0xcb70
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 6,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_6_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 6,C
 Opcode:	0xcb71
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 6,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_6_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 6,D
 Opcode:	0xcb72
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 6,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_6_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 6,E
 Opcode:	0xcb73
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 6,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_6_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 6,H
 Opcode:	0xcb74
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 6,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_6_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 6,L
 Opcode:	0xcb75
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 6,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_6__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 6,(HL)
 Opcode:	0xcb76
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction BIT 6,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_6_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 6,A
 Opcode:	0xcb77
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 6,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_7_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 7,B
 Opcode:	0xcb78
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 7,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_7_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 7,C
 Opcode:	0xcb79
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 7,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_7_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 7,D
 Opcode:	0xcb7a
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 7,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_7_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 7,E
 Opcode:	0xcb7b
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 7,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_7_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 7,H
 Opcode:	0xcb7c
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 7,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_7_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 7,L
 Opcode:	0xcb7d
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 7,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_7__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 7,(HL)
 Opcode:	0xcb7e
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction BIT 7,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::BIT_7_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	BIT 7,A
 Opcode:	0xcb7f
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction BIT 7,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_0_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 0,B
 Opcode:	0xcb80
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 0,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_0_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 0,C
 Opcode:	0xcb81
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 0,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_0_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 0,D
 Opcode:	0xcb82
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 0,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_0_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 0,E
 Opcode:	0xcb83
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 0,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_0_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 0,H
 Opcode:	0xcb84
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 0,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_0_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 0,L
 Opcode:	0xcb85
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 0,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_0__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 0,(HL)
 Opcode:	0xcb86
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction RES 0,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_0_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 0,A
 Opcode:	0xcb87
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 0,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_1_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 1,B
 Opcode:	0xcb88
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 1,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_1_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 1,C
 Opcode:	0xcb89
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 1,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_1_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 1,D
 Opcode:	0xcb8a
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 1,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_1_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 1,E
 Opcode:	0xcb8b
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 1,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_1_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 1,H
 Opcode:	0xcb8c
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 1,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_1_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 1,L
 Opcode:	0xcb8d
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 1,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_1__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 1,(HL)
 Opcode:	0xcb8e
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction RES 1,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_1_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 1,A
 Opcode:	0xcb8f
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 1,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_2_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 2,B
 Opcode:	0xcb90
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 2,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_2_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 2,C
 Opcode:	0xcb91
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 2,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_2_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 2,D
 Opcode:	0xcb92
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 2,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_2_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 2,E
 Opcode:	0xcb93
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 2,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_2_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 2,H
 Opcode:	0xcb94
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 2,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_2_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 2,L
 Opcode:	0xcb95
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 2,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_2__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 2,(HL)
 Opcode:	0xcb96
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction RES 2,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_2_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 2,A
 Opcode:	0xcb97
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 2,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_3_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 3,B
 Opcode:	0xcb98
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 3,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_3_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 3,C
 Opcode:	0xcb99
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 3,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_3_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 3,D
 Opcode:	0xcb9a
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 3,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_3_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 3,E
 Opcode:	0xcb9b
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 3,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_3_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 3,H
 Opcode:	0xcb9c
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 3,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_3_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 3,L
 Opcode:	0xcb9d
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 3,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_3__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 3,(HL)
 Opcode:	0xcb9e
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction RES 3,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_3_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 3,A
 Opcode:	0xcb9f
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 3,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_4_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 4,B
 Opcode:	0xcba0
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 4,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_4_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 4,C
 Opcode:	0xcba1
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 4,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_4_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 4,D
 Opcode:	0xcba2
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 4,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_4_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 4,E
 Opcode:	0xcba3
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 4,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_4_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 4,H
 Opcode:	0xcba4
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 4,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_4_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 4,L
 Opcode:	0xcba5
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 4,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_4__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 4,(HL)
 Opcode:	0xcba6
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction RES 4,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_4_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 4,A
 Opcode:	0xcba7
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 4,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_5_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 5,B
 Opcode:	0xcba8
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 5,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_5_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 5,C
 Opcode:	0xcba9
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 5,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_5_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 5,D
 Opcode:	0xcbaa
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 5,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_5_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 5,E
 Opcode:	0xcbab
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 5,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_5_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 5,H
 Opcode:	0xcbac
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 5,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_5_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 5,L
 Opcode:	0xcbad
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 5,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_5__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 5,(HL)
 Opcode:	0xcbae
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction RES 5,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_5_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 5,A
 Opcode:	0xcbaf
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 5,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_6_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 6,B
 Opcode:	0xcbb0
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 6,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_6_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 6,C
 Opcode:	0xcbb1
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 6,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_6_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 6,D
 Opcode:	0xcbb2
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 6,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_6_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 6,E
 Opcode:	0xcbb3
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 6,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_6_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 6,H
 Opcode:	0xcbb4
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 6,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_6_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 6,L
 Opcode:	0xcbb5
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 6,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_6__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 6,(HL)
 Opcode:	0xcbb6
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction RES 6,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_6_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 6,A
 Opcode:	0xcbb7
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 6,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_7_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 7,B
 Opcode:	0xcbb8
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 7,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_7_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 7,C
 Opcode:	0xcbb9
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 7,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_7_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 7,D
 Opcode:	0xcbba
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 7,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_7_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 7,E
 Opcode:	0xcbbb
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 7,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_7_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 7,H
 Opcode:	0xcbbc
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 7,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_7_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 7,L
 Opcode:	0xcbbd
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 7,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_7__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 7,(HL)
 Opcode:	0xcbbe
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction RES 7,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RES_7_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	RES 7,A
 Opcode:	0xcbbf
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction RES 7,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_0_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 0,B
 Opcode:	0xcbc0
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 0,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_0_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 0,C
 Opcode:	0xcbc1
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 0,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_0_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 0,D
 Opcode:	0xcbc2
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 0,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_0_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 0,E
 Opcode:	0xcbc3
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 0,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_0_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 0,H
 Opcode:	0xcbc4
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 0,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_0_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 0,L
 Opcode:	0xcbc5
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 0,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_0__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 0,(HL)
 Opcode:	0xcbc6
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction SET 0,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_0_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 0,A
 Opcode:	0xcbc7
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 0,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_1_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 1,B
 Opcode:	0xcbc8
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 1,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_1_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 1,C
 Opcode:	0xcbc9
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 1,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_1_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 1,D
 Opcode:	0xcbca
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 1,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_1_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 1,E
 Opcode:	0xcbcb
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 1,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_1_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 1,H
 Opcode:	0xcbcc
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 1,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_1_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 1,L
 Opcode:	0xcbcd
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 1,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_1__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 1,(HL)
 Opcode:	0xcbce
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction SET 1,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_1_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 1,A
 Opcode:	0xcbcf
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 1,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_2_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 2,B
 Opcode:	0xcbd0
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 2,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_2_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 2,C
 Opcode:	0xcbd1
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 2,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_2_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 2,D
 Opcode:	0xcbd2
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 2,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_2_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 2,E
 Opcode:	0xcbd3
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 2,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_2_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 2,H
 Opcode:	0xcbd4
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 2,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_2_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 2,L
 Opcode:	0xcbd5
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 2,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_2__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 2,(HL)
 Opcode:	0xcbd6
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction SET 2,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_2_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 2,A
 Opcode:	0xcbd7
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 2,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_3_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 3,B
 Opcode:	0xcbd8
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 3,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_3_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 3,C
 Opcode:	0xcbd9
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 3,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_3_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 3,D
 Opcode:	0xcbda
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 3,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_3_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 3,E
 Opcode:	0xcbdb
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 3,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_3_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 3,H
 Opcode:	0xcbdc
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 3,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_3_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 3,L
 Opcode:	0xcbdd
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 3,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_3__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 3,(HL)
 Opcode:	0xcbde
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction SET 3,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_3_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 3,A
 Opcode:	0xcbdf
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 3,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_4_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 4,B
 Opcode:	0xcbe0
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 4,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_4_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 4,C
 Opcode:	0xcbe1
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 4,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_4_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 4,D
 Opcode:	0xcbe2
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 4,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_4_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 4,E
 Opcode:	0xcbe3
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 4,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_4_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 4,H
 Opcode:	0xcbe4
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 4,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_4_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 4,L
 Opcode:	0xcbe5
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 4,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_4__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 4,(HL)
 Opcode:	0xcbe6
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction SET 4,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_4_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 4,A
 Opcode:	0xcbe7
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 4,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_5_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 5,B
 Opcode:	0xcbe8
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 5,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_5_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 5,C
 Opcode:	0xcbe9
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 5,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_5_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 5,D
 Opcode:	0xcbea
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 5,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_5_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 5,E
 Opcode:	0xcbeb
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 5,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_5_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 5,H
 Opcode:	0xcbec
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 5,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_5_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 5,L
 Opcode:	0xcbed
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 5,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_5__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 5,(HL)
 Opcode:	0xcbee
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction SET 5,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_5_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 5,A
 Opcode:	0xcbef
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 5,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_6_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 6,B
 Opcode:	0xcbf0
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 6,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_6_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 6,C
 Opcode:	0xcbf1
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 6,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_6_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 6,D
 Opcode:	0xcbf2
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 6,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_6_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 6,E
 Opcode:	0xcbf3
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 6,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_6_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 6,H
 Opcode:	0xcbf4
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 6,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_6_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 6,L
 Opcode:	0xcbf5
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 6,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_6__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 6,(HL)
 Opcode:	0xcbf6
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction SET 6,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_6_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 6,A
 Opcode:	0xcbf7
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 6,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_7_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 7,B
 Opcode:	0xcbf8
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 7,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_7_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 7,C
 Opcode:	0xcbf9
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 7,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_7_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 7,D
 Opcode:	0xcbfa
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 7,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_7_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 7,E
 Opcode:	0xcbfb
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 7,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_7_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 7,H
 Opcode:	0xcbfc
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 7,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_7_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 7,L
 Opcode:	0xcbfd
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 7,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_7__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 7,(HL)
 Opcode:	0xcbfe
 Width:		2
 Cycles:	16/16
 --*/
{
	throw std::runtime_error("Instruction SET 7,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SET_7_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TickCount
	)
/*++
 Operation:	SET 7,A
 Opcode:	0xcbff
 Width:		2
 Cycles:	8/8
 --*/
{
	throw std::runtime_error("Instruction SET 7,A not implemented");
	return Opcode.TickCount;
}

