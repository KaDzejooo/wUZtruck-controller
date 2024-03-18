#include <gui/startupscreen_screen/startupScreenView.hpp>

startupScreenView::startupScreenView( )
{

}

void startupScreenView::setupScreen( )
{

	startupScreenViewBase::setupScreen( );
	textArea.moveTo(5, 260);

}

void startupScreenView::tearDownScreen( )
{
	startupScreenViewBase::tearDownScreen( );
}
void startupScreenView::tickScreen( )
{

//	textArea.startMoveAnimation(0, y, 4);
//	//textArea.setXY(0, y);
//	textArea.invalidate();
//	y--;

	static int tickCount = 0;
	static int prevTickCount = 0;

	if (tickCount - prevTickCount > (rand( ) % 20 ))
	{
		moveText( );
		prevTickCount = tickCount;
	}

	tickCount++;

}

void startupScreenView::moveText( )
{
	//textArea.startMoveAnimation(0, y, 8);
	if (textArea.getY()<-1000){
		application().gotomainScreenScreenNoTransition();
		return;
	}
	textArea.setXY(5, y);
	textArea.invalidate( );
	y -= 12 * ((rand( )%2));

}
