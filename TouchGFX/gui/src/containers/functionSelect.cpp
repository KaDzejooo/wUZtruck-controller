#include <gui/containers/functionSelect.hpp>
#include <images/BitmapDatabase.hpp>

functionSelect::functionSelect( ) :
		flexButtonCallback(this, &functionSelect::flexButtonCallbackHandler), stateVal(0), upVal(0), downVal(
				0)
{

	buttonToggle.setAction(flexButtonCallback);
	buttonDown.setAction(flexButtonCallback);
	buttonUp.setAction(flexButtonCallback);
	iconUpDown.setVisible(0);
}

void functionSelect::initialize( )
{
	textArea.setWildcard(textAreaBuffer);
	textArea2.setWildcard(textArea2Buffer);
	functionSelectBase::initialize( );
	forceState( );
	invalidate( );
}

void functionSelect::setStateValue(bool *variable)
{
	stateVal = variable;
}
void functionSelect::setUpValue(bool *variable)
{
	upVal = variable;
}
void functionSelect::setDownValue(bool *variable)
{
	downVal = variable;
}

void functionSelect::setType(funcType newType)
{
	// toggle by default

	if (newType == funcType::toggle)
	{
		containerUpDown.setVisible(0);
		containerToggle.setVisible(1);
	}
	if (newType == funcType::upDown)
	{
		containerUpDown.setVisible(1);
		containerToggle.setVisible(0);
	}
}

void functionSelect::setIcon(touchgfx::Bitmap newIcon)
{
	imageType.setBitmap(newIcon);
}

void functionSelect::forceState(bool newState)
{
	buttonToggle.forceState(newState);
	functionSelect::setStateIcon(newState);
}

void functionSelect::forceState( )
{
	buttonToggle.forceState(*stateVal);
	functionSelect::setStateIcon(*stateVal);
}

void functionSelect::setText(const char *newText)
{
	Unicode::snprintf(textAreaBuffer, TEXTAREA_SIZE, newText);
}

void functionSelect::setTextSec(const char *newText)
{
	Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, newText);
}

void functionSelect::setColor(uint8_t newR, uint8_t newG, uint8_t newB)
{
	shapePriorityPainter.setColor(touchgfx::Color::getColorFromRGB(newR, newG, newB));
}
void functionSelect::setStateIcon(bool stateIcon)
{
	if (stateIcon == 0)
	{
		iconStateToggle.setBitmap(BITMAP_RADIO_BUTTON_UNCHECKED_FILL0_WGHT100_GRAD200_OPSZ24_ID);
	}
	else
	{
		iconStateToggle.setBitmap(BITMAP_RADIO_BUTTON_CHECKED_FILL0_WGHT100_GRAD200_OPSZ24_ID);
	}
	invalidate( );
	iconStateToggle.invalidate( );
}

void functionSelect::setStateIconDef()
{
	if (*stateVal == 0)
	{
		iconStateToggle.setBitmap(BITMAP_RADIO_BUTTON_UNCHECKED_FILL0_WGHT100_GRAD200_OPSZ24_ID);
	}
	else
	{
		iconStateToggle.setBitmap(BITMAP_RADIO_BUTTON_CHECKED_FILL0_WGHT100_GRAD200_OPSZ24_ID);
	}
	invalidate( );
	iconStateToggle.invalidate( );
}
void functionSelect::setUpDownIcon(upDown newState)
{

	switch (newState)
	{
		case upDown::up:
			iconUpDown.setVisible(1);
			iconUpDown.setBitmap(BITMAP_ARROW_DROP_UP_FILL0_WGHT100_GRAD200_OPSZ24_ID);
		break;
		case upDown::down:
			iconUpDown.setVisible(1);
			iconUpDown.setBitmap(BITMAP_ARROW_DROP_DOWN_FILL0_WGHT100_GRAD200_OPSZ24_ID);
		break;
		case upDown::none:
			iconUpDown.setVisible(0);
			iconUpDown.setBitmap(BITMAP_ARROW_DROP_DOWN_FILL0_WGHT100_GRAD200_OPSZ24_ID);
		break;
	}
	iconUpDown.invalidate( );
}
void functionSelect::resetUpDown( )
{
	up = 0;
	down = 0;
	setUpDownIcon(upDown::none);
}
void functionSelect::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer &src)
{

	if (&src == &buttonToggle)
	{
		*stateVal = !*stateVal;

		functionSelect::setStateIcon(*stateVal);
		invalidate( );
	};

	if (&src == &buttonDown)
	{

		*downVal = 1;

		setUpDownIcon(upDown::down);
		invalidate( );

	}
	if (&src == &buttonUp)
	{
		*upVal = 1;
		setUpDownIcon(upDown::up);
		invalidate( );
	}
}
