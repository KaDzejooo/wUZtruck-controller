/*
 * ThemeFactory.hpp
 *
 *  Created on: Sep 15, 2023
 *      Author: KaDzejoo
 */

#ifndef THEMEFACTORY_HPP_
#define THEMEFACTORY_HPP_
#include <images/BitmapDatabase.hpp>
#include "ControllerSettings.hpp"
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/canvas/PainterRGB888.hpp>
#include <touchgfx/Color.hpp>
#include <touchgfx/hal/Types.hpp>
#include <vector>
#include <gui/containers/lineDiv.hpp>

extern ControllerSettings settingsM;
/*
 *
 */
union ColorHex
{
    unsigned int hex;
    struct { unsigned char b, g, r; };
};


class ThemeFactory
{
	public:
		ThemeFactory(User user);





		ThemeFactory(User user, touchgfx::Image &backgroundImg);
		ThemeFactory(User user, touchgfx::Image &backgroundImg, touchgfx::PainterRGB888 &painter);
		ThemeFactory(User user, touchgfx::Image &backgroundImg, touchgfx::PainterRGB888 &painter,
				touchgfx::PainterRGB888 &painter2);
		ThemeFactory(User user, touchgfx::Image &backgroundImg, std::vector<touchgfx::PainterRGB888*> &painter);



		void bindBackground(touchgfx::Image &backgroundImg){
			backgroundImg.setBitmap(userBackground);
		}

		void applyPainters(std::vector<touchgfx::PainterRGB888*> &painter)
		{
			for(uint8_t i = 0;i<painter.size();i++)
			{
				setPainterColor(selUser,*painter[i]);
			}
		}


		template <class T>
		void bindColor(T &in){;
		in.setColor(touchgfx::Color::getRed(userCol),
				touchgfx::Color::getGreen(userCol),
				touchgfx::Color::getBlue(userCol));
		in.invalidate();
		}

		template <class T>
		void bindColor(T &in, int x){
		in.setColor(userCol);
		in.invalidate();
		}


		template <class T>
		void bindColorSecondary(T &in){;
		in.setColor(touchgfx::Color::getRed(userColSecondary),
				touchgfx::Color::getGreen(userColSecondary),
				touchgfx::Color::getBlue(userColSecondary));
		in.invalidate();
		}

		template <class T>
		void bindColorSecondary(T &in, int x){
		in.setColor(userColSecondary);
		in.invalidate();
		}
	private:
		void setBackground(User user,touchgfx::Image &backgroundImg);
		void setPainterColor(User user, touchgfx::PainterRGB888 &painter);
		//void setPaintersColor(User user, std::vector<touchgfx::PainterRGB888*> &painter);
		User selUser;
		touchgfx::colortype defaultCol;
		touchgfx::colortype userCol;
		touchgfx::colortype userColSecondary;

		touchgfx::Bitmap userBackground;
};

#endif /* THEMEFACTORY_HPP_ */
