#ifndef TOGGLEBUTTON_HPP
#define TOGGLEBUTTON_HPP

#include <gui_generated/containers/toggleButtonBase.hpp>

class toggleButton : public toggleButtonBase
{
public:
    toggleButton();
    virtual ~toggleButton() {}

    virtual void initialize();

    void bind(bool *variable){acceptVal = variable;};
    bool getState(){return state;};
    void setIcon(touchgfx::Bitmap newBitmap);
    void setText(const char * text);
    void forceState(bool stated);

protected:
    bool * acceptVal;
    bool state;

    touchgfx::Callback<toggleButton, const touchgfx::AbstractButtonContainer&> flexButtonCallback;
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);
};

#endif // TOGGLEBUTTON_HPP
