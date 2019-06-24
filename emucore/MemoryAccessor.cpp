//
//  MemoryAccessor.cpp
//  emucore
//
//  Created by Gareth Evans on 24/06/2019.
//  Copyright © 2019 Gareth Evans. All rights reserved.
//

#include <cstdint>
#include "MemoryAccessor.hpp"

MemoryAccessor&
MemoryAccessor::operator=(
						  const uint8_t Value
						  )
{
	/* If we have a callback registered, use it */
	if( m_WriteCallback )
	{
		m_WriteCallback(m_Address, Value);
	}
	else
	{
		*m_Value = Value;
	}
	return *this;
}

uint8_t
MemoryAccessor::Get(void)
{
	/* If we have a callback registered, use it */
	if( m_ReadCallback )
	{
		return m_ReadCallback(m_Address);
	}
	
	return *m_Value;
}
