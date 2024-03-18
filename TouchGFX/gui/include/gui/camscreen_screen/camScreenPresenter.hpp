#ifndef CAMSCREENPRESENTER_HPP
#define CAMSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class camScreenView;

class camScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    camScreenPresenter(camScreenView& v);

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

    virtual ~camScreenPresenter() {};

private:
    camScreenPresenter();

    camScreenView& view;
};

#endif // CAMSCREENPRESENTER_HPP
