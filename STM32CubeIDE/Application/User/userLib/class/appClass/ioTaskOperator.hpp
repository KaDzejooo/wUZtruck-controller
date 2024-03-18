/*
 * ioTaskOperator.hpp
 *
 *  Created on: 29 June 2023
 *      Author: KaDzejoo
 */

#ifndef IOTASKOPERATOR_HPP
#define IOTASKOPERATOR_HPP
#include "Notification.hpp"


enum led {
	ledRed,
	ledGreen
};

class ioTaskOperator
{
	public:
		ioTaskOperator( );
		void taskEntry( );
		void getADCvalues( );
		void assignData( );
		void readSettings( );
		float addDeadzone(float data);
		float cutoffValue(float data);
		void detectJoyActivity(float data);
		bool checkJoyConnection(float data);
		static void turnOffScreen();
		static void turnOnScreen();
		static void ledRed(bool state);
		static void ledGreen(bool state);
		static void toggleLed(led target);


	private:
		uint8_t previousTick = 0;
		float expoFactor;
		uint8_t expoOffset;
		float smoothFactor;
		uint8_t conversionWaitTime;
		uint8_t queueTimeoutTime;
		static const unsigned short int axisCount = 5;

		float deadzone = 5;
		float joystickMidPoint = 50;
		uint8_t axisMax = 100;
		uint8_t axisMin = 0;
		uint8_t detectBorder = 10;
		uint8_t detectMid = 5;
		float topValCut = 2.0;

		float adc12bMaxVal;
		float adc16bMaxVal;

		uint8_t osTimeDelay;

		long unsigned axis3 [3]; // adc3 12b
		long unsigned axis1 [2]; // adc1 16b

		float axisOut[axisCount] = {50,50,50,50,50}; // output axis data
		float axisNorm [axisCount]; // normalized axis of controller  to 0-100
		float axisBefore [axisCount]; // last
		unsigned short int RxData [257];


};

#endif /* IOTASKOPERATOR_HPP */
