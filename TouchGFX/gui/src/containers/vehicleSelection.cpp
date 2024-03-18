#include <gui/containers/vehicleSelection.hpp>

vehicleSelection::vehicleSelection( )
{

}

void vehicleSelection::initialize( )
{
	vehicleSelectionBase::initialize( );
}
void vehicleSelection::setIconType(touchgfx::Bitmap newBitmap)
{
	iconType.setBitmap(newBitmap);
	iconTypeBitmap = newBitmap;
}
void vehicleSelection::setColor(uint8_t r, uint8_t g, uint8_t b)
{
	lineDecoPainter.setColor(touchgfx::Color::getColorFromRGB(r, g, b));
	shapePriorityPainter.setColor(touchgfx::Color::getColorFromRGB(r, g, b));
}
void vehicleSelection::setTitle(const char *newText)
{
	Unicode::snprintf(textAreaBuffer, TEXTAREA_SIZE, newText);
	title = newText;
}
void vehicleSelection::setDescription(const char *newText)
{
	Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, newText);
}
void vehicleSelection::setAdress(uint8_t newAdress)
{
	Unicode::snprintf(textAdressBuffer, TEXTADRESS_SIZE, "0x%02X", newAdress);
	intAdress = newAdress;
}

void vehicleSelection::setActive(bool set)
{
	active = set;
}

void vehicleSelection::startAnimaion(){
	animatedIcon.startAnimation(0);
}
