/*
 * integrityManager.cpp
 *
 *  Created on: Jul 16, 2023
 *      Author: KaDzejoo
 */

#include "integrityManager.hpp"
#include "cmsis_os.h"
#include "InputOutputModel.hpp"
#include "ControllerSettings.hpp"
#include "cmsis_os2.h"
#include "task.h"
#include "NotificationFactory.hpp"
#include "KeyboardDecoder.hpp"
#include "MessageEncoder.hpp"
#include "ioTaskOperator.hpp"

extern osThreadId_t taskIOHandle;
extern osThreadId_t videoDecodeHandle;
extern osThreadId_t uartCommsHandle;
extern osThreadId_t TouchGFXTaskHandle;
extern osThreadId_t integrityMngrHandle;


InputOutputModel controllerState;
ControllerSettings settingsM;
NotificationFactory notificationFactory;
KeyboardDecoder keyboard;
MessageEncoder encoder;


integrityManager::integrityManager( ) :
		osTimeDelay(10)
{
	settingsM.directionAxis = &controllerState.joyData.joy1x;
	settingsM.turnAxis = &controllerState.joyData.joy1y;
	settingsM.camxAxis = &controllerState.joyData.joy2x;
	settingsM.camyAxis = &controllerState.joyData.joy2y;
	settingsM.gearUpAxis = &controllerState.joyData.bttn1;
	settingsM.gearDownAxis = &controllerState.joyData.bttn2;


	osThreadSetPriority(integrityMngrHandle, osPriorityRealtime);

}
void integrityManager::taskEntry( )
{

#ifdef ENABLE_DEBUG_PRINTER
	integrityTaskHandle = xTaskGetHandle("integrityMngr");
	gfxTaskHandle = xTaskGetHandle("TouchGFXTask");
	ioTaskHandle = xTaskGetHandle("taskIO");
#endif

	for (;;)
	{
#ifdef ENABLE_DEBUG_PRINTER
		integrityManager::getHighWaterMark();
#endif

		checkActivity( );
		axisAssignment( );
		buttonAssignment( );
		manageSleep( );
		manageSystemNotifications( );
		secretCodes(settingsM.lastCode);
		setHardwareLed();

		switch (settingsM.performancePriority)
		{
			case PerformancePriority::gui:
				integrityManager::setPriorityGui( );
			break;
			case PerformancePriority::comms:
				integrityManager::setPriorityComms( );
			break;
			case PerformancePriority::io:
				integrityManager::setPriorityIo( );
			break;

			default:
			break;
		}



		osDelay(osTimeDelay);
	}

}

