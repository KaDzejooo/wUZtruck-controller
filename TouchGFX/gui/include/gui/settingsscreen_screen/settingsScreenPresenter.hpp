#ifndef SETTINGSSCREENPRESENTER_HPP
#define SETTINGSSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class settingsScreenView;

class settingsScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    settingsScreenPresenter(settingsScreenView& v);

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

    void tickScreen();
    virtual void settingsSave(double val, int index);


    virtual ~settingsScreenPresenter() {};

private:
    settingsScreenPresenter();

    settingsScreenView& view;
};

#endif // SETTINGSSCREENPRESENTER_HPP
