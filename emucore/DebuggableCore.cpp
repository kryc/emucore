//
//  DebuggableCore.cpp
//  emucore
//
//  Created by Gareth Evans on 27/06/2019.
//  Copyright © 2019 Gareth Evans. All rights reserved.
//

#include "DebuggableCore.hpp"

bool
DebuggableCore::ShouldBreak(const register_t Address)
{
	/* A single break has been requested */
	if( m_Break )
	{
		m_Break = false;
		m_Broken = true;
		m_LastBroken = Address;
		return true;
	}
	
	/* We are returning from a previous breakpoint. Reset state and continue */
	if( m_Broken && Address == m_LastBroken )
	{
		m_Broken = false;
		return false;
	}
	
	/* Is this address in our list of breakpoints? */
	if( std::find(m_Breakpoints.begin(), m_Breakpoints.end(), Address) != m_Breakpoints.end() )
	{
		m_Broken = true;
		m_LastBroken = Address;
		return true;
	}
	
	return false;
}