void integrityManager::manageSystemNotifications( )
{
	if (settingsM.locked == 1){
		notificationFactory.issueNotification(notificationFactory.lockNoti);
	}else{
		notificationFactory.removeNotification(notificationFactory.lockNoti);
	}
	if (controllerState.batteryChargeController < settingsM.batteryWarningLevel){
		notificationFactory.issueNotification(notificationFactory.batteryCtrlLowNoti);
	}else{
		notificationFactory.removeNotification(notificationFactory.batteryCtrlLowNoti);
	}
	if (controllerState.batteryChargeVehicle < settingsM.batteryWarningLevel){
		notificationFactory.issueNotification(notificationFactory.batteryTruckLowNoti);
	}else{
		notificationFactory.removeNotification(notificationFactory.batteryTruckLowNoti);
	}
	if(controllerState.connected == 0){
		notificationFactory.issueNotification(notificationFactory.disconnectedNoti);
	}else{
		notificationFactory.removeNotification(notificationFactory.disconnectedNoti);
	}

}
void integrityManager::buttonAssignment( )
{
#ifndef ENABLE_BUTTON_ASSIGNMENT
	//controllerState.highBeams = controllerState.joyData.bttn1;
	//controllerState.hazards = controllerState.joyData.bttn2;
	//controllerState.leftBlinker = controllerState.joyData.bttn3;
	//controllerState.rightBlinker = controllerState.joyData.bttn4;
	return;
#endif


	switch (settingsM.selectedSteeringMode)
	{
		case 1:
			settingsM.topButtonText = "Main screen";
			settingsM.bottomButtonText = "Hazards";
			settingsM.leftButtonText = "Left Blinker";
			settingsM.rightButtonText = "Right Blinker";

			if (!controllerState.joyData.bttn1){
				static int tickCount = 0;
				static int prevTickCount = 0;
				if (tickCount - prevTickCount > 200 * 1)
				{
					application().gotomainScreenScreenSlideTransitionSouth();
					prevTickCount = tickCount;
				}
				tickCount++;
			}
			controllerState.hazards = controllerState.joyData.bttn2;
			controllerState.leftBlinker = controllerState.joyData.bttn3;
			controllerState.rightBlinker = controllerState.joyData.bttn4;

		break;
		case 2:
			settingsM.topButtonText = "Turn lights off";
			settingsM.bottomButtonText = "Horn";
			settingsM.leftButtonText = "Gear Up";
			settingsM.rightButtonText = "Gear Down";

			controllerState.highBeams = controllerState.joyData.bttn1;
			controllerState.horn = controllerState.joyData.bttn2;
			controllerState.gearUp = controllerState.joyData.bttn3;
			controllerState.gearDown = controllerState.joyData.bttn4;
		break;
		case 3:
			settingsM.topButtonText = "Top lights";
			settingsM.bottomButtonText = "Pos lights";
			settingsM.leftButtonText = "High beams";
			settingsM.rightButtonText = "Low beams";

			controllerState.topLights = controllerState.joyData.bttn1;
			controllerState.posLights = controllerState.joyData.bttn2;
			controllerState.highBeams = controllerState.joyData.bttn3;
			controllerState.lowBeams = controllerState.joyData.bttn4;
		break;
		case 4:
			settingsM.topButtonText = "empty1";
			settingsM.bottomButtonText = "empty2";
			settingsM.leftButtonText = "empty3";
			settingsM.rightButtonText = "empty4";
		break;
	}

}
void integrityManager::suspendTasks( )
{
	/*
	 * Add osThreadSuspend(xtaskHandle) when adding new tasks
	 */
	ioTaskOperator::turnOffScreen();
	osThreadSuspend(taskIOHandle);
	osThreadSuspend(videoDecodeHandle);
	osThreadSuspend(uartCommsHandle);

}

void integrityManager::resumeTasks( )
{
	/*
	 * Add osThreadResume(xtaskHandle) when adding new tasks
	 */
	if (osThreadGetState(taskIOHandle) == osThreadBlocked
			|| osThreadGetState(videoDecodeHandle) == osThreadBlocked
			|| osThreadGetState(uartCommsHandle) == osThreadBlocked)
	{
		//HAL_GPIO_WritePin(GPIOG, GPIO_PIN_15, GPIO_PIN_SET);
		//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET);
		osThreadResume(taskIOHandle);
		osThreadResume(videoDecodeHandle);
		osThreadResume(uartCommsHandle);
	}
}

void integrityManager::reinitializeData(InputOutputModel &data)
{
	data.iomReInit( );
}

void integrityManager::setPriorityGui( )
{
	osThreadSetPriority(TouchGFXTaskHandle, osPriorityNormal);
	osThreadSetPriority(taskIOHandle, osPriorityBelowNormal);
	osThreadSetPriority(uartCommsHandle, osPriorityBelowNormal);
}

