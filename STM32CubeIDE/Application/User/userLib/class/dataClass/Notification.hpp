/*
 * Notification.hpp
 *
 *  Created on: Aug 25, 2023
 *      Author: KaDzejoo
 */

#ifndef NOTIFICATION_HPP_
#define NOTIFICATION_HPP_

#include <gui/containers/notificationContainer.hpp>
#include <touchgfx/Bitmap.hpp>
#include <string>
/*
 *
 */

class Notification
{
	public:
		Notification( );
		virtual ~Notification( );

		/*
		 * Set/get type of notification
		 * notification:: -text -bar -small
		 */
		notification::notificationType getType( ) const;
		void setType(notification::notificationType type);

		/*
		 * Set/get title(top Text) of notification
		 */
		const std::string& getTitle( ) const;
		void setTitle(const std::string &title);

		/*
		 * Set/get subtext (bottom text) of notification
		 */
		const std::string& getSubText( ) const;
		void setSubText(const std::string &subText);
		/*
		 * Set/get subtext (bottom text) of notification
		 * pt.2
		 */
		const std::string& getSubText2( ) const;
		void setSubText2(const std::string &subText2);

		/*
		 * Set/get text displayed under bar
		 */
		const std::string& getVehicle( ) const;
		void setVehicle(const std::string &vehicle);
		/*
		 * Set/get icon bitmap of notification
		 * 24dp
		 */
		touchgfx::Bitmap getIcon24dp( ) const;
		void setIcon24dp(touchgfx::Bitmap icon24dp);

		/*
		 * Set/get icon bitmap of notification
		 * 48dp
		 */
		touchgfx::Bitmap getIcon48dp( ) const;
		void setIcon48dp(touchgfx::Bitmap icon48dp);

		/*
		 * Set/get bar value of notification
		 * only visible when type is set to
		 * notification::bar
		 */
		int getBarValue( ) const;
		void setBarValue(int barValue);

		/*
		 * Sets/gets priority color of notification
		 * color isn't tied to priority
		 */
		notification::priorityColor getPriorityColor( ) const;
		void setPriorityColor(notification::priorityColor priorityColor);

		/*
		 * Set/get priority of notification
		 * priority sets order of notifications
		 * from top to bottom
		 * priority #0 first
		 */
		int getPriority( ) const;
		void setPriority(int priority);


		/*
		 * Decides if notification should blink on main screen
		 */
		bool isBlink( ) const;
		void setBlink(bool blink);
		/*
		 * Dynamic notifications has values that may change over lifetime
		 * of a notification
		 *
		 */
		bool isDynamic( ) const;
		void setDynamic(bool dynamic);

		/*
		 * dummy method
		 */
		bool isVisible( ) const;
		void setVisible(bool visible);


		struct notificationHasher
		{
				size_t operator()(const Notification &obj) const
				{
					//some weird shit happens here when i remove @suppress
					// it works but shows some errors
					// but compiles and runs
					// soo it gets suppressed
					return std::hash <std::string>( )(obj.getTitle( )); // @suppress("Ambiguous problem")
				}
		};
		struct notificationComparator
		{
				bool operator()(const Notification &obj1, const Notification &obj2) const
				{
					if (obj1.getTitle( ) == obj2.getTitle( )) return true;
					return false;
				}
		};


	private:
		touchgfx::Bitmap icon48dp;
		touchgfx::Bitmap icon24dp = BITMAP_SYNC_FILL0_WGHT100_GRAD200_OPSZ24_ID;
		notification::notificationType type = notification::text;
		notification::priorityColor priorityColor = notification::red;
		std::string title = "name too long bruh";
		std::string subText = "go to notificationFactory to set it";
		std::string subText2 = "";
		std::string vehicle = "not set";
		const char *textCP = title.c_str( );
		const char *subTextCP = subText.c_str( );
		const char *subText2CP = subText2.c_str( );
		const char *vehicleCP = vehicle.c_str( );
		int barValue;
		int priority = 5;
		bool visible;
		bool dynamic;
		bool blink;
};

#endif /* NOTIFICATION_HPP_ */
