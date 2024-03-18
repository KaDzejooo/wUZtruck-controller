#ifndef HELPSCREENVIEW_HPP
#define HELPSCREENVIEW_HPP

#include <gui_generated/helpscreen_screen/helpScreenViewBase.hpp>
#include <gui/helpscreen_screen/helpScreenPresenter.hpp>
#include <gui/containers/helpFunctions.hpp>


class helpScreenView : public helpScreenViewBase
{
public:
    helpScreenView();
    virtual ~helpScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:

};

#endif // HELPSCREENVIEW_HPP
