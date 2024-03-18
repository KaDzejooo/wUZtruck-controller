#include <gui/containers/notificationContainer.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

notificationContainer::notificationContainer( )
{
	iconType24dp.setAlpha(0);
}

void notificationContainer::initialize( )
{
	notificationContainerBase::initialize( );
}
void notificationContainer::setIcon24dp(touchgfx::Bitmap iconId24dp)
{
	iconType24dp.setBitmap(iconId24dp);
}
void notificationContainer::setIcon(touchgfx::Bitmap iconId)
{
	iconType.setBitmap(iconId);
}
void notificationContainer::setType(notification::notificationType type)
{

	switch (type)
	{
		case notification::bar:
			containerBarDisplay.setVisible(1);
			containerSubText.setVisible(0);
			containerBig.setVisible(1);
			iconType24dp.setVisible(0);
		break;
		case notification::text:
			containerBarDisplay.setVisible(0);
			containerSubText.setVisible(1);
			containerBig.setVisible(1);
			iconType24dp.setVisible(0);
		break;
		case notification::small:
			containerBig.setVisible(0);
			iconType24dp.setVisible(1);
		break;

	}

	if (type == notification::bar)
	{
		containerBarDisplay.setVisible(1);
		containerSubText.setVisible(0);
	}
	else
	{
		containerBarDisplay.setVisible(0);
		containerSubText.setVisible(1);
	}
}
void notificationContainer::setTitle(const char *title)
{
	Unicode::snprintf(textTitleBuffer, TEXTTITLE_SIZE, title);
	textTitle.setWildcard(textTitleBuffer);
}
void notificationContainer::setTitle(std::string title)
{
	Unicode::snprintf(textTitleBuffer, TEXTTITLE_SIZE, "%s", title);
	textTitle.setWildcard(textTitleBuffer);
}
void notificationContainer::setSubTextTop(std::string subtext)
{
	Unicode::snprintf(subText1Buffer, SUBTEXT1_SIZE, "%s", subtext);
	subText1.setWildcard(subText1Buffer);
}
void notificationContainer::setSubTextBottom(std::string subtext)
{
	Unicode::snprintf(subText2Buffer, SUBTEXT2_SIZE, "%s", subtext);
	subText2.setWildcard(subText2Buffer);
}
void notificationContainer::setSubTextTop(const char *subtext)
{
	Unicode::snprintf(subText1Buffer, SUBTEXT1_SIZE, subtext);
	subText1.setWildcard(subText1Buffer);
}
void notificationContainer::setSubTextBottom(const char *subtext)
{
	Unicode::snprintf(subText2Buffer, SUBTEXT2_SIZE, subtext);
	subText2.setWildcard(subText2Buffer);
}

void notificationContainer::setVechicleText(std::string text)
{
	Unicode::snprintf(textTruckBuffer, TEXTTRUCK_SIZE, "%s", text);
	textTruck.setWildcard(textTruckBuffer);
}
void notificationContainer::setVechicleText(const char *text)
{

	Unicode::snprintf(textTruckBuffer, TEXTTRUCK_SIZE,text);
	textTruck.setWildcard(textTruckBuffer);
}

void notificationContainer::setBar(int percentage)
{
//	barDisplay.setColor(
//			touchgfx::Color::getColorFromRGB(0,255,13));
	barDisplay.setValue(percentage);

	std::string str = std::to_string(percentage);
	const char *strCP = str.c_str( );
	Unicode::snprintf(textPercentageBuffer, TEXTPERCENTAGE_SIZE, strCP);
	textPercentage.setWildcard(textPercentageBuffer);
}
void notificationContainer::setPriorityColor(notification::priorityColor color)
{
	switch (color)
	{
		case notification::red:
			shapePriorityPainter.setColor(touchgfx::Color::getColorFromRGB(227, 0, 0));
			//priority = 1;
		break;
		case notification::orange:
			shapePriorityPainter.setColor(touchgfx::Color::getColorFromRGB(227, 95, 0));
			//priority = 2;
		break;
		case notification::blue:
			shapePriorityPainter.setColor(touchgfx::Color::getColorFromRGB(0, 166, 229));
			//priority = 4;
		break;
		case notification::green:
			shapePriorityPainter.setColor(touchgfx::Color::getColorFromRGB(79, 227, 0));
			//priority = 5;
		break;
	}
}
void notificationContainer::setColor(uint8_t r,uint8_t g,uint8_t b)
{
	shapePriorityPainter.setColor(touchgfx::Color::getColorFromRGB(r, g, b));
}

int notificationContainer::getAlpha( )
{
	return alpha;
}

void notificationContainer::setAlpha(uint8_t newAlpha)
{
	this->alpha = newAlpha;
	iconType24dp.setAlpha(newAlpha);
	iconType.setAlpha(newAlpha);
//	shapePriority.setAlpha(newAlpha);
//	textTitle.setAlpha(newAlpha);
//	subText1.setAlpha(newAlpha);
//	subText2.setAlpha(newAlpha);
//	lineDeco.setAlpha(newAlpha);
//	barDisplay.setAlpha(newAlpha);
//	boxBcgrnd.setAlpha(newAlpha);
//	textPercentage.setAlpha(newAlpha);
//	textTruck.setAlpha(newAlpha);
}

