#include <gui/settingsscreen_screen/settingsScreenView.hpp>
#include "integrityManager.hpp"
#include "ControllerSettings.hpp"
#include "integrityManager.hpp"
#include <images/BitmapDatabase.hpp>
#include "ThemeFactory.hpp"

#include "SetupSettings.hpp"

extern ControllerSettings settingsM;
char debugStringBufferSize [80];

settingsScreenView::settingsScreenView( ) :
		buttonCallback(this, &settingsScreenView::buttonCallbackHandler), sliderValueChangedCallback(
				this, &settingsScreenView::sliderValueChangedCallbackHandler), sliderValueEndChangedCallback(
				this, &settingsScreenView::sliderValueEndChangedCallbackHandler), flexButtonCallback(
				this, &settingsScreenView::flexButtonCallbackHandler), radioButtonSelectedCallback(
				this, &settingsScreenView::radioButtonSelectedCallbackHandler)
{




#ifdef ENABLE_DUMMY_MODE
	toggleUSBcharge.setText("Enable USB charging");
	toggleUSBcharge.setIcon(BITMAP_BOLT_FILL0_WGHT100_GRAD200_OPSZ24_ID);

	toggle3D.setText("Enable 3D steering");
	toggle3D.setIcon(BITMAP_OUTLINE_3D_ROTATION_WHITE_24DP_ID);

	toggleEnergySaving.setText("Enable energy saving");
	toggleEnergySaving.setIcon(BITMAP_BOLT_FILL0_WGHT100_GRAD200_OPSZ24_ID);

	toggleAudio.setText("Enable audio output");
	toggleAudio.setIcon(BITMAP_NOTIFICATIONS_FILL0_WGHT100_GRAD200_OPSZ24_ID);

	listToggle.add(toggle3D);
	listToggle.add(toggleUSBcharge);
	listToggle.add(toggleAudio);
	listToggle.add(toggleEnergySaving);
#endif

	buttonAudio.setAction(flexButtonCallback);
	flexButton1_1.setAction(flexButtonCallback);


	buttonJoy1x.setAction(flexButtonCallback);
	buttonJoy1y.setAction(flexButtonCallback);
	buttonJoy2x.setAction(flexButtonCallback);
	buttonJoy2y.setAction(flexButtonCallback);
	buttonJoyTrigg.setAction(flexButtonCallback);

	buttonSelectionSpeed.setAction(flexButtonCallback);
	buttonSelectionDirection.setAction(flexButtonCallback);
	buttonSelectionCamX.setAction(flexButtonCallback);
	buttonSelectionCamY.setAction(flexButtonCallback);
	buttonAccept.setAction(flexButtonCallback);
	buttonDefault.setAction(flexButtonCallback);
	buttonEmpty.setAction(flexButtonCallback);
	buttonInvert.setAction(flexButtonCallback);


	buttonMain.setAction(buttonCallback);

	toggleGauges.setText("Enable gauges on MS");
	toggleGauges.setIcon(BITMAP_SPEED_FILL0_WGHT100_GRAD200_OPSZ24_ID);

	toggleScreen.setText("Leave the screen on");
	toggleScreen.setIcon(BITMAP_PACE_FILL0_WGHT100_GRAD200_OPSZ24_ID);

	toggleKeypad.setText("Enable Keypad on MS");
	toggleKeypad.setIcon(BITMAP_KEYBOARD_FILL0_WGHT100_GRAD200_OPSZ24_ID);

	toggleVideoTask.setText("Enable video processing");
	toggleVideoTask.setIcon(BITMAP_VIDEOCAM_FILL0_WGHT100_GRAD200_OPSZ24_ID);

	div1.setText("Other");
	div2.setText("Main screen");
	lineDiv1.setText("Priority:");
	lineDiv2.setText("Advanced:");


	listToggle.add(div2);
	listToggle.add(toggleGauges);
	listToggle.add(toggleKeypad);
	listToggle.add(div1);
	listToggle.add(toggleScreen);
	listToggle.add(toggleVideoTask);
//	listToggle.add(lineDiv2);

	notificationBlink.setColor(255, 0, 0);
	notificationBlink.setMaxVal(10);
	notificationBlink.setMinVal(0);
	notificationBlink.setText("Notification blink");
	notificationBlink.setText2("max priority to blink");
	notificationBlink.setIcon(BITMAP_NOTIFICATIONS_FILL0_WGHT100_GRAD200_OPSZ24_ID);


	//toggleGauges.bind(&settingsM.gaugesActive);

	uartTime.setColor(255, 0, 0);
	uartTime.setMaxVal(200);
	uartTime.setMinVal(20);
	uartTime.setText("UART send time");
	uartTime.setText2("Time between messages send via uart");
	uartTime.setIcon(BITMAP_PACE_FILL0_WGHT100_GRAD200_OPSZ24_ID);

	sleepTime.setColor(0, 130, 22);
	sleepTime.setMaxVal(255);
	sleepTime.setMinVal(5);
	sleepTime.setText("Sleep time");
	sleepTime.setText2("time to turn screen off");
	sleepTime.setIcon(BITMAP_PACE_FILL0_WGHT100_GRAD200_OPSZ24_ID);


	modeSelect.setColor(55,55,55);
	modeSelect.setMaxVal(4);
	modeSelect.setMinVal(1);
	modeSelect.setText("Steering Presset");
	modeSelect.setIcon(BITMAP_JOYSTICK_FILL0_WGHT100_GRAD200_OPSZ24_ID);
	std::vector<std::string> modes={"","Basic","Hardware","Lights Controll","Empty preset"};
	modeSelect.setVariableBottomText();
	modeSelect.setIncrementText(modes);
	modeSelect.bind(&settingsM.selectedSteeringMode);

	//BITMAP_PACE_FILL0_WGHT100_GRAD200_OPSZ24_ID
	idleTime.setColor(170, 100, 50);
	idleTime.setMaxVal(255);
	idleTime.setMinVal(30);
	idleTime.setText("idle time");
	idleTime.setText2("time to suspend");
	idleTime.setIcon(BITMAP_PACE_FILL0_WGHT100_GRAD200_OPSZ24_ID);

	sliderSmooth.setNewValueCallback(sliderValueChangedCallback);
	sliderExpo.setNewValueCallback(sliderValueChangedCallback);
	sliderDeadzone.setNewValueCallback(sliderValueChangedCallback);
	sliderTopVal.setNewValueCallback(sliderValueChangedCallback);



}

