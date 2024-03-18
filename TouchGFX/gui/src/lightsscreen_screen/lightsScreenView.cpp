#include <gui/lightsscreen_screen/lightsScreenView.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "InputOutputModel.hpp"
#include "SetupSettings.hpp"
#include "ThemeFactory.hpp"


lightsScreenView::lightsScreenView( ) :
		buttonCallback(this, &lightsScreenView::buttonCallbackHandler), flexButtonCallback(this,
				&lightsScreenView::flexButtonCallbackHandler)
{

	lowBeamsButton.setIconBitmaps(Bitmap(BITMAP_HIGHLIGHT_FILL0_WGHT100_GRAD200_OPSZ48_ID),
			Bitmap(BITMAP_HIGHLIGHT_FILL1_WGHT100_GRAD200_OPSZ48_ID));
	lowBeamsButton.setIconXY(0, 0);
	lowBeamsButton.setAction(flexButtonCallback);
	lowBeamsButton.setText(TypedText(T_LOWBEAMS));
	lowBeamsButton.setTextPosition(0, 42, 50, 60);
	lowBeamsButton.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255),
			touchgfx::Color::getColorFromRGB(94, 255, 0));
	lowBeamsButton.setWidth(50);
	lowBeamsButton.setHeight(60);

	highBeamsButton.setIconBitmaps(Bitmap(BITMAP_WB_INCANDESCENT_FILL0_WGHT100_GRAD200_OPSZ48_ID),
			Bitmap(BITMAP_WB_INCANDESCENT_FILL1_WGHT100_GRAD200_OPSZ48_ID));
	highBeamsButton.setIconXY(0, 0);
	highBeamsButton.setAction(flexButtonCallback);
	highBeamsButton.setText(TypedText(T_HIGHBEAMS));
	highBeamsButton.setTextPosition(0, 42, 50, 60);
	highBeamsButton.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255),
			touchgfx::Color::getColorFromRGB(94, 255, 0));
	highBeamsButton.setWidth(50);
	highBeamsButton.setHeight(60);

	topLightsButton.setIconBitmaps(Bitmap(BITMAP_E911_EMERGENCY_FILL0_WGHT100_GRAD200_OPSZ48_ID),
			Bitmap(BITMAP_E911_EMERGENCY_FILL1_WGHT100_GRAD200_OPSZ48_ID));
	topLightsButton.setIconXY(0, 0);
	topLightsButton.setAction(flexButtonCallback);
	topLightsButton.setText(TypedText(T_TOPLIGHTS));
	topLightsButton.setTextPosition(0, 42, 50, 60);
	topLightsButton.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255),
			touchgfx::Color::getColorFromRGB(94, 255, 0));
	topLightsButton.setWidth(50);
	topLightsButton.setHeight(60);

	posLightsButton.setIconBitmaps(Bitmap(BITMAP_WB_SUNNY_FILL0_WGHT100_GRAD200_OPSZ48_ID),
			Bitmap(BITMAP_WB_SUNNY_FILL1_WGHT100_GRAD200_OPSZ48_ID));
	posLightsButton.setIconXY(0, 0);
	posLightsButton.setAction(flexButtonCallback);
	posLightsButton.setText(TypedText(T_POSLIGHTS));
	posLightsButton.setTextPosition(0, 42, 50, 60);
	posLightsButton.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255),
			touchgfx::Color::getColorFromRGB(94, 255, 0));
	posLightsButton.setWidth(50);
	posLightsButton.setHeight(60);

	hazardsButton.setIconBitmaps(Bitmap(BITMAP_EMERGENCY_HOME_FILL0_WGHT100_GRAD200_OPSZ48_ID),
			Bitmap(BITMAP_EMERGENCY_HOME_FILL1_WGHT100_GRAD200_OPSZ48_ID));
	hazardsButton.setIconXY(0, 0);
	hazardsButton.setAction(flexButtonCallback);
	hazardsButton.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255),
			touchgfx::Color::getColorFromRGB(94, 255, 0));
	hazardsButton.setWidth(50);
	hazardsButton.setHeight(60);

	leftBlinkerButton.setIconBitmaps(Bitmap(BITMAP_ARROW_BACK_FILL0_WGHT100_GRAD200_OPSZ48_ID),
			Bitmap(BITMAP_ARROW_BACK_FILL1_WGHT300_GRAD200_OPSZ48_ID));
	leftBlinkerButton.setIconXY(0, 0);
	leftBlinkerButton.setAction(flexButtonCallback);
	leftBlinkerButton.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255),
			touchgfx::Color::getColorFromRGB(94, 255, 0));
	leftBlinkerButton.setWidth(50);
	leftBlinkerButton.setHeight(60);

	rightBlinkerButton.setIconBitmaps(Bitmap(BITMAP_ARROW_FORWARD_FILL0_WGHT100_GRAD200_OPSZ48_ID),
			Bitmap(BITMAP_ARROW_FORWARD_FILL1_WGHT300_GRAD200_OPSZ48_ID));
	rightBlinkerButton.setIconXY(0, 0);
	rightBlinkerButton.setAction(flexButtonCallback);
	rightBlinkerButton.setTextColors(touchgfx::Color::getColorFromRGB(255, 5, 255),
			touchgfx::Color::getColorFromRGB(94, 255, 0));
	rightBlinkerButton.setWidth(50);
	rightBlinkerButton.setHeight(60);

	fogLightsFrontButton.setIconBitmaps(
			Bitmap(BITMAP_WB_TWILIGHT_FILL0_WGHT100_GRAD200_OPSZ48_3_ID),
			Bitmap(BITMAP_WB_TWILIGHT_FILL1_WGHT100_GRAD200_OPSZ48_ID));
	fogLightsFrontButton.setIconXY(0, 0);
	fogLightsFrontButton.setAction(flexButtonCallback);
	fogLightsFrontButton.setText(TypedText(T_FOGLIGHTSFRONT));
	fogLightsFrontButton.setTextPosition(0, 42, 50, 60);
	fogLightsFrontButton.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255),
			touchgfx::Color::getColorFromRGB(94, 255, 0));
	fogLightsFrontButton.setWidth(50);
	fogLightsFrontButton.setHeight(60);

	fogLightsRearButton.setIconBitmaps(Bitmap(BITMAP_WB_TWILIGHT_FILL0_WGHT100_GRAD200_OPSZ48_2_ID),
			Bitmap(BITMAP_WB_TWILIGHT_FILL1_WGHT100_GRAD200_OPSZ48_2_ID));
	fogLightsRearButton.setIconXY(0, 0);
	fogLightsRearButton.setAction(flexButtonCallback);
	fogLightsRearButton.setText(TypedText(T_FOGLIGHTSREAR));
	fogLightsRearButton.setTextPosition(0, 42, 50, 60);
	fogLightsRearButton.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255),
			touchgfx::Color::getColorFromRGB(94, 255, 0));
	fogLightsRearButton.setWidth(50);
	fogLightsRearButton.setHeight(60);

	gearUpButton.setIconBitmaps(Bitmap(BITMAP_EXPAND_LESS_FILL0_WGHT100_GRAD200_OPSZ48_ID),
			Bitmap(BITMAP_EXPAND_LESS_FILL0_WGHT100_GRAD200_OPSZ48_ID));
	gearUpButton.setIconXY(0, 0);
	gearUpButton.setAction(flexButtonCallback);
	gearUpButton.setTextColors(touchgfx::Color::getColorFromRGB(255, 5, 255),
			touchgfx::Color::getColorFromRGB(94, 255, 0));
	gearUpButton.setWidth(50);
	gearUpButton.setHeight(60);

	gearDownButton.setIconBitmaps(Bitmap(BITMAP_EXPAND_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID),
			Bitmap(BITMAP_EXPAND_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID));
	gearDownButton.setIconXY(0, 0);
	gearDownButton.setAction(flexButtonCallback);
	gearDownButton.setTextColors(touchgfx::Color::getColorFromRGB(255, 5, 255),
			touchgfx::Color::getColorFromRGB(94, 255, 0));
	gearDownButton.setWidth(50);
	gearDownButton.setHeight(60);

	hornButton.setIconBitmaps(Bitmap(BITMAP_NOTIFICATIONS_ACTIVE_FILL0_WGHT100_GRAD200_OPSZ48_ID),
			Bitmap(BITMAP_NOTIFICATIONS_ACTIVE_FILL0_WGHT100_GRAD200_OPSZ48_ID));
	hornButton.setIconXY(0, 0);
	hornButton.setAction(flexButtonCallback);
	hornButton.setTextColors(touchgfx::Color::getColorFromRGB(255, 5, 255),
			touchgfx::Color::getColorFromRGB(94, 255, 0));
	hornButton.setWidth(50);
	hornButton.setHeight(60);

	axleLiftingButton.setIconBitmaps(Bitmap(BITMAP_DOWNLOAD_FILL0_WGHT100_GRAD200_OPSZ48_ID),
			Bitmap(BITMAP_DOWNLOAD_FILL0_WGHT100_GRAD200_OPSZ48_ID));
	axleLiftingButton.setIconXY(0, 0);
	axleLiftingButton.setAction(flexButtonCallback);
	axleLiftingButton.setText(TypedText(T_AXLELIFTING));
	axleLiftingButton.setTextPosition(0, 42, 50, 60);
	axleLiftingButton.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255),
			touchgfx::Color::getColorFromRGB(94, 255, 0));
	axleLiftingButton.setWidth(50);
	axleLiftingButton.setHeight(60);

	trailerConnectButton.setIconBitmaps(Bitmap(BITMAP_RV_HOOKUP_FILL0_WGHT100_GRAD200_OPSZ48_ID),
			Bitmap(BITMAP_RV_HOOKUP_FILL0_WGHT100_GRAD200_OPSZ48_ID));
	trailerConnectButton.setIconXY(0, 0);
	trailerConnectButton.setAction(flexButtonCallback);
	trailerConnectButton.setText(TypedText(T_TRAILERCONNECT));
	trailerConnectButton.setTextPosition(0, 42, 50, 60);
	trailerConnectButton.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255),
			touchgfx::Color::getColorFromRGB(94, 255, 0));
	trailerConnectButton.setWidth(50);
	trailerConnectButton.setHeight(60);

