#include <gui/common/CustomKeyboard.hpp>
#include <string.h>
#include <touchgfx/Color.hpp>
#include "ControllerSettings.hpp"

extern ControllerSettings settingsM;

CustomKeyboard::CustomKeyboard() :
		keyboard( ), modeBtnTextArea( ), backspacePressed(this,
				&CustomKeyboard::backspacePressedHandler), acceptPressed(this,
				&CustomKeyboard::acceptPressedHandler), keyPressed(this,
				&CustomKeyboard::keyPressedhandler), alphaKeys(true), uppercaseKeys(false), firstCharacterEntry(
				false)
{
	//Set the callbacks for the callback areas of the keyboard and set its layout.
	layout.callbackAreaArray [0].callback = &acceptPressed;
	layout.callbackAreaArray [1].callback = &backspacePressed;

	layoutRed.callbackAreaArray [0].callback = &acceptPressed;
	layoutRed.callbackAreaArray [1].callback = &backspacePressed;

	keyboard.setLayout(&layout);
	keyboard.setKeyListener(keyPressed);
	keyboard.setPosition(0, 0, 100, 185);
	keyboard.setTextIndentation( );

	//Allocate the buffer associated with keyboard.
	memset(buffer, 0, sizeof ( buffer ));
	keyboard.setBuffer(buffer, BUFFER_SIZE);

	uppercaseKeys = true;
	firstCharacterEntry = true;

//    modeBtnTextArea.setPosition(5, 196, 56, 40);
//    modeBtnTextArea.setColor(Color::getColorFromRGB(0x00, 0xFF, 0xFF));

	setKeyMappingList( );

	add(keyboard);
	add(modeBtnTextArea);
}

void CustomKeyboard::setKeyMappingList( )
{
	keyboard.setKeymappingList(&keyMappingListAlphaLower);

}

void CustomKeyboard::backspacePressedHandler( )
{
	uint16_t pos = keyboard.getBufferPosition( );
	if (pos > 0)
	{
		//Delete the previous entry in the buffer and decrement the position.
		buffer [pos - 1] = 0;
		keyboard.setBufferPosition(pos - 1);

		//Change keymappings if we have reached the first position.
		if (1 == pos)
		{
			firstCharacterEntry = true;
			uppercaseKeys = true;
			setKeyMappingList( );
		}
	}
}

void CustomKeyboard::acceptPressedHandler( )
{
	*acceptVal = 1;
	memset(buffer, 0, sizeof ( buffer ));
	keyboard.setBufferPosition(0);
	invalidate( );
}
void CustomKeyboard::setAcceptVar(bool * variable)
{
	acceptVal = variable;
}

void CustomKeyboard::keyPressedhandler(Unicode::UnicodeChar keyChar)
{
	// 01234
	// 00SL5

	if (buffer [0] == 48 && buffer[1] == 48){
		keyboard.setLayout(&layoutRed);
	}else{
		keyboard.setLayout(&layout);
	}

	if (buffer [0] == 48 && buffer[1] == 48
			&&( keyboard.getBufferPosition( )== 3 || keyboard.getBufferPosition( )== 2))
	{
		keyboard.setKeymappingList(&keyMappingListChar);
	}
	else
	{
		keyboard.setKeymappingList(&keyMappingListAlphaLower);
	}



	if (keyChar != (Unicode::UnicodeChar) 0)
	{

		*acceptVal = 0;
	}
}

void CustomKeyboard::setTouchable(bool touch)
{
	Container::setTouchable(touch);
	keyboard.setTouchable(touch);
}
