//
//  ProcessingCore.cpp
//  emucore
//
//  Created by Gareth Evans on 13/06/2019.
//  Copyright © 2019 Gareth Evans. All rights reserved.
//

#include "ProcessingCore.hpp"

ProcessingCore::ProcessingCore()
{
	this->SetFreq(1.0);
}
void
ProcessingCore::Cb(int Id)
{
	std::cout << "[+] Interrupt " << Id << " raised" << std::endl;
}

void
ProcessingCore::Tick(void)
{
	std::cout << "[+] Tick" << std::endl;
	if( std::rand() % 10 == 0 )
		RaiseInterrupt(1);
}
