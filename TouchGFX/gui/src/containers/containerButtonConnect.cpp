#include <gui/containers/containerButtonConnect.hpp>
#include "utilities.hpp"
#include <touchgfx/Bitmap.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/widgets/Image.hpp>

containerButtonConnect::containerButtonConnect( )
{

}
void containerButtonConnect::initialize( )
{
	containerButtonConnectBase::initialize( );
	imageSelected.setAlpha(0);
}
void containerButtonConnect::setButtonIcon(TruckType type)
{
	switch (type)
	{
		case TruckType::none:
			buttonIcon.setIconBitmaps(Bitmap(BITMAP_EMERGENCY_HOME_FILL0_WGHT100_GRAD200_OPSZ48_ID),
					Bitmap(BITMAP_EMERGENCY_HOME_FILL0_WGHT100_GRAD200_OPSZ48_ID));
		break;
		case TruckType::truck:
			buttonIcon.setIconBitmaps(Bitmap(BITMAP_LOCAL_SHIPPING_FILL0_WGHT100_GRAD200_OPSZ48_ID),
					Bitmap(BITMAP_LOCAL_SHIPPING_FILL0_WGHT100_GRAD200_OPSZ48_ID));
		break;
		case TruckType::roadAssist:
			buttonIcon.setIconBitmaps(Bitmap(BITMAP_SOS_FILL0_WGHT100_GRAD200_OPSZ48_ID),
					Bitmap(BITMAP_SOS_FILL0_WGHT100_GRAD200_OPSZ48_ID));
		break;
		case TruckType::drift:
			buttonIcon.setIconBitmaps(Bitmap(BITMAP_DIRECTIONS_CAR_FILL0_WGHT100_GRAD200_OPSZ48_ID),
					Bitmap(BITMAP_DIRECTIONS_CAR_FILL0_WGHT100_GRAD200_OPSZ48_ID));
		break;
		case TruckType::heli:
			buttonIcon.setIconBitmaps(Bitmap(BITMAP_HELICOPTER_FILL0_WGHT100_GRAD200_OPSZ48_ID),
					Bitmap(BITMAP_HELICOPTER_FILL0_WGHT100_GRAD200_OPSZ48_ID));
		break;
		case TruckType::custom1:
			buttonIcon.setIconBitmaps(Bitmap(BITMAP_DOWNLOAD_FILL0_WGHT100_GRAD200_OPSZ48_ID),
					Bitmap(BITMAP_DOWNLOAD_FILL0_WGHT100_GRAD200_OPSZ48_ID));
		break;
	}
}
void containerButtonConnect::setBatteryIcon(int batteryPercentage)
{
	switch (batteryPercentage)
	{
		case 0:
			imageBatteryState.setBitmap(
					touchgfx::Bitmap(BITMAP_BATTERY_0_BAR_FILL0_WGHT100_GRAD200_OPSZ24_ID));
		break;
		case 1:
			imageBatteryState.setBitmap(
					touchgfx::Bitmap(BITMAP_BATTERY_1_BAR_FILL0_WGHT100_GRAD200_OPSZ24_ID));
		break;
		case 2:
			imageBatteryState.setBitmap(
					touchgfx::Bitmap(BITMAP_BATTERY_2_BAR_FILL0_WGHT100_GRAD200_OPSZ24_ID));
		break;
		case 3:
			imageBatteryState.setBitmap(
					touchgfx::Bitmap(BITMAP_BATTERY_3_BAR_FILL0_WGHT100_GRAD200_OPSZ24_ID));
		break;
		case 4:
			imageBatteryState.setBitmap(
					touchgfx::Bitmap(BITMAP_BATTERY_4_BAR_FILL0_WGHT100_GRAD200_OPSZ24_ID));
		break;
		case 5:
			imageBatteryState.setBitmap(
					touchgfx::Bitmap(BITMAP_BATTERY_5_BAR_FILL0_WGHT100_GRAD200_OPSZ24_ID));
		break;
		case 6:
			imageBatteryState.setBitmap(
					touchgfx::Bitmap(BITMAP_BATTERY_6_BAR_FILL0_WGHT100_GRAD200_OPSZ24_ID));
		break;
		case 7:
			imageBatteryState.setBitmap(
					touchgfx::Bitmap(BITMAP_BATTERY_FULL_FILL0_WGHT100_GRAD200_OPSZ24_ID));
		break;

	}

}
void containerButtonConnect::setStatusIcon(const Bitmap &newIcon)
{
	imageStatus.setBitmap(newIcon);
}
void containerButtonConnect::setConnectionStatus(int connection)
{


}
void containerButtonConnect::setName(const char *newName)
{
	Unicode::snprintf(textNameBuffer, TEXTNAME_SIZE, newName);
	textName.setWildcard(textNameBuffer);
}
void containerButtonConnect::setName(std::string newName)
{
	Unicode::snprintf(textNameBuffer, TEXTNAME_SIZE, "%s", newName);
	textName.setWildcard(textNameBuffer);
}
void containerButtonConnect::setSelected( )
{

	selected = 1;
	imageSelected.setAlpha(80);

}
void containerButtonConnect::setDeselected( )
{

	selected = 0;
	imageSelected.setAlpha(0);

}
bool containerButtonConnect::getSelected( )
{

	return selected;

}
void containerButtonConnect::setAdress(int adress)
{
	adressToConnect = adress;
}
int containerButtonConnect::getAdress( )
{
	return adressToConnect;

}
