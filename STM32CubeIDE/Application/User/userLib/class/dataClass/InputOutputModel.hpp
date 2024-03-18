/*
 // * InputOutput.hpp
 *
 *  Created on: 11 lip 2023
 *      Author: KaDzejoo
 */

#ifndef INPUTOUTPUTMODEL_HPP_
#define INPUTOUTPUTMODEL_HPP_
#include "main.h"
#include <string>
#include "UTypes.hpp"

class InputOutputModel
{



	public:

		// SYNTAX - how to assign value to enum
		// by default set to none
		// TruckType truckType = TruckType::truck;



		TruckType truckType = TruckType::drift;

		std::string connectedTruckName = "Mazda RX7 Drift";
		const char *connectedTruckNameCP = connectedTruckName.c_str( );

		// all trucks
		bool topLights;
		bool highBeams;
		bool lowBeams;
		bool posLights;
		bool dayLights;
		bool hazards;
		bool leftBlinker;
		bool rightBlinker;
		bool fogLightsFront;
		bool fogLightsRear;
		bool gearUp;
		bool gearDown;
		bool horn;

		// truck specific
		bool axleLifting;
		bool trailerConnect;
		//road assist specific
		bool firstWinchUp;
		bool firstWinchDown;
		bool secondWinchUp;
		bool secondWinchDown;

		bool rightSupportRetrtact;
		bool rightSupportEject;
		bool leftSupportRetrtact;
		bool leftSupportEject;

		bool armRetract;
		bool armEject;
		bool armUp;
		bool armDown;

		bool forkRetract;
		bool forkEject;
		bool forkUp;
		bool forkDown;

		// #1 winch
		// #2 winch
		// R support
		// L support
		// arm
		// fork


		// drift
		bool lights;

		// gears
		uint8_t gear = 1;
		uint8_t maxGear = 3;
		uint8_t minGear = 1;


		bool connected = 0;
		uint8_t adress = 0x00; // none by default;


		// battery
		batteryState batteryStatus = batteryState::discharged;
		uint8_t batteryChargeController = 35;
		uint8_t batteryChargeVehicle = 55;

		// controller status
		bool idle = 0;

		/// default params
		uint8_t camx = 50;
		int noneVal = 50;
		/*
		 * Struct defined in main.h
		 * contains all joystick axis and buttons
		 */
		dataToSend joyData;


		// assignment of joystick axis into functions
		controllerFunc axis;

		InputOutputModel( );
		/*
		 * Sets vehicle name to newName
		 */
		void setVehicleName(std::string newName);
		/*
		 * Sets vehicle type to one of TruckType enum
		 * that are defined above in IOM class header
		 */
		void setTruckType( );
		void setTruckType(TruckType type);
		/*
		 * Getter to whole dataToSend joystick buttons and axis status
		 */
		const dataToSend& getJoyData( ) const;
		/*
		 * Setter to whole dataToSend joystick buttons and axis status
		 */
		void setJoyData(const dataToSend &joyDataIn);

		/*
		 * Turns all lights off
		 */
		void turnLightsOff(bool all = 1);
		/*
		 * sets gear button to 0
		 */
		void resetGearButton( );
		/*
		 * Sets All winches down
		 */
		void winchesDown( );
		/*
		 * Reinitialize IOM class with all zeroes
		 * useful after connecting to new vehicle
		 */
		void iomReInit( );

};

#endif /* INPUTOUTPUTMODEL_HPP_ */
