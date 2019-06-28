//
//  main.cpp
//  emucore
//
//  Created by Gareth Evans on 11/06/2019.
//  Copyright © 2019 Gareth Evans. All rights reserved.
//

#include <iostream>
#include <memory>
#include <chrono>
#include <thread>

#include "Cpu.hpp"

int main(int argc, const char * argv[]) {
	// insert code here...
	
	if( argc < 2 )
	{
		std::cerr << "Usage: " << argv[0] << " <romfile>" << std::endl;
		return 0;
	}

	std::shared_ptr<Cpu> cpu = std::make_shared<Cpu>();
	cpu->SetFreqMhz(4.194304);
	cpu->LoadRom(argv[1]);
	cpu->Run();

	return 0;
}
