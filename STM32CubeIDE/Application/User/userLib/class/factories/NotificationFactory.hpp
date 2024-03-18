/*
 * NotificationFactory.hpp
 *
 *  Created on: Aug 26, 2023
 *      Author: KaDzejoo
 */

#ifndef NOTIFICATIONFACTORY_HPP_
#define NOTIFICATIONFACTORY_HPP_

#include <touchgfx/Bitmap.hpp>
#include <gui/notificationscreen_screen/notificationScreenView.hpp>
#include <gui/containers/notificationContainer.hpp>
#include <images/BitmapDatabase.hpp>
#include <vector>
#include <string>
#include <algorithm>
#include "Notification.hpp"
#include <bits/stdc++.h>
#include <touchgfx/containers/ListLayout.hpp>
#include <NotificationDatabase.hpp>

class NotificationFactory: public NotificationDatabase
{
	public:

		NotificationFactory( );

		/*
		 * method for issuing notifications from other places in program
		 *
		 */
		void issueNotification(Notification &notificationType);

		/*
		 * method for issuing dynamic notifications from other places in program
		 * dynamic notifications changes state or data in lifetime of notification
		 */
		void issueNotificationDynamic(Notification &notificationType,
				void (Notification::*funcptr)(int), int value);
		void issueNotificationDynamic(Notification &notificationType,void (Notification::*funcptr)(const std::string&)
				, std::string newText);
		void issueNotificationDynamic(Notification &notificationType,void (Notification::*funcptr)(touchgfx::Bitmap)
				, touchgfx::Bitmap newBitmap);
		/*
		 * method for removing notifications from other places in program
		 *
		 */
		void removeNotification(Notification &notificationType);
		void removeNotification(int num);
		/*
		 * generates 6 dummy notifications for showing
		 */
		void generateDummyNotifications( );
		/*
		 * adds 1 random generated notification to the pool
		 */
		void addDummyNotification( );
		/*
		 * Returns Size of notification vector
		 */
		uint8_t getSize( );
		/*
		 * Returns maxSize of notification vector
		 */
		uint8_t getMaxSize( )
		{
			return maxSize;
		}
		;
		/*
		 * returns notification vector with removed duplicates and sorted
		 */
		std::vector <Notification> getNotifications( );

		/*
		 * Generates notificationContainer from notification class
		 */
		static void generateWidgets(Notification src, notificationContainer &dest);
		/*
		 * Generates notificationContainer from notification class
		 * variant that takes parameter, thus generating small widgets,
		 * TODO other types of notifications (mandatory ??)
		 */
		static void generateWidgets(Notification src, notificationContainer &dest,
				notification::screen screenType);
		/*
		 * clears entire notification vector, removing all elements
		 */
		void clearNotificationsSet( );

	private:
		/*
		 * Assigns set of notifications to vector
		 */
		void asignToVector( );
		/*
		 *  Sorts all notifications using priority and provided
		 *  sorting function (right now using lambda expression)
		 */
		void sortWidgetsViaPriority( );

		uint8_t maxSize = 32;
		std::vector <Notification> notifications;
		std::unordered_set <Notification, Notification::notificationHasher,
				Notification::notificationComparator> pendingNotifications;
	public:
		/*
		 * define notifications here \/
		 * and add enum
		 */


};

#endif /* NOTIFICATIONFACTORY_HPP_ */
