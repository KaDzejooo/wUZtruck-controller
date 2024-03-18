#ifndef LIGHTSSCREENPRESENTER_HPP
#define LIGHTSSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class lightsScreenView;

class lightsScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    lightsScreenPresenter(lightsScreenView& v);

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

    virtual ~lightsScreenPresenter() {};

private:
    lightsScreenPresenter();

    lightsScreenView& view;
};

#endif // LIGHTSSCREENPRESENTER_HPP
