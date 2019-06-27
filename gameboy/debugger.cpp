//
//  debugger.cpp
//  gameboydebuggger
//
//  Created by Gareth Evans on 27/06/2019.
//  Copyright © 2019 Gareth Evans. All rights reserved.
//

#include <iostream>
#include <memory>
#include <chrono>
#include <thread>

#include "Cpu.hpp"

int main(int argc, const char * argv[]) {
	// insert code here...
	
	std::shared_ptr<Cpu> cpu = std::make_shared<Cpu>();
	cpu->SetFreqMhz(4.194304);
	cpu->LoadRom(argv[1]);
	
	std::string lastCommand;
	register_t lastMem = (register_t)-1;
	
	for (std::string line; std::getline(std::cin, line);) {
		if( line == "" )
		{
			/* Empty line re-runs last command */
			line = lastCommand;
		}
		std::string command = line.substr(0, line.find(" "));

		if( command == "r" || command == "run" )
		{
			lastCommand = command;
			std::cerr << "Running emulator" << std::endl;
			cpu->Run();
			std::cerr << "Trapped to debugger" << std::endl;
		}
		else if( command == "b" || command == "bp" || command == "break" || command == "breakpoint" )
		{
			lastCommand = command;
			std::string address = line.substr(line.find(" ")+1);
			register_t iAddress = (register_t) strtoull(address.c_str(), 0, 16);
			std::cerr << "Adding breakpoint at 0x" << std::hex << iAddress << std::dec << std::endl;
			cpu->AddBreakPoint(iAddress);
		}
		else if( command == "reg" || command == "info reg" )
		{
			lastCommand = command;
			std::cerr << "Register state:" << std::endl;
			for ( const auto &reg : cpu->GetRegisters() ) {
				std::cout << "\t" << reg.first << ": " << std::hex << reg.second << std::dec << std::endl;
			}
		}
		else if( command == "mem" || command == "x" )
		{
			lastCommand = command;
			register_t iAddress;
			if( line.find(' ') == std::string::npos ){
				// No address
				if( lastMem == (register_t)-1 )
					iAddress = 0;
				else
					iAddress = lastMem + (16*4);
			}else{
				std::string address = line.substr(line.find(" ")+1);
				iAddress = (register_t) strtoull(address.c_str(), 0, 16);
			}
			
			lastMem = iAddress;
			
			Memory& memory = cpu->GetMemory();
			for( size_t i=0; i<4; i++ )
			{
				char fmtAddress[10] = {0};
				sprintf(fmtAddress, "%04x", (unsigned int)(iAddress + (i*16)));
				std::cerr << fmtAddress << "\t";
				for(size_t j=0; j<16; j++ )
				{
					fprintf(stderr, "%02x ", (int)memory[iAddress + (i*16) + j].Get());
				}
				std::cerr << std::dec << std::endl;
			}
		}
	}
	
	
//	cpu->Run();
	
	return 0;
}
