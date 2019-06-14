//
//  InterruptableCore.cpp
//  emucore
//
//  Created by Gareth Evans on 13/06/2019.
//  Copyright © 2019 Gareth Evans. All rights reserved.
//

#include <iostream>
#include <map>
#include <algorithm>
#include <mutex>
#include <functional>
#include "InterruptableCore.hpp"

void
InterruptableCore::SetInterruptsEnabled(bool Enabled)
{
	std::lock_guard<std::mutex> guard(m_Mutex);
	m_InterruptsEnabled = Enabled;
}

bool
InterruptableCore::InterruptExists(int Id)
{
	std::lock_guard<std::mutex> guard(m_Mutex);
	return !( m_Interrupts.find(Id) == m_Interrupts.end() );
}

void
InterruptableCore::RegisterInterrupt(const int Id, const InterruptCallback Callback)
{
	/* Ignore if this ID is already registered */
	if( this->InterruptExists(Id) )
		return;
	/* Acquire lock add it to the vector */
	std::lock_guard<std::mutex> guard(m_Mutex);
	m_Interrupts[Id] = Callback;
}

int
InterruptableCore::RaiseInterrupt(int Id)
{
	if( !m_InterruptsEnabled ){
		m_IgnoredInterrupts++;
		return 0;
	}
	if( !this->InterruptExists(Id) ){
#ifdef DEBUG
		std::cerr << "[!] Unhandled interrupt raised! [" << Id << "]" << std::endl;
#endif
		throw std::runtime_error("Unhandled interrupt");
	}
	
	InterruptCallback callback;
	{
		std::lock_guard<std::mutex> guard(m_Mutex);
		callback = m_Interrupts[Id];
	}
	callback(Id);
	return 0;
}
