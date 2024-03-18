#include <gui/containers/helpFunctions.hpp>

helpFunctions::helpFunctions()
{

}

void helpFunctions::initialize()
{
    helpFunctionsBase::initialize();
}
void helpFunctions::setBitmap(touchgfx::Bitmap newBitmap)
{
	image.setBitmap(newBitmap);
}
void helpFunctions::setColor(uint8_t r,uint8_t g,uint8_t b)
{
	shapePriorityPainter.setColor(touchgfx::Color::getColorFromRGB(r, g, b));
}
void helpFunctions::setTitle(const char * newTitle)
{
	Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, newTitle);
}
void helpFunctions::setDesc(const char * newDesc)
{
	Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, newDesc);
}


