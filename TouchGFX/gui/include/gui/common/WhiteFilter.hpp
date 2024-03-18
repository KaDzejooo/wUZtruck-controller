/*
 * WhiteFilter.hpp
 *
 *  Created on: Oct 4, 2023
 *      Author: KaDzejoo
 */

#ifndef WHITEFILTER_HPP_
#define WHITEFILTER_HPP_
/*
 *
 */
#include <touchgfx/widgets/Widget.hpp>

class WhiteFilter : public touchgfx::Widget
{
	public:
		WhiteFilter( ){};

		void draw(const touchgfx::Rect &invalidatedArea) const
		{

			touchgfx::Rect absolute = getAbsoluteRect();

			    uint16_t* framebuffer = touchgfx::HAL::getInstance()->lockFrameBuffer();

			    for (int y = invalidatedArea.y; y < invalidatedArea.bottom(); y++)
			    {
			        for (int x = invalidatedArea.x; x < invalidatedArea.right(); x++)
			        {
			            framebuffer[absolute.x + x + (absolute.y + y) * touchgfx::HAL::DISPLAY_WIDTH] = 0xff;
			        }
			    }

			    touchgfx::HAL::getInstance()->unlockFrameBuffer();
		}


		touchgfx::Rect getSolidRect( ) const
		{
			 return touchgfx::Rect(0, 0, 0, 0);
		}

};

#endif /* WHITEFILTER_HPP_ */
