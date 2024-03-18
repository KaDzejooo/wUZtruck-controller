#ifndef DEMOSCREENPRESENTER_HPP
#define DEMOSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class demoScreenView;

class demoScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    demoScreenPresenter(demoScreenView& v);

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

    virtual ~demoScreenPresenter() {}

private:
    demoScreenPresenter();

    demoScreenView& view;
};

#endif // DEMOSCREENPRESENTER_HPP
