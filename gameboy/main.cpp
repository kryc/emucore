//
//  main.cpp
//  emucore
//
//  Created by Gareth Evans on 11/06/2019.
//  Copyright © 2019 Gareth Evans. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <thread>

#include "Cpu.hpp"

int main(int argc, const char * argv[]) {
	// insert code here...
	
	Cpu cpu;
#ifdef DEBUG
	cpu.SetFreq(32.0);
#else
	cpu.SetFreqMhz(4.194304);
#endif
	cpu.LoadRom(argv[1]);
	cpu.Run();
	
	
	Memory& m = cpu.GetMemory();
	
	std::cerr << (int)m.Get16(0xff47) << std::endl;
	
	m[0xe001] = 0xff;
	m[0xe002] = 0xfe;
	
	std::cerr << (int)m[0xc001].Get() << std::endl;
	std::cerr << (int)m[0xc002].Get() << std::endl;
	std::cerr << (int)m[0xff04].Get() << std::endl;
	std::cerr << (int)m[0xff04].Get() << std::endl;
	
	m[0xff47] = 1;
	
//	std::cerr << m[0xff04] << std::endl;

	std::cout << "Hello " << m.GetRomName() << std::endl;
	return 0;
}
