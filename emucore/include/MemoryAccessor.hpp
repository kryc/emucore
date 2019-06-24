//
//  MemoryAccessor.hpp
//  emucore
//
//  Created by Gareth Evans on 24/06/2019.
//  Copyright © 2019 Gareth Evans. All rights reserved.
//

#ifndef MemoryAccessor_hpp
#define MemoryAccessor_hpp

#include <functional>

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
	MemoryAccessor operator++(int);
	uint8_t Get(void);
protected:
	uint8_t * const 		m_Value;
	const size_t			m_Address;
	OnMemoryReadCallback 	m_ReadCallback;
	OnMemoryWriteCallback 	m_WriteCallback;
};

#endif /* MemoryAccessor_hpp */
