#ifndef LIGHTSSCREENVIEW_HPP
#define LIGHTSSCREENVIEW_HPP

#include <gui_generated/lightsscreen_screen/lightsScreenViewBase.hpp>
#include <gui/lightsscreen_screen/lightsScreenPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/ButtonWithIcon.hpp>
#include <touchgfx/containers/ListLayout.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/ButtonWithIcon.hpp>

class lightsScreenView : public lightsScreenViewBase
{
public:
    lightsScreenView();
    virtual ~lightsScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void button2clicked();
    virtual void setupButtons();
    virtual void tearDownButtons();
protected:

    //touchgfx::ButtonWithIcon button2;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ToggleButtonTrigger >  >  lowBeamsButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ToggleButtonTrigger >  >  highBeamsButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ToggleButtonTrigger >  >  topLightsButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ToggleButtonTrigger >  >  posLightsButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ToggleButtonTrigger >  >  hazardsButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ToggleButtonTrigger >  >  leftBlinkerButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ToggleButtonTrigger >  >  rightBlinkerButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ToggleButtonTrigger >  >  fogLightsFrontButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ToggleButtonTrigger >  >  fogLightsRearButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ToggleButtonTrigger >  >  gearUpButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ToggleButtonTrigger >  >  gearDownButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ToggleButtonTrigger >  >  hornButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ToggleButtonTrigger >  >  axleLiftingButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ToggleButtonTrigger >  >  trailerConnectButton;

// road assist buttons
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ToggleButtonTrigger >  >  firstWinchUpButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ToggleButtonTrigger >  >  firstWinchDownButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ToggleButtonTrigger >  >  secondWinchDownButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ToggleButtonTrigger >  >  secondWinchUpButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ToggleButtonTrigger >  >  rightSupportRetrtactButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ToggleButtonTrigger >  >  rightSupportEjectButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ToggleButtonTrigger >  >  leftSupportRetrtactButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ToggleButtonTrigger >  >  leftSupportEjectButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ToggleButtonTrigger >  >  armRetractButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ToggleButtonTrigger >  >  armEjectButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ToggleButtonTrigger >  >  armUpButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ToggleButtonTrigger >  >  armDownButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ToggleButtonTrigger >  >  forkRetractButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ToggleButtonTrigger >  >  forkEjectButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ToggleButtonTrigger >  >  forkUpButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ToggleButtonTrigger >  >  forkDownButton;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<lightsScreenView, const touchgfx::AbstractButton&> buttonCallback;
    touchgfx::Callback<lightsScreenView, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

};

#endif // LIGHTSSCREENVIEW_HPP
