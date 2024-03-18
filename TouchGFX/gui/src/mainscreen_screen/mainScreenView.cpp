#include <gui/mainscreen_screen/mainScreenView.hpp>
#include <string>
#include <images/BitmapDatabase.hpp>
#include "ControllerSettings.hpp"
#include "InputOutputModel.hpp"
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/bitmap.hpp>
#include "SetupSettings.hpp"
#include <stdio.h>
#include "NotificationFactory.hpp"
#include <gui/containers/notificationContainer.hpp>
#include <stdlib.h>
#include "ThemeFactory.hpp"
#include "MessageEncoder.hpp"

extern MessageEncoder encoder;
extern ControllerSettings settingsM;
extern InputOutputModel controllerState, truckState;
extern NotificationFactory notificationFactory;

char debugStringBuffer [800];

mainScreenView::mainScreenView( ) :
		flexButtonCallback(this, &mainScreenView::flexButtonCallbackHandler), imageFadeAnimationEndedCallback(
				this, &mainScreenView::imageFadeAnimationEndedHandler), containerFadeAnimationEndedCallback(
				this, &mainScreenView::containerFadeAnimationEndedHandler)
{
	buttonNotification.setWildcardTextBuffer(buttonNotificationBuffer);
	buttonGearUp.setAction(flexButtonCallback);
	buttonGearDown.setAction(flexButtonCallback);

	buttonJoystick.setAction(flexButtonCallback);
	hideButton.setAction(flexButtonCallback);

	keyboard.setPosition(40, 0, 100, 185);
	keyboard.setTouchable(1);
	slideKeypad.add(keyboard);

	plusImage.setBitmap(touchgfx::Bitmap(BITMAP_ADD_FILL0_WGHT100_GRAD200_OPSZ24_ID));
	imageCameraDynamic.setXY(200, 100);




	//boxText.setPainter(whitePainter);
	//add(boxText);

}
void mainScreenView::setupScreen( )
{
	Unicode::snprintf(buttonNotificationBuffer, BUTTONNOTIFICATION_SIZE,"");

	listLeft.removeAll();
	slideKeypad.setVisible(settingsM.keypadEnable);
	listLeft.add(buttonTurnOn);

	if(settingsM.user != User::defaultUser ){
	listLeft.add(buttonApps);
	}

	listLeft.add(buttonLights);
	listLeft.add(buttonTruckChange);
	listLeft.add(buttonNotifications);
	listLeft.add(buttonSettings);
	listLeft.add(buttonJoystick);
#ifdef ENABLE_DUMMY_MODE
	listLeft.add(demoButton);
#endif


	keyboard.setAcceptVar(&settingsM.codeAccepted);



	std::vector<touchgfx::PainterRGB888*> painters;
	painters.push_back(&circleGearPainter);
	painters.push_back(&lineDecoPainter);
	painters.push_back(&shapePriorityPainter);


	ThemeFactory th(settingsM.user);
	th.bindBackground(imageBackground);
	th.bindColorSecondary(boxDeco, 1);
	th.bindColorSecondary(textConnection, 1);
	th.applyPainters(painters);


	mainScreenView::notificationInit( );
	mainScreenView::setupNotifications( );
	mainScreenViewBase::setupScreen( );
	mainScreenView::setupDisplay( );
	mainScreenView::setupButtonState( );

#ifndef DISABLE_DYNAMIC_BITMAP
	   BitmapId bmpId;
	    bmpId = Bitmap::dynamicBitmapCreate(100, 100, Bitmap::RGB565);

	    if (bmpId != BITMAP_INVALID)
	    {
	        //set all pixels white
	        uint16_t* const bitmapPixels = (uint16_t*)Bitmap::dynamicBitmapGetAddress(bmpId);
	        memset(bitmapPixels, 0xF81F, 100*100*2);

	        //first 200 pixels red, => two column on the right on display
	        for (int i = 0; i<200; i++) bitmapPixels[i] = 0x56c7;

	        //first two pixels in all rows green in bitmap => top two rows on display
	        for (int i = 0; i<100; i++)
	        {
	            bitmapPixels[i*100]     = 0x0000;
	            bitmapPixels[i*100 + 1] = 0x0000;
	        }
	    }

	    imageCameraDynamic.setBitmap(bmpId);
		add(imageCameraDynamic);
#endif

}
void mainScreenView::tearDownScreen( )
{

	listNotification.removeAll( );
	mainScreenViewBase::tearDownScreen( );
}

