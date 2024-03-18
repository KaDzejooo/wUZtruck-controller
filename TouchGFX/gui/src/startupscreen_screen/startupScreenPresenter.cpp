#include <gui/startupscreen_screen/startupScreenView.hpp>
#include <gui/startupscreen_screen/startupScreenPresenter.hpp>

startupScreenPresenter::startupScreenPresenter(startupScreenView &v) :
		view(v)
{

}

void startupScreenPresenter::activate( )
{

}

void startupScreenPresenter::deactivate( )
{

}
void startupScreenPresenter::tickScreen( )
{
	view.tickScreen( );

}
