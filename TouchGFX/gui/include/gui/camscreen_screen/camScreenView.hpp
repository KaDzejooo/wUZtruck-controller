#ifndef CAMSCREENVIEW_HPP
#define CAMSCREENVIEW_HPP

#include <gui_generated/camscreen_screen/camScreenViewBase.hpp>
#include <gui/camscreen_screen/camScreenPresenter.hpp>
#include <touchgfx/widgets/Image.hpp>
#include "SetupSettings.hpp"

class camScreenView : public camScreenViewBase
{
public:
    camScreenView();
    virtual ~camScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:

    touchgfx::Image imageCameraDynamic;
};

#endif // CAMSCREENVIEW_HPP
