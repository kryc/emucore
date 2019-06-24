//
//  Memory.cpp
//  emucore
//
//  Created by Gareth Evans on 14/06/2019.
//  Copyright © 2019 Gareth Evans. All rights reserved.
//


#include <iostream>
#include <ctime>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include "Memory.hpp"

Memory::Memory(void)
{
	/* Initialize the memory */
	Initialize();
	
	/* Seed the PRNG for IO Port 0xff04 */
	std::srand( (unsigned int)std::time(nullptr) );
}

void
Memory::Initialize(void)
{
	m_Memory[0xff05] = 0x00;
	m_Memory[0xff06] = 0x00;
	m_Memory[0xff07] = 0x00;
	m_Memory[0xff10] = 0x80;
	m_Memory[0xff11] = 0xbf;
	m_Memory[0xff12] = 0xf3;
	m_Memory[0xff14] = 0xbf;
	m_Memory[0xff1a] = 0x7f;
	m_Memory[0xff1b] = 0xff;
	m_Memory[0xff1c] = 0x9f;
	m_Memory[0xff1e] = 0xbf;
	m_Memory[0xff20] = 0xff;
	m_Memory[0xff21] = 0x00;
	m_Memory[0xff22] = 0x00;
	m_Memory[0xff23] = 0xbf;
	m_Memory[0xff24] = 0x77;
	m_Memory[0xff25] = 0xf3;
	m_Memory[0xff26] = 0xf1; //SGB = 0xf0
	m_Memory[0xff40] = 0x91;
	m_Memory[0xff42] = 0x00;
	m_Memory[0xff43] = 0x00;
	m_Memory[0xff45] = 0x00;
	m_Memory[0xff47] = 0xfc;
	m_Memory[0xff48] = 0xff;
	m_Memory[0xff49] = 0xff;
	m_Memory[0xff4a] = 0x00;
	m_Memory[0xff4b] = 0x00;
	m_Memory[0xffff] = 0x00;
	
}

void
Memory::LoadRom(
	std::string RomFile
	)
{
	std::cerr << RomFile << std::endl;
	m_Rom = fopen(RomFile.c_str(), "rb");
	if( m_Rom == NULL )
	{
		throw std::runtime_error("Unable to open ROM file");
	}
	
	std::fseek(m_Rom, 0, SEEK_END);
	m_RomSize = std::ftell(m_Rom);
	std::fseek(m_Rom, 0, SEEK_SET);
	
	m_MmappedRom = (uint8_t*) mmap(nullptr, m_RomSize, PROT_READ | PROT_WRITE, MAP_PRIVATE, fileno(m_Rom), 0);
	if( m_MmappedRom == (uint8_t*)-1 )
	{
		throw std::runtime_error("Unable to mmap Rom file");
	}
}

std::string
Memory::GetRomName()
{
	if( m_MmappedRom == nullptr )
		throw std::runtime_error("Rom not loaded");
	char *namePointer = (char*)&m_MmappedRom[0x134];
	return std::string(namePointer);
}

uint8_t
Memory::GetRomType()
{
	if( m_MmappedRom == nullptr )
		throw std::runtime_error("Rom not loaded");
	return m_MmappedRom[0x147];
}

uint16_t
Memory::Get16(
	const size_t Address
	)
{
	uint16_t ret;
	ret = operator[](Address+1).Get();
	ret <<= 8;
	ret |= operator[](Address).Get();
	return ret;
}

uint8_t
Memory::OnIoPortRead(
	const size_t Address
	)
{
	if( Address == 0xff04 ){
		return (uint8_t)std::rand();
	}
	
	/* Fallback to returning the value at the address */
#ifdef DEBUG
	std::cerr << "Unhandled IoPortRead: " << std::hex << Address << std::endl;
#endif
	return m_Memory[Address];
}

void
Memory::OnIoPortWrite(
	const size_t Address,
	const uint8_t Value
	)
{
	/* Fallback to writing to the value at the address */
#ifdef DEBUG
	std::cerr << "Unhandled IoPortWrite: " << std::hex << Address << " = " << (int)Value << std::endl;
#endif
	m_Memory[Address] = Value;
}

void
Memory::OnReadOnlyWrite(
	const size_t Address,
	const uint8_t Value
	)
{
	std::runtime_error("Caught write to read only memory");
}

MemoryAccessor
Memory::operator[] (
	const size_t Address
	)
{
	/* Read from ROM range */
	if( Address >= 0 && Address <= 0x4000 )
	{
		// We pass a handler to the write accessor to catch writes to ROM range
		return MemoryAccessor(Address,
							  (uint8_t * const)&m_MmappedRom[Address],
							  nullptr,
							  (std::bind(&Memory::OnReadOnlyWrite, this, std::placeholders::_1, std::placeholders::_2)));
	}
	
	/* Emulate the echo region */
	if( Address >= 0xe000 && Address < 0xfe00 )
	{
		return MemoryAccessor(Address-0x2000, (uint8_t * const)&m_Memory[Address-0x2000]);
	}
	
	/* IO Port Range */
	if( Address >= 0xff00 && Address < 0xff4c )
	{
		return MemoryAccessor(Address,
							  (uint8_t * const)&m_Memory[Address],
							  (std::bind(&Memory::OnIoPortRead, this, std::placeholders::_1)),
							  (std::bind(&Memory::OnIoPortWrite, this, std::placeholders::_1, std::placeholders::_2))
							  );
	}
	
	/* Access base memory */
	return MemoryAccessor(Address, (uint8_t * const)&m_Memory[Address]);
}

Memory::~Memory()
{
	munmap(m_MmappedRom, m_RomSize);
}
