#include <gui/outputsscreen_screen/outputsScreenView.hpp>
#include <gui/outputsscreen_screen/outputsScreenPresenter.hpp>

outputsScreenPresenter::outputsScreenPresenter(outputsScreenView& v)
    : view(v)
{

}

void outputsScreenPresenter::activate()
{

}

void outputsScreenPresenter::deactivate()
{

}
void outputsScreenPresenter::tickScreen( )
{
	view.tickView( );
}
