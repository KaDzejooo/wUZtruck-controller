#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>



#ifndef SIMULATOR

#include <cmsis_os2.h>

#include "ControllerSettings.hpp"
#include "InputOutputModel.hpp"

	dataToSend dataIORecv;
	uartData_t dataUartRecv;
	model2user modelData;

	extern InputOutputModel controllerState;
	extern ControllerSettings settingsM;


extern "C"
{
	extern osMessageQueueId_t queueIOHandle;
	extern osMessageQueueId_t queueUARTHandle;
	extern osMessageQueueId_t model2userHandle;
}




#endif




Model::Model() : modelListener(0), queueWaitTime(15)
{



}

void Model::tick()
{
#ifndef SIMULATOR

	modelListener->tickScreen();
//    if (osMessageQueueGet(queueIOHandle, &dataIORecv, 0U, queueWaitTime) == osOK)
//    {
//        modelListener->valueChanged();
//    }
//
//
//    if(osMessageQueueGet(queueUARTHandle,&dataUartRecv,0U,queueWaitTime)==osOK)
//	{
//    	modelListener->uartChanged();
//    	snprintf(uartBuffer,257,dataUartRecv.Data);
//    	uartSize = dataUartRecv.size;
//    }

//    modelData.aux[0] = aux[0];
//    modelData.aux[1] = aux[1];
//    modelData.aux[2] = aux[2];
//    modelData.aux[3] = aux[3];
//    modelData.settings[0] = settings[0];
//    modelData.settings[1] = settings[1];

  //  osMessageQueuePut(model2userHandle, &modelData, 0U, queueWaitTime);


#else
    // simulator specific code;
    modelListener->valueChanged();
    modelListener->uartChanged();
    snprintf(uartBuffer,257,"Pozdrawiam z Model.cpp");

#endif
}

#ifndef SIMULATOR


ControllerSettings& Model::getSettings(){
	return settingsM;
}
void Model::setSettings(ControllerSettings& data){
	settingsM = data;
}
InputOutputModel& Model::getControllerState(){
	return controllerState;
}
void Model::setControllerState(InputOutputModel& state){
	controllerState = state;
}
dataToSend Model::getInputBuffer(){
	return dataIORecv;
}




bool Model::getAuxSave(int n)
{
	return aux[n];
}
void Model::setAuxSave(int n,bool value)
{
	aux[n]=value;
}
bool Model::getLightsSave(int n)
{
	return lights[n];
}
void Model::setLightsSave(int n,bool value)
{
	lights[n]=value;
}
double Model::getSettingsSave(int n)
{
	return settings[n];
}
void Model::setSettingsSave(int n,double value)
{
	settings[n]=value;
}
char* Model::getUartFull()
{
	return uartBuffer;
}
#endif



