//
//  debugger.cpp
//  gameboydebuggger
//
//  Created by Gareth Evans on 27/06/2019.
//  Copyright © 2019 Gareth Evans. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <iterator>
#include <memory>
#include <chrono>
#include <thread>

#include "Cpu.hpp"

std::vector<std::string>
SplitCommand(std::string Line)
{
	std::istringstream iss(Line);
	std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
										std::istream_iterator<std::string>());
	return results;
}

register_t
ReadAddress(std::string Address)
{
	std::string hexBytes = Address.substr(0,2) == "0x" ? Address.substr(2) : Address;
	register_t address = (register_t) strtoull(hexBytes.c_str(), 0, 16);
	return address;
}

std::string lastCommand;
register_t lastMem = (register_t)-1;
register_t lastDis = (register_t)-1;

void
RunCommand(
	std::shared_ptr<Cpu> cpu,
	std::vector<std::string> commandLine
	)
{
	std::string command;
	if( commandLine.size() == 0 && lastCommand != "" )
	{
		/* Empty line re-runs last command */
		command = lastCommand;
	}
	else if( commandLine.size() == 0 && lastCommand == "" )
	{
		std::cerr << "Please enter a command or \"help\" for help" << std::endl;
		return;
	}
	else
	{
		command = commandLine[0];
	}

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
		register_t address = commandLine.size() > 1 ? ReadAddress(commandLine[1]) : 0;
		std::cerr << "Adding breakpoint at 0x" << std::hex << address << std::dec << std::endl;
		cpu->AddBreakPoint(address);
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
		register_t address;
		if( commandLine.size() < 2 ){
			// No address
			if( lastMem == (register_t)-1 )
				address = 0;
			else
				address = lastMem + (16*4);
		}else{
			address = ReadAddress(commandLine[1]);
		}
		
		lastMem = address;
		
		for( size_t i=0; i<4; i++ )
		{
			char fmtAddress[10] = {0};
			sprintf(fmtAddress, "%04x", (unsigned int)(cpu->ReadMemory(address + (i*16))));
			std::cerr << fmtAddress << "\t";
			for(size_t j=0; j<16; j++ )
			{
				fprintf(stderr, "%02x ", (int)cpu->ReadMemory(address + (i*16) + j));
			}
			std::cerr << std::dec << std::endl;
		}
	}		
	else if( command == "d" || command.substr(0,3) == "dis" || command == "u" )
	{
		lastCommand = command;
		register_t address;
		size_t readLen = 16;

		if( commandLine.size() < 2 ){
			// No address
			if( lastDis == (register_t)-1 )
				address = cpu->GetRegisters()["pc"];
			else
				address = lastDis + (16*4);
		}else{
			address = ReadAddress(commandLine[1]);
		}

		if( commandLine.size() > 2 )
		{
			readLen = ReadAddress(commandLine[2]);
		}

		lastDis = address;

		for( size_t i=0; i<readLen; i++ )
		{
			size_t instructionWidth;
			char fmtAddress[10] = {0};
			sprintf(fmtAddress, "%04x\t", (unsigned int)(address));
			try{
				std::cerr << fmtAddress << cpu->FormatDebugString(address, &instructionWidth) << std::endl;
			}
			catch( ... )
			{
				std::cerr << fmtAddress << std::endl;
			}
			address += instructionWidth;
		}

	}
}

int main(int argc, const char * argv[]) {
	// insert code here...
	
	if( argc < 2 )
	{
		std::cerr << "Usage: " << argv[0] << " <romfile> [<command>]" << std::endl;
		return 0;
	}
	
	std::shared_ptr<Cpu> cpu = std::make_shared<Cpu>();
	cpu->SetFreqMhz(4.194304);
	cpu->LoadRom(argv[1]);
	
	if( argc > 2 ){
		std::vector<std::string> commandLine;
		for( int i=2; i<argc; i++ )
		{
			commandLine.push_back(argv[i]);
		}
		RunCommand(cpu, commandLine);
		return 0;
	}

	for (std::string line; std::getline(std::cin, line);) {

		auto commandLine = SplitCommand(line);

		RunCommand(cpu, commandLine);
	}
	
	return 0;
}
