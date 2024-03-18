/*
 * ControllerSettings.cpp
 *
 *  Created on: Jul 13, 2023
 *      Author: KaDzejoo
 */

#include <class/dataClass/ControllerSettings.hpp>

ControllerSettings::ControllerSettings( ) :
		expoSlider(3), smoothSlider(5), fourthSlider(50), audioToggle(1), lockToggle(
				0), energyToggle(1), baseToggle(1), settingsScreenMenuNumber(0), hardwareTestScreenMenuNumber(
				0)
{
	setUser(User::defaultUser);
#ifdef ENABLE_DEBUG_USER
	setUser(User::kaDzejoo);
#endif
}

void ControllerSettings::setUser( )
{
	user = User::defaultUser;

}

void ControllerSettings::setUser(User userIn)
{
	user = userIn;

	switch (userIn)
	{
		case User::kaDzejoo:
			//mainScreenData = MainScreenData::mainScreenGauges;
			//performancePriority = PerformancePriority::gui;
			//expoSlider = 5;
			//smoothSlider = 95;
			//deadzoneSlider = 5;
			batteryWarningLevel = 15;
			timeToScreenSleep = 150;
			timeToIdle = 300;
			//maxBlinkPriority = 2;
			locked = 0;
			//selectedSteeringMode = 4;
			gaugesActive = 0;
			screenBlackout = 1;
			keypadEnable = 1;
		break;
		case User::defaultUser:
			locked =1;
			gaugesActive = 1;
			keypadEnable = 0;
			batteryWarningLevel = 30;
		break;
		case User::debugUser:
			locked = 0;
			batteryWarningLevel = 30;
		break;
		case User::pope:
			locked = 1;
			batteryWarningLevel = 30;
		break;
		case User::cptFrost:
			gaugesActive = 1;
			keypadEnable = 1;
			locked = 0;
		break;
	}

}
