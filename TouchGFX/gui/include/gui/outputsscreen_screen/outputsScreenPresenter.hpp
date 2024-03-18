#ifndef OUTPUTSSCREENPRESENTER_HPP
#define OUTPUTSSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class outputsScreenView;

class outputsScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    outputsScreenPresenter(outputsScreenView& v);

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

    void tickScreen( );

    virtual ~outputsScreenPresenter() {}

private:
    outputsScreenPresenter();

    outputsScreenView& view;
};

#endif // OUTPUTSSCREENPRESENTER_HPP
