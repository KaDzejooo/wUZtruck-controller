/*
 * WhitePainTer.hpp
 *
 *  Created on: Sep 21, 2023
 *      Author: KaDzejoo
 */

#ifndef WHITEPAINTER_HPP_
#define WHITEPAINTER_HPP_
#include <touchgfx/widgets/canvas/AbstractPainterRGB888.hpp>
#include <touchgfx/Color.hpp>
/*
 *
 */
using namespace touchgfx;
class WhitePainter : public AbstractPainterRGB888
{
	public:
		void paint(uint8_t *dest, int16_t offset, int16_t widgetX, int16_t widgetY, int16_t count,
				uint8_t alpha) const
		{

			uint16_t *framebuffer = reinterpret_cast <uint16_t*>(dest) + offset;
			const uint16_t *const lineend = framebuffer + count;

//			const uint16_t redColor = 0xF800;
//			const uint16_t whitecolor = 0xFFFFFF;
//			const uint16_t blueColor = 0x0000FF;

			// 1111100000022222
			// 0000011111100000
			// 0000022222211111

			//int Y = 0.2126 R + 0.7152 G + 0.0722 B;

			do
			{
				uint16_t screenColor = *(framebuffer);

//				  int r = (screenColor >> 11) & 0xFF;
//				  int g = (screenColor >> 5)  & 0xFF;
//				  int b =  screenColor        & 0xFF;
//
//				  int Y = 0.2126*r + 0.7152*g + 0.0722*b;

		           if (true)
		            {
		                *framebuffer = screenColor>>5; // Write to framebuffer
		            }
		            else
		            {
		                *framebuffer = screenColor>>2;
		            }

			}
			while (++framebuffer < lineend);

		}
};

#endif /* WHITEPAINTER_HPP_ */
