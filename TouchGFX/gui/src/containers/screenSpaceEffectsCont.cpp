#include <gui/containers/screenSpaceEffectsCont.hpp>

screenSpaceEffectsCont::screenSpaceEffectsCont( )
{

}

void screenSpaceEffectsCont::initialize( )
{
	//screenSpaceEffectsBase::initialize( );
}
void screenSpaceEffectsCont::setBrightness(int eff)
{

	brightness = 255-eff;
	brightnessBox.setAlpha(255-eff);
}
void screenSpaceEffectsCont::setBlinkColor(colortype color){

	blinkBox.setColor(color);
}
void screenSpaceEffectsCont::setAlpha(int newAlpha){
	alpha = newAlpha;
	blinkBox.setAlpha(newAlpha);
}

int screenSpaceEffectsCont::getAlpha( )
{
	return alpha;
}
int screenSpaceEffectsCont::getBrightness( )
{
	return brightness;
}
