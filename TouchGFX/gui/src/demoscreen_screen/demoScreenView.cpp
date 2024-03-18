#include <gui/demoscreen_screen/demoScreenView.hpp>
#include "ThemeFactory.hpp"



demoScreenView::demoScreenView( ):
	selectedTruckCallback(this, &demoScreenView::selectedTruckCallbackHandler)
{

}

void demoScreenView::setupScreen( )
{

	ThemeFactory th(settingsM.user);
	th.bindBackground(background);
	demoScreenViewBase::setupScreen( );
}

void demoScreenView::tearDownScreen( )
{
	demoScreenViewBase::tearDownScreen( );
}
void demoScreenView::selectedTruckCallbackHandler(const vehicleSelection& src,const ClickEvent &e){


}
