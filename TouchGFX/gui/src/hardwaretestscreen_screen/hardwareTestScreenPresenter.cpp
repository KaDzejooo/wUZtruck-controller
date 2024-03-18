#include <gui/hardwaretestscreen_screen/hardwareTestScreenView.hpp>
#include <gui/hardwaretestscreen_screen/hardwareTestScreenPresenter.hpp>

hardwareTestScreenPresenter::hardwareTestScreenPresenter(hardwareTestScreenView& v)
    : view(v)
{

}

void hardwareTestScreenPresenter::activate()
{
	//view.readingSave=model->getSave();
}

void hardwareTestScreenPresenter::deactivate()
{

}

void hardwareTestScreenPresenter::tickScreen()
{
	view.tickView();
}

