//
//  Gpu.hpp
//  emucore
//
//  Created by Gareth Evans on 24/06/2019.
//  Copyright © 2019 Gareth Evans. All rights reserved.
//

#ifndef Gpu_hpp
#define Gpu_hpp

#include "Cpu.hpp"
#include "Memory.hpp"

class Gpu
{
public:
	Gpu(Cpu* Cpu, Memory* Memory)
		: m_Cpu(Cpu), m_Memory(Memory){};
	void Tick(void);
private:
	Cpu*	m_Cpu;
	Memory*	m_Memory;
};

#endif /* Gpu_hpp */
