/*
 * VehicleFactory.cpp
 *
 *  Created on: Sep 17, 2023
 *      Author: KaDzejoo
 */

#include <class/factories/VehicleFactory.hpp>

VehicleFactory::VehicleFactory( )
{

}

VehicleFactory::panel VehicleFactory::createVehicle(vehicleData newVehicle)
{

	panel retVal;
//	newVehicle.type;
//	newVehicle.battery;
//	newVehicle.iconStatus;
//	newVehicle.connection;
//	newVehicle.name;
//	newVehicle.adress;

	containerButtonConnect graphics;

	graphics.setStatusIcon(newVehicle.iconStatus);
	graphics.setName(newVehicle.name);
	graphics.setBatteryIcon(newVehicle.battery);
	graphics.setConnectionStatus(newVehicle.connection);
	graphics.setButtonIcon(newVehicle.type);

	touchgfx::RadioButton button;
	button.setXY(0, 0);
	button.setPosition(0, 0, 300, 50);
	button.setSelected(true);
	button.setDeselectionEnabled(true);

	touchgfx::Container container;
	container.setWidth(300);
	container.setHeight(50);

	container.add(graphics);
	container.add(button);

	retVal.button = button;
	retVal.container = container;
	retVal.widget = graphics;

	return retVal;
}
