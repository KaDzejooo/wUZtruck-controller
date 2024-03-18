#include <gui/idlescreen_screen/idleScreenView.hpp>


idleScreenView::idleScreenView()
{

}

void idleScreenView::setupScreen()
{
	controllerState.idle = 1;
    idleScreenViewBase::setupScreen();


}

void idleScreenView::tearDownScreen()
{
	controllerState.idle = 0;
    idleScreenViewBase::tearDownScreen();
}
