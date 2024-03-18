#include <gui/hardwaretestscreen_screen/hardwareTestScreenView.hpp>
#include "integrityManager.hpp"
#include "ControllerSettings.hpp"
#include <images/BitmapDatabase.hpp>
#include "NotificationFactory.hpp"
#include <string>
#include "ThemeFactory.hpp"
#include "MessageEncoder.hpp"


extern ControllerSettings settingsM;
extern InputOutputModel controllerState;
extern NotificationFactory notificationFactory;
extern MessageEncoder encoder;

hardwareTestScreenView::hardwareTestScreenView( ):
		flexButtonCallback(this, &hardwareTestScreenView::flexButtonCallbackHandler)
{
	//CustomKeyboard keyboard(settingsM.codeAccepted);
	buttonResetController.setAction(flexButtonCallback);
	buttonSummonNotifications.setAction(flexButtonCallback);
	buttonKillNotifications.setAction(flexButtonCallback);
	buttonAddNotification.setAction(flexButtonCallback);

	buttonReset.setAction(flexButtonCallback);
	buttonTruck.setAction(flexButtonCallback);
	buttonDrift.setAction(flexButtonCallback);
	buttonHeli.setAction(flexButtonCallback);
	buttonRoadAssist.setAction(flexButtonCallback);
	buttonNone.setAction(flexButtonCallback);
	buttonDisconnected.setAction(flexButtonCallback);
	buttonConnected.setAction(flexButtonCallback);
}

void hardwareTestScreenView::setupScreen( )
{
	hardwareTestScreenView::setupIomDisplay( );
	swipeContainer.setSelectedPage(settingsM.hardwareTestScreenMenuNumber);
	hardwareTestScreenViewBase::setupScreen( );

//	float expoMap(int x, int easingFactor, int offset)
//	{
//		x = x - offset; // -50 lol xd
//		float val;
//		val = exp( ( ( abs(x) - offset ) * easingFactor ) / 1000) * x;
//		return val + offset;
//	}



	keyboard.setAcceptVar(&settingsM.codeAccepted);
	std::vector<touchgfx::PainterRGB888*> painters;
	ThemeFactory th(settingsM.user);
	th.bindBackground(background);
	painters.push_back(&lineJoy1XPainter);
	painters.push_back(&lineJoy1YPainter);
	painters.push_back(&lineJoy2XPainter);
	painters.push_back(&lineJoy2YPainter);
	painters.push_back(&lineTriggLPainter);
	painters.push_back(&lineTriggRPainter);
	th.applyPainters(painters);

}

void hardwareTestScreenView::tearDownScreen( )
{
	settingsM.hardwareTestScreenMenuNumber = swipeContainer.getSelectedPage( );
	hardwareTestScreenViewBase::tearDownScreen( );
}
void hardwareTestScreenView::tickView( )
{
	settingsM.lastCode = keyboard.getBuffer();
	Unicode::snprintf(textArea1Buffer, 69,"%#X",encoder.binaryArr);


	Unicode::snprintf(textSpeedValBuffer, TEXTSPEEDVAL_SIZE,"%d",controllerState.axis.direction);
	Unicode::snprintf(textDirectionValBuffer, TEXTDIRECTIONVAL_SIZE,"%d",controllerState.axis.turn);
	textDirectionVal.invalidate();
	textSpeedVal.invalidate();

	hardwareTestScreenView::updateIomDisplay( );
	hardwareTestScreenView::updateLineDisplay( );
	hardwareTestScreenView::updateButtonsDisplay( );

	textureMapper1.setAngles((float) ( controllerState.axis.direction - 50 ) / 50, 0,
			(float) ( controllerState.axis.turn - 50 ) / 50);
	textureMapper1.invalidate( );

	boxBackground.invalidate( );
	//swipeContainerPage3.invalidate();
}

