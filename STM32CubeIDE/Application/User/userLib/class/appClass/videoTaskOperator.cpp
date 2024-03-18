/*
 * videoTaskOperator.cpp
 *
 *  Created on: 1 lip 2023
 *      Author: KaDzejoo
 */

#include <videoTaskOperator.hpp>
#include "cmsis_os2.h"
videoTaskOperator::videoTaskOperator() {


}

void videoTaskOperator::taskEntry() {

	for(;;){

		osDelay(500);
	};

}
