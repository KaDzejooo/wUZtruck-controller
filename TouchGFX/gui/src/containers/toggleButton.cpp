#include <gui/containers/toggleButton.hpp>

toggleButton::toggleButton():
flexButtonCallback(this, &toggleButton::flexButtonCallbackHandler)
{
	textArea.setWildcard(textAreaBuffer);
	flexButton.setAction(flexButtonCallback);
}

void toggleButton::initialize()
{
	toggleButtonBase::initialize();
}

void toggleButton::setIcon(touchgfx::Bitmap newBitmap){
	imageIcon.setBitmap(newBitmap);
}
void toggleButton::setText(const char * text){
	Unicode::snprintf(textAreaBuffer, TEXTAREA_SIZE,text);
}
void toggleButton::forceState(bool stated)
{
 state = stated;
 flexButton.forceState(stated);
 invalidate();
}
void toggleButton::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
	if(&src == &flexButton){
		state = !state;
	}
}
