/*
 * app_user.c
 *
 *  Created on: Jun 28, 2023
 *      Author: KaDzejoo
 */
#include "app_user.h"

/* create all task references here with func prototype
 * --void assTask_TaskEntry(void);
 * implement and Call forward to uartComms_taskEntry in C++ domain
 * exists in TaskStarter.cpp
 */

void uartComms_taskEntry(void);
void videoDecode_taskEntry(void);
void taskIO_taskEntry(void);
void integrityManager_taskEntry(void);

void StartIntegrityMngr(void *argument)
{
	integrityManager_taskEntry( );
}

void StartUartComms(void *argument)
{
	uartComms_taskEntry( );
}
void StartVideoDecode(void *argument)
{
	videoDecode_taskEntry( );
}
void StartTaskIO(void *argument)
{
	taskIO_taskEntry( );
}
