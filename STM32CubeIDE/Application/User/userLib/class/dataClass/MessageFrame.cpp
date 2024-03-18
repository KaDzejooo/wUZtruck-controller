/*
 * MessageFrame.cpp
 *
 *  Created on: Mar 13, 2024
 *      Author: KaDzejoo
 */

#include <MessageFrame.hpp>

MessageFrame::MessageFrame( )
{
	// TODO Auto-generated constructor stub
	
}

uint8_t MessageFrame::toByte(bool b [8])
{
	uint8_t c = 0;
	for (int it = 0; it < 8; ++it)
		if (b [it]) c |= 1 << it;
	return c;
}

void MessageFrame::fromByte(uint8_t c, uint8_t b [8])
{
	for (int i = 0; i < 8; ++i)
	{
		b [i] = ( c & ( 1 << i ) ) != 0;
	}
}

uint8_t MessageFrame::xbeeChecksum(uint8_t *arr)
{
	uint8_t checksum;
	uint16_t crc = 0;

	for (int it = 3; it <= 18; it++)
	{
		crc += arr [it];
	}
	crc &= 0xFF;
	crc = 0xFF - crc;
	checksum = crc;

	return checksum;
}

bool MessageFrame::getBoolAtByte(uint8_t byte, uint8_t index)
{
	eliminateEscapeChars();
	bool c;
	uint8_t tmp[8]={0};
	fromByte(recvEscaped[byte],tmp);
	c = tmp[index];
	return c;
}

void MessageFrame::eliminateEscapeChars( )
{
	//TODO write implementation of elimination of escape chars in input stream
}
