#ifndef DEMOSCREENVIEW_HPP
#define DEMOSCREENVIEW_HPP

#include <gui_generated/demoscreen_screen/demoScreenViewBase.hpp>
#include <gui/demoscreen_screen/demoScreenPresenter.hpp>
#include <touchgfx/mixins/ClickListener.hpp>
#include <gui/containers/vehicleSelection.hpp>


class demoScreenView : public demoScreenViewBase
{
public:
    demoScreenView();
    virtual ~demoScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

protected:

	touchgfx::Callback<demoScreenView, const vehicleSelection&, const ClickEvent&> selectedTruckCallback;
	void selectedTruckCallbackHandler(const vehicleSelection& src,const ClickEvent &e);
};

#endif // DEMOSCREENVIEW_HPP