void mainScreenView::notificationInit( )
{
	plusImage.setAlpha(0);
	plusImage.startFadeAnimation(0, 20, touchgfx::EasingEquations::expoEaseInOut);
	plusImage.setFadeAnimationEndedAction(imageFadeAnimationEndedCallback);

	for (uint8_t i = 0; i < notificationSlots; i++)
	{
		notifications [i].setFadeAnimationEndedAction(containerFadeAnimationEndedCallback);
		notifications [i].startFadeAnimation(255, 15 + ( 5 * i ),
				touchgfx::EasingEquations::expoEaseInOut);
	}

}
void mainScreenView::tickView( )
{

	mainScreenView::updateGearDisp( );
	updateGauge();
	settingsM.lastCode = keyboard.getBuffer( );
	//imageCameraDynamic.invalidate();
	//imageCameraDynamic.setBitmap(Bitmap(bmpId));
	static int tickCount = 0;
	static int prevTickCount = 0;



	if (tickCount - prevTickCount > 60 * 1)
	{

		mainScreenView::updateNotifications( );
		listNotification.invalidateContent( );
		if (notificationFactory.getSize( )!=0){
			Unicode::snprintf(buttonNotificationBuffer, BUTTONNOTIFICATION_SIZE, "%d",
							notificationFactory.getSize( ));
		}else{
			Unicode::snprintf(buttonNotificationBuffer, BUTTONNOTIFICATION_SIZE,"");
		}

		if (controllerState.connected == 1)
		{
			char str[100];
			strcpy(str, "// Connected to ");
			strcat(str, controllerState.connectedTruckNameCP);

			Unicode::snprintf(textConnectionBuffer, TEXTCONNECTION_SIZE,str);
			textConnection.invalidate();
		}else{
			Unicode::snprintf(textConnectionBuffer, TEXTCONNECTION_SIZE,
					"/// Controller disconnected");
			textConnection.invalidate();
		}

		prevTickCount = tickCount;
	}


	tickCount++;


#ifdef ENABLE_DUMMY_MODE
	gaugesMain.setGaugeL((tickCount/5)%100);
	gaugesMain.setGaugeR((tickCount/3)%100);


	gaugesMain.setBatteryController((tickCount/35)%100);
	gaugesMain.setBatteryVehicle((tickCount/15)%100);

	if (gaugesMain.getValueL()>80){
		gaugesMain.gearUp(1);
	}
	if (gaugesMain.getValueL()<10){
		gaugesMain.gearUp(0);
	}
	if (gaugesMain.getValueL()<10){
		gaugesMain.gearDown(1);
	}
	if (gaugesMain.getValueL()>20){
		gaugesMain.gearDown(0);
	}

#endif


	buttonNotification.invalidate( );

#ifdef ENABLE_DEBUG_PRINTER
	mainScreenView::updateDebugString( );
#endif
}
void mainScreenView::updateGearDisp( )
{

	if (controllerState.axis.direction >= 50)
	{
		Unicode::snprintf(textGearBuffer, TEXTGEAR_SIZE,"%d", controllerState.gear);
	}else{
		Unicode::snprintf(textGearBuffer, TEXTGEAR_SIZE,"R%d", controllerState.gear);
	}



	gearIcon = BITMAP_NOGEAR_ID;

	if (controllerState.gear == 1 && controllerState.axis.direction > 50)
	{
		gearIcon = BITMAP_FIRSTFORWARD_ID;
	}
	if (controllerState.gear == 2 and controllerState.axis.direction > 50)
	{
		gearIcon = BITMAP_SECONDFORWARD_ID;
	}
	if (controllerState.gear == 3 and controllerState.axis.direction > 50)
	{
		gearIcon = BITMAP_THIRDFORWARD_ID;
	}
	if (controllerState.gear == 1 and controllerState.axis.direction < 50)
	{
		gearIcon = BITMAP_FIRSTREVERSE_ID;
	}
	if (controllerState.gear == 2 and controllerState.axis.direction < 50)
	{
		gearIcon = BITMAP_SECONDREVERSE_ID;
	}
	if (controllerState.gear == 3 and controllerState.axis.direction < 50)
	{
		gearIcon = BITMAP_THIRDREVERSE_ID;
	}

	imageGear.setBitmap(gearIcon);
	slideGear.invalidateContent();
}


