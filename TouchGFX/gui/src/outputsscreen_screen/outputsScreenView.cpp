#include <gui/outputsscreen_screen/outputsScreenView.hpp>
#include "IntegrityManager.hpp"
#include <gui/containers/functionSelect.hpp>
#include <images/BitmapDatabase.hpp>
#include "ThemeFactory.hpp"
#include "SetupSettings.hpp"
#include <vector>
#include "MessageEncoder.hpp"
#include <algorithm>


extern MessageEncoder encoder;
extern InputOutputModel controllerState;
extern char debugStringBuffer[800];



void FromByte(uint8_t c, bool b[8])
{
    for (int i=0; i < 8; ++i)
        b[i] = (c & (1<<i)) != 0;
}
outputsScreenView::outputsScreenView()
{
	topLights.setIcon(BITMAP_E911_EMERGENCY_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	topLights.setType(funcType::toggle);
	topLights.setText("Top lights");
	topLights.setTextSec("Turn top lights on / off");
	topLights.setColor(255,200,0); // orange
	topLights.addAllowedVehicle(TruckType::truck);
	topLights.addAllowedVehicle(TruckType::roadAssist);
	functions.push_back(&topLights);

	highBeams.setIcon(BITMAP_WB_INCANDESCENT_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	highBeams.setType(funcType::toggle);
	highBeams.setText("High beams");
	highBeams.setTextSec("Turn high beams on / off");
	highBeams.setColor(255,200,0); // orange
	highBeams.addAllowedVehicle(TruckType::truck);
	highBeams.addAllowedVehicle(TruckType::drift);
	highBeams.addAllowedVehicle(TruckType::roadAssist);
	functions.push_back(&highBeams);

	lowBeams.setIcon(BITMAP_HIGHLIGHT_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	lowBeams.setType(funcType::toggle);
	lowBeams.setText("Low beams");
	lowBeams.setTextSec("Turn low beams on / off");
	lowBeams.setColor(255,200,0); // orange
	lowBeams.addAllowedVehicle(TruckType::truck);
	lowBeams.addAllowedVehicle(TruckType::drift);
	lowBeams.addAllowedVehicle(TruckType::roadAssist);
	functions.push_back(&lowBeams);

	dayLights.setIcon(BITMAP_WB_INCANDESCENT_FILL1_WGHT100_GRAD200_OPSZ48_ID);
	dayLights.setType(funcType::toggle);
	dayLights.setText("Day Lights");
	dayLights.setTextSec("Turn Day Lights on / off");
	dayLights.setColor(255,200,0); // orange
	dayLights.addAllowedVehicle(TruckType::truck);
	dayLights.addAllowedVehicle(TruckType::roadAssist);
	functions.push_back(&dayLights);


	posLights.setIcon(BITMAP_WB_SUNNY_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	posLights.setType(funcType::toggle);
	posLights.setText("position lights");
	posLights.setTextSec("Turn position lights on / off");
	posLights.setColor(255,200,0); // orange
	posLights.addAllowedVehicle(TruckType::truck);
	posLights.addAllowedVehicle(TruckType::roadAssist);
	functions.push_back(&posLights);

	hazards.setIcon(BITMAP_EMERGENCY_HOME_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	hazards.setType(funcType::toggle);
	hazards.setText("Hazard lights");
	hazards.setTextSec("Turn hazards on / off");
	hazards.setColor(255, 0,0); // red
	hazards.addAllowedVehicle(TruckType::truck);
	hazards.addAllowedVehicle(TruckType::drift);
	hazards.addAllowedVehicle(TruckType::roadAssist);
	functions.push_back(&hazards);

	leftBlinker.setIcon(BITMAP_ARROW_BACK_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	leftBlinker.setType(funcType::toggle);
	leftBlinker.setText("Left Blinker");
	leftBlinker.setTextSec("Turn signal on / off");
	leftBlinker.setColor(0, 255,0); // green duh >?
	leftBlinker.addAllowedVehicle(TruckType::truck);
	leftBlinker.addAllowedVehicle(TruckType::drift);
	leftBlinker.addAllowedVehicle(TruckType::roadAssist);
	functions.push_back(&leftBlinker);

	rightBlinker.setIcon(BITMAP_ARROW_FORWARD_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	rightBlinker.setType(funcType::toggle);
	rightBlinker.setText("Right Blinker");
	rightBlinker.setTextSec("Turn signal on / off");
	rightBlinker.setColor(0, 255,0); // green duh >?
	rightBlinker.addAllowedVehicle(TruckType::truck);
	rightBlinker.addAllowedVehicle(TruckType::drift);
	rightBlinker.addAllowedVehicle(TruckType::roadAssist);
	functions.push_back(&rightBlinker);

	fogLightsFront.setIcon(BITMAP_LENS_BLUR_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	fogLightsFront.setType(funcType::toggle);
	fogLightsFront.setText("Front fog lights");
	fogLightsFront.setTextSec("Turn front fog lights on / off");
	fogLightsFront.setColor(200, 200,0); // orangish
	fogLightsFront.addAllowedVehicle(TruckType::truck);
	fogLightsFront.addAllowedVehicle(TruckType::roadAssist);
	functions.push_back(&fogLightsFront);

	fogLightsRear.setIcon(BITMAP_LENS_BLUR_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	fogLightsRear.setType(funcType::toggle);
	fogLightsRear.setText("Rear fog lights");
	fogLightsRear.setTextSec("Turn rear fog lights on / off");
	fogLightsRear.setColor(200, 200,0); // orangish
	fogLightsRear.addAllowedVehicle(TruckType::truck);
	fogLightsRear.addAllowedVehicle(TruckType::roadAssist);
	functions.push_back(&fogLightsRear);


	horn.setIcon(BITMAP_DONUT_LARGE_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	horn.setType(funcType::toggle);
	horn.setText("Horn");
	horn.setTextSec("Horn signal");
	horn.setColor(170, 70,200); // bluh duh >?
	horn.addAllowedVehicle(TruckType::truck);
	horn.addAllowedVehicle(TruckType::drift);
	horn.addAllowedVehicle(TruckType::roadAssist);
	functions.push_back(&horn);
// truck spec
	axleLifting.setIcon(BITMAP_SETTINGS_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	axleLifting.setType(funcType::toggle);
	axleLifting.setText("Axle lifting");
	axleLifting.setTextSec("Lift axle up");
	axleLifting.setColor(0, 5,255); // bluh duh >?
	axleLifting.addAllowedVehicle(TruckType::truck);
	functions.push_back(&axleLifting);

	trailerConnect.setIcon(BITMAP_RV_HOOKUP_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	trailerConnect.setType(funcType::toggle);
	trailerConnect.setText("Connect trailer");
	trailerConnect.setTextSec("Connect trailer to the truck");
	trailerConnect.setColor(0, 5,255); // bluh duh >?
	trailerConnect.addAllowedVehicle(TruckType::truck);
	functions.push_back(&trailerConnect);
// assist spec

	firstWinch.setIcon(BITMAP_UNFOLD_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	firstWinch.setType(funcType::upDown);
	firstWinch.setText("First Winch");
	firstWinch.setTextSec("Move first winch");
	firstWinch.setColor(200,0,255); // violet duh >?
	firstWinch.addAllowedVehicle(TruckType::roadAssist);
	functions.push_back(&firstWinch);

	secondWinch.setIcon(BITMAP_UNFOLD_MORE_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	secondWinch.setType(funcType::upDown);
	secondWinch.setText("Second Winch");
	secondWinch.setTextSec("Move second winch");
	secondWinch.setColor(200,0,255); // violet duh >?
	secondWinch.addAllowedVehicle(TruckType::roadAssist);
	functions.push_back(&secondWinch);

	rightSupportER.setIcon(BITMAP_PLACE_ITEM_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	rightSupportER.setType(funcType::upDown);
	rightSupportER.setText("Right support");
	rightSupportER.setTextSec("Extend / retract right support");
	rightSupportER.setColor(255,0,155); // violet duh >?
	rightSupportER.addAllowedVehicle(TruckType::roadAssist);
	functions.push_back(&rightSupportER);

	leftSupportER.setIcon(BITMAP_PLACE_ITEM_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	leftSupportER.setType(funcType::upDown);
	leftSupportER.setText("Left support");
	leftSupportER.setTextSec("Extend / retract left support");
	leftSupportER.setColor(255,0,155); // violet duh >?
	leftSupportER.addAllowedVehicle(TruckType::roadAssist);
	functions.push_back(&leftSupportER);

	armER.setIcon(BITMAP_PLACE_ITEM_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	armER.setType(funcType::upDown);
	armER.setText("Arm extension");
	armER.setTextSec("Extend / retract arm");
	armER.setColor(255,90,0); // orangen duh >?
	armER.addAllowedVehicle(TruckType::roadAssist);
	functions.push_back(&armER);

	armUD.setIcon(BITMAP_SWAP_VERT_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	armUD.setType(funcType::upDown);
	armUD.setText("Arm position");
	armUD.setTextSec("Move arm up / down");
	armUD.setColor(255,90,0); // orangen duh >?
	armUD.addAllowedVehicle(TruckType::roadAssist);
	functions.push_back(&armUD);

	forkER.setIcon(BITMAP_GAMEPAD_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	forkER.setType(funcType::upDown);
	forkER.setText("Fork extension");
	forkER.setTextSec("Extend / retract fork");
	forkER.setColor(0,255,0); // green duh >?
	forkER.addAllowedVehicle(TruckType::roadAssist);
	functions.push_back(&forkER);

	forkUD.setIcon(BITMAP_SWAP_VERT_FILL0_WGHT100_GRAD200_OPSZ24_ID);
	forkUD.setType(funcType::upDown);
	forkUD.setText("Fork position");
	forkUD.setTextSec("Move fork up / down");
	forkUD.setColor(0,255,0); // green duh >?
	forkUD.addAllowedVehicle(TruckType::roadAssist);
	functions.push_back(&forkUD);





    topLights.setStateValue(&controllerState.topLights);
    highBeams.setStateValue(&controllerState.highBeams);
	lowBeams.setStateValue(&controllerState.lowBeams);
	dayLights.setStateValue(&controllerState.dayLights);
	posLights.setStateValue(&controllerState.posLights);
	hazards.setStateValue(&controllerState.hazards);
	leftBlinker.setStateValue(&controllerState.leftBlinker);
	rightBlinker.setStateValue(&controllerState.rightBlinker);
	fogLightsFront.setStateValue(&controllerState.fogLightsFront);
	fogLightsRear.setStateValue(&controllerState.fogLightsRear);
	horn.setStateValue(&controllerState.horn);
	axleLifting.setStateValue(&controllerState.axleLifting);
	trailerConnect.setStateValue(&controllerState.trailerConnect);
	//running.setStateValue(&controllerState.);


	firstWinch.setUpValue(&controllerState.firstWinchUp);
	firstWinch.setDownValue(&controllerState.firstWinchDown);
	secondWinch.setUpValue(&controllerState.secondWinchUp);
	secondWinch.setDownValue(&controllerState.secondWinchDown);

	rightSupportER.setUpValue(&controllerState.rightSupportRetrtact);
	rightSupportER.setDownValue(&controllerState.rightSupportEject);
	leftSupportER.setUpValue(&controllerState.leftSupportRetrtact);
	leftSupportER.setDownValue(&controllerState.leftSupportEject);

	armER.setUpValue(&controllerState.armRetract);
	armER.setDownValue(&controllerState.armEject);
	armUD.setUpValue(&controllerState.armUp);
	armUD.setDownValue(&controllerState.armUp);

	forkER.setUpValue(&controllerState.forkRetract);
	forkER.setDownValue(&controllerState.forkEject);
	forkUD.setUpValue(&controllerState.forkUp);
	forkUD.setDownValue(&controllerState.forkDown);

#ifdef ENABLE_DEBUG_PRINTER
	debugBox.setAlpha(200);

#endif

}

void outputsScreenView::setupScreen()
{

	if(controllerState.connected!=1){
		containerDisabled.setVisible(1);
	}else{
		containerDisabled.setVisible(0);
	}

	std::vector<touchgfx::PainterRGB888*> painters;
	painters.push_back(&lineDecoScroll1Painter);
	painters.push_back(&lineDecoScroll2Painter);

	ThemeFactory th(settingsM.user);
	th.bindBackground(imageBackground);
	th.applyPainters(painters);
	th.bindColorSecondary(textDisabled,1);
    setupButtons();
    invalidate();
    listFunctions.invalidateContent();
    outputsScreenViewBase::setupScreen();
}

void outputsScreenView::tearDownScreen()
{
    outputsScreenViewBase::tearDownScreen();
}

void outputsScreenView::tickView(){

	static int tickCount = 0;
	static int prevTickCount = 0;

	if (tickCount - prevTickCount > 20 * 1)
	{
		listFunctions.invalidate();
		topLights.setStateIconDef();
		highBeams.setStateIconDef();
		lowBeams.setStateIconDef();
		dayLights.setStateIconDef();
		hazards.setStateIconDef();
		leftBlinker.setStateIconDef();
		rightBlinker.setStateIconDef();
		horn.setStateIconDef();
		fogLightsFront.setStateIconDef();
		fogLightsRear.setStateIconDef();
		axleLifting.setStateIconDef();
		trailerConnect.setStateIconDef();
		fogLightsFront.setStateIconDef();

		prevTickCount = tickCount;
	}


	tickCount++;

#ifdef ENABLE_DEBUG_PRINTER
	updateDebugString();

#endif

}

void outputsScreenView::updateDebugString( )
{

	/// debug bitfields
	bool compoundStatus[8];  // compound status 10
	bool vehicleStatus[8]; // vehicle status
	bool trailerStatus[8]; // trailer status
	bool lightsStatus[8]; // lights
	bool lights2Status[8]; // lights pt2 14


	FromByte(encoder.binaryArr[9],compoundStatus);
	FromByte(encoder.binaryArr[10],vehicleStatus);
	FromByte(encoder.binaryArr[11],trailerStatus);
	FromByte(encoder.binaryArr[12],lightsStatus);
	FromByte(encoder.binaryArr[13],lights2Status);


	const char *debugInfo =
			"\n DATA RAW: "
			"\n START:0x%02x "
			"\n LEN HI:LO: %02x:%02x"
			"\n API:0x%02x "
			"\n frID:0x%02x"
			"\n HIaddr:0x%02x "
			"\n LOaddr:0x%02x"
			"\n Opt:0x%02x"
			"\n DATA: correct place if nonShifted"
			"\n 0x%02x  44"
			"\n 0x%02x  COMP STATUS"
			"\n 0x%02x  VEHICLE STATUS"
			"\n 0x%02x  TRAILER STATUS"
			"\n 0x%02x  LIGHTS STATUS"
			"\n 0x%02x  LIGHTS2 STATUS"
			"\n 0x%02x  CAMX"
			"\n 0x%02x  CAMY"
			"\n 0x%02x  GEAR"
			"\n 0x%02x  JOY1Y"
			"\n 0x%02x  JOY1X"
			"\n 0x%02x  CHECKSUM"
			"\n 0x%02x 0x%02x 0x%02x 0x%02x"
			"\n 0x%02x 0x%02x 0x%02x 0x%02x"
			"\n 0x%02x 0x%02x"
			"\n "
			"\n COMPOUND STATUS   %d%d%d%d%d%d%d%d   0x%02x"
			"\n VEHICLE STATUS    %d%d%d%d%d%d%d%d   0x%02x"
			"\n TRAILER STATUS    %d%d%d%d%d%d%d%d   0x%02x"
			"\n LIGHTS I          %d%d%d%d%d%d%d%d   0x%02x"
			"\n LIGHTS II         %d%d%d%d%d%d%d%d   0x%02x"
			"\n"
			"\n SPEED: %d  TURN %d"
			"\n CHECKSUM 0x%02X"
			"\n OFFSET: %d"
			"\n DATA WILL BE OFFSETED BY THIS VALUE"
			"\n ";

		snprintf(debugStringBuffer, sizeof ( debugStringBuffer ), debugInfo,
				encoder.binaryArr[0], encoder.binaryArr[1],	encoder.binaryArr[2],
				encoder.binaryArr[3], encoder.binaryArr[4],encoder.binaryArr[5],
				encoder.binaryArr[6], encoder.binaryArr[7], encoder.binaryArr[8],
				encoder.binaryArr[9],encoder.binaryArr[10], encoder.binaryArr[11],
				encoder.binaryArr[12],encoder.binaryArr[13], encoder.binaryArr[14],
				encoder.binaryArr[15], encoder.binaryArr[16], encoder.binaryArr[17],
				encoder.binaryArr[18], encoder.binaryArr[19],encoder.binaryArr[20],
				encoder.binaryArr[21], encoder.binaryArr[22],encoder.binaryArr[23],
				encoder.binaryArr[24],encoder.binaryArr[25], encoder.binaryArr[26],
				encoder.binaryArr[27],encoder.binaryArr[28], encoder.binaryArr[29],
				compoundStatus[0],compoundStatus[1],compoundStatus[2],compoundStatus[3],
				compoundStatus[4],compoundStatus[5],compoundStatus[6],compoundStatus[7],encoder.binaryArr[9],
				vehicleStatus[0],vehicleStatus[1],vehicleStatus[2],vehicleStatus[3],
				vehicleStatus[4],vehicleStatus[5],vehicleStatus[6],vehicleStatus[7],encoder.binaryArr[10],
				trailerStatus[0],trailerStatus[1],trailerStatus[2],trailerStatus[3],
				trailerStatus[4],trailerStatus[5],trailerStatus[6],trailerStatus[7],encoder.binaryArr[11],
				lightsStatus[0],lightsStatus[1],lightsStatus[2],lightsStatus[3],
				lightsStatus[4],lightsStatus[5],lightsStatus[6],lightsStatus[7],encoder.binaryArr[12],
				lights2Status[0],lights2Status[1],lights2Status[2],lights2Status[3],
				lights2Status[4],lights2Status[5],lights2Status[6],lights2Status[7],encoder.binaryArr[13],
				encoder.binaryArr[17],encoder.binaryArr[18],encoder.binaryArr[19],encoder.offset);


	Application::getDebugPrinter( )->setScale(1);
	Application::getDebugPrinter( )->setColor(touchgfx::Color::getColorFromRGB(0,255,0));
	Application::getDebugPrinter( )->setPosition(5, 0, 240, 272);
	Application::getDebugPrinter( )->setString(debugStringBuffer);
	Application::invalidateDebugRegion( );

}



void outputsScreenView::setupButtons()
{
	topLights.forceState();
	highBeams.forceState();
	lowBeams.forceState();
	dayLights.forceState();
	posLights.forceState();
	hazards.forceState();
	leftBlinker.forceState();
	rightBlinker.forceState();
	fogLightsFront.forceState();
	fogLightsRear.forceState();
	horn.forceState();
	axleLifting.forceState();
	trailerConnect.forceState();
	listFunctions.removeAll();


	for (functionSelect *i : functions)
	{
		std::vector <TruckType> vehicle = i->getAllowedVehicleList( );
		if (std::find(vehicle.begin( ), vehicle.end( ), controllerState.truckType)!= vehicle.end( ))
		{
			listFunctions.add(*i);
		}
	}

}

