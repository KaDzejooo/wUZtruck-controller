#ifndef AUTHORSCREENVIEW_HPP
#define AUTHORSCREENVIEW_HPP

#include <gui_generated/authorscreen_screen/authorScreenViewBase.hpp>
#include <gui/authorscreen_screen/authorScreenPresenter.hpp>

class authorScreenView : public authorScreenViewBase
{
public:
    authorScreenView();
    virtual ~authorScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // AUTHORSCREENVIEW_HPP
