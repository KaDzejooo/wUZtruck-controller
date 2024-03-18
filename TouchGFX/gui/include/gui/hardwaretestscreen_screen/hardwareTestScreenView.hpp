#ifndef HARDWARETESTSCREENVIEW_HPP
#define HARDWARETESTSCREENVIEW_HPP

#include <gui_generated/hardwaretestscreen_screen/hardwareTestScreenViewBase.hpp>
#include <gui/hardwaretestscreen_screen/hardwareTestScreenPresenter.hpp>
#include <gui/common/CustomKeyboard.hpp>



class hardwareTestScreenView : public hardwareTestScreenViewBase
{
public:
	hardwareTestScreenView();
	virtual ~hardwareTestScreenView() {}
	virtual void setupScreen();
	virtual void tearDownScreen();

	/*
	 * Sets up IOM display widget
	 */
	virtual void setupIomDisplay();
	/*
	 * Updates data on IOM display on hardwareTestScreen
	 */
	virtual void updateIomDisplay();
	/*
	 * Updates buttons state on hTS
	 */
	virtual void updateButtonsDisplay();
	/*
	 * Updates line display widgets
	 */
	virtual void updateLineDisplay();
	/*
	 * Method that refreshes screen every frame (16.67ms)
	 * called thru hTS presenters function tickScreen()
	 */
	virtual void tickView();

protected:
	CustomKeyboard keyboard;

    /*
     * Callback Declarations
     */
    touchgfx::Callback<hardwareTestScreenView, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Callback Handler Declarations
     */
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);
};

#endif // HARDWARETESTSCREENVIEW_HPP