void settingsScreenView::setupScreen( )
{
	settingsScreenViewBase::setupScreen( );

    selected=NULL;
    inversion=NULL;
    dst=NULL;
	toggleGauges.forceState(settingsM.gaugesActive);
	toggleScreen.forceState(settingsM.screenBlackout);
	toggleKeypad.forceState(settingsM.keypadEnable);
	toggleVideoTask.forceState(settingsM.videoTaskEnable);
	buttonAudio.ToggleButtonTrigger::forceState(settingsM.audioToggle);
	buttonAudio.invalidate( );

	std::vector<touchgfx::PainterRGB888*> painters;
	painters.push_back(&lineDecoScroll1Painter);
	painters.push_back(&lineDecoScroll2Painter);
	painters.push_back(&lineDeco2Painter);
	painters.push_back(&lineDecoPainter);
	painters.push_back(&lineDecoScrollModal1Painter);
	painters.push_back(&lineDecoScrollModal2Painter);
	painters.push_back(&lineDecoScrollJoyPainter);
	painters.push_back(&lineDecoScrollJoy2Painter);
	painters.push_back(&circleDecoPainter);
	painters.push_back(&shapeModalPainter);
	painters.push_back(&graphExpoLine1Painter);



	ThemeFactory th(settingsM.user);
	th.bindBackground(background);
	th.applyPainters(painters);
	th.bindColor(div1);
	th.bindColor(div2);
	th.bindColor(lineDiv1);
	th.bindColorSecondary(sleepTime);
	th.bindColorSecondary(idleTime);
	th.bindColorSecondary(notificationBlink);
	th.bindColorSecondary(modeSelect);
	th.bindColorSecondary(uartTime);


	notificationBlink.setValue(settingsM.maxBlinkPriority);
	sleepTime.setValue(settingsM.timeToScreenSleep);
	idleTime.setValue(settingsM.timeToIdle);
	modeSelect.setValue(settingsM.selectedSteeringMode);
	uartTime.setValue(settingsM.uartTimeDelay);

	swipeContainer.setSelectedPage(settingsM.settingsScreenMenuNumber);

	sliderExpo.setValue(settingsM.expoSlider);
	sliderSmooth.setValue(settingsM.smoothSlider);
	sliderDeadzone.setValue(settingsM.deadzoneSlider);
	sliderTopVal.setValue(settingsM.topValueCutoff);

	graphExpoOverlay.clear();
	for (float x = 0; x < 102; x+=0.3)
	{
	graphExpoOverlay.addDataPoint(x,x);
	}
	graphExpoOverlay.invalidate();

}

