/*
 * KeyboardDecoder.cpp
 *
 *  Created on: Sep 14, 2023
 *      Author: KaDzejoo
 */

#include <class/factories/KeyboardDecoder.hpp>
#include <string>
#include "InputOutputModel.hpp"
#include "ControllerSettings.hpp"

extern InputOutputModel controllerState;
extern ControllerSettings settingsM;

KeyboardDecoder::KeyboardDecoder( )
{

}

void KeyboardDecoder::decode(std::string actualCode, bool &executed)
{
	// here place decoder for codes "opening" with 00
	if (!actualCode.find(functionCodePrefix))
	{
		std::string value = actualCode.substr(4, 3); // 00 CC 123

		int valueInt = 0;

		if (value.at(0) != '\0')
		{
			valueInt = stoi(value);
		}

		executed += opValues(actualCode, valueInt);

		// opcodes with additional specific codes
		if (actualCode.find(opcodeLock) == 2)
		{
			executed += opLock(actualCode);
		}

		if (actualCode.find(opcodeUser) == 2)
		{
			executed += opCodes(actualCode);
		}

	}
	// end place
}

bool KeyboardDecoder::opCodes(std::string actualCode)
{

	if (actualCode.find(userCodeD) == 4)
	{
		settingsM.setUser(User::defaultUser);
		return 1;
	}
	if (actualCode.find(userCodeDbg) == 4)
	{
		settingsM.setUser(User::debugUser);
		return 1;
	}
	if (actualCode.find(userCodeK) == 4)
	{
		settingsM.setUser(User::kaDzejoo);
		return 1;
	}
	if (actualCode.find(userCodeP) == 4)
	{
		settingsM.setUser(User::pope);
		return 1;
	}
	if (actualCode.find(userCodeF) == 4)
	{
		settingsM.setUser(User::cptFrost);
		return 1;
	}
	return 0;
}

bool KeyboardDecoder::opValues(std::string actualCode, int value)
{
	// opcodes wiht values
	if (actualCode.find(opcodeSleep) == 2)
	{
		settingsM.timeToScreenSleep = value;
		return 1;
	}
	if (actualCode.find(opcodeTimeout) == 2)
	{
		settingsM.timeToIdle = value;
		return 1;
	}
	if (actualCode.find(opcodeMess) == 2)
	{
		controllerState.camx = value;
		return 1;
	}
	if (actualCode.find(opcodeVehi) == 2)
	{
		controllerState.adress = value;
		return 1;
	}
	if (actualCode.find(opcodeType) == 2)
	{
		if (value >4 )
		{
			return 0;
		}
		controllerState.setTruckType((TruckType)value);
		return 1;
	}
	return 0;
}

bool KeyboardDecoder::opLock(std::string actualCode)
{
	if (actualCode.find(lockCode) == 4)
	{
		settingsM.locked = 1;
		return 1;
	}
	if (actualCode.find(unlockCode) == 4)
	{
		settingsM.locked = 0;
		return 1;
	}

	return 0;
}
