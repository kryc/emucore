//
//  Common.hpp
//  emucore
//
//  Created by Gareth Evans on 26/06/2019.
//  Copyright © 2019 Gareth Evans. All rights reserved.
//

#ifndef Common_hpp
#define Common_hpp

enum : int
{
	INTERRUPT_VBLANK = 0x01,
	INTERRUPT_LCDC = 0x02,
	INTERRUPT_TIMA = 0x04,
	INTERRUPT_SERIAL = 0x08,
	INTERRUPT_INPUT = 0x10
};

#endif /* Common_hpp */
