//
//  Gpu.cpp
//  emucore
//
//  Created by Gareth Evans on 24/06/2019.
//  Copyright © 2019 Gareth Evans. All rights reserved.
//

#include <assert.h>
#include "Gpu.hpp"
#include "Common.hpp"
#include "Cpu.hpp"

static const size_t TileWidth = 8;
static const size_t TileHeight = 8;
static const size_t PixelsPerTile = TileWidth*TileHeight;
static const size_t PixelsPerTileElement = (sizeof(uint16_t) * 8) / 2;
static const size_t ElementsPerTile = (TileWidth*TileHeight)/PixelsPerTileElement;

static const size_t ScreenBufferWidthPixels = 256;
static const size_t ScreenBufferHeightPixels = 256;
static const size_t ScreenBufferWidthTiles = (ScreenBufferWidthPixels/TileWidth);
static const size_t ScreenBufferHeightTiles = (ScreenBufferHeightPixels/TileHeight);

void
Gpu::Tick(void)
/*++
 Code shamelessly copied and modified from @teesee23
 --*/
{
	/* Use of GetNoHook is safe here to bypass IoPort handlers
		designed to catch CPU accesses */
	uint8_t stat 	= m_Memory[0xff41].GetNoHook();
	uint8_t ly 		= m_Memory[0xff44].GetNoHook();
	uint8_t mode 	= stat & 3;

	switch (mode)
	{
		case 0x0: /* H-Blank */
		{
			if(m_TicksInCurrentCycle >= 204)
			{
				ly++;
				m_TicksInCurrentCycle = 0;
				
				if(ly == 143) /* transition to vblank if drawn a whole screen */
				{
					//log_debug("------TRANSITION TO VBLANK FROM HBLANK-----");
					mode = 1;
					//update texture maps
					m_Cpu->RaiseInterrupt(INTERRUPT_VBLANK);
					MakeBmp();
				}
				else    /* Otherwise go to OAM mode */
				{
					//log_debug("------TRANSITION TO OAM ACCESS FROM HBLANK-----");
					mode = 2;
				}
			}
			break;
		}
		case 0x1: /* V-Blank */
		{
			if(m_TicksInCurrentCycle >=456)
			{
				m_TicksInCurrentCycle = 0; /* reset the clock */
				ly++;
				
				if(ly > 153)
				{
					//log_debug("------TRANSITION TO OAM ACCESS FROM VBLANK-----");
					mode = 2;
					ly = 0;
				}
			}
			break;
		}
		case 0x2: /* Accessing OAM (NO CPU allowed) */
		{
			if(m_TicksInCurrentCycle >= 80)
			{
				//log_debug("------TRANSITION TO VRAM ACCESS FROM OAM-----");
				m_TicksInCurrentCycle = 0;
				mode = 3;
			}
			break;
		}
		case 0x3: /* Accessing VRAM (No CPU allowed) */
		{
			if(m_TicksInCurrentCycle >= 172) /* transition to hblank */
			{
				//log_debug("------TRANSITION TO HBLANK from VRAM-----");
				m_TicksInCurrentCycle = 0;
				mode = 0;
				//render line
			}
			break;
		}
		default:
			throw std::runtime_error("GPU: Unknown STAT mode");
		
	}

	m_TicksInCurrentCycle++;
	m_TotalTicks++;
	 
	stat &=0xFC; /* blank out old mode */
	stat |= mode;
	/* Use of SetNoHook is safe here to bypass IoPort handlers
		designed to catch CPU accesses */
	m_Memory[0xff41].SetNoHook(stat);
	m_Memory[0xff44].SetNoHook(ly);
}



void
Gpu::DecodeTile(
   const uint16_t TileOffset,
   uint8_t *ColorValues
	)
{
	for(size_t element = 0; element < ElementsPerTile; element++ )
	{
		uint16_t x = m_Memory.Get16(TileOffset + (element*2));
		/* Perfect shuffle algorithm */
		x = (x & 0x00f0) << 4 | ((x >> 4) & 0x00f0) | (x & 0xf00f);
		x = (x & 0x0c0c) << 2 | ((x >> 2) & 0x0c0c) | (x & 0xc3c3);
		x = (x & 0x2222) << 1 | ((x >> 1) & 0x2222) | (x & 0x9999);
		x = (x & 0x5555) << 1 | ((x >> 1) & 0x5555);
		/* Output the numeric values */
		ColorValues[(element * PixelsPerTileElement) + 0] = (x & 0xc000) >> 14;
		ColorValues[(element * PixelsPerTileElement) + 1] = (x & 0x3000) >> 12;
		ColorValues[(element * PixelsPerTileElement) + 2] = (x & 0x0c00) >> 10;
		ColorValues[(element * PixelsPerTileElement) + 3] = (x & 0x0300) >>  8;
		ColorValues[(element * PixelsPerTileElement) + 4] = (x & 0x00c0) >>  6;
		ColorValues[(element * PixelsPerTileElement) + 5] = (x & 0x0030) >>  4;
		ColorValues[(element * PixelsPerTileElement) + 6] = (x & 0x000c) >>  2;
		ColorValues[(element * PixelsPerTileElement) + 7] = (x & 0x0003) >>  0;
	}
}

