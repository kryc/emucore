//
//  Gpu.hpp
//  emucore
//
//  Created by Gareth Evans on 24/06/2019.
//  Copyright © 2019 Gareth Evans. All rights reserved.
//

#ifndef Gpu_hpp
#define Gpu_hpp

class Cpu;

#include <memory>
#include "Memory.hpp"

class Gpu
{
public:
	Gpu(std::shared_ptr<Cpu> Cpu, Memory& Memory)
		: m_Cpu(Cpu), m_Memory(Memory){};
	void Tick(void);
private:
	std::shared_ptr<Cpu>	m_Cpu;
	Memory&					m_Memory;
	size_t					m_TicksInCurrentCycle = 0;
	size_t					m_TotalTicks = 0;
};

#endif /* Gpu_hpp */
