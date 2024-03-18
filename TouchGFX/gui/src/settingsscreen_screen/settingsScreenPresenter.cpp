#include <gui/settingsscreen_screen/settingsScreenView.hpp>
#include <gui/settingsscreen_screen/settingsScreenPresenter.hpp>

settingsScreenPresenter::settingsScreenPresenter(settingsScreenView& v)
    : view(v)
{

}

void settingsScreenPresenter::activate()
{

}

void settingsScreenPresenter::deactivate()
{

}
void settingsScreenPresenter::settingsSave(double val, int index)
{


}

void settingsScreenPresenter::tickScreen(){
	view.tickView();
}

