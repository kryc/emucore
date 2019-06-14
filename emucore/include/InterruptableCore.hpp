//
//  InterruptableCore.hpp
//  emucore
//
//  Created by Gareth Evans on 13/06/2019.
//  Copyright © 2019 Gareth Evans. All rights reserved.
//

#ifndef InterruptableCore_hpp
#define InterruptableCore_hpp

#include <map>

/* Callback info from https://embeddedartistry.com/blog/2017/1/26/c11-improving-your-callback-game */
using InterruptCallback = std::function<void(int)>;

#define INTERRUPT_CALLBACK(pFn, pThis) (std::bind((pFn), (pThis), std::placeholders::_1))
#define INTERRUPT_CALLBACK_THIS(pFn) (std::bind((pFn), this, std::placeholders::_1))

class InterruptableCore
{
public:
	void 	RegisterInterrupt(const int Id, const InterruptCallback Callback);
	bool 	InterruptExists(int Id);
	bool	InterruptsEnabled(void) { return m_InterruptsEnabled; };
	void	SetInterruptsEnabled(bool Enabled);
	void	DisableInterrupts() { SetInterruptsEnabled(false); };
	void	EnableInterrupts() { SetInterruptsEnabled(true); };
	int 	RaiseInterrupt(int Id);
private:
	std::mutex							m_Mutex;
	bool								m_InterruptsEnabled = true;
	std::map<int, InterruptCallback> 	m_Interrupts;
	size_t								m_IgnoredInterrupts = 0;
};

#endif /* InterruptableCore_hpp */
