


/*
 * ioTaskOperator.cpp
 *
 *  Created on: 29 June 2023
 *      Author: KaDzejoo
 */
#include <stdio.h>
#include <ioTaskOperator.hpp>
#include "cmsis_os2.h"
#include "main.h"
#include "stm32h7xx_hal.h"
#include "utilities.hpp"
#include "InputOutputModel.hpp"
#include "ControllerSettings.hpp"
#include "integrityManager.hpp"
#include "NotificationFactory.hpp"

extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc3;

extern InputOutputModel controllerState;
extern ControllerSettings settingsM;
extern integrityManager integrity;
extern NotificationFactory notificationFactory;
// all of those (beneath) should be deprecated; replaced by IOM and CS

ioTaskOperator::ioTaskOperator( ) :
		expoFactor(25), expoOffset(50), smoothFactor(10), conversionWaitTime(20), queueTimeoutTime(
				10), adc12bMaxVal(40.95), adc16bMaxVal(655.35), osTimeDelay(5)
{

}

void ioTaskOperator::taskEntry( )
{

	for (;;)
	{
		ioTaskOperator::readSettings( );
		// get ADC values from converters
		ioTaskOperator::getADCvalues( );



		if ( ( xTaskGetTickCount( ) - previousTick ) > 1500)
		{

/*			for (int i = 0; i < axisCount; i++)
			{
				if(checkJoyConnection(axisNorm[i]))
				{
					joyDisconnected.setTitle("Joystick disconnected  #" + std::to_string(i));
					notificationFactory.issueNotification(joyDisconnected);
				}
			}*/
			previousTick = xTaskGetTickCount( );
		}



		for (int i = 0; i < axisCount; i++)
		{
			axisBefore [i] = axisNorm [i];
		}

		// normalize 0-100 using expo curve
		axisNorm [0] = expoMap(axis1 [0] / adc16bMaxVal, expoFactor, expoOffset);
		axisNorm [1] = expoMap(axis1 [1] / adc16bMaxVal, expoFactor, expoOffset);
		axisNorm [2] = expoMap(axis3 [0] / adc12bMaxVal, expoFactor, expoOffset);
		axisNorm [3] = expoMap(axis3 [1] / adc12bMaxVal, expoFactor, expoOffset);
		axisNorm [4] = expoMap(axis3 [2] / adc12bMaxVal, expoFactor, expoOffset);

		// low pass filter n-1 / leaky integrator
		// deadzone
		// top cutoff value
		for (int i = 0; i < axisCount; i++)
		{
			axisNorm [i] = leakyIntegrator(axisNorm [i], axisBefore [i], smoothFactor);
			axisOut [i] = addDeadzone(axisNorm[i]);
			axisOut[i] = cutoffValue(axisOut[i]);
			detectJoyActivity(axisOut[i]);
		}




		ioTaskOperator::assignData( );
		osDelay(osTimeDelay);

	}

}
void ioTaskOperator::getADCvalues( )
{
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, conversionWaitTime);
	axis1 [0] = HAL_ADC_GetValue(&hadc1);
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, conversionWaitTime);
	axis1 [1] = HAL_ADC_GetValue(&hadc1);
	HAL_ADC_Start(&hadc3);
	HAL_ADC_PollForConversion(&hadc3, conversionWaitTime);
	axis3 [0] = HAL_ADC_GetValue(&hadc3);
	HAL_ADC_Start(&hadc3);
	HAL_ADC_PollForConversion(&hadc3, conversionWaitTime);
	axis3 [1] = HAL_ADC_GetValue(&hadc3);
	HAL_ADC_Start(&hadc3);
	HAL_ADC_PollForConversion(&hadc3, conversionWaitTime);
	axis3 [2] = HAL_ADC_GetValue(&hadc3);
	//srand (axis1 [0]);
}

void ioTaskOperator::assignData( )
{
	controllerState.joyData.joy1x = axisOut [0];
	controllerState.joyData.joy1y = axisOut [1];
	controllerState.joyData.joy2x = axisOut [2];
	controllerState.joyData.joy2y = axisOut [3];
	controllerState.joyData.trigg = axisOut [4];
#ifdef JOYSTICK_CONSTANT_VALUE
	controllerState.joyData.joy1x = 10;
	controllerState.joyData.joy1y = 10;
	controllerState.joyData.joy2x = 60;
	controllerState.joyData.joy2y = 10;
	controllerState.joyData.trigg = 10;
#endif
	controllerState.joyData.bttn1 = HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_4);
	controllerState.joyData.bttn2 = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3);
	controllerState.joyData.bttn3 = HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_4);
	controllerState.joyData.bttn4 = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3);
	controllerState.joyData.bttn5 = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4);
	controllerState.joyData.bttn6 = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_3); // blue button on pcb
}

void ioTaskOperator::readSettings( )
{
	expoFactor = settingsM.expoSlider/10;
	smoothFactor = 100-settingsM.smoothSlider;
	deadzone = settingsM.deadzoneSlider/10;
	topValCut = settingsM.topValueCutoff/10;
}

float ioTaskOperator::addDeadzone(float data)
{

//return ((fabs(data) < deadzone) ? (joystickMidPoint) : (data));




	if(data > joystickMidPoint+deadzone || data < joystickMidPoint-deadzone)
	{
		settingsM.deadzoneFlag = 0;
		return data;
	}

	settingsM.deadzoneFlag = 1;
	return joystickMidPoint;
}
float ioTaskOperator::cutoffValue(float data)
{
	if(data > (100 - topValCut))
	{
		return 100;
	}
	if (data < (0 + topValCut))
	{
		return 0;
	}

	return data;
}
void ioTaskOperator::detectJoyActivity(float data)
{
	//TODO detecting joy activity
	// issue: joystick randomly can jump into top or bottom value, causing this
	// to trigger even if joysticks aren't used
    if ((data > joystickMidPoint + detectMid || data < joystickMidPoint - detectMid)
    && (data < axisMax - detectBorder && data > axisMin + detectBorder))
    {
    	settingsM.sampledJoy = 1;
    }
}

bool ioTaskOperator::checkJoyConnection(float data)
{
	//TODO joystick fault detection algorithm
	// ADC-Disconnection detection basically:
	// "How to detect floating ADC Input and then suspend conversion to avoid weird behavior ?"

    if (data < axisMax - detectBorder && data > axisMin + detectBorder)
    {
    	return 1;
    }
    return 0;  //disconnected
}

void ioTaskOperator::turnOffScreen( )
{
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_15, GPIO_PIN_RESET);
}

void ioTaskOperator::turnOnScreen( )
{
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_15, GPIO_PIN_SET);
}

void ioTaskOperator::ledRed(bool state)
{
	//HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_2);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,(GPIO_PinState)state);
}

void ioTaskOperator::ledGreen(bool state)
{
	//HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_3);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,(GPIO_PinState)state);
}



void ioTaskOperator::toggleLed(led target)
{
	switch (target){
		case led::ledGreen:
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_3);
		break;
		case led::ledRed:
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_2);
		break;
	}
}
