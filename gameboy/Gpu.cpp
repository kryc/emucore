//
//  Gpu.cpp
//  emucore
//
//  Created by Gareth Evans on 24/06/2019.
//  Copyright © 2019 Gareth Evans. All rights reserved.
//

#include "Gpu.hpp"
#include "Common.hpp"
#include "Cpu.hpp"

void
Gpu::Tick(void)
/*++
 Code shamelessly copied and modified from @teesee23
 --*/
{
	/* Use of GetNoHook is safe here to bypass IoPort handlers
		designed to catch CPU accesses */
	uint8_t stat 	= m_Memory[0xff41].GetNoHook();
	uint8_t ly 		= m_Memory[0xff44].GetNoHook();
	uint8_t mode 	= stat & 3;

	switch (mode)
	{
		case 0x0: /* H-Blank */
		{
			if(m_TicksInCurrentCycle >= 204)
			{
				ly++;
				m_TicksInCurrentCycle = 0;
				
				if(ly == 143) /* transition to vblank if drawn a whole screen */
				{
					//log_debug("------TRANSITION TO VBLANK FROM HBLANK-----");
					mode = 1;
					//update texture maps
					m_Cpu->RaiseInterrupt(INTERRUPT_VBLANK);
				}
				else    /* Otherwise go to OAM mode */
				{
					//log_debug("------TRANSITION TO OAM ACCESS FROM HBLANK-----");
					mode = 2;
				}
			}
			break;
		}
		case 0x1: /* V-Blank */
		{
			if(m_TicksInCurrentCycle >=456)
			{
				m_TicksInCurrentCycle = 0; /* reset the clock */
				ly++;
				
				if(ly > 153)
				{
					//log_debug("------TRANSITION TO OAM ACCESS FROM VBLANK-----");
					mode = 2;
					ly = 0;
				}
			}
			break;
		}
		case 0x2: /* Accessing OAM (NO CPU allowed) */
		{
			if(m_TicksInCurrentCycle >= 80)
			{
				//log_debug("------TRANSITION TO VRAM ACCESS FROM OAM-----");
				m_TicksInCurrentCycle = 0;
				mode = 3;
			}
			break;
		}
		case 0x3: /* Accessing VRAM (No CPU allowed) */
		{
			if(m_TicksInCurrentCycle >= 172) /* transition to hblank */
			{
				//log_debug("------TRANSITION TO HBLANK from VRAM-----");
				m_TicksInCurrentCycle = 0;
				mode = 0;
				//render line
			}
			break;
		}
		default:
			throw std::runtime_error("GPU: Unknown STAT mode");
		
	}

	m_TicksInCurrentCycle++;
	m_TotalTicks++;
	 
	stat &=0xFC; /* blank out old mode */
	stat |= mode;
	/* Use of SetNoHook is safe here to bypass IoPort handlers
		designed to catch CPU accesses */
	m_Memory[0xff41].SetNoHook(stat);
	m_Memory[0xff44].SetNoHook(ly);
}