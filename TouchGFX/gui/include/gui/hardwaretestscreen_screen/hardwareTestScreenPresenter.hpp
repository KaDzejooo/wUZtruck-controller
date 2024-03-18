#ifndef HARDWARETESTSCREENPRESENTER_HPP
#define HARDWARETESTSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class hardwareTestScreenView;

class hardwareTestScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    hardwareTestScreenPresenter(hardwareTestScreenView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();
    virtual void tickScreen();
    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~hardwareTestScreenPresenter() {};

private:
    hardwareTestScreenPresenter();

    hardwareTestScreenView& view;
};

#endif // HARDWARETESTSCREENPRESENTER_HPP