void hardwareTestScreenView::setupIomDisplay( )
{
	Unicode::snprintf(textNameBuffer, TEXTNAME_SIZE, controllerState.connectedTruckNameCP);
	Unicode::snprintf(textTruckTypeBuffer, TEXTTRUCKTYPE_SIZE, "%d", controllerState.truckType);
	Unicode::snprintf(textTopBuffer, TEXTTOP_SIZE, "%d", controllerState.topLights);
	Unicode::snprintf(textHighBuffer, TEXTHIGH_SIZE, "%d", controllerState.highBeams);
	Unicode::snprintf(textLowBuffer, TEXTLOW_SIZE, "%d", controllerState.lowBeams);
	Unicode::snprintf(textPosBuffer, TEXTPOS_SIZE, "%d", controllerState.posLights);
	Unicode::snprintf(textHazardsBuffer, TEXTHAZARDS_SIZE, "%d", controllerState.hazards);
	Unicode::snprintf(textLeftBlinkerBuffer, TEXTLEFTBLINKER_SIZE, "%d",
			controllerState.leftBlinker);
	Unicode::snprintf(textRightBlinkerBuffer, TEXTRIGHTBLINKER_SIZE, "%d",
			controllerState.rightBlinker);
	Unicode::snprintf(textFogRBuffer, TEXTFOGR_SIZE, "%d", controllerState.fogLightsRear);
	Unicode::snprintf(textFogFBuffer, TEXTFOGF_SIZE, "%d", controllerState.fogLightsFront);
	Unicode::snprintf(textGearDownBuffer, TEXTGEARDOWN_SIZE, "%d", controllerState.gearDown);
	Unicode::snprintf(textGearUpBuffer, TEXTGEARUP_SIZE, "%d", controllerState.gearUp);
	Unicode::snprintf(textHornBuffer, TEXTHORN_SIZE, "%d", controllerState.horn);
	Unicode::snprintf(textAdressBuffer, TEXTADRESS_SIZE, "0x%02X", controllerState.adress);
}
void hardwareTestScreenView::updateIomDisplay( )
{
	hardwareTestScreenView::setupIomDisplay( );
}
void hardwareTestScreenView::updateLineDisplay( )
{
	lineJoy1X.setValue(controllerState.joyData.joy1x);
	lineJoy1Y.setValue(controllerState.joyData.joy1y);
	lineJoy2X.setValue(controllerState.joyData.joy2x);
	lineJoy2Y.setValue(controllerState.joyData.joy2y);
	lineTriggL.setValue(controllerState.joyData.trigg);
	lineTriggR.setValue(controllerState.joyData.trigg);

	lineJoy1.setEnd(100 - controllerState.joyData.joy1x, controllerState.joyData.joy1y);
	lineJoy2.setEnd(100 - controllerState.joyData.joy2x, controllerState.joyData.joy2y);


	lineJoy1.invalidate( );
	lineJoy2.invalidate( );



}
void hardwareTestScreenView::updateButtonsDisplay( )
{
	if (controllerState.joyData.bttn1 == 1)
	{
		imageBttn1.setBitmap(
				touchgfx::Bitmap(BITMAP_RADIO_BUTTON_CHECKED_FILL0_WGHT100_GRAD200_OPSZ24_ID));
	}
	else
	{
		imageBttn1.setBitmap(
				touchgfx::Bitmap(BITMAP_RADIO_BUTTON_UNCHECKED_FILL0_WGHT100_GRAD200_OPSZ24_ID));
	}
	if (controllerState.joyData.bttn2 == 1)
	{
		imageBttn2.setBitmap(
				touchgfx::Bitmap(BITMAP_RADIO_BUTTON_CHECKED_FILL0_WGHT100_GRAD200_OPSZ24_ID));
	}
	else
	{
		imageBttn2.setBitmap(
				touchgfx::Bitmap(BITMAP_RADIO_BUTTON_UNCHECKED_FILL0_WGHT100_GRAD200_OPSZ24_ID));
	}
	if (controllerState.joyData.bttn3 == 1)
	{
		imageBttn3.setBitmap(
				touchgfx::Bitmap(BITMAP_RADIO_BUTTON_CHECKED_FILL0_WGHT100_GRAD200_OPSZ24_ID));
	}
	else
	{
		imageBttn3.setBitmap(
				touchgfx::Bitmap(BITMAP_RADIO_BUTTON_UNCHECKED_FILL0_WGHT100_GRAD200_OPSZ24_ID));
	}
	if (controllerState.joyData.bttn4 == 1)
	{
		imageBttn4.setBitmap(
				touchgfx::Bitmap(BITMAP_RADIO_BUTTON_CHECKED_FILL0_WGHT100_GRAD200_OPSZ24_ID));
	}
	else
	{
		imageBttn4.setBitmap(
				touchgfx::Bitmap(BITMAP_RADIO_BUTTON_UNCHECKED_FILL0_WGHT100_GRAD200_OPSZ24_ID));
	}
	if (controllerState.joyData.bttn5 == 1)
	{
		imageBttn5.setBitmap(
				touchgfx::Bitmap(BITMAP_RADIO_BUTTON_CHECKED_FILL0_WGHT100_GRAD200_OPSZ24_ID));
	}
	else
	{
		imageBttn5.setBitmap(
				touchgfx::Bitmap(BITMAP_RADIO_BUTTON_UNCHECKED_FILL0_WGHT100_GRAD200_OPSZ24_ID));
	}
	if (controllerState.joyData.bttn6 == 1)
	{
		imageBttn6.setBitmap(
				touchgfx::Bitmap(BITMAP_RADIO_BUTTON_CHECKED_FILL0_WGHT100_GRAD200_OPSZ24_ID));
	}
	else
	{
		imageBttn6.setBitmap(
				touchgfx::Bitmap(BITMAP_RADIO_BUTTON_UNCHECKED_FILL0_WGHT100_GRAD200_OPSZ24_ID));
	}
	/*
	 * each time all buttons are invalidated
	 * move this section into if statements for performance
	 * i'm too lazy for that
	 * cheers
	 */
	imageBttn1.invalidate( );
	imageBttn2.invalidate( );
	imageBttn3.invalidate( );
	imageBttn4.invalidate( );
	imageBttn5.invalidate( );
	imageBttn6.invalidate( );

}
void hardwareTestScreenView::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &buttonResetController)
    {
    	HAL_NVIC_SystemReset();
    }
    if (&src == &buttonReset)
    {
    	controllerState.iomReInit();
    }
    if (&src == &buttonKillNotifications)
    {
    	notificationFactory.clearNotificationsSet( );
    }
    if (&src == &buttonSummonNotifications)
    {
    	notificationFactory.generateDummyNotifications( );
    }
    if (&src == &buttonAddNotification)
    {
    	notificationFactory.addDummyNotification( );
    }
    if (&src == &buttonRoadAssist){
    	controllerState.truckType =TruckType::roadAssist;
    	controllerState.connectedTruckNameCP = "Road Assistance";
    }
    if (&src == &buttonTruck){
    	controllerState.truckType =TruckType::truck;
    	controllerState.connectedTruckNameCP = "Scania Boi";
    }
    if (&src == &buttonDrift){
    	controllerState.truckType =TruckType::drift;
    }
    if (&src == &buttonHeli){
    	controllerState.truckType =TruckType::heli;
    }
    if (&src == &buttonNone){
    	controllerState.truckType =TruckType::custom1;
    }
    if(&src == &buttonDisconnected){
    	controllerState.connected = 0;
    }
    if(&src == &buttonConnected){
    	controllerState.connected = 1;
    }


}