void
Gpu::MakeBmp(void)
{
	/* read lcdc to find out which tilemap to use */
	uint8_t tm = (m_Memory[0xFF40].GetNoHook() & (1<<3)) >> 3;
	uint16_t tm_loc = 0;
	if(tm == 0)
		tm_loc = 0x9800;
	else
		tm_loc = 0x9c00;
	
	//log_debug("tm_loc = %x", tm_loc);
	
	/* same for tile data */
	uint8_t td = (m_Memory[0xFF40].GetNoHook() & (1<<4)) >> 4;
	uint16_t td_loc = 0;
	if(td == 0)
		td_loc = 0x8000;
	else
		td_loc = 0x8800;
	
#if 0
	uint8_t bg_and_window_on = (m_Memory[0xFF40].GetNoHook() & 1) ;
	uint8_t sprite_disp_on = (m_Memory[0xFF40].GetNoHook() & (1 << 1)) >> 1;
	uint8_t sprite_size = (m_Memory[0xFF40].GetNoHook() & (1 << 2)) >> 2;
	uint8_t window_disp_on = (m_Memory[0xFF40].GetNoHook() & (1 << 5)) >> 5;
	uint8_t lcd_on = (m_Memory[0xFF40].GetNoHook() & (1 << 7)) >> 7;
#endif
	
	std::array<uint8_t, ScreenBufferWidthPixels*ScreenBufferHeightPixels> 	screenBuffer;
	std::array<uint8_t, ScreenBufferWidthPixels*ScreenBufferHeightPixels*3> screenBufferRgb;

	size_t nextPixel = 0;
	
	for( size_t tileRow = 0; tileRow < ScreenBufferHeightTiles; tileRow++ )
	{
		for( size_t tileCol = 0; tileCol < ScreenBufferWidthTiles; tileCol++ )
		{
			uint16_t tilenum = (uint16_t)m_Memory[tm_loc + (tileCol*32+tileRow)].Get();
			uint16_t tileData = td_loc + (tilenum*16);
			
			DecodeTile(tileData, &screenBuffer[nextPixel]);
			nextPixel += PixelsPerTile;
		}
	}

	for(size_t i=0; i<screenBuffer.size(); i++)
	{
		uint8_t pixval = 64 * screenBuffer[i];
		screenBufferRgb[(i*3)] = pixval;
		screenBufferRgb[(i*3)+1] = pixval;
		screenBufferRgb[(i*3)+2] = pixval;
	}
	
	
	uint32_t filesize = 54 + (TileWidth*TileHeight*3);
	
	uint8_t bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
	uint8_t bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0};
	uint8_t bmppad[3] = {0,0,0};
	
	bmpfileheader[ 2] = (uint8_t)(filesize    );
	bmpfileheader[ 3] = (uint8_t)(filesize>> 8);
	bmpfileheader[ 4] = (uint8_t)(filesize>>16);
	bmpfileheader[ 5] = (uint8_t)(filesize>>24);
	
	bmpinfoheader[ 4] = (uint8_t)(ScreenBufferWidthPixels      );
	bmpinfoheader[ 5] = (uint8_t)(ScreenBufferWidthPixels  >> 8);
	bmpinfoheader[ 6] = (uint8_t)(ScreenBufferWidthPixels  >>16);
	bmpinfoheader[ 7] = (uint8_t)(ScreenBufferWidthPixels  >>24);
	bmpinfoheader[ 8] = (uint8_t)(ScreenBufferHeightPixels     );
	bmpinfoheader[ 9] = (uint8_t)(ScreenBufferHeightPixels >> 8);
	bmpinfoheader[10] = (uint8_t)(ScreenBufferHeightPixels >>16);
	bmpinfoheader[11] = (uint8_t)(ScreenBufferHeightPixels >>24);
	
	FILE *f = fopen("/home/gareth/Desktop/ScreenBuffer.bmp","wb");
	if( f != nullptr )
	{
		fwrite(bmpfileheader,1,14,f);
		fwrite(bmpinfoheader,1,40,f);
		for( size_t i=0; i<ScreenBufferHeightPixels; i++ )
		{
			fwrite(&screenBufferRgb[0]+(ScreenBufferWidthPixels*(ScreenBufferHeightPixels-i-1)*3),3,ScreenBufferWidthPixels,f);
			fwrite(bmppad,1,(4-(ScreenBufferWidthPixels*3)%4)%4,f);
		}
		
		fclose(f);
	}
}
