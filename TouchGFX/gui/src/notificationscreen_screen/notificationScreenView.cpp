#include <gui/notificationscreen_screen/notificationScreenView.hpp>
#include <images/BitmapDatabase.hpp>
#include <NotificationFactory.hpp>
#include <sys/_stdint.h>
#include <touchgfx/Bitmap.hpp>
#include <touchgfx/Screen.hpp>
#include <touchgfx/Unicode.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <string>
#include "SetupSettings.hpp"
#include "ThemeFactory.hpp"
#include "InputOutputModel.hpp"

extern NotificationFactory notificationFactory;
extern InputOutputModel controllerState;
extern char debugStringBuffer [80];

notificationScreenView::notificationScreenView( ) :
		flexButtonCallback(this, &notificationScreenView::flexButtonCallbackHandler),
		containerFadeAnimationEndedCallback(this, &notificationScreenView::containerFadeAnimationEndedHandler)
{
	/*
	 * Those two notifications will stay on forever
	 * vehicle battery / controller battery
	 */
	textAmount.setWildcard(textAmountBuffer);
	buttonClear.setAction(flexButtonCallback);

	notificationContainerA.setType(notification::bar);
	notificationContainerA.setIcon(BITMAP_DIRECTIONS_CAR_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	notificationContainerA.setTitle("Vehicle battery");
	notificationContainerA.setPriorityColor(notification::blue);
	notificationContainerA.setVechicleText("Disconected  ");
	notificationContainerA.setBar(controllerState.batteryChargeVehicle);

	notificationContainerB.setType(notification::bar);
	notificationContainerB.setIcon(BITMAP_STADIA_CONTROLLER_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	notificationContainerB.setTitle("Controller battery");
	notificationContainerB.setPriorityColor(notification::blue);
	notificationContainerB.setBar(controllerState.batteryChargeController);

#ifdef ENABLE_DEBUG_PRINTER
	notificationContainerC.setType(notification::text);
	notificationContainerC.setIcon(BITMAP_SETTINGS_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	notificationContainerC.setTitle("Debug printer enabled");
	notificationContainerC.setPriorityColor(notification::blue);
	notificationContainerC.setSubTextTop("Debug printer enabled");
	notificationContainerC.setSubTextBottom("Debug printer enabled");
#endif

}

void notificationScreenView::setupScreen( )
{
	std::vector<touchgfx::PainterRGB888*> painters;
	painters.push_back(&lineDecoScroll1Painter);
	painters.push_back(&lineDecoScroll2Painter);
	painters.push_back(&circleAmountPainter);

	ThemeFactory th(settingsM.user);
	th.bindBackground(background);
	th.applyPainters(painters);
	th.bindColorSecondary(notificationContainerA);
	th.bindColorSecondary(notificationContainerB);

	listNotification.add(notificationContainerA);
	listNotification.add(notificationContainerB);

#ifdef ENABLE_DEBUG_PRINTER
	listNotification.add(notificationContainerC);
#endif

	notificationScreenView::notificationsInit( );
	notificationScreenView::setupNotifications( );
	notificationScreenView::notificationsFadeStart( );
	notificationScreenViewBase::setupScreen( );
}

void notificationScreenView::tearDownScreen( )
{
	listNotification.removeAll( );
	notificationScreenViewBase::tearDownScreen( );
}

void notificationScreenView::tickView( )
{
	static int tickCount = 0;
	static int prevTickCount = 0;





	if (tickCount - prevTickCount > 60)
	{
		//int scroll = scrollableNotification.getScrolledY( );
		notificationScreenView::updateNotifications( );
		//scrollableNotification.doScroll(0, scroll);
		prevTickCount = tickCount;
	}
	tickCount++;

	//notificationScreenView::setupNotifications();
#ifdef ENABLE_DEBUG_PRINTER
	notificationScreenView::updateDebugString();
#endif
}

void notificationScreenView::updateDebugString( )
{
	static int count = 0;
	count++;
	snprintf(debugStringBuffer, sizeof ( debugStringBuffer ), "nickleback: %d", count);
	Application::getDebugPrinter( )->setString(debugStringBuffer);
	Application::invalidateDebugRegion( );
}

void notificationScreenView::setupNotifications( )
{
	std::vector <Notification> notify = notificationFactory.getNotifications( );
	settingsM.notificationCount = notify.size( );
	Unicode::snprintf(textAmountBuffer, TEXTAMOUNT_SIZE, "%d", notificationFactory.getSize( ));

	for (uint8_t i = 0; i < notify.size( ); i++)
	{
		if (i == ( slotsSize - 1 ))
		{
			return;
		}
		NotificationFactory::generateWidgets(notify [i], slots [i]);
		listNotification.add(slots [i]);
	}


//		if (slots [0].getX( ) > 100)
//		{
//			notificationFactory.removeNotification(notify [0]);
//			listNotification.invalidate();
//		}


}

void notificationScreenView::updateNotifications( )
{
	int scroll = scrollableNotification.getScrolledY( );

	listNotification.removeAll( );
	listNotification.add(notificationContainerA);
	listNotification.add(notificationContainerB);
	notificationsFadeStart( );
	notificationScreenView::setupNotifications( );

	scrollableNotification.doScroll(0, scroll);
	listNotification.invalidate( );
}
void notificationScreenView::notificationsInit( )
{

	for (uint8_t i = 0; i < slotsSize; i++)
	{
		slots [i].setFadeAnimationEndedAction(containerFadeAnimationEndedCallback);
		slots [i].startFadeAnimation(255, 30 + ( 5 * i ), touchgfx::EasingEquations::expoEaseInOut);
	}
}
void notificationScreenView::notificationsFadeStart( )
{
	for (uint8_t i = 0; i < slotsSize; i++)
	{
		if (slots [i].isFadeAnimationRunning( ) == 0
				&& slots [i].getPriority( ) < settingsM.maxBlinkPriority)
		{
			slots [i].setAlpha(50);
			slots [i].startFadeAnimation(255, 40 + i, touchgfx::EasingEquations::expoEaseInOut);
		}
	}
}
void notificationScreenView::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer &src)
{

	if (&src == &buttonClear)
	{
		listNotification.removeAll( );
		listNotification.add(notificationContainerA);
		listNotification.add(notificationContainerB);
		notificationFactory.clearNotificationsSet( );
		listNotification.invalidate( );
		background.invalidate( );
	}
}

void notificationScreenView::containerFadeAnimationEndedHandler(
		const touchgfx::FadeAnimator <notificationContainer> &comp)
{
	{
		for (uint8_t i = 0; i < slotsSize; i++)
		{
			if (&comp == &slots [i] && slots [i].getPriority( ) < settingsM.maxBlinkPriority)
			{
				if (slots [i].getAlpha( ) == 50)
				{
					slots [i].startFadeAnimation(255, 30, touchgfx::EasingEquations::expoEaseInOut);
				}
				if (slots [i].getAlpha( ) == 255)
				{
					slots [i].startFadeAnimation(50, 30, touchgfx::EasingEquations::expoEaseInOut);
				}
			}
		}
	}

}
