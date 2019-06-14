//
//  ProcessingCore.hpp
//  emucore
//
//  Created by Gareth Evans on 13/06/2019.
//  Copyright © 2019 Gareth Evans. All rights reserved.
//

#ifndef ProcessingCore_hpp
#define ProcessingCore_hpp

#include <iostream>
#include "Clock.hpp"
#include "InterruptableCore.hpp"

class ProcessingCore : public InterruptableCore, public Clock
{
public:
	ProcessingCore();
	void Cb(int Id);
	void Tick(void);
};

#endif /* ProcessingCore_hpp */
