#ifndef NOTIFICATIONCONTAINER_HPP
#define NOTIFICATIONCONTAINER_HPP

#include <gui_generated/containers/notificationContainerBase.hpp>
#include <string>
#include <images/BitmapDatabase.hpp>

namespace notification
{
	enum notificationType
	{
			bar,
			text,
			small
	};

	enum priorityColor
	{
			red,
			orange,
			blue,
			green
	};
	enum screen
	{
		mainScreen,
		notificationScreen
	};

}

class notificationContainer : public notificationContainerBase
{
	public:
		notificationContainer( );
		virtual ~notificationContainer( )
		{
		}

		virtual void initialize( );
		void setIcon(touchgfx::Bitmap iconId);
		void setIcon24dp(touchgfx::Bitmap iconId24dp);
		void setType(notification::notificationType type);
		void setPriorityColor(notification::priorityColor color);
		void setTitle(std::string title);
		void setSubTextTop(std::string subtext);
		void setSubTextBottom(std::string subtext);
		void setVechicleText(std::string text);
		void setVechicleText(const char* text);
		void setSubTextTop(const char *subtext);
		void setSubTextBottom(const char *subtext);
		void setTitle(const char *title);
		void setBar(int percentage);



		void setColor(uint8_t r,uint8_t g,uint8_t b);



		int getAlpha();
		void setAlpha(uint8_t newAlpha);


		bool operator <(const notificationContainer &src) const
		{
			return ( priority < src.priority );
		}
		void setPriority(int priority)
		{
			this->priority = priority;
		}
		int getPriority()
		{
			return priority;
		}
	    touchgfx::PainterRGB888 getPainter(){return lineDecoPainter;};
	protected:
		int alpha=0;
		int priority;
};

#endif // NOTIFICATIONCONTAINER_HPP