void integrityManager::setPriorityComms( )
{
	osThreadSetPriority(TouchGFXTaskHandle, osPriorityBelowNormal);
	osThreadSetPriority(taskIOHandle, osPriorityBelowNormal);
	osThreadSetPriority(uartCommsHandle, osPriorityBelowNormal);
}
void integrityManager::setPriorityIo( )
{
	osThreadSetPriority(TouchGFXTaskHandle, osPriorityBelowNormal);
	osThreadSetPriority(taskIOHandle, osPriorityNormal);
	osThreadSetPriority(uartCommsHandle, osPriorityBelowNormal);
}
void integrityManager::getHighWaterMark( )
{
	/* Inspect our own high water mark on entering the task. */
	settingsM.uxHighWaterMarkIntegrity = uxTaskGetStackHighWaterMark(integrityTaskHandle);
	settingsM.uxHighWaterMarkGFX = uxTaskGetStackHighWaterMark(gfxTaskHandle);
	settingsM.uxHighWaterMarkIO = uxTaskGetStackHighWaterMark(ioTaskHandle);


}
void integrityManager::getTaskInfo(void)
{
//TODO function name says it all
	// at first enable in cubeIDE in rtos settings
	// gathering data bout' the tasks
	// and then format it nicely
}
unsigned long int integrityManager::secToTick(int timeInSec)
{
	//       7000 / 10
	//			700
	return ( timeInSec * 1000 ) / ( osTimeDelay / 10 );
}
void integrityManager::manageSleep( )
{



	if ( ( xTaskGetTickCount( ) - lastTouchEvent ) > secToTick(settingsM.timeToScreenSleep))
	{
		ioTaskOperator::turnOffScreen();
	}

	if ( ( xTaskGetTickCount( ) - lastTouchEvent ) > secToTick(settingsM.timeToIdle))
	{
		application( ).gotoidleScreenScreenBlockTransition( );
	}

	if (controllerState.idle == 1)
	{
		integrityManager::suspendTasks( );
	}
	else
	{
		integrityManager::resumeTasks( );
	}

}
void integrityManager::secretCodes(std::string actualCode)
{
	if (settingsM.codeAccepted == 0)
	{
		return;
	}
	bool executed = 0;
// keycodes definitions are in KeyboardDecoder.hpp
	keyboard.decode(actualCode, executed);

	if (executed == 1)
	{
		// what to do after code is accepted
		//screen->startSMOC({0,0,480,272});
		application( ).gotomainScreenScreenSlideTransitionSouth( );
		//application( ).gotomainScreenScreenCyberTransition( );
	}

	//mandatory i guess
	settingsM.codeAccepted = 0;
}

void integrityManager::axisAssignment( )
{
	invert(controllerState.axis.direction,settingsM.directionAxis,settingsM.directionInv);
	invert(controllerState.axis.turn,settingsM.turnAxis,settingsM.turnInv);
	invert(controllerState.axis.camx,settingsM.camxAxis,settingsM.camxInv);
	invert(controllerState.axis.camy,settingsM.camyAxis,settingsM.camyInv);

	controllerState.axis.gearUp = *settingsM.gearUpAxis;
	controllerState.axis.gearDown = *settingsM.gearDownAxis;
}

void integrityManager::checkActivity( )
{
	if (settingsM.sampledTouch || settingsM.sampledButton ||
			settingsM.screenBlackout)
	{
		settingsM.sampledButton = 0;
		settingsM.sampledJoy = 0;
		settingsM.sampledTouch = 0;
		ioTaskOperator::turnOnScreen();
		lastTouchEvent = xTaskGetTickCount( );
	}
}

void integrityManager::setHardwareLed( )
{

	if (controllerState.idle == 1)
	{
		if ( ( xTaskGetTickCount( ) - previousTick ) > 700)
		{
			ioTaskOperator::toggleLed(led::ledGreen);
			previousTick = xTaskGetTickCount( );
		}
	}else{
		ioTaskOperator::ledGreen(1);
	}


	if (controllerState.connected == 0)
	{
		if ( ( xTaskGetTickCount( ) - connectionTimer ) > 500)
		{
			ioTaskOperator::toggleLed(led::ledRed);
			connectionTimer = xTaskGetTickCount( );
		}
	}else{
		ioTaskOperator::ledRed(0);
	}

}

int integrityManager::invert(int &axis, int* in,bool invert)
{
	if (invert == 1)
	{
		axis = 100 - ( *in );
	}
	else
	{
		axis = *in;
	}
	return 0;
}
