/*
 * integrityManager.hpp
 *
 *  Created on: Jul 16, 2023
 *      Author: KaDzejoo
 */

#ifndef INTEGRITYMANAGER_HPP_
#define INTEGRITYMANAGER_HPP_

#include <InputOutputModel.hpp>
#include "ControllerSettings.hpp"
#include <gui/common/FrontendApplication.hpp>
#include "main.h"
#include "cmsis_os.h"
#include "cmsis_os2.h"
#include "UTypes.hpp"
#include <stdlib.h>

extern InputOutputModel controllerState;
extern InputOutputModel truckState;
extern ControllerSettings settingsM;

class integrityManager
{
		FrontendApplication& application( )
		{
			return *static_cast <FrontendApplication*>(touchgfx::Application::getInstance( ));
		}

		//

	private:
		char osTimeDelay;
		unsigned long previousTick = 0;
		unsigned long lastTouchEvent = 0;
		unsigned long connectionTimer = 0;
		TaskHandle_t integrityTaskHandle;
		TaskHandle_t gfxTaskHandle;
		TaskHandle_t ioTaskHandle;

	public:

		integrityManager( );
		void taskEntry( ) __attribute__ ((noreturn));
		void getTaskInfo(void);
		void getHighWaterMark( );
		void manageSleep( );
		void secretCodes(std::string actualCode);
		void manageSystemNotifications( );
		void buttonAssignment( );
		void axisAssignment( );
		void checkActivity();

		unsigned long int secToTick(int timeInSec);

		/*
		 * Reinitializes given IOM class object with ZEROES
		 *
		 */
		static void reinitializeData(InputOutputModel &data);

		/*
		 * Suspends tasks while idle
		 * - IOTask - UARTTask - VideoTask
		 */
		static void suspendTasks( );
		/*
		 * Resumes tasks
		 * - IOTask - UARTTask - VideoTask
		 */
		static void resumeTasks( );

		static void setPriorityGui( );
		static void setPriorityComms( );
		static void setPriorityIo( );
	private:
		void setHardwareLed();
		int invert(int &axis, int* in,bool invert = 0);
		TaskStatus_t pxTaskStatusArray;

};

#endif /* INTEGRITYMANAGER_HPP_ */
