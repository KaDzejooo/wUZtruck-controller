#ifndef NOTIFICATIONSCREENVIEW_HPP
#define NOTIFICATIONSCREENVIEW_HPP

#include <gui_generated/notificationscreen_screen/notificationScreenViewBase.hpp>
#include <gui/notificationscreen_screen/notificationScreenPresenter.hpp>
#include <gui/containers/notificationContainer.hpp>
#include "Notification.hpp"
#include <vector>
#include <touchgfx/mixins/FadeAnimator.hpp>
#include <touchgfx/mixins/Draggable.hpp>



class notificationScreenView : public notificationScreenViewBase
{
public:
    notificationScreenView();
    virtual ~notificationScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void updateDebugString();
    virtual void setupNotifications();
    virtual void updateNotifications();
    virtual void tickView();
    virtual void notificationsInit();
    virtual void notificationsFadeStart();

protected:

    notificationContainer notificationContainerA;
    notificationContainer notificationContainerB;
    notificationContainer notificationContainerC;
	static const int slotsSize = 31;
	touchgfx::Draggable<touchgfx::FadeAnimator<notificationContainer>> slots[slotsSize];

	touchgfx::Callback <notificationScreenView, const touchgfx::AbstractButtonContainer&> flexButtonCallback;
	touchgfx::Callback <notificationScreenView, const touchgfx::FadeAnimator<notificationContainer>&> containerFadeAnimationEndedCallback;

	void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer &src);
	void containerFadeAnimationEndedHandler(const touchgfx::FadeAnimator<notificationContainer>& comp);




	//std::vector<notificationContainer> slots;



//    notificationContainer notificationContainerC;
//    notificationContainer notificationContainerD;
//    notificationContainer notificationContainerE;
//    notificationContainer notificationContainerF;
//    notificationContainer notificationContainerG;


};

#endif // NOTIFICATIONSCREENVIEW_HPP
