#ifndef IDLESCREENPRESENTER_HPP
#define IDLESCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class idleScreenView;

class idleScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    idleScreenPresenter(idleScreenView& v);

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

    virtual ~idleScreenPresenter() {};

private:
    idleScreenPresenter();

    idleScreenView& view;
};

#endif // IDLESCREENPRESENTER_HPP
