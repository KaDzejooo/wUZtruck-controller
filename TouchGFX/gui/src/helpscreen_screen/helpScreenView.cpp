#include <gui/helpscreen_screen/helpScreenView.hpp>
#include <images/BitmapDatabase.hpp>
#include "ThemeFactory.hpp"
helpScreenView::helpScreenView()
{
	helpArrows.setBitmap(BITMAP_ARROW_BACK_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	helpArrows.setTitle("Turn signals");
	helpArrows.setDesc("Turns on/off turn signals on vehicle");

	helpHazards.setBitmap(BITMAP_EMERGENCY_HOME_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	helpHazards.setTitle("Hazard lights");
	helpHazards.setDesc("Turns on/off hazard lights on vehicle");

	helpHigh.setBitmap(BITMAP_WB_INCANDESCENT_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	helpHigh.setTitle("High beams");
	helpHigh.setDesc("Turns on/off high beams on vehicle");

	helpLow.setBitmap(BITMAP_HIGHLIGHT_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	helpLow.setTitle("Low beams");
	helpLow.setDesc("Turns on/off low beams on vehicle");

	helpTop.setBitmap(BITMAP_E911_EMERGENCY_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	helpTop.setTitle("Top lights");
	helpTop.setDesc("Turns on/off top lights on vehicle");

	helpPos.setBitmap(BITMAP_WB_SUNNY_FILL0_WGHT100_GRAD200_OPSZ48_ID);
	helpPos.setTitle("Position lights");
	helpPos.setDesc("Turns on/off position lights on vehicle");


}

void helpScreenView::setupScreen()
{
    helpScreenViewBase::setupScreen();

	std::vector<touchgfx::PainterRGB888*> painters;
	painters.push_back(&lineDecoScroll1Painter);
	painters.push_back(&lineDecoScroll2Painter);

	ThemeFactory th(settingsM.user);
	th.bindBackground(imageBackground);
	th.bindColor(helpArrows);
	th.bindColor(helpHazards);
	th.bindColor(helpHigh);
	th.bindColor(helpLow);
	th.bindColor(helpPos);
	th.bindColor(helpTop);
	th.applyPainters(painters);
}

void helpScreenView::tearDownScreen()
{
    helpScreenViewBase::tearDownScreen();
}
