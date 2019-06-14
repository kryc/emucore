//
//  Clock.hpp
//  emucore
//
//  Created by Gareth Evans on 11/06/2019.
//  Copyright © 2019 Gareth Evans. All rights reserved.
//

#ifndef Clock_hpp
#define Clock_hpp

#include <cstdint>

class Clock
{
public:
	virtual void Tick(void);
	void Run(void);
	void SetFreq(double Hz);
	void SetFreqMhz(double MHz);
private:
	double m_Freq = 1.0;
	double m_TickTime = 1.0;
	unsigned int m_TickTimeUs = 1000000;
	size_t m_MissedTicks = 0;
};



#endif /* Clock_hpp */
