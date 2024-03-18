#ifndef SETTINGSSCREENVIEW_HPP
#define SETTINGSSCREENVIEW_HPP

#include <gui_generated/settingsscreen_screen/settingsScreenViewBase.hpp>
#include <gui/settingsscreen_screen/settingsScreenPresenter.hpp>
#include <gui/containers/lineDiv.hpp>
#include <gui/containers/toggleButton.hpp>

class settingsScreenView : public settingsScreenViewBase
{
public:
    settingsScreenView();
    virtual ~settingsScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void tickView();
    void updateDebugString( );
    void graphAnim();

    // dummy
    toggleButton toggleUSBcharge;
    toggleButton toggle3D;
    toggleButton toggleAudio;
    toggleButton toggleEnergySaving;


    // real
    toggleButton toggleGauges;
    toggleButton toggleScreen;
    toggleButton toggleKeypad;
    toggleButton toggleVideoTask;

    // line div
    lineDiv div1;
    lineDiv div2;


   // virtual void radioButtonSelectedCallbackHandler(const touchgfx::AbstractButton& src);


protected:

    //touchgfx::IconButtonStyle< touchgfx::TextButtonStyle< touchgfx::ToggleButtonTrigger >  >  buttonAudio;

    RadioButton bttn;
private:
    touchgfx::Callback<settingsScreenView, const touchgfx::AbstractButton&> buttonCallback;
    touchgfx::Callback<settingsScreenView, const touchgfx::Slider&, int> sliderValueChangedCallback;
    touchgfx::Callback<settingsScreenView, const touchgfx::Slider&, int> sliderValueEndChangedCallback;
    touchgfx::Callback<settingsScreenView, const touchgfx::AbstractButtonContainer&> flexButtonCallback;
    touchgfx::Callback<settingsScreenView, const touchgfx::AbstractButton&> radioButtonSelectedCallback;

   /*
    * Callback Handler Declarations
    */

    int* selected;
    bool* inversion;
    uint16_t* dst;
    void radioButtonSelectedCallbackHandler(const touchgfx::AbstractButton& src);
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    void sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value);
    void sliderValueEndChangedCallbackHandler(const touchgfx::Slider& src, int value);
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);
};

#endif // SETTINGSSCREENVIEW_HPP