void settingsScreenView::tearDownScreen( )
{
	settingsM.settingsScreenMenuNumber = swipeContainer.getSelectedPage( );
	settingsM.maxBlinkPriority = notificationBlink.getValue( );
	settingsM.timeToScreenSleep = sleepTime.getValue( );
	settingsM.timeToIdle = idleTime.getValue( );
	//settingsM.deadzoneSlider = sliderDeadzone.getValue();
	settingsM.selectedSteeringMode = modeSelect.getValue();
	settingsM.uartTimeDelay = uartTime.getValue();

	settingsM.gaugesActive = toggleGauges.getState( );
	settingsM.screenBlackout = toggleScreen.getState();
	settingsM.keypadEnable = toggleKeypad.getState();
	settingsM.videoTaskEnable = toggleVideoTask.getState();
	settingsScreenViewBase::tearDownScreen( );
}

void settingsScreenView::tickView( )
{
	Unicode::snprintf(textTopButtonBuffer, TEXTTOPBUTTON_SIZE,settingsM.topButtonText.c_str());
	Unicode::snprintf(textLeftButtonBuffer, TEXTTOPBUTTON_SIZE,settingsM.leftButtonText.c_str());
	Unicode::snprintf(textRightButtonBuffer, TEXTTOPBUTTON_SIZE,settingsM.rightButtonText.c_str());
	Unicode::snprintf(textBottomButtonBuffer, TEXTTOPBUTTON_SIZE,settingsM.bottomButtonText.c_str());

	textBottomButton.invalidate();
	textTopButton.invalidate();
	textRightButton.invalidate();
	textLeftButton.invalidate();




#ifdef ENABLE_DEBUG_PRINTER
	settingsScreenView::updateDebugString( );
#endif

}
void settingsScreenView::updateDebugString( )
{
	static int count = 0;
	count++;
	const char *debugInfo = "%d :value";
	snprintf(debugStringBufferSize, sizeof ( debugStringBufferSize ), debugInfo,
			settingsM.gaugesActive);

	Application::getDebugPrinter( )->setString(debugStringBufferSize);
	Application::invalidateDebugRegion( );
}

void settingsScreenView::buttonCallbackHandler(const touchgfx::AbstractButton &src)
{
	if (&src == &buttonMain)
	{
		//transitionMain
		//When buttonMain clicked change screen to mainScreen
		//Go to mainScreen with screen transition towards South
		application( ).gotomainScreenScreenSlideTransitionSouth( );
	}

}

void settingsScreenView::sliderValueChangedCallbackHandler(const touchgfx::Slider &src, int value)
{
	if (&src == &sliderSmooth)
	{
		settingsM.smoothSlider = value;
	}
	if (&src == &sliderExpo)
	{
		settingsM.expoSlider = value;
		settingsScreenView::graphAnim();
	}
	if (&src == &sliderDeadzone)
	{
		settingsM.deadzoneSlider = value;
		settingsScreenView::graphAnim();
	}
	if (&src == &sliderTopVal)
	{
		settingsM.topValueCutoff = value;
		settingsScreenView::graphAnim();
	}



}
void settingsScreenView::sliderValueEndChangedCallbackHandler(const touchgfx::Slider &src,
		int value)
{


}


