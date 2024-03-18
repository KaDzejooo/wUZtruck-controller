/*
 * messageEncoder.cpp
 *
 *  Created on: Oct 7, 2023
 *      Author: KaDzejoo & KRYSTIAN
 */

#include <class/factories/MessageEncoder.hpp>
extern InputOutputModel controllerState;
extern ControllerSettings settingsM;



MessageEncoder::MessageEncoder( )
{
	
}
void MessageEncoder::setState(InputOutputModel model)
{
	state = model;
}

InputOutputModel MessageEncoder::getReceived( )
{
	return received;
}

void MessageEncoder::decodeMessageToState(MessageFrame frame)
{

//TODO fill all fields with data
	received.gear = frame.getBoolAtByte(7, 2);

}

void MessageEncoder::encodeStateToMessage( )
{
	offset = 0;
	setState(controllerState);
	packStatuses( );
	prepareMessage( );
	tableAssignment();
	calculateOffset( );
}

void MessageEncoder::prepareMessage( )
{


	uint8_t lock = settingsM.locked;

	if(lock == 1){
		state.axis.direction = 50;
		state.axis.turn = 50;
		state.axis.camx = 50;
		state.axis.camy =  50;
	}

	switch (messageType)
	{
		case MessageTypes::messageD:
			generateFrameD();
		break;
		case MessageTypes::messageQ:
		break;
	}


}
void MessageEncoder::packStatuses( )
{
	bool compArr[8]={
			0, // --
			0, // empty
			0, // --
			0, // --
			0, // is trailer connected
			0, // is trailer on saddle
			0, // is trailer active
			0, // truck active
	};
	bool vehiArr[8]={
			0, //
			0,
			0,
			1, // scania lol
			1, // cam selection
			0, // cam sel pt2
			0, // audio module
			0  // gearbox up/down
	};
	bool traiArr[8]={
			0, // trailer type
			0,
			0,
			0, // tt end
			0, // steering axis available
			0, // lifting axis available
			0, // is lifted
			0  // is supports lifted yes
	};
	bool lighArr[8]={
			state.fogLightsRear,
			state.fogLightsFront,
			state.highBeams,
			state.topLights,
			state.dayLights, // daylies :nonexistent in code
			state.lowBeams, // drogowe :nonexistent in code // replaced by LB for now
			state.lowBeams, // Mijania :nonexistent in code
			state.posLights
	};
	bool lig2Arr[8]={
			state.horn,
			state.topLights,
			state.horn, // backing lights TODO backing lights: nonexistent in code
			state.hazards,
			state.leftBlinker, // IDK
			state.rightBlinker,
			state.leftBlinker,
			state.rightBlinker
	};

	compoundStatus = reverseByte(toByte(compArr));
	vehicleStatus = reverseByte(toByte(vehiArr));
	trailerStatus = reverseByte(toByte(traiArr));
	lightsStatus = reverseByte(toByte(lighArr));
	lights2Status = reverseByte(toByte(lig2Arr));
}
uint8_t MessageEncoder::xbeeChecksum(uint8_t *arr)
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
void MessageEncoder::fromByte(uint8_t c, uint8_t b[8])
{
	for (int i = 0; i < 8; ++i)
	{
		b [i] = ( c & ( 1 << i ) ) != 0;
	}

}
uint8_t MessageEncoder::toByte(bool b[8])
{
	uint8_t c = 0;
	for (int it = 0; it < 8; ++it)
		if (b [it]) c |= 1 << it;
	return c;
}

void MessageEncoder::tableAssignment( )
{
	/*
	 * This func generates escape bytes and assigns Temporary array into message array
	 */
	binaryArr[0] = tmpArr[0];
	binaryArr[1] = tmpArr[1];
	binaryArr[2] = tmpArr[2];

	for(int i=1, x=1; i<tempLen; i++,x++)
	{
		if (startByte == tmpArr [i] || escapeByte == tmpArr [i] || xON == tmpArr [i]
				|| xOFF
				== tmpArr [i])
		{
			binaryArr [x] = escapeByte;
			binaryArr [++x] = tmpArr [i] ^ 0x20;
		}
		else
		{
			binaryArr [x] = tmpArr [i];
		}

	arrLen=x;
	}
	binaryArr [arrLen] = xbeeChecksum(tmpArr);
}

void MessageEncoder::calculateOffset( )
{
	for (int i = 1; i < tempLen; i++)
	{
		if (escapeByte == binaryArr [i])
		{
			offset++;
		}
	}
}
uint8_t MessageEncoder::reverseByte(uint8_t b)
{
	b = ( b & 0xF0 ) >> 4 | ( b & 0x0F ) << 4;
	b = ( b & 0xCC ) >> 2 | ( b & 0x33 ) << 2;
	b = ( b & 0xAA ) >> 1 | ( b & 0x55 ) << 1;
	return b;
}

void MessageEncoder::generateFrameD( )
{
	uint8_t i = 0;

		tmpArr [0] = startByte;                 //Start delimiter: 0x7E		//- between length and checksum fields
		tmpArr[1] =0 ;							    //len
		//tmpArr[2]                             //len
		tmpArr [3] = 0x01;						// API - frame type
		tmpArr [4] = 0x00;						//Frame ID
		tmpArr [5] = 0x00;						//02hex destination address
		tmpArr [6] = state.adress;				//0x20:Scania address
		tmpArr [7] = 0x00;						//Options:0x00==none
		i = 8;
		// command's parameter
		tmpArr [i++] = messageIdentifier;			//'Always' ASCII 'D' 0x44
		tmpArr [i++] = compoundStatus;  			// compound status
		tmpArr [i++] = vehicleStatus; 				// vehicle status
		tmpArr [i++] = trailerStatus; 				// trailer status
		tmpArr [i++] = lightsStatus; 				// lights
		tmpArr [i++] = lights2Status; 				// lights pt2
		tmpArr [i++] = state.gear; 			//gear
		tmpArr [i++] = state.axis.direction; 	//speed
		tmpArr [i++] = state.axis.turn; 	// turn
		tmpArr [i++] = state.axis.camx;				// camx
		tmpArr [i++] = state.axis.camy;						// camy
		tmpArr [i++] = xbeeChecksum(tmpArr); 		//checksum byte

		i = 20;
		tmpArr [2] = 0x10 ;		// len LO
		tempLen = i;


	
}

void MessageEncoder::generateFrameQ( )
{
	//TODO check for all frame types and write functions for them
	return;
}
