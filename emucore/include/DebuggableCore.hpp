//
//  DebuggableCore.hpp
//  emucore
//
//  Created by Gareth Evans on 27/06/2019.
//  Copyright © 2019 Gareth Evans. All rights reserved.
//

#ifndef DebuggableCore_hpp
#define DebuggableCore_hpp

#include <map>
#include <string>
#include <vector>
#include <algorithm>

class DebuggableCore
{
public:
	void	Break(void) { m_Break = true; };
	void 	AddBreakPoint(const register_t Address) { m_Breakpoints.push_back(Address); };
	virtual std::map<std::string, register_t> GetRegisters(void) = 0;
	virtual uint8_t ReadMemory(register_t Address) = 0;
	virtual std::vector<uint8_t> ReadMemoryRange(register_t StartAddress, size_t Length) = 0;
protected:
	bool	ShouldBreak(const register_t Address);
	void	Breaking(register_t Address) { m_Broken = true; m_LastBroken = Address; };
private:
	std::vector<register_t>	m_Breakpoints;
	bool					m_Break = false;
	bool					m_Broken = false;
	register_t				m_LastBroken = 0;
};

#endif /* DebuggableCore_hpp */
