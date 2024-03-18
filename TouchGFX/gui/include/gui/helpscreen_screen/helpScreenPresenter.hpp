#ifndef HELPSCREENPRESENTER_HPP
#define HELPSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class helpScreenView;

class helpScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    helpScreenPresenter(helpScreenView& v);

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

    virtual ~helpScreenPresenter() {}

private:
    helpScreenPresenter();

    helpScreenView& view;
};

#endif // HELPSCREENPRESENTER_HPP
