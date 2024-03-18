/*
 * AbstractIOM.hpp
 *
 *  Created on: Sep 8, 2023
 *      Author: KaDzejoo
 */

#ifndef ABSTRACTIOM_HPP_
#define ABSTRACTIOM_HPP_
#include "main.h"
#include <string>

enum class VehicleType
{
		none = -1,
		truck = 0,
		roadAssist = 1,
		drift = 2,
		heli = 3,
		custom1 = 4,
};

enum class BatteryState
{
		charging,
		discharged,
		disconnected,
		fault,
		full,
		notFull
};
enum class Functions{
		basicTruckFunc,
		roadAssistFunc,
		driftFunc,
		heliFunc,
		noneFunc
};



class AbstractIOM
{
	public:
		AbstractIOM( );

//		virtual BasicTruckFunctions getData();
//		virtual RoadAssistFunctions getData();
//		virtual DriftFunctions getData();

//		virtual bool setData(BasicTruckFunctions set);
//		virtual bool setData(RoadAssistFunctions set);
//		virtual bool setData(DriftFunctions set);




		dataToSend joyData;

		void setVehicleName(std::string newName);
		int getAdress( ) const;
		void setAdress(int adress);
		int getBatteryCharge( ) const;
		void setBatteryCharge(int batteryCharge);
		bool isConnected( ) const;
		void setConnected(bool connected);
		const std::string& getConnectedVehicleName( ) const;
		void setConnectedVehicleName(const std::string &connectedVehicleName);

	protected:
		std::string connectedVehicleName = "ndef";
		bool connected = 0;
		int adress = 0;
		int batteryCharge = 0;

};/* ABSTRACTIOM_HPP_ */


#endif
