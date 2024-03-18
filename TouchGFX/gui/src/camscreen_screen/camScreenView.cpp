#include <gui/camscreen_screen/camScreenView.hpp>
#include <touchgfx/widgets/Image.hpp>
#include "SetupSettings.hpp"


camScreenView::camScreenView()
{

}

void camScreenView::setupScreen()
{
//#ifndef DISABLE_DYNAMIC_BITMAP
//	BitmapId bmpId;
//	//Create (24bit) dynamic bitmap of size 256x144
//	const int width = 256;
//	const int height = 144;
//	bmpId = Bitmap::dynamicBitmapCreate(width,height, Bitmap::RGB565);
//
//	//set all pixels some weird color
//	if (bmpId != BITMAP_INVALID)
//	{
//		memset(Bitmap::dynamicBitmapGetAddress(bmpId), 0x1C,width*height* 2);
//	}
//	//Make Image widget show the dynamic bitmap
//	imageCameraDynamic.setBitmap(Bitmap(bmpId));
//#endif

    camScreenViewBase::setupScreen();
}

void camScreenView::tearDownScreen()
{
    camScreenViewBase::tearDownScreen();
}
