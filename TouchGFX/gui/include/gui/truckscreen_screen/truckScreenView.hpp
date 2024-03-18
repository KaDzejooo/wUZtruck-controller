#ifndef TRUCKSCREENVIEW_HPP
#define TRUCKSCREENVIEW_HPP

#include <gui_generated/truckscreen_screen/truckScreenViewBase.hpp>
#include <gui/truckscreen_screen/truckScreenPresenter.hpp>
#include <touchgfx/mixins/ClickListener.hpp>
#include <gui/common/ClickListenerClick.hpp>
#include <gui/containers/vehicleSelection.hpp>
#include <touchgfx/widgets/canvas/PainterRGB888.hpp>



class truckScreenView : public truckScreenViewBase
{
public:
    truckScreenView();
    virtual ~truckScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    touchgfx::ClickListenerClick< vehicleSelection > vehicleSelection1;
	touchgfx::ClickListenerClick< vehicleSelection > vehicleSelection2;
    touchgfx::ClickListenerClick< vehicleSelection > vehicleSelection3;
	touchgfx::ClickListenerClick< vehicleSelection > vehicleSelection4;
	touchgfx::ClickListenerClick< vehicleSelection > vehicleSelection5;
	touchgfx::ClickListenerClick< vehicleSelection > vehicleSelection6;

protected:

	uint8_t adress;
	const char * name;
	TruckType type;
	touchgfx::Bitmap icon;
	touchgfx::Callback<truckScreenView, const vehicleSelection&, const ClickEvent&> selectedTruckCallback;
	void selectedTruckCallbackHandler(const vehicleSelection& src,const ClickEvent &e);

	touchgfx::Callback <truckScreenView, const touchgfx::AbstractButtonContainer&> flexButtonCallback;
	void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer &src);
private:

};

#endif // TRUCKSCREENVIEW_HPP
