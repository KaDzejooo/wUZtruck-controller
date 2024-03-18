#ifndef MAINSCREENVIEW_HPP
#define MAINSCREENVIEW_HPP

#include <gui_generated/mainscreen_screen/mainScreenViewBase.hpp>
#include <gui/mainscreen_screen/mainScreenPresenter.hpp>
#include <gui/containers/notificationContainer.hpp>
#include <touchgfx/mixins/FadeAnimator.hpp>
#include <gui/common/CustomKeyboard.hpp>
#include <gui/common/WhitePainter.hpp>
#include <gui/common/WhiteFilter.hpp>

class mainScreenView : public mainScreenViewBase
{
	public:
		mainScreenView( );

		virtual ~mainScreenView( )
		{
		}

		virtual void setupScreen( );
		virtual void tearDownScreen( );

		//virtual void saveButton(bool n1,bool n2, bool n3,bool n4);
		virtual void tickView( );
		virtual void updateGearDisp( );
		virtual void setupDisplay( );
		virtual void setupButtonState( );
		virtual void updateDebugString( );
		virtual void setupNotifications( );
		virtual void updateNotifications( );
		virtual void notificationInit( );
		virtual void notificationsFadeStart( );
		void updateGauge();

		touchgfx::Bitmap gearIcon;
	protected:

		CustomKeyboard keyboard;



		touchgfx::Image imageCameraDynamic;
		touchgfx::FadeAnimator <touchgfx::Image> plusImage;
		static const int notificationSlots = 6;
		touchgfx::FadeAnimator <notificationContainer> notifications [notificationSlots];

		int maxPriorityBlink = 1;
		touchgfx::Callback <mainScreenView, const touchgfx::FadeAnimator <touchgfx::Image>&> imageFadeAnimationEndedCallback;
		touchgfx::Callback <mainScreenView, const touchgfx::AbstractButtonContainer&> flexButtonCallback;
		touchgfx::Callback <mainScreenView, const touchgfx::FadeAnimator <notificationContainer>&> containerFadeAnimationEndedCallback;
	private:
		void containerFadeAnimationEndedHandler(
				const touchgfx::FadeAnimator <notificationContainer> &comp);
		void imageFadeAnimationEndedHandler(const touchgfx::FadeAnimator <touchgfx::Image> &comp);
		void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer &src);
};

#endif // MAINSCREENVIEW_HPP
