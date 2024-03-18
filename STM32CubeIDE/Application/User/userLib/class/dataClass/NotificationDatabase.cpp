/*
 * NotificationDatabase.cpp
 *
 *  Created on: Mar 4, 2024
 *      Author: KaDzejoo
 */

#include <NotificationDatabase.hpp>

NotificationDatabase::NotificationDatabase( )
{
	dynamicTry.setType(notification::text);
	dynamicTry.setIcon48dp(BITMAP_STADIA_CONTROLLER_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	dynamicTry.setIcon24dp(BITMAP_WARNING_FILL0_WGHT100_GRAD200_OPSZ24_ID);
	dynamicTry.setTitle("IO Task operator");
	dynamicTry.setPriorityColor(notification::red);
	dynamicTry.setBarValue(45);
	dynamicTry.setSubText("you shouldn't see that");
	dynamicTry.setSubText2("if you see 'joy1x = x %' it works ");
	dynamicTry.setVehicle("Disconnected");
	dynamicTry.setPriority(5);

	joyDisconnected.setType(notification::text);
	joyDisconnected.setIcon48dp(BITMAP_STADIA_CONTROLLER_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	joyDisconnected.setIcon24dp(BITMAP_WARNING_FILL0_WGHT100_GRAD200_OPSZ24_ID);
	joyDisconnected.setTitle("Joystick disconnected");
	joyDisconnected.setPriorityColor(notification::red);
	joyDisconnected.setSubText("you shouldn't see that");
	joyDisconnected.setSubText2("one of the joysticks has faulty connection");
	joyDisconnected.setVehicle("");
	joyDisconnected.setPriority(0);

	batteryCtrlLowNoti.setType(notification::text);
	batteryCtrlLowNoti.setIcon48dp(BITMAP_BATTERY_ERROR_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	batteryCtrlLowNoti.setIcon24dp(BITMAP_OUTLINE_BATTERY_ALERT_WHITE_24DP_ID);
	batteryCtrlLowNoti.setTitle("Controller battery low");
	batteryCtrlLowNoti.setPriorityColor(notification::red);
	batteryCtrlLowNoti.setSubText("Controller battery is low");
	batteryCtrlLowNoti.setSubText2("Consider connecting to charger");
	batteryCtrlLowNoti.setPriority(0);

	batteryTruckLowNoti.setType(notification::text);
	batteryTruckLowNoti.setIcon48dp(BITMAP_BATTERY_ERROR_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	batteryTruckLowNoti.setIcon24dp(BITMAP_OUTLINE_BATTERY_ALERT_WHITE_24DP_ID);
	batteryTruckLowNoti.setTitle("Vehicle battery low");
	batteryTruckLowNoti.setPriorityColor(notification::red);
	batteryTruckLowNoti.setSubText("Vehicle battery is low");
	batteryTruckLowNoti.setSubText2("Reduced screen time and processing speed");
	batteryTruckLowNoti.setPriority(0);

	batteryChargingNoti.setType(notification::text);
	batteryChargingNoti.setIcon48dp(BITMAP_BATTERY_CHARGING_FULL_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	batteryChargingNoti.setIcon24dp(BITMAP_BATTERY_CHARGING_80_FILL0_WGHT100_GRAD200_OPSZ24_ID);
	batteryChargingNoti.setTitle("Battery charging");
	batteryChargingNoti.setPriorityColor(notification::blue);
	batteryChargingNoti.setSubText("Controlleer battery is charging ");
	batteryChargingNoti.setSubText2("est. time: 21:37");
	batteryChargingNoti.setPriority(2);

	autoTruckNoti.setType(notification::text);
	autoTruckNoti.setIcon48dp(BITMAP_DETECTION_AND_ZONE_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	autoTruckNoti.setIcon24dp(BITMAP_HDR_AUTO_FILL0_WGHT100_GRAD200_OPSZ24_ID);
	autoTruckNoti.setTitle("Auto truck backing is enabled");
	autoTruckNoti.setPriorityColor(notification::green);
	autoTruckNoti.setSubText("Directional controll is now provided by system");
	autoTruckNoti.setSubText2("move via LT and RT");
	autoTruckNoti.setPriority(4);

	reportedErrorNoti.setType(notification::text);
	reportedErrorNoti.setIcon48dp(BITMAP_NEARBY_ERROR_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	reportedErrorNoti.setIcon24dp(BITMAP_WARNING_FILL0_WGHT100_GRAD200_OPSZ24_ID);
	reportedErrorNoti.setTitle("Vehicle reported error");
	reportedErrorNoti.setPriorityColor(notification::red);
	reportedErrorNoti.setSubText("Check engine");
	reportedErrorNoti.setSubText2("");
	reportedErrorNoti.setPriority(0);

	memoryCardNoti.setType(notification::text);
	memoryCardNoti.setIcon48dp(BITMAP_SIM_CARD_DOWNLOAD_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	memoryCardNoti.setIcon24dp(BITMAP_SD_CARD_FILL0_WGHT100_GRAD200_OPSZ24_ID);
	memoryCardNoti.setTitle("Inserted memory card");
	memoryCardNoti.setPriorityColor(notification::blue);
	memoryCardNoti.setSubText("Reading content");
	memoryCardNoti.setSubText2("please wait");
	memoryCardNoti.setPriority(2);

	disconnectedNoti.setType(notification::text);
	disconnectedNoti.setIcon48dp(BITMAP_SIGNAL_DISCONNECTED_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	disconnectedNoti.setIcon24dp(BITMAP_SIGNAL_WIFI_BAD_FILL0_WGHT100_GRAD200_OPSZ24_ID);
	disconnectedNoti.setTitle("Vehicle disconnected");
	disconnectedNoti.setPriorityColor(notification::red);
	disconnectedNoti.setSubText("Go to vehicle selection screen to connect again");
	disconnectedNoti.setSubText2("");
	disconnectedNoti.setPriority(0);

	cameraDisabledNoti.setType(notification::text);
	cameraDisabledNoti.setIcon48dp(BITMAP_VIDEOCAM_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	cameraDisabledNoti.setIcon24dp(BITMAP_VIDEOCAM_OFF_FILL0_WGHT100_GRAD200_OPSZ24_ID);
	cameraDisabledNoti.setTitle("Camera disabled");
	cameraDisabledNoti.setPriorityColor(notification::orange);
	cameraDisabledNoti.setSubText("Camera video feed disconnected");
	cameraDisabledNoti.setSubText2("");
	cameraDisabledNoti.setPriority(1);

	cameraEnabledNoti.setType(notification::text);
	cameraEnabledNoti.setIcon48dp(BITMAP_VIDEOCAM_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	cameraEnabledNoti.setIcon24dp(BITMAP_VIDEOCAM_FILL0_WGHT100_GRAD200_OPSZ24_ID);
	cameraEnabledNoti.setTitle("Camera enabled");
	cameraEnabledNoti.setPriorityColor(notification::blue);
	cameraEnabledNoti.setSubText("Camera enabled, use secondary joystick to move");
	cameraEnabledNoti.setSubText2("may reduce overall performance of controller");
	cameraEnabledNoti.setPriority(2);

	accelSteerNoti.setType(notification::text);
	accelSteerNoti.setIcon48dp(BITMAP_TREED_ROTATION_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	accelSteerNoti.setIcon24dp(BITMAP_TREED_ROTATION_FILL0_WGHT100_GRAD200_OPSZ24_ID);
	accelSteerNoti.setTitle("Accelerometer steering ON");
	accelSteerNoti.setPriorityColor(notification::green);
	accelSteerNoti.setSubText("Now enabled acc steering, tilt controller to steer");
	accelSteerNoti.setSubText2("go to settings to change blending amount");
	accelSteerNoti.setPriority(4);

	lockNoti.setType(notification::text);
	lockNoti.setIcon48dp(BITMAP_KEY_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	lockNoti.setIcon24dp(BITMAP_LOCK_FILL0_WGHT100_GRAD200_OPSZ24_ID);
	lockNoti.setTitle("Controller lock");
	lockNoti.setPriorityColor(notification::red);
	lockNoti.setSubText("Steering disabled");
	lockNoti.setSubText2("Log in to enagle all functions");
	lockNoti.setPriority(0);

	energySavingNoti.setType(notification::text);
	energySavingNoti.setIcon48dp(BITMAP_ENERGY_SAVINGS_LEAF_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	energySavingNoti.setIcon24dp(BITMAP_BATTERY_SAVER_FILL0_WGHT100_GRAD200_OPSZ24_ID);
	energySavingNoti.setTitle("Energy saving Mode");
	energySavingNoti.setPriorityColor(notification::green);
	energySavingNoti.setSubText("Enabled energy saving mode");
	energySavingNoti.setSubText2("Reduced screen time and processing speed");
	energySavingNoti.setPriority(4);

	controllerHardwareNoti.setType(notification::text);
	controllerHardwareNoti.setIcon48dp(BITMAP_STADIA_CONTROLLER_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	controllerHardwareNoti.setIcon24dp(BITMAP_WARNING_FILL0_WGHT100_GRAD200_OPSZ24_ID);
	controllerHardwareNoti.setTitle("Controller hardware error reported");
	controllerHardwareNoti.setPriorityColor(notification::red);
	controllerHardwareNoti.setSubText("Controller hardware may be malfunctioning");
	controllerHardwareNoti.setSubText2("Please check all components");
	controllerHardwareNoti.setPriority(1);
}