// roadAssist buttons

	firstWinchUpButton.setIconBitmaps(Bitmap(BITMAP_EXPAND_LESS_FILL0_WGHT100_GRAD200_OPSZ48_ID),
			Bitmap(BITMAP_EXPAND_LESS_FILL0_WGHT100_GRAD200_OPSZ48_ID));
	firstWinchUpButton.setIconXY(0, 0);
	firstWinchUpButton.setAction(flexButtonCallback);
	firstWinchUpButton.setTextColors(touchgfx::Color::getColorFromRGB(255, 5, 255),
			touchgfx::Color::getColorFromRGB(94, 255, 0));
	firstWinchUpButton.setWidth(50);
	firstWinchUpButton.setHeight(60);

	firstWinchDownButton.setIconBitmaps(Bitmap(BITMAP_EXPAND_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID),
			Bitmap(BITMAP_EXPAND_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID));
	firstWinchDownButton.setIconXY(0, 0);
	firstWinchDownButton.setAction(flexButtonCallback);
	firstWinchDownButton.setTextColors(touchgfx::Color::getColorFromRGB(255, 5, 255),
			touchgfx::Color::getColorFromRGB(94, 255, 0));
	firstWinchDownButton.setWidth(50);
	firstWinchDownButton.setHeight(60);

	secondWinchUpButton.setIconBitmaps(Bitmap(BITMAP_EXPAND_LESS_FILL0_WGHT100_GRAD200_OPSZ48_ID),
			Bitmap(BITMAP_EXPAND_LESS_FILL0_WGHT100_GRAD200_OPSZ48_ID));
	secondWinchUpButton.setIconXY(0, 0);
	secondWinchUpButton.setAction(flexButtonCallback);
	secondWinchUpButton.setTextColors(touchgfx::Color::getColorFromRGB(255, 5, 255),
			touchgfx::Color::getColorFromRGB(94, 255, 0));
	secondWinchUpButton.setWidth(50);
	secondWinchUpButton.setHeight(60);

	secondWinchDownButton.setIconBitmaps(Bitmap(BITMAP_EXPAND_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID),
			Bitmap(BITMAP_EXPAND_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID));
	secondWinchDownButton.setIconXY(0, 0);
	secondWinchDownButton.setAction(flexButtonCallback);
	secondWinchDownButton.setTextColors(touchgfx::Color::getColorFromRGB(255, 5, 255),
			touchgfx::Color::getColorFromRGB(94, 255, 0));
	secondWinchDownButton.setWidth(50);
	secondWinchDownButton.setHeight(60);

	rightSupportRetrtactButton.setIconBitmaps(
			Bitmap(BITMAP_EXPAND_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID),
			Bitmap(BITMAP_EXPAND_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID));
	rightSupportRetrtactButton.setIconXY(0, 0);
	rightSupportRetrtactButton.setAction(flexButtonCallback);
	rightSupportRetrtactButton.setTextColors(touchgfx::Color::getColorFromRGB(255, 5, 255),
			touchgfx::Color::getColorFromRGB(94, 255, 0));
	rightSupportRetrtactButton.setWidth(50);
	rightSupportRetrtactButton.setHeight(60);

	leftSupportRetrtactButton.setIconBitmaps(
			Bitmap(BITMAP_EXPAND_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID),
			Bitmap(BITMAP_EXPAND_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID));
	leftSupportRetrtactButton.setIconXY(0, 0);
	leftSupportRetrtactButton.setAction(flexButtonCallback);
	leftSupportRetrtactButton.setTextColors(touchgfx::Color::getColorFromRGB(255, 5, 255),
			touchgfx::Color::getColorFromRGB(94, 255, 0));
	leftSupportRetrtactButton.setWidth(50);
	leftSupportRetrtactButton.setHeight(60);

	rightSupportEjectButton.setIconBitmaps(
			Bitmap(BITMAP_EXPAND_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID),
			Bitmap(BITMAP_EXPAND_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID));
	rightSupportEjectButton.setIconXY(0, 0);
	rightSupportEjectButton.setAction(flexButtonCallback);
	rightSupportEjectButton.setTextColors(touchgfx::Color::getColorFromRGB(255, 5, 255),
			touchgfx::Color::getColorFromRGB(94, 255, 0));
	rightSupportEjectButton.setWidth(50);
	rightSupportEjectButton.setHeight(60);

	leftSupportEjectButton.setIconBitmaps(
			Bitmap(BITMAP_EXPAND_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID),
			Bitmap(BITMAP_EXPAND_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID));
	leftSupportEjectButton.setIconXY(0, 0);
	leftSupportEjectButton.setAction(flexButtonCallback);
	leftSupportEjectButton.setTextColors(touchgfx::Color::getColorFromRGB(255, 5, 255),
			touchgfx::Color::getColorFromRGB(94, 255, 0));
	leftSupportEjectButton.setWidth(50);
	leftSupportEjectButton.setHeight(60);

	armRetractButton.setIconBitmaps(Bitmap(BITMAP_EXPAND_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID),
			Bitmap(BITMAP_EXPAND_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID));
	armRetractButton.setIconXY(0, 0);
	armRetractButton.setAction(flexButtonCallback);
	armRetractButton.setTextColors(touchgfx::Color::getColorFromRGB(255, 5, 255),
			touchgfx::Color::getColorFromRGB(94, 255, 0));
	armRetractButton.setWidth(50);
	armRetractButton.setHeight(60);

	armEjectButton.setIconBitmaps(Bitmap(BITMAP_EXPAND_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID),
			Bitmap(BITMAP_EXPAND_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID));
	armEjectButton.setIconXY(0, 0);
	armEjectButton.setAction(flexButtonCallback);
	armEjectButton.setTextColors(touchgfx::Color::getColorFromRGB(255, 5, 255),
			touchgfx::Color::getColorFromRGB(94, 255, 0));
	armEjectButton.setWidth(50);
	armEjectButton.setHeight(60);

	armUpButton.setIconBitmaps(Bitmap(BITMAP_EXPAND_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID),
			Bitmap(BITMAP_EXPAND_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID));
	armUpButton.setIconXY(0, 0);
	armUpButton.setAction(flexButtonCallback);
	armUpButton.setTextColors(touchgfx::Color::getColorFromRGB(255, 5, 255),
			touchgfx::Color::getColorFromRGB(94, 255, 0));
	armUpButton.setWidth(50);
	armUpButton.setHeight(60);

	armDownButton.setIconBitmaps(Bitmap(BITMAP_EXPAND_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID),
			Bitmap(BITMAP_EXPAND_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID));
	armDownButton.setIconXY(0, 0);
	armDownButton.setAction(flexButtonCallback);
	armDownButton.setTextColors(touchgfx::Color::getColorFromRGB(255, 5, 255),
			touchgfx::Color::getColorFromRGB(94, 255, 0));
	armDownButton.setWidth(50);
	armDownButton.setHeight(60);

	forkRetractButton.setIconBitmaps(Bitmap(BITMAP_EXPAND_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID),
			Bitmap(BITMAP_EXPAND_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID));
	forkRetractButton.setIconXY(0, 0);
	forkRetractButton.setAction(flexButtonCallback);
	forkRetractButton.setTextColors(touchgfx::Color::getColorFromRGB(255, 5, 255),
			touchgfx::Color::getColorFromRGB(94, 255, 0));
	forkRetractButton.setWidth(50);
	forkRetractButton.setHeight(60);

	forkEjectButton.setIconBitmaps(Bitmap(BITMAP_EXPAND_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID),
			Bitmap(BITMAP_EXPAND_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID));
	forkEjectButton.setIconXY(0, 0);
	forkEjectButton.setAction(flexButtonCallback);
	forkEjectButton.setTextColors(touchgfx::Color::getColorFromRGB(255, 5, 255),
			touchgfx::Color::getColorFromRGB(94, 255, 0));
	forkEjectButton.setWidth(50);
	forkEjectButton.setHeight(60);

	forkUpButton.setIconBitmaps(Bitmap(BITMAP_EXPAND_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID),
			Bitmap(BITMAP_EXPAND_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID));
	forkUpButton.setIconXY(0, 0);
	forkUpButton.setAction(flexButtonCallback);
	forkUpButton.setTextColors(touchgfx::Color::getColorFromRGB(255, 5, 255),
			touchgfx::Color::getColorFromRGB(94, 255, 0));
	forkUpButton.setWidth(50);
	forkUpButton.setHeight(60);

	forkDownButton.setIconBitmaps(Bitmap(BITMAP_EXPAND_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID),
			Bitmap(BITMAP_EXPAND_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID));
	forkDownButton.setIconXY(0, 0);
	forkDownButton.setAction(flexButtonCallback);
	forkDownButton.setTextColors(touchgfx::Color::getColorFromRGB(255, 5, 255),
			touchgfx::Color::getColorFromRGB(94, 255, 0));
	forkDownButton.setWidth(50);
	forkDownButton.setHeight(60);
