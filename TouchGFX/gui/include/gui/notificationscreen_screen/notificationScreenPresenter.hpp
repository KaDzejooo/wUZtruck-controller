#ifndef NOTIFICATIONSCREENPRESENTER_HPP
#define NOTIFICATIONSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class notificationScreenView;

class notificationScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    notificationScreenPresenter(notificationScreenView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual void tickScreen();
    virtual ~notificationScreenPresenter() {};

private:
    notificationScreenPresenter();

    notificationScreenView& view;
};

#endif // NOTIFICATIONSCREENPRESENTER_HPP
