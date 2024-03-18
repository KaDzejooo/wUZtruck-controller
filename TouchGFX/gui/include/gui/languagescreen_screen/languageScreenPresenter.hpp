#ifndef LANGUAGESCREENPRESENTER_HPP
#define LANGUAGESCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class languageScreenView;

class languageScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    languageScreenPresenter(languageScreenView& v);

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

    virtual ~languageScreenPresenter() {};

private:
    languageScreenPresenter();

    languageScreenView& view;
};

#endif // LANGUAGESCREENPRESENTER_HPP
