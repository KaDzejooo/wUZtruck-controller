#ifndef TASK_STARTER_CPP
#define TASK_STARTER_CPP
/*
 * TaskStarter.cpp
 *
 *  Created on: June 28, 2023
 *      Author: KaDzejoo
 */
#include "uartTaskOperator.hpp"
#include "ioTaskOperator.hpp"
#include "videoTaskOperator.hpp"
#include "integrityManager.hpp"

extern "C" void uartComms_taskEntry( );
extern "C" void videoDecode_taskEntry( );
extern "C" void taskIO_taskEntry( );
extern "C" void integrityManager_taskEntry( );

static uartTaskOperator uart;
static ioTaskOperator io;
static videoTaskOperator video;
static integrityManager integrity;

void uartComms_taskEntry( )
{
	uart.taskEntry( );
}

void taskIO_taskEntry( )
{
	io.taskEntry( );
}

void videoDecode_taskEntry( )
{
	video.taskEntry( );
}

void integrityManager_taskEntry( )
{
	integrity.taskEntry( );
}

#endif

