/*
 * NotificationDatabase.hpp
 *
 *  Created on: Mar 4, 2024
 *      Author: KaDzejoo
 */

#ifndef NOTIFICATIONDATABASE_HPP_
#define NOTIFICATIONDATABASE_HPP_
#include <gui/containers/notificationContainer.hpp>
#include <images/BitmapDatabase.hpp>
#include "Notification.hpp"
/*
 *
 */
class NotificationDatabase
{
	public:
		NotificationDatabase( );
		Notification batteryTruckLowNoti;
		Notification batteryCtrlLowNoti;
		Notification batteryChargingNoti;
		Notification autoTruckNoti;
		Notification reportedErrorNoti;
		Notification memoryCardNoti;
		Notification controllerHardwareNoti;
		Notification disconnectedNoti;
		Notification cameraDisabledNoti, cameraEnabledNoti;
		Notification accelSteerNoti;
		Notification lockNoti;
		Notification energySavingNoti;
		Notification dynamicTry;
		Notification joyDisconnected;

};

#endif /* NOTIFICATIONDATABASE_HPP_ */
