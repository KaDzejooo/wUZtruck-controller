#ifndef STARTUPSCREENVIEW_HPP
#define STARTUPSCREENVIEW_HPP

#include <gui_generated/startupscreen_screen/startupScreenViewBase.hpp>
#include <gui/startupscreen_screen/startupScreenPresenter.hpp>

class startupScreenView : public startupScreenViewBase
{
public:
    startupScreenView();
    virtual ~startupScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void moveText();
    void tickScreen();
protected:
    int y = 272;
};

#endif // STARTUPSCREENVIEW_HPP
