#include "Cpu.hpp"

ssize_t
Cpu::NOP(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_BC_d16(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD BC,d16 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD__BC__A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD (BC),A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::INC_BC(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction INC BC not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::INC_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction INC B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::DEC_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
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
	ssize_t& TicksRequired
	)
{
	m_Registers.B = IMM8();

	/* Flags not affected */

	return Opcode.TickCount;
}

ssize_t
Cpu::RLCA(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction RLCA  not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD__a16__SP(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD (a16),SP not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADD_HL_BC(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction ADD HL,BC not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_A__BC_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD A,(BC) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::DEC_BC(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction DEC BC not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::INC_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction INC C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::DEC_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction DEC C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_C_d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	m_Registers.C = IMM8();

	/* Flags not affected */

	return Opcode.TickCount;
}

ssize_t
Cpu::RRCA(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction RRCA  not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::STOP_0(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction STOP 0 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_DE_d16(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD DE,d16 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD__DE__A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD (DE),A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::INC_DE(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction INC DE not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::INC_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction INC D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::DEC_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction DEC D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_D_d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD D,d8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RLA(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction RLA  not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::JR_r8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction JR r8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADD_HL_DE(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction ADD HL,DE not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_A__DE_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD A,(DE) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::DEC_DE(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction DEC DE not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::INC_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction INC E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::DEC_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction DEC E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_E_d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD E,d8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RRA(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction RRA  not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::JR_NZ_r8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction JR NZ,r8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_HL_d16(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	m_Registers.HL = m_Memory.Get16(m_Registers.PC+1);

	/* No flags affected */

	return Opcode.TickCount;
}

ssize_t
Cpu::LD__HLpls__A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD (HL+),A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::INC_HL(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction INC HL not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::INC_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction INC H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::DEC_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction DEC H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_H_d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD H,d8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::DAA(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction DAA  not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::JR_Z_r8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction JR Z,r8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADD_HL_HL(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction ADD HL,HL not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_A__HLpls_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD A,(HL+) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::DEC_HL(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction DEC HL not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::INC_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction INC L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::DEC_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction DEC L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_L_d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD L,d8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::CPL(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction CPL  not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::JR_NC_r8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction JR NC,r8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_SP_d16(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD SP,d16 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD__HLmin__A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
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
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction INC SP not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::INC__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction INC (HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::DEC__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction DEC (HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD__HL__d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD (HL),d8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SCF(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction SCF  not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::JR_C_r8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction JR C,r8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADD_HL_SP(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction ADD HL,SP not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_A__HLmin_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD A,(HL-) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::DEC_SP(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction DEC SP not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::INC_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction INC A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::DEC_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction DEC A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_A_d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD A,d8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::CCF(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction CCF  not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_B_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD B,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_B_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD B,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_B_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD B,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_B_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD B,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_B_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD B,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_B_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD B,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_B__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD B,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_B_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD B,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_C_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD C,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_C_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD C,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_C_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD C,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_C_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD C,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_C_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD C,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_C_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD C,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_C__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD C,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_C_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD C,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_D_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD D,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_D_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD D,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_D_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD D,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_D_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD D,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_D_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD D,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_D_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD D,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_D__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD D,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_D_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD D,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_E_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD E,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_E_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD E,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_E_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD E,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_E_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD E,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_E_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD E,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_E_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD E,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_E__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD E,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_E_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD E,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_H_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD H,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_H_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD H,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_H_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD H,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_H_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD H,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_H_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD H,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_H_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD H,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_H__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD H,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_H_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD H,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_L_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD L,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_L_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD L,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_L_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD L,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_L_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD L,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_L_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD L,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_L_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD L,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_L__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD L,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_L_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD L,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD__HL__B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD (HL),B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD__HL__C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD (HL),C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD__HL__D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD (HL),D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD__HL__E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD (HL),E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD__HL__H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD (HL),H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD__HL__L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD (HL),L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::HALT(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction HALT  not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD__HL__A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD (HL),A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_A_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD A,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_A_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD A,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_A_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD A,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_A_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD A,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_A_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD A,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_A_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD A,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_A__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD A,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_A_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD A,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADD_A_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction ADD A,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADD_A_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction ADD A,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADD_A_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction ADD A,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADD_A_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction ADD A,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADD_A_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction ADD A,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADD_A_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction ADD A,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADD_A__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction ADD A,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADD_A_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction ADD A,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADC_A_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction ADC A,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADC_A_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction ADC A,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADC_A_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction ADC A,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADC_A_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction ADC A,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADC_A_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction ADC A,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADC_A_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction ADC A,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADC_A__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction ADC A,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADC_A_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction ADC A,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SUB_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction SUB B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SUB_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction SUB C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SUB_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction SUB D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SUB_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction SUB E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SUB_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction SUB H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SUB_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction SUB L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SUB__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction SUB (HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SUB_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction SUB A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SBC_A_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction SBC A,B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SBC_A_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction SBC A,C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SBC_A_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction SBC A,D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SBC_A_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction SBC A,E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SBC_A_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction SBC A,H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SBC_A_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction SBC A,L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SBC_A__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction SBC A,(HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SBC_A_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction SBC A,A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::AND_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction AND B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::AND_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction AND C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::AND_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction AND D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::AND_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction AND E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::AND_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction AND H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::AND_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction AND L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::AND__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction AND (HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::AND_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction AND A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::XOR_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction XOR B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::XOR_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction XOR C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::XOR_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction XOR D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::XOR_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction XOR E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::XOR_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction XOR H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::XOR_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction XOR L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::XOR__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction XOR (HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::XOR_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
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
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction OR B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::OR_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction OR C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::OR_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction OR D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::OR_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction OR E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::OR_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction OR H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::OR_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction OR L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::OR__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction OR (HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::OR_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction OR A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::CP_B(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction CP B not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::CP_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction CP C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::CP_D(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction CP D not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::CP_E(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction CP E not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::CP_H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction CP H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::CP_L(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction CP L not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::CP__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction CP (HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::CP_A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction CP A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RET_NZ(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction RET NZ not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::POP_BC(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction POP BC not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::JP_NZ_a16(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction JP NZ,a16 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::JP_a16(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	uint16_t address = m_Memory.Get16(m_Registers.PC+1);
	m_Registers.PC = address;
	return Opcode.TickCount;
}

ssize_t
Cpu::CALL_NZ_a16(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction CALL NZ,a16 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::PUSH_BC(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction PUSH BC not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADD_A_d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction ADD A,d8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RST_00H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction RST 00H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RET_Z(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction RET Z not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RET(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction RET  not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::JP_Z_a16(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction JP Z,a16 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::PREFIX_CB(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction PREFIX CB not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::CALL_Z_a16(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction CALL Z,a16 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::CALL_a16(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction CALL a16 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADC_A_d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction ADC A,d8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RST_08H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction RST 08H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RET_NC(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction RET NC not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::POP_DE(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction POP DE not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::JP_NC_a16(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction JP NC,a16 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::CALL_NC_a16(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction CALL NC,a16 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::PUSH_DE(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction PUSH DE not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SUB_d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction SUB d8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RST_10H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction RST 10H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RET_C(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction RET C not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RETI(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction RETI  not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::JP_C_a16(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction JP C,a16 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::CALL_C_a16(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction CALL C,a16 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::SBC_A_d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction SBC A,d8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RST_18H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction RST 18H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LDH__a8__A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LDH (a8),A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::POP_HL(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction POP HL not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD__C__A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD (C),A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::PUSH_HL(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction PUSH HL not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::AND_d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction AND d8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RST_20H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction RST 20H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::ADD_SP_r8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction ADD SP,r8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::JP__HL_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction JP (HL) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD__a16__A(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD (a16),A not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::XOR_d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction XOR d8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RST_28H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction RST 28H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LDH_A__a8_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LDH A,(a8) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::POP_AF(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction POP AF not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_A__C_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD A,(C) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::DI(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction DI  not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::PUSH_AF(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction PUSH AF not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::OR_d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction OR d8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RST_30H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction RST 30H not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_HL_SPplsr8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD HL,SP+r8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_SP_HL(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD SP,HL not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::LD_A__a16_(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction LD A,(a16) not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::EI(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction EI  not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::CP_d8(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction CP d8 not implemented");
	return Opcode.TickCount;
}

ssize_t
Cpu::RST_38H(
	const struct Opcode& Opcode,
	ssize_t Tick,
	ssize_t& TicksRequired
	)
{
	throw std::runtime_error("Instruction RST 38H not implemented");
	return Opcode.TickCount;
}

