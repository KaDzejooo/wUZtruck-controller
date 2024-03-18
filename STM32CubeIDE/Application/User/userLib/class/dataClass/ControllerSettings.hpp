/*
 // * controllerSettings.hpp
 *
 *  Created on: 6 lip 2023
 *      Author: KaDzejoo
 */

#ifndef CONTROLLERSETTINGS_HPP_
#define CONTROLLERSETTINGS_HPP_
#include "globals/SetupSettings.hpp"
#include "InputOutputModel.hpp"
#include <string>
#include "UTypes.hpp"




class ControllerSettings
{
	public:
		ControllerSettings( );




		/// left for backwards compatibility
		/// deprecated
		int fourthSlider;
		bool energyToggle;
		bool lockToggle;
		bool audioToggle;
		bool baseToggle;
		int notificationCount;// unused
		MainScreenData mainScreenData = MainScreenData::none; // unused
		ControllerLock controllerLock = ControllerLock::noLock;
		int scrolledAmountOnTruckScreen;
		int selectedRadioOnTruckScreen;
		int mainScreenDisplayX = 0;
		int mainScreenDisplayY = 0;
		///
		///
		///
		///
		///
		uint8_t batteryWarningLevel = 15; // warning for both of truck and controller
		bool energySaving;
		bool gaugesActive=1;
		bool screenBlackout = 0;
		bool keypadEnable = 0;
		bool videoTaskEnable = 0;
		int timeToScreenSleep = 50;
		int timeToIdle = 150;
		int maxBlinkPriority = 2;
		uint8_t selectedSteeringMode = 4;
		float expoSlider;
		float smoothSlider;
		float deadzoneSlider=4;
		float topValueCutoff=0;
		int uartTimeDelay = 20;

		// defaults for enums
		PerformancePriority performancePriority = PerformancePriority::gui;
		User user = User::defaultUser;

		//codes
		std::string lastCode = "none";
		bool popeMode = 0;
		bool codeAccepted = 0;

		//
		int settingsScreenMenuNumber = 3;
		int hardwareTestScreenMenuNumber = 3;

		// default placeholder that shouldn't be visible
		std::string topButtonText = "top";
		std::string bottomButtonText = "bottom";
		std::string leftButtonText = "left";
		std::string rightButtonText = "right";

		// joystick setup
		int* directionAxis ;
		int* turnAxis  ;
		int* camxAxis ;
		int* camyAxis ;
		int* gearUpAxis ;
		int* gearDownAxis ;
		//function inversion
		bool directionInv=0;
		bool turnInv=0;
		bool camxInv=0;
		bool camyInv=0;

		//True if sampled T in current cycle
		bool sampledTouch;
		bool sampledJoy;
		bool sampledButton;
		bool deadzoneFlag = 0;

		// locked should set all the movement commands to 0 if True
		bool locked = 0;

		/**
		 * high water mark for task % debug only
		 */
		unsigned long uxHighWaterMarkIntegrity = 0;
		unsigned long uxHighWaterMarkGFX = 0;
		unsigned long uxHighWaterMarkIO = 0;
		/*
		 * Sets active user
		 * if none selected sets to default;
		 */


		void setUser( );
		void setUser(User userIn);

};

#endif /* CONTROLLERSETTINGS_HPP_ */
