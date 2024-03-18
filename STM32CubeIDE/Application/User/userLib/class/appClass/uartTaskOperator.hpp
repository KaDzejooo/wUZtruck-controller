/*
 * uartTaskOperator.hpp
 *
 *  Created on: Jun 29, 2023
 *      Author: KaDzejoo
 */

#ifndef UARTTASKOPERATOR_HPP
#define UARTTASKOPERATOR_HPP
#include "main.h"
class uartTaskOperator
{
public:
	uartTaskOperator();
	void taskEntry();

	uint8_t recieved[60];
//	uint8_t sign;
	uint8_t send[30] = {0x7e,0x00, 0x10, 0x01, 0x00, 0x00, 0x21,0x00, 0x44, 0x00, 0x18 , 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x69, 0x69, 0xaf};
//	uint8_t value;
//	uint8_t tab[30];
};

#endif /* UARTTASKOPERATOR_HPP */
