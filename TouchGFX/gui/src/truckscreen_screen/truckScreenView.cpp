#include <gui/truckscreen_screen/truckScreenView.hpp>
#include "InputOutputModel.hpp"
#include <images/BitmapDatabase.hpp>
#include "ControllerSettings.hpp"
#include <string>
#include "ThemeFactory.hpp"
#include <images/BitmapDatabase.hpp>

extern InputOutputModel controllerState;
extern ControllerSettings settingsM;

truckScreenView::truckScreenView( ):
			selectedTruckCallback(this, &truckScreenView::selectedTruckCallbackHandler),
			flexButtonCallback(this, &truckScreenView::flexButtonCallbackHandler)

{
	scrollableActive.setScrollThreshold(1);
	scrollableActive.setScrollDurationSlowdown(1);
	scrollableActive.setMaxVelocity(10);

	acceptButton.setAction(flexButtonCallback);

	vehicleSelection1.setAdress(0x21);
	vehicleSelection1.setColor(255,0,0);
	vehicleSelection1.setTitle("White Scania");
	vehicleSelection1.setDescription("Basic scania truck <3");
	vehicleSelection1.setIconType(BITMAP_LOCAL_SHIPPING_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	vehicleSelection1.setType(TruckType::truck);

	vehicleSelection2.setAdress(0x26);
	vehicleSelection2.setColor(255,0,0);
	vehicleSelection2.setTitle("Silver Volvo");
	vehicleSelection2.setDescription("Basic Volvo truck");
	vehicleSelection2.setIconType(BITMAP_LOCAL_SHIPPING_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	vehicleSelection2.setType(TruckType::truck);

	vehicleSelection3.setAdress(0x22);
	vehicleSelection3.setColor(255,0,0);
	vehicleSelection3.setTitle("Road assistance");
	vehicleSelection3.setDescription("Road assistance truck");
	vehicleSelection3.setIconType(BITMAP_AUTO_TOWING_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	vehicleSelection3.setType(TruckType::roadAssist);

	vehicleSelection4.setAdress(0x23);
	vehicleSelection4.setColor(255,0,0);
	vehicleSelection4.setTitle("DriftCar");
	vehicleSelection4.setDescription("Wrooooom !");
	vehicleSelection4.setIconType(BITMAP_DIRECTIONS_CAR_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	vehicleSelection4.setType(TruckType::drift);

	vehicleSelection1.setClickAction(selectedTruckCallback);
	vehicleSelection2.setClickAction(selectedTruckCallback);
	vehicleSelection3.setClickAction(selectedTruckCallback);
	vehicleSelection4.setClickAction(selectedTruckCallback);

}
void truckScreenView::setupScreen( )
{
	listActive.removeAll();
	Unicode::snprintf(textConnectedBuffer, TEXTCONNECTED_SIZE, "0x%02X", controllerState.adress);

	std::vector<touchgfx::PainterRGB888*> painters;
	painters.push_back(&lineDecoScroll1Painter);
	painters.push_back(&lineDecoScroll2Painter);

	ThemeFactory th(settingsM.user);
	th.bindBackground(background);
	th.applyPainters(painters);
	th.bindColorSecondary(vehicleSelection1);
	th.bindColorSecondary(vehicleSelection2);
	th.bindColorSecondary(vehicleSelection3);
	th.bindColorSecondary(vehicleSelection4);

	truckScreenViewBase::setupScreen( );
	scrollableActive.doScroll(0, settingsM.scrolledAmountOnTruckScreen);

	listActive.add(vehicleSelection1);
	listActive.add(vehicleSelection2);
	listActive.add(vehicleSelection3);
	listActive.add(vehicleSelection4);
}

void truckScreenView::tearDownScreen( )
{
	truckScreenViewBase::tearDownScreen( );
	settingsM.scrolledAmountOnTruckScreen = scrollableActive.getScrolledY( );
}

void truckScreenView::selectedTruckCallbackHandler(const vehicleSelection& src,const ClickEvent &e)
{
//TODO Compress this if statement to one for loop
	if (&src == &vehicleSelection1)
	{
		adress = vehicleSelection1.getAdress( );
		name = vehicleSelection1.getTitle( );
		type = vehicleSelection1.getType( );
		icon = vehicleSelection1.getIconType();
		imageSelected.setBitmap(icon);
		textConnected.setColor(touchgfx::Color::getColorFromRGB(255, 255, 0));
		Unicode::snprintf(textConnectedBuffer, TEXTCONNECTED_SIZE, "0x%02X", adress);
		textConnected.invalidate( );
	}

	if (&src == &vehicleSelection2)
	{
		adress = vehicleSelection2.getAdress( );
		name = vehicleSelection2.getTitle( );
		type = vehicleSelection2.getType( );
		icon = vehicleSelection2.getIconType();
		imageSelected.setBitmap(icon);
		textConnected.setColor(touchgfx::Color::getColorFromRGB(255, 255, 0));
		Unicode::snprintf(textConnectedBuffer, TEXTCONNECTED_SIZE, "0x%02X", adress);
		textConnected.invalidate( );
	}

	if (&src == &vehicleSelection3)
	{
		adress = vehicleSelection3.getAdress( );
		name = vehicleSelection3.getTitle( );
		type = vehicleSelection3.getType( );
		icon = vehicleSelection3.getIconType();
		imageSelected.setBitmap(icon);
		textConnected.setColor(touchgfx::Color::getColorFromRGB(255, 255, 0));
		Unicode::snprintf(textConnectedBuffer, TEXTCONNECTED_SIZE, "0x%02X", adress);
		textConnected.invalidate( );
	}

	if (&src == &vehicleSelection4)
	{
		adress = vehicleSelection4.getAdress( );
		name = vehicleSelection4.getTitle( );
		type = vehicleSelection4.getType( );
		icon = vehicleSelection4.getIconType();
		imageSelected.setBitmap(icon);
		textConnected.setColor(touchgfx::Color::getColorFromRGB(255, 255, 0));
		Unicode::snprintf(textConnectedBuffer, TEXTCONNECTED_SIZE, "0x%02X", adress);
		textConnected.invalidate( );
	}

	imageSelected.invalidate();
}
void truckScreenView::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer &src)
{
	if (&src == &acceptButton)
	{
		controllerState.adress = adress;
		controllerState.connectedTruckNameCP = name;
		controllerState.truckType = type;

		//TODO delete this when connection manager is in place
		controllerState.connected = 1;

		Unicode::snprintf(textConnectedBuffer, TEXTCONNECTED_SIZE, "0x%02X", adress);
		textConnected.invalidate( );
		textConnected.setColor(touchgfx::Color::getColorFromRGB(0, 255,0));
	}

}