//listLayout1.add(button2);
//listLayout1.add(button3);

}

void lightsScreenView::setupScreen( )
{
	ThemeFactory th(settingsM.user,background);
	lightsScreenView::setupButtons( );
	lightsScreenViewBase::setupScreen( );
}

void lightsScreenView::tearDownScreen( )
{
	lightsScreenView::tearDownButtons( );
	lightsScreenViewBase::tearDownScreen( );
}

void lightsScreenView::buttonCallbackHandler(const touchgfx::AbstractButton &src)
{
//    if (&src == &button2)
//    {
//    	buttonHazards.ToggleButtonTrigger::forceState(1);
//    	buttonHazards.invalidate();
//    }
}

void lightsScreenView::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer &src)
{
#ifndef DISABLE_TOGGLE_CLASS_VARIABLE_STATE
	if (&src == &highBeamsButton)
	{
		controllerState.highBeams = !controllerState.highBeams;
	}
	if (&src == &lowBeamsButton)
	{
		controllerState.lowBeams = !controllerState.lowBeams;
	}
	if (&src == &topLightsButton)
	{
		controllerState.topLights = !controllerState.topLights;
	}
	if (&src == &posLightsButton)
	{
		controllerState.posLights = !controllerState.posLights;
	}
	if (&src == &hazardsButton)
	{
		controllerState.hazards = !controllerState.hazards;
	}
	if (&src == &leftBlinkerButton)
	{
		controllerState.leftBlinker = !controllerState.leftBlinker;
	}
	if (&src == &rightBlinkerButton)
	{
		controllerState.rightBlinker = !controllerState.rightBlinker;
	}
	if (&src == &fogLightsFrontButton)
	{
		controllerState.fogLightsFront = !controllerState.fogLightsFront;
	}
	if (&src == &fogLightsRearButton)
	{
		controllerState.fogLightsRear = !controllerState.fogLightsRear;
	}
	if (&src == &hornButton)
	{
		controllerState.horn = !controllerState.horn;
	}
#else
	if (&src == &highBeamsButton)
	{
		controllerState.highBeams = 1;
	}
	if (&src == &lowBeamsButton)
	{
		controllerState.lowBeams = 1;
	}
	if (&src == &topLightsButton)
	{
		controllerState.topLights = 1;
	}
	if (&src == &posLightsButton)
	{
		controllerState.posLights = 1;
	}
	if (&src == &hazardsButton)
	{
		controllerState.hazards = 1;
	}
	if (&src == &leftBlinkerButton)
	{
		controllerState.leftBlinker = 1;
	}
	if (&src == &rightBlinkerButton)
	{
		controllerState.rightBlinker = 1;
	}
	if (&src == &fogLightsFrontButton)
	{
		controllerState.fogLightsFront = 1;
	}
	if (&src == &fogLightsRearButton)
	{
		controllerState.fogLightsRear = 1;
	}
	if (&src == &hornButton)
	{
		controllerState.horn = 1;
	}


#endif

}
void lightsScreenView::button2clicked( )
{
}
void lightsScreenView::setupButtons( )
{

	hazardsButton.ToggleButtonTrigger::forceState(controllerState.hazards);
	highBeamsButton.ToggleButtonTrigger::forceState(controllerState.highBeams);
	lowBeamsButton.ToggleButtonTrigger::forceState(controllerState.lowBeams);
	leftBlinkerButton.ToggleButtonTrigger::forceState(controllerState.leftBlinker);
	rightBlinkerButton.ToggleButtonTrigger::forceState(controllerState.rightBlinker);
	topLightsButton.ToggleButtonTrigger::forceState(controllerState.topLights);
	posLightsButton.ToggleButtonTrigger::forceState(controllerState.posLights);

	hazardsButton.invalidate( );
	highBeamsButton.invalidate( );
	lowBeamsButton.invalidate( );
	leftBlinkerButton.invalidate( );
	rightBlinkerButton.invalidate( );
	topLightsButton.invalidate( );
	posLightsButton.invalidate( );

	listLights.add(highBeamsButton);
	listLights.add(lowBeamsButton);
	listLights.add(topLightsButton);
	listLights.add(posLightsButton);
	listLightsTwo.add(hazardsButton);

//		none = -1,
//		truck=0,
//		roadAssist=1,
//		drift=2,
//		heli=3,
//		custom1 = 4,

	switch (controllerState.truckType)
	{

		case TruckType::none:

		break;
		case TruckType::truck:
			listLightsTwo.add(fogLightsRearButton);
			listLightsTwo.add(fogLightsFrontButton);

			listFunc.add(leftBlinkerButton);
			listFunc.add(rightBlinkerButton);
			listFunc.add(trailerConnectButton);
			listFunc.add(axleLiftingButton);
			listFunc.add(hornButton);

			listGear.add(gearUpButton);
			listGear.add(gearDownButton);

			swipeContainer.setVisible(0);
			box1.setVisible(0);

		break;
		case TruckType::roadAssist:
			swipeContainer.setVisible(1);
			box1.setVisible(1);

			listWinchFirst.add(firstWinchDownButton);
			listWinchFirst.add(firstWinchUpButton);
			listWinchSecond.add(secondWinchDownButton);
			listWinchSecond.add(secondWinchUpButton);
			listRightSupport.add(rightSupportRetrtactButton);
			listRightSupport.add(rightSupportEjectButton);
			listLeftSupport.add(leftSupportRetrtactButton);
			listLeftSupport.add(leftSupportEjectButton);
			listArmOne.add(armRetractButton);
			listArmOne.add(armEjectButton);
			listArmTwo.add(armUpButton);
			listArmTwo.add(armDownButton);
			listForkOne.add(forkUpButton);
			listForkOne.add(forkDownButton);
			listForkTwo.add(forkEjectButton);
			listForkTwo.add(forkRetractButton);

		break;
		case TruckType::drift:

			listLights.add(highBeamsButton);
			listLights.add(lowBeamsButton);

		break;
		case TruckType::heli:

		break;
		case TruckType::custom1:

		break;

		default:
		break;
	}

}
void lightsScreenView::tearDownButtons( )
{

	listLights.removeAll( );
	listLightsTwo.removeAll( );
	listFunc.removeAll( );
	listGear.removeAll( );
	listWinchFirst.removeAll( );
	listWinchSecond.removeAll( );
	listRightSupport.removeAll( );
	listLeftSupport.removeAll( );
	listArmOne.removeAll( );
	listArmTwo.removeAll( );
	listForkOne.removeAll( );
	listForkTwo.removeAll( );

}
