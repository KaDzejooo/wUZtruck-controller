#ifndef OUTPUTSSCREENVIEW_HPP
#define OUTPUTSSCREENVIEW_HPP

#include <gui_generated/outputsscreen_screen/outputsScreenViewBase.hpp>
#include <gui/outputsscreen_screen/outputsScreenPresenter.hpp>
#include <gui/containers/functionSelect.hpp>
class outputsScreenView : public outputsScreenViewBase
{
public:
    outputsScreenView();
    virtual ~outputsScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void updateDebugString( );
    void tickView();

    void setupButtons();
    functionSelect topLights;
    functionSelect highBeams;
    functionSelect lowBeams;

    functionSelect posLights;
    functionSelect hazards;
    functionSelect leftBlinker;
    functionSelect rightBlinker;
    functionSelect fogLightsFront;
    functionSelect fogLightsRear;
    functionSelect horn;

    functionSelect axleLifting;
    functionSelect trailerConnect;

    functionSelect firstWinch;
    functionSelect secondWinch;

    functionSelect rightSupportER;
    functionSelect leftSupportER;

    functionSelect armER;
    functionSelect armUD;

    functionSelect forkER;
    functionSelect forkUD;

    /// TODO missing functions for vehicles
    functionSelect dayLights;
    std::vector<functionSelect*> functions;
protected:

			//(this,&functionSelect::setStateIconDef);
};

#endif // OUTPUTSSCREENVIEW_HPP