void mainScreenView::updateDebugString( )
{
	static int count = 0;
	count++;
//	const char *debugInfo = " Integrity: %d \n GFX: %d \n IO: %s \n size in words";
//	snprintf(debugStringBuffer, sizeof ( debugStringBuffer ), debugInfo,
//			settingsM.uxHighWaterMarkIntegrity, settingsM.uxHighWaterMarkGFX,
//			settingsM.uxHighWaterMarkIO);

	const char *debugInfo =
			"\n startB:%04X lenHI:%04X lenLO:%04X API:%04X frID:%04X"
			"\n HIaddr:%04X LOaddr:%04X Opt:%04X"
			"\n D:"
			"\n         %04X %04X id/cmp"
			"\n         %04X %04X ve/tr"
			"\n         %04X %04X lt/lt2"
			"\n         %04X %04X cx/cy"
			"\n         %04X %04X gr/j1y"
			"\n         %04X %04X j1x/cs"
			"\n %04X %04X"
			"\n %04X %04X"
			"\n %04X %04X"
			"\n %04X %04X"
			"\n %04X %04X";
		snprintf(debugStringBuffer, sizeof ( debugStringBuffer ), debugInfo,
				encoder.tmpArr[0], encoder.tmpArr[1],	encoder.tmpArr[2], encoder.tmpArr[3], encoder.tmpArr[4],
				encoder.tmpArr[5], encoder.tmpArr[6], encoder.tmpArr[7], encoder.tmpArr[8], encoder.tmpArr[9],
				encoder.tmpArr[10], encoder.tmpArr[11], encoder.tmpArr[12], encoder.tmpArr[13], encoder.tmpArr[14],
				encoder.tmpArr[15], encoder.tmpArr[16], encoder.tmpArr[17], encoder.tmpArr[18], encoder.tmpArr[19],
				encoder.tmpArr[20], encoder.tmpArr[21], encoder.tmpArr[22], encoder.tmpArr[23], encoder.tmpArr[24],
				encoder.tmpArr[25], encoder.tmpArr[26], encoder.tmpArr[27], encoder.tmpArr[28], encoder.tmpArr[29]);

	Application::getDebugPrinter( )->setScale(2);
	Application::getDebugPrinter( )->setString(debugStringBuffer);
	Application::invalidateDebugRegion( );
}
void mainScreenView::setupButtonState( )
{

}
void mainScreenView::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer &src)
{

	if(&src == &buttonJoystick)
	{
		settingsM.settingsScreenMenuNumber = 2;
		application().gotosettingsScreenScreenSlideTransitionNorth();
	}
	if (&src == &hideButton)
	{
		slideKeypad.animateToState(SlideMenu::COLLAPSED);
		slideBar.animateToState(SlideMenu::COLLAPSED);
		slideGear.animateToState(SlideMenu::COLLAPSED);
	}


	if (&src == &buttonGearUp)
	{
		if(controllerState.gear != controllerState.maxGear)
		{
			controllerState.gear++;
		}

	}
	if (&src == &buttonGearDown)
	{
		if(controllerState.gear != controllerState.minGear)
		{
			controllerState.gear--;
		}
	}
}
void mainScreenView::setupDisplay( )
{

	if(settingsM.gaugesActive){
		gaugesMain.setVisible(1);
	}else{
		gaugesMain.setVisible(0);
	}


}
void mainScreenView::setupNotifications( )
{
	std::vector <Notification> notify1 = notificationFactory.getNotifications( );

	if (notificationFactory.getSize( ) <= notificationSlots)
	{
		for (uint8_t i = 0; i < notificationFactory.getSize( ); i++)
		{
			if (i == notificationSlots)
			{
				return;
			}
			NotificationFactory::generateWidgets(notify1 [i], notifications [i],
					notification::mainScreen);
			listNotification.add(notifications [i]);
		}
	}
	if (notificationFactory.getSize( ) > notificationSlots)
	{
		for (uint8_t i = 0; i < notificationFactory.getSize( ); i++)
		{
			if (i < notificationSlots - 1)
			{
				NotificationFactory::generateWidgets(notify1 [i], notifications [i],
						notification::mainScreen);
				listNotification.add(notifications [i]);
			}
		}
		listNotification.add(plusImage);
	}
}
void mainScreenView::updateNotifications( )
{
	listNotification.removeAll( );
	mainScreenView::setupNotifications( );
	mainScreenView::notificationsFadeStart( );
	buttonNotification.invalidate( );
	listNotification.childGeometryChanged( );
	listNotification.invalidate( );
	listNotification.invalidateContent( );
}
void mainScreenView::notificationsFadeStart( )
{
	for (uint8_t i = 0; i < notificationSlots; i++)
	{
		if (notifications [i].isFadeAnimationRunning( ) == 0
				&& notifications [i].getPriority( ) < settingsM.maxBlinkPriority)
		{
			notifications [i].setAlpha(0);
			//notifications [i].setFadeAnimationDelay(i);
			notifications [i].startFadeAnimation(255, 30 + i,
					touchgfx::EasingEquations::expoEaseInOut);
		}
	}
}
void mainScreenView::imageFadeAnimationEndedHandler(
		const touchgfx::FadeAnimator <touchgfx::Image> &comp)
{
	if (&comp == &plusImage)
	{
		if (plusImage.getAlpha( ) == 0)
		{
			plusImage.startFadeAnimation(255, 30, touchgfx::EasingEquations::expoEaseInOut);
		}
		if (plusImage.getAlpha( ) == 255)
		{
			plusImage.startFadeAnimation(0, 50, touchgfx::EasingEquations::expoEaseInOut);
		}
	}
}
void mainScreenView::containerFadeAnimationEndedHandler(
		const touchgfx::FadeAnimator <notificationContainer> &comp)
{
	for (uint8_t i = 0; i < notificationSlots; i++)
	{
		if (&comp == &notifications [i]
				&& notifications [i].getPriority( ) < settingsM.maxBlinkPriority)
		{
			if (notifications [i].getAlpha( ) == 30)
			{
				notifications [i].startFadeAnimation(255, 30,
						touchgfx::EasingEquations::expoEaseInOut);
			}
			if (notifications [i].getAlpha( ) == 255)
			{
				notifications [i].startFadeAnimation(30, 30,
						touchgfx::EasingEquations::expoEaseInOut);
			}
		}
	}
}
void mainScreenView::updateGauge(){
	gaugesMain.setBatteryController(controllerState.batteryChargeController);
	gaugesMain.setBatteryVehicle(controllerState.batteryChargeVehicle);
	gaugesMain.setGaugeR(controllerState.axis.direction);
	gaugesMain.setGear(controllerState.gear);
}
