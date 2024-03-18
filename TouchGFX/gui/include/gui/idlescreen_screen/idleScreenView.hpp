#ifndef IDLESCREENVIEW_HPP
#define IDLESCREENVIEW_HPP

#include <gui_generated/idlescreen_screen/idleScreenViewBase.hpp>
#include <gui/idlescreen_screen/idleScreenPresenter.hpp>

class idleScreenView : public idleScreenViewBase
{
public:
    idleScreenView();
    virtual ~idleScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // IDLESCREENVIEW_HPP
