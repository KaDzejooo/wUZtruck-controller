#ifndef TOUCHGFX_CLICKLISTENERCLICK_HPP
#define TOUCHGFX_CLICKLISTENERCLICK_HPP

#include <touchgfx/Callback.hpp>
#include <touchgfx/events/ClickEvent.hpp>

namespace touchgfx
{
template <class T>
class ClickListenerClick : public T
{
public:

    ClickListenerClick()
        : T(), clickAction(0)
    {
        T::setTouchable(true);
    }

    virtual void handleClickEvent(const ClickEvent& event)
    {
        bool wasPressed = getPressed();
        bool newPressedValue = (event.getType() == ClickEvent::PRESSED);
        if ((newPressedValue && !wasPressed) || (!newPressedValue && wasPressed))
        {
            setPressed(newPressedValue);
            T::invalidate();
        }
        if (wasPressed && (event.getType() == ClickEvent::RELEASED))
        {
        	clickAction->execute(*this, event);
        }
    }

    void setClickAction(GenericCallback<const T&, const ClickEvent&>& callback)
    {
        clickAction = &callback;
    }


    void setPressed(bool isPressed)
       {
           pressed = isPressed;
       }


       bool getPressed()
       {
           return pressed;
       }

protected:
       bool pressed;
    GenericCallback<const T&, const ClickEvent&>* clickAction; ///< The callback to be executed when T is clicked
};

} // namespace touchgfx

#endif // TOUCHGFX_CLICKLISTENER_HPP
