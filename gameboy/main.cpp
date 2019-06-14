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

#include "ProcessingCore.hpp"

int main(int argc, const char * argv[]) {
	// insert code here...
	ProcessingCore p;
	
	p.RegisterInterrupt(1, INTERRUPT_CALLBACK(&ProcessingCore::Cb, &p));
	p.RaiseInterrupt(1);
	
	p.Run();

	std::cout << "Hello, World!\n";
	return 0;
}