void settingsScreenView::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer &src)
{


	//dst=textActual3Buffer;

	if (&src == &buttonAudio)
	{
		controllerState.truckType = TruckType::roadAssist;
	}
	if (&src == &flexButton1_1)
	{
		controllerState.truckType = TruckType::truck;
	}


	if (&src == &buttonDefault)
	{
		settingsM.directionAxis = &controllerState.joyData.joy1x;
		settingsM.turnAxis = &controllerState.joyData.joy1y;
		settingsM.camxAxis = &controllerState.joyData.joy2x;
		settingsM.camyAxis = &controllerState.joyData.joy2y;
		settingsM.gearUpAxis = &controllerState.joyData.bttn1;
		settingsM.gearDownAxis = &controllerState.joyData.bttn2;

		Unicode::strncpy(textActual1Buffer, "Drive",15);
		Unicode::strncpy(textActual2Buffer, "Turn",15);
		Unicode::strncpy(textActual3Buffer, "CamX",15);
		Unicode::strncpy(textActual4Buffer, "CamY",15);
		Unicode::strncpy(textActual5Buffer, "empty",15);

	}
	if (&src == &buttonEmpty)
	{
		settingsM.directionAxis = &controllerState.noneVal;
		settingsM.turnAxis = &controllerState.noneVal;
		settingsM.camxAxis = &controllerState.noneVal;
		settingsM.camyAxis = &controllerState.noneVal;
		settingsM.gearUpAxis = &controllerState.noneVal;
		settingsM.gearDownAxis = &controllerState.noneVal;

		Unicode::strncpy(textActual1Buffer, "None",15);
		Unicode::strncpy(textActual2Buffer, "None",15);
		Unicode::strncpy(textActual3Buffer, "None",15);
		Unicode::strncpy(textActual4Buffer, "None",15);
		Unicode::strncpy(textActual5Buffer, "None",15);
		invalidate();
	}


	if (&src == &buttonJoy1x)
	{
		dst=textActual1Buffer;
		selected = &controllerState.joyData.joy1x;
		modalWindow.show();
	}
	if (&src == &buttonJoy1y)
	{
		dst=textActual2Buffer;
		selected = &controllerState.joyData.joy1y;
		modalWindow.show();
	}
	if (&src == &buttonJoy2x)
	{
		dst=textActual3Buffer;
		selected = &controllerState.joyData.joy2x;
		modalWindow.show();
	}
	if (&src == &buttonJoy2y)
	{
		dst=textActual4Buffer;
		selected = &controllerState.joyData.joy2y;
		modalWindow.show();
	}
	if (&src == &buttonJoyTrigg)
	{
		dst=textActual5Buffer;
		selected = &controllerState.joyData.trigg;
		modalWindow.show();
	}



	if (&src == &buttonSelectionSpeed)
	{
		settingsM.directionAxis = selected;
		inversion = &settingsM.directionInv;
		touchgfx::Unicode::snprintf(textInversionBuffer1, TEXTINVERSIONBUFFER2_SIZE,"Drive");
		touchgfx::Unicode::snprintf(textInversionBuffer2, TEXTINVERSIONBUFFER2_SIZE,(*inversion)? "Inverted" :"NonInverted");
		Unicode::strncpy(dst, "Drive",15);
		listActual.invalidateContent();
	}

	if (&src == &buttonSelectionDirection)
	{
		settingsM.turnAxis = selected;
		inversion = &settingsM.turnInv;
		touchgfx::Unicode::snprintf(textInversionBuffer1, TEXTINVERSIONBUFFER2_SIZE,"Turn");
		touchgfx::Unicode::snprintf(textInversionBuffer2, TEXTINVERSIONBUFFER2_SIZE,(*inversion)? "Inverted" :"NonInverted");
		Unicode::snprintf(dst, 15,"Turn");
		listActual.invalidateContent();
	}
	if (&src == &buttonSelectionCamX)
	{
		settingsM.camxAxis = selected;
		inversion = &settingsM.camxInv;
		Unicode::snprintf(dst, 15,"CamX");
		touchgfx::Unicode::snprintf(textInversionBuffer1, TEXTINVERSIONBUFFER2_SIZE,"CamX");
		touchgfx::Unicode::snprintf(textInversionBuffer2, TEXTINVERSIONBUFFER2_SIZE,(*inversion)? "Inverted" :"NonInverted");
		listActual.invalidateContent();
	}
	if (&src == &buttonSelectionCamY)
	{
		settingsM.camyAxis = selected;
		inversion = &settingsM.camyInv;
		Unicode::snprintf(dst, 15,"CamY");
		touchgfx::Unicode::snprintf(textInversionBuffer1, TEXTINVERSIONBUFFER2_SIZE,"CamY");
		touchgfx::Unicode::snprintf(textInversionBuffer2, TEXTINVERSIONBUFFER2_SIZE,(*inversion)? "Inverted" :"NonInverted");
		textInversion.invalidate();
		listActual.invalidateContent();
	}

	if (&src == &buttonAccept)
	{
		modalWindow.hide();
	}
	if (&src == &buttonInvert)
	{
		*inversion=!(*inversion);
		touchgfx::Unicode::snprintf(textInversionBuffer2, TEXTINVERSIONBUFFER2_SIZE,(*inversion)? "Inverted" :"NonInverted");
		textInversion.invalidate();
		modalWindow.invalidate();
	}
}

void settingsScreenView::radioButtonSelectedCallbackHandler(const touchgfx::AbstractButton &src)
{

}
void settingsScreenView::graphAnim()
{
	graphExpo.clear();
	for (float x = 0; x < 102; x+=0.3)
	{
		float _x = x;
		float val ;
		val = expoMap(x, settingsM.expoSlider/10, 50);
		if(val < 50+settingsM.deadzoneSlider/10 && val > 50-settingsM.deadzoneSlider/10)
		{
			val = 50;
		}
		if(val > 100-settingsM.topValueCutoff/10)
		{
			val = 100;
		}
		if (val< 0+settingsM.topValueCutoff/10)
		{
			val = 0;
		}
		graphExpo.addDataPoint(_x, val);
	}
	graphExpo.invalidate();
}
