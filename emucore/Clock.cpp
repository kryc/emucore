//
//  Clock.cpp
//  emucore
//
//  Created by Gareth Evans on 11/06/2019.
//  Copyright © 2019 Gareth Evans. All rights reserved.
//
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ratio>
#include <cmath>
#include <unistd.h>

#include "Clock.hpp"

void
Clock::SetFreq(double Hz)
{
	m_Freq = Hz;
	m_TickTime = 1/Hz;
	m_TickTimeUs = std::round(m_TickTime*1000*1000);
#ifdef DEBUG
	std::cerr << "Setting Frequency: " << m_Freq << " Hz" << std::endl;
	std::cerr << "New Tick Time: " << m_TickTime << " s" << std::endl;
	std::cerr << "New Tick Time: " << m_TickTimeUs << " us" << std::endl;
#endif
}

void
Clock::SetFreqMhz(double MHz)
{
	SetFreq(MHz * 1000);
}

 void
 Clock::Tick(void)
 {
#ifdef DEBUG
 	unsigned int randomSleep = std::rand() % (int)std::round(m_TickTimeUs/2);
 	if( usleep(randomSleep) == -1 )
 		std::cerr << "Err: " << errno << std::endl;
#endif
 }

void
Clock::Run(void)
{
	for(;;){
		auto start = std::chrono::steady_clock::now();
		this->Tick();
		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double> diff = end-start;
		
		double timeInTick = std::chrono::duration_cast<std::chrono::microseconds>(diff).count();
		double sleepTime = m_TickTimeUs - timeInTick;
		
		if( sleepTime < -5.0 )
		{
			/* We missed our tick! */
			m_MissedTicks++;
#ifdef DEBUG
			std::cerr << "Tick missed! [" << timeInTick << "/" << m_TickTimeUs << "][" << sleepTime << "]" << std::endl;
#endif
			continue;
		}
		else
		{
			if( sleepTime > 1.0 )
			{
				/* We need to sleep! */
				int usecs = (int)std::round(sleepTime);
				usleep(usecs);
			}
			/* No sleeping to do */
			continue;
		}
		
	}
}
