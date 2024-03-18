#include <gui/notificationscreen_screen/notificationScreenView.hpp>
#include <gui/notificationscreen_screen/notificationScreenPresenter.hpp>

notificationScreenPresenter::notificationScreenPresenter(notificationScreenView& v)
    : view(v)
{

}

void notificationScreenPresenter::activate()
{

}

void notificationScreenPresenter::deactivate()
{

}
void notificationScreenPresenter::tickScreen()
{
 view.tickView();
}
