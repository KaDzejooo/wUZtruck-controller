/*
 * ThemeFactory.cpp
 *
 *  Created on: Sep 15, 2023
 *      Author: KaDzejoo
 */

#include <class/factories/ThemeFactory.hpp>
ThemeFactory::ThemeFactory(User user)
{
	selUser = user;
	defaultCol = touchgfx::Color::getColorFromRGB(255, 255, 255);

	switch (user)
	{
		case User::kaDzejoo:
			userCol = touchgfx::Color::getColorFromRGB(255, 40, 0);
			userColSecondary = touchgfx::Color::getColorFromRGB(255, 168, 0);
			userBackground = BITMAP_WINXD_ID;//BITMAP_WINXD_ID;
		break;
		case User::defaultUser:
			userCol = touchgfx::Color::getColorFromRGB(102, 163, 206);
			userColSecondary = touchgfx::Color::getColorFromRGB(102, 206, 197);
			userBackground = BITMAP_IDRIVE_ID;
		break;
		case User::debugUser:
			userCol = defaultCol;
			userColSecondary =defaultCol;
			userBackground = BITMAP_WINXD_ID;
		break;
		case User::pope:
			userCol = touchgfx::Color::getColorFromRGB(235, 207, 52);
			userColSecondary = touchgfx::Color::getColorFromRGB(221, 79, 175);//rgb(162, 0, 122)
			userBackground = BITMAP_POPE_ID;
		break;
		case User::cptFrost:
			ColorHex hex,secHex;
			hex.hex = 0xEDBF85;
			secHex.hex = 0xD64045;
			userCol = touchgfx::Color::getColorFromRGB(	hex.r, hex.g, hex.r );
			userColSecondary = touchgfx::Color::getColorFromRGB(secHex.r, secHex.g, secHex.b);
			userBackground = BITMAP_CIRCUITS_BOARD_ID;
			//EDBF85

		break;
	}


}


ThemeFactory::ThemeFactory(User user, touchgfx::Image &backgroundImg)
{
	setBackground(user,backgroundImg);
}

ThemeFactory::ThemeFactory(User user, touchgfx::Image &backgroundImg,
		touchgfx::PainterRGB888 &painter)
{
	setPainterColor(user,painter);
	setBackground(user,backgroundImg);
}

ThemeFactory::ThemeFactory(User user, touchgfx::Image &backgroundImg,
		touchgfx::PainterRGB888 &painter, touchgfx::PainterRGB888 &painter2)
{
	setPainterColor(user,painter);
	setPainterColor(user,painter2);
	setBackground(user,backgroundImg);
}
ThemeFactory::ThemeFactory(User user, touchgfx::Image &backgroundImg,
		std::vector <touchgfx::PainterRGB888*> &painter)
{
	setPainterColor(user,*painter[0]);
	for(uint8_t i = 0;i<painter.size();i++)
	{
		setPainterColor(user,*painter[i]);
	}
	setBackground(user,backgroundImg);
}
void ThemeFactory::setBackground(User user, touchgfx::Image &backgroundImg)
{
	backgroundImg.setBitmap(userBackground);
}

void ThemeFactory::setPainterColor(User user, touchgfx::PainterRGB888 &painter)
{
	painter.setColor(userCol);
}


