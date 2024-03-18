/*
 * InputOutputModel.cpp
 *
 *  Created on: 11 lip 2023
 *      Author: KaDzejoo
 */

#include "InputOutputModel.hpp"
#include <string>

InputOutputModel::InputOutputModel( )
{
	InputOutputModel::iomReInit( );
}

const dataToSend& InputOutputModel::getJoyData( ) const
{
	return joyData;
}

void InputOutputModel::setJoyData(const dataToSend &joyData)
{
	this->joyData = joyData;
}

void InputOutputModel::setTruckType( )
{
	InputOutputModel::truckType = TruckType::none;
}

void InputOutputModel::setTruckType(TruckType type)
{
	InputOutputModel::truckType = type;
}

void InputOutputModel::resetGearButton( )
{
	gearUp = 0;
	gearDown = 0;
}

void InputOutputModel::turnLightsOff(bool all)
{
	if (all == 0)
	{
		lowBeams = 0;
		posLights = 0;
	}
	else
	{
		topLights = 0;
		highBeams = 0;
		lowBeams = 0;
		posLights = 0;
		hazards = 0;
		leftBlinker = 0;
		rightBlinker = 0;
		fogLightsFront = 0;
		fogLightsRear = 0;
	}
}

void InputOutputModel::winchesDown( )
{
	firstWinchDown = 0;
	secondWinchDown = 0;

}

void InputOutputModel::iomReInit( )
{

	truckType = TruckType::none;
	batteryStatus = batteryState::discharged;
	connectedTruckName = "none";

	lowBeams = 0;
	posLights = 0;
	topLights = 0;
	highBeams = 0;
	hazards = 0;
	leftBlinker = 0;
	rightBlinker = 0;
	fogLightsFront = 0;
	fogLightsRear = 0;

	gearUp = 0;
	gearDown = 0;

	axleLifting = 0;
	trailerConnect = 0;

	firstWinchUp = 0;
	firstWinchDown = 0;
	secondWinchUp = 0;
	secondWinchDown = 0;
	rightSupportRetrtact = 0;
	rightSupportEject = 0;
	leftSupportRetrtact = 0;
	leftSupportEject = 0;
	armRetract = 0;
	armEject = 0;
	armUp = 0;
	armDown = 0;
	forkRetract = 0;
	forkEject = 0;
	forkUp = 0;
	forkDown = 0;

	
}

void InputOutputModel::setVehicleName(std::string newName)
{
	connectedTruckName = newName;
	connectedTruckNameCP = newName.c_str( );
}


