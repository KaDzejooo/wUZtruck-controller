#ifndef KEYBOARD_KEY_MAPPING_H
#define KEYBOARD_KEY_MAPPING_H

#include <touchgfx/widgets/Keyboard.hpp>
using namespace touchgfx;

/**
 * This file contains all the keymappings for the CustomKeyboard.
 */
static const Keyboard::KeyMapping keyMappingsAlphaLower [12] =
{
{1, 30 + 18},  // 0
{2, 31 + 18},  // 1
{3, 32 + 18},  // 2
{4, 33 + 18},  // 3
{5, 34 + 18},  // 4
{6, 35 + 18},  // 5
{7, 36 + 18},  // 6
{8, 37 + 18},  // 7
{9, 38 + 18},  // 8
{10, 39 + 18},  // 9
{11, 35},  // #
{12, 68},  // d

		};

static const Keyboard::KeyMappingList keyMappingListAlphaLower =
{keyMappingsAlphaLower, 12};

static const Keyboard::KeyMapping keyMappingsChar [12] =
{

		//65 - 90 = A-Z
{1, 74},  // J
{2, 76},  // L
{3, 77},  //
{4, 78},  //
{5, 79},  //
{6, 80},  //
{7, 81},  //
{8, 82},  //
{9, 83},  //
{10, 84},  //
{11, 35},  //
{12, 127},  // Del / D

		};

static const Keyboard::KeyMappingList keyMappingListChar =
{keyMappingsChar, 12};

#endif
