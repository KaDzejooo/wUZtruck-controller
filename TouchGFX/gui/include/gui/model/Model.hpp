#ifndef MODEL_HPP
#define MODEL_HPP
#include <stdio.h>

class ModelListener;

#ifndef SIMULATOR

#include "main.h"
#include "InputOutputModel.hpp"
#include "ControllerSettings.hpp"


extern dataToSend dataIORecv;
extern ControllerSettings settingsM;
extern InputOutputModel controllerState;


#else

#include "C:\Users\oem\Desktop\repositories\wUZtruck-controllerApp\Core\Inc\main.h"
#include "C:\Users\oem\Desktop\repositories\wUZtruck-controllerApp\STM32CubeIDE\Application\User\userLib\class\dataClass\ControllerSettings.hpp"
extern dataToSend dataIORecv;
extern ControllerSettings settingsM;

#endif

class Model
{
protected:
    ModelListener* modelListener;
    int queueWaitTime;
    long joy1x,joy1y,joy2x,joy2y,trigg,in1,in2,in3,in4;
    long inputBuffer[9]; //Input channels buffer
    int aux[4]; // 4 aux buttons main screen
	int lights[8]; // 8 toggle channels from lights screen
    double settings[8]; // 8 value settings
    long Io[9]; // a ty po chuj
    char uartBuffer[257]="empty buffer";
	int uartSize = 5;

public:
    Model();
    void tick();
    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    //controllerSettings
    ControllerSettings& getSettings();
    void setSettings(ControllerSettings& data);
    //InputOutputModel
    InputOutputModel& getControllerState();
    void setControllerState(InputOutputModel& state);
    //dataToSend (data from IO task) // add function to translate some of its data to
    // IOModel
    dataToSend getInputBuffer();
    // just using getters should be enough cause they are passed via reference
    // so any screenView class modifies original class instance values

    // should be no longer used or supported; left for compatibility\/

    // Main Screen buttons getters / setters
    bool getAuxSave(int n);
    void setAuxSave(int n,bool value);

    // light screen setters/getters
    bool getLightsSave(int n);
    void setLightsSave(int n,bool value);
    // settings screen setters/getters
    double getSettingsSave(int n);
    void setSettingsSave(int n,double value);
    char* getUartFull();

};

#endif // MODEL_HPP
