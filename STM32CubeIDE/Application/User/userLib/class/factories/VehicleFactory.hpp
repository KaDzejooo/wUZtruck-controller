/*
 * VehicleFactory.hpp
 *
 *  Created on: Sep 17, 2023
 *      Author: KaDzejoo
 */

#ifndef VEHICLEFACTORY_HPP_
#define VEHICLEFACTORY_HPP_
#include <gui/containers/containerButtonConnect.hpp>
#include <touchgfx/widgets/RadioButton.hpp>
#include <touchgfx/widgets/RadioButtonGroup.hpp>
#include <vector>
/*
 *
 */
class VehicleFactory
{
	public:
		class vehicleData
		{
			public:
				TruckType type;
				int battery;
				const Bitmap &iconStatus;
				int connection;
				std::string name;
				int adress;
		};
		class panel
		{
			public:
				containerButtonConnect widget;
				touchgfx::RadioButton button;
				touchgfx::Container container;
		};

		VehicleFactory( );
		static panel createVehicle(vehicleData newVehicle);

	private:
		//static int numberOfVehicles = 0 ;
//		std::vector <containerButtonConnect&> widget;
//		std::vector <touchgfx::RadioButton&> button;
//		std::vector <touchgfx::Container&> container;
};

#endif /* VEHICLEFACTORY_HPP_ */
