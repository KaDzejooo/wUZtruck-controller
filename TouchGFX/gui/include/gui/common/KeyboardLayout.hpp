#ifndef KEYBOARD_LAYOUT
#define KEYBOARD_LAYOUT

#include <touchgfx/widgets/Keyboard.hpp>
#include <touchgfx/hal/Types.hpp>
#include <fonts/ApplicationFontProvider.hpp>
#include "BitmapDatabase.hpp"

using namespace touchgfx;

/**
 * Array specifying the keys used in the CustomKeyboard.
 */
static const Keyboard::Key keyArray[12] =
{

		//7 28 28 28 9
    { 1, Rect(8+28,120, 26, 40), BITMAP_BUTTONBCG26X40_ID}, // 0

    { 2, Rect(8 , 0, 26, 40), BITMAP_BUTTONBCG26X40_ID}, // ONE TO NINE
    { 3, Rect(8 + 28 * 1, 0, 26, 40), BITMAP_BUTTONBCG26X40_ID},
    { 4, Rect(8 + 28 * 2, 0, 26, 40), BITMAP_BUTTONBCG26X40_ID},

    { 5, Rect(8 , 40, 26, 40), BITMAP_BUTTONBCG26X40_ID},
    { 6, Rect(8 + 28 * 1, 40, 26, 40), BITMAP_BUTTONBCG26X40_ID},
    { 7, Rect(8 + 28 * 2, 40, 26, 40), BITMAP_BUTTONBCG26X40_ID},

    { 8, Rect(8 , 80, 26, 40), BITMAP_BUTTONBCG26X40_ID},
    { 9, Rect(8 + 28 * 1, 80, 26, 40), BITMAP_BUTTONBCG26X40_ID},
    {10, Rect(8 + 28 * 2, 80, 26, 40), BITMAP_BUTTONBCG26X40_ID},

	// dummy keys for functions
    {11, Rect(8, 120, 26, 40), BITMAP_BUTTONBCG26X40_ID},
    {12, Rect(8 + 28*2 , 120, 26, 40), BITMAP_BUTTONBCG26X40_ID},
};
/**
 * Callback areas for the special buttons on the CustomKeyboard.
 */
static Keyboard::CallbackArea callbackAreas[2] =
{
    {Rect(8, 120, 26, 40),0 ,BITMAP_BUTTONBCG26X40_ID}, //accept
    {Rect(8 + 28*2 , 120, 26, 40),0, BITMAP_BUTTONBCG26X40_ID}, //backspace


	//7 + 26 =33    160 + 40 = 160
	// +7 56 + 26 = 89

	//{ 1, Rect(7+28, 95+44, 26, 40), BITMAP_BUTTONBCG26X40_ID}, // 0
    // {Rect(5, 149, 56, 40), 0, BITMAP_KEYBOARD_KEY_SHIFT_HIGHLIGHTED_ID},     // accept
    // {Rect(258, 149, 56, 40), 0, BITMAP_KEYBOARD_KEY_DELETE_HIGHLIGHTED_ID},  // backspace
};

/**
 * The layout for the CustomKeyboard.
 */
static const Keyboard::Layout layout =
{
		BITMAP_BCGROUND30050_ID,
    keyArray,
    12,
    callbackAreas,
    2,
    Rect(15, 160, 65, 26),
    TypedText(T_PLACEHOLDER),
    0xffffff,
    Typography::DEFAULT,
    0xffffff
};

static const Keyboard::Layout layoutRed =
{
		BITMAP_BCGROUND30050_ID,
    keyArray,
    12,
    callbackAreas,
    2,
    Rect(15, 160, 65, 26),
    TypedText(T_PLACEHOLDER),
    0x00ff00,
    Typography::DEFAULT,
    0xffffff
};

#endif
