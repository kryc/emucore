//
//  Memory.hpp
//  emucore
//
//  Created by Gareth Evans on 14/06/2019.
//  Copyright © 2019 Gareth Evans. All rights reserved.
//

/*
 Interrupt Enable Register
 --------------------------- FFFF
 Internal RAM
 --------------------------- FF80
 Empty but unusable for I/O
 --------------------------- FF4C
 I/O ports
 --------------------------- FF00
 Empty but unusable for I/O
 --------------------------- FEA0
 Sprite Attrib Memory (OAM)
 --------------------------- FE00
 Echo of 8kB Internal RAM
 --------------------------- E000
 8kB Internal RAM
 --------------------------- C000
 8kB switchable RAM bank
 --------------------------- A000
 8kB Video RAM
 --------------------------- 8000 --
 16kB switchable ROM bank         |
 --------------------------- 4000  |= 32kB Cartrigbe
 16kB ROM bank #0                 |
 --------------------------- 0000 --
 */

#ifndef Memory_hpp
#define Memory_hpp

#include <string>
#include <array>
#include <cstdint>
#include <functional>
#include <stdlib.h>

#define MAX_ROM_SIZE	0x8000	// 32k
#define RAM_SIZE		0x10000 // 64k

using OnMemoryReadCallback = std::function<int(size_t)>;
using OnMemoryWriteCallback = std::function<void(size_t, uint8_t)>;

class MemoryAccessor
{
public:
	MemoryAccessor(const size_t Address, uint8_t * const Value) :
		m_Value(Value), m_Address(Address), m_ReadCallback(nullptr){};
	MemoryAccessor(const size_t Address, uint8_t * const Value, OnMemoryReadCallback ReadCallback, OnMemoryWriteCallback WriteCallback) :
	m_Value(Value), m_Address(Address), m_ReadCallback(ReadCallback), m_WriteCallback(WriteCallback){};
	MemoryAccessor& operator=(const uint8_t Value);
	uint8_t Get(void);
protected:
	uint8_t * const 		m_Value;
	const size_t			m_Address;
	OnMemoryReadCallback 	m_ReadCallback;
	OnMemoryWriteCallback 	m_WriteCallback;
};

class Memory
{
public:
	Memory(void);
	~Memory(void);
	void 			Initialize(void);
	void 			LoadRom(std::string RomFile);
	std::string 	GetRomName(void);
	uint8_t 		GetRomType(void);
//	uint8_t&		Get(const size_t Address);
	uint16_t		Get16(const size_t Address);
	MemoryAccessor  operator[] (const size_t Address);
	uint8_t 		OnIoPortRead(const size_t Address);
	void	 		OnIoPortWrite(const size_t Address, const uint8_t Value);
private:
	std::FILE*						m_Rom;
	size_t							m_RomSize;
	uint8_t*						m_MmappedRom = nullptr;
	std::array<uint8_t, RAM_SIZE>	m_Memory{};
};

#endif /* Memory_hpp */
