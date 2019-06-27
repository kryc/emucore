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
#include <stdio.h>
#include "Clock.hpp"

void
Clock::SetFreq(double Hz)
{
	// double min_freq = (double)std::chrono::high_resolution_clock::period::num /   
	// 		std::chrono::high_resolution_clock::period::den;

	m_Freq = Hz;
	m_TickTime = 1/Hz;
	m_TickTimeUs = std::round(m_TickTime*1000*1000);

	// printf("%.10f %.10f\n", m_TickTime, min_freq);
	// exit(0);
	// if( m_TickTime < min_freq )
	// {
	// 	throw std::runtime_error("Cannot support frequency");
	// }
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
Clock::Run(void)
{
	int sleepFudge = 0;
	
	for(;;){
		auto start = std::chrono::steady_clock::now();
		if( !Tick() )
		{
			/* If tick returns false then the callee is requesting to stop */
			break;
		}
		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double> diff = end-start;
		
		double timeInTick = std::chrono::duration_cast<std::chrono::microseconds>(diff).count();
		int sleepTime = (int)std::round(m_TickTimeUs - timeInTick);
		
		if( sleepTime < -5 )
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

			if( sleepTime - sleepFudge > 1 )
			{
				/* We need to sleep! */
				usleep(sleepTime - sleepFudge);
			}

			auto end = std::chrono::steady_clock::now();
			std::chrono::duration<double> diff = end-start;
			float totalTimeInCycleWithSleep = std::chrono::duration_cast<std::chrono::microseconds>(diff).count();
			int marginOfTickError = (int)std::round(m_TickTimeUs - totalTimeInCycleWithSleep);

			sleepFudge -= marginOfTickError;
			
			/* No sleeping to do */
			continue;
		}
		
	}
}
