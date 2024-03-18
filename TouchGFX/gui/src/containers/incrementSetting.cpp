#include <gui/containers/incrementSetting.hpp>
#include <touchgfx/Color.hpp>

incrementSetting::incrementSetting( ) :
		flexButtonCallback(this, &incrementSetting::flexButtonCallbackHandler)
{
	textNumber.setWildcard(textNumberBuffer);
	textArea.setWildcard(textAreaBuffer);
	textArea2.setWildcard(textArea2Buffer);

	buttonUp.setAction(flexButtonCallback);
	buttonDown.setAction(flexButtonCallback);
}

void incrementSetting::initialize( )
{
	incrementSettingBase::initialize( );
}
void incrementSetting::setVariableBottomText( )
{
	variableBottomText = 1;
}
void incrementSetting::bind(uint8_t* newValue)
{

	selectedValue = newValue;
}

int incrementSetting::getValue( )
{
	return value;
}
void incrementSetting::setValue(int newVal)
{
	value = newVal;
	*selectedValue = newVal;
	Unicode::snprintf(textNumberBuffer, TEXTNUMBER_SIZE, "%d", value);
	invalidate( );
}
void incrementSetting::setMaxVal(int newVal)
{
	maxVal = newVal;
}
void incrementSetting::setMinVal(int newVal)
{
	minVal = newVal;
	;
}

void incrementSetting::setText(const char *newText)
{
// max 29 char
	Unicode::snprintf(textAreaBuffer, TEXTAREA_SIZE, newText);
	textArea.resizeToCurrentText();
	textArea.invalidate();


}
void incrementSetting::setText2(const char *newText)
{
// max 29 char
	Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, newText);

	if (variableBottomText == 1){
		Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, texts[value].c_str( ));
	}
	textArea2.resizeToCurrentText();
	textArea.invalidate();

}
void incrementSetting::setIcon(touchgfx::Bitmap icon)
{

	imageType.setBitmap(icon);
}
void incrementSetting::setColor(uint8_t r, uint8_t g, uint8_t b)
{
	shapePriorityPainter.setColor(touchgfx::Color::getColorFromRGB(r, g, b));
}
void incrementSetting::setIncrementText(std::vector<std::string>newTexts)
{
	texts = newTexts;
}

void incrementSetting::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer &src)
{
	if (&src == &buttonUp)
	{
		if (value < maxVal)
		{
			value += 1;
			*selectedValue = value;

		}

		//shapePriorityPainter.setColor(touchgfx::Color::getColorFromRGB(55, 0,0));
		//textNumber;
	}

	if (&src == &buttonDown)
	{

		if (value > minVal)
		{
			value -= 1;
			*selectedValue = value;

		}
		//shapePriorityPainter.setColor(touchgfx::Color::getColorFromRGB(0,55, 7));
		//textNumber;
	}

	if (variableBottomText == 1){
		Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, texts[value].c_str( ));
		invalidate( );
	}

	Unicode::snprintf(textNumberBuffer, TEXTNUMBER_SIZE, "%d", value);

	invalidate( );
}
