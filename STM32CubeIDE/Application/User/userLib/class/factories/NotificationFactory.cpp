/*
 * NotificationFactory.cpp
 *
 *  Created on: Aug 26, 2023
 *      Author: KaDzejoo
 */

#include <class/factories/NotificationFactory.hpp>
#include <gui/containers/notificationContainer.hpp>
#include <gui/notificationscreen_screen/notificationScreenView.hpp>
#include "Notification.hpp"
#include <images/BitmapDatabase.hpp>
#include <string>
#include "InputOutputModel.hpp"
#include "ControllerSettings.hpp"
#include <vector>
#include <unordered_set>
#include "SetupSettings.hpp"
#include <stdlib.h>


extern InputOutputModel controllerState;
extern ControllerSettings settingsM;

NotificationFactory::NotificationFactory( )
{
	pendingNotifications.reserve(maxSize);
	notifications.reserve(maxSize);

	/*
	 * list of notification for use in program
	 */



}
void NotificationFactory::issueNotificationDynamic(Notification &notificationType,
		void (Notification::*funcptr)(int), int value)
{
	removeNotification(notificationType);
	( notificationType.*funcptr )(value);
	issueNotification(notificationType);
}
void NotificationFactory::issueNotificationDynamic(Notification &notificationType,
		void (Notification::*funcptr)(const std::string&), std::string newText)
{
	removeNotification(notificationType);
	( notificationType.*funcptr )(newText);
	issueNotification(notificationType);
}
void NotificationFactory::issueNotificationDynamic(Notification &notificationType,
		void (Notification::*funcptr)(touchgfx::Bitmap), touchgfx::Bitmap newBitmap)
{
	removeNotification(notificationType);
	( notificationType.*funcptr )(newBitmap);
	issueNotification(notificationType);
}
void NotificationFactory::issueNotification(Notification &notificationType)
{
	if (pendingNotifications.size( ) > getMaxSize( ))
	{
		return;
	}
	pendingNotifications.insert(notificationType);
}
void NotificationFactory::removeNotification(Notification &notificationType)
{
	if (pendingNotifications.size( ) == 0
			or pendingNotifications.find(notificationType) == pendingNotifications.end())
	{
		return;
	}
	pendingNotifications.erase(pendingNotifications.find(notificationType));
}

void NotificationFactory::removeNotification(int num)
{
	// TODO you cannot remove single notification
	// issue: you cannot remove single notification from the list of all
	// SORTED notifications
	notifications.erase(notifications.begin()+num);
}

void NotificationFactory::sortWidgetsViaPriority( )
{
	std::sort(notifications.begin( ), notifications.end( ),
			[ ](const Notification &lhs, const Notification &rhs)
			{
				return lhs.getPriority() < rhs.getPriority();
			});
}
void NotificationFactory::asignToVector( )
{
	notifications.clear( );
	if (pendingNotifications.size() == 0){
		return;
	}
	notifications.assign(pendingNotifications.begin( ), pendingNotifications.end( ));
}
void NotificationFactory::clearNotificationsSet( )
{
	pendingNotifications.clear( );
}
std::vector <Notification> NotificationFactory::getNotifications( )
{

//#ifdef ENABLE_DUMMY_MODE
//	NotificationFactory::generateDummyNotifications( );
//#endif

	NotificationFactory::asignToVector( );
	NotificationFactory::sortWidgetsViaPriority( );

	return notifications;
}
uint8_t NotificationFactory::getSize( )
{
	return pendingNotifications.size( );
}
void NotificationFactory::generateWidgets(Notification src, notificationContainer &dest)
{
	if (src.isDynamic( ))
	{
		dest.invalidate( );
	}
	dest.setIcon(src.getIcon48dp( ));
	dest.setIcon24dp(src.getIcon24dp( ));
	dest.setType(src.getType( ));
	dest.setTitle(src.getTitle( ).c_str( ));
	dest.setPriorityColor(src.getPriorityColor( ));
	dest.setSubTextTop(src.getSubText( ).c_str( ));
	dest.setSubTextBottom(src.getSubText2( ).c_str( ));
	dest.setBar(src.getBarValue( ));
	dest.setVechicleText(src.getVehicle());
	dest.setPriority(src.getPriority());
}
void NotificationFactory::generateWidgets(Notification src, notificationContainer &dest,
		notification::screen screenType)
{

	if (src.isDynamic( ))
	{
		dest.invalidate( );
	}

	dest.setType(src.getType( ));

	if (screenType == notification::mainScreen)
	{
		dest.setType(notification::small);
		dest.setWidthHeight(25, 50);
	}

	dest.setIcon(src.getIcon48dp( ));
	dest.setIcon24dp(src.getIcon24dp( ));
	dest.setTitle(src.getTitle( ).c_str( ));
	dest.setPriorityColor(src.getPriorityColor( ));
	dest.setSubTextTop(src.getSubText( ).c_str( ));
	dest.setSubTextBottom(src.getSubText2( ).c_str( ));
	dest.setBar(src.getBarValue( ));
	dest.setPriority(src.getPriority());
	dest.setVechicleText(src.getVehicle());
}

void NotificationFactory::generateDummyNotifications( )
{
	pendingNotifications.insert(NotificationDatabase::energySavingNoti);
	pendingNotifications.insert(NotificationDatabase::disconnectedNoti);
	pendingNotifications.insert(NotificationDatabase::accelSteerNoti);
	pendingNotifications.insert(NotificationDatabase::reportedErrorNoti);
	pendingNotifications.insert(NotificationDatabase::autoTruckNoti);
	pendingNotifications.insert(NotificationDatabase::batteryChargingNoti);
}
void NotificationFactory::addDummyNotification( ){
	Notification dummy;
	int rng = rand()%100;

	std::string hash = "Generated notification #";
	std::string title = std::to_string(rng);
	dummy.setType(notification::text);
	dummy.setIcon48dp(BITMAP_APPS_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	dummy.setIcon24dp(BITMAP_RADIO_BUTTON_UNCHECKED_FILL0_WGHT100_GRAD200_OPSZ24_ID);
	dummy.setTitle(hash+title);
	dummy.setPriority(rng+4);
	dummy.setPriorityColor((notification::priorityColor)(rand()%4));
	dummy.setSubText("Dummy #");
	dummy.setSubText2(std::to_string(rng+4)+" / "+std::to_string(settingsM.maxBlinkPriority));

	NotificationFactory::issueNotification(dummy);

}

