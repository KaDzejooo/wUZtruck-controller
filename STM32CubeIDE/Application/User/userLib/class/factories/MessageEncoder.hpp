/*
 * messageEncoder.hpp
 *
 *  Created on: Oct 7, 2023
 *      Author: KaDzejoo
 */

#ifndef MESSAGEENCODER_HPP_
#define MESSAGEENCODER_HPP_

#include "InputOutputModel.hpp"
#include "ControllerSettings.hpp"
#include "UTypes.hpp"
#include "MessageFrame.hpp"
#include <vector>
#include <algorithm>




class MessageEncoder
{
	public:
		MessageEncoder( );
		/*
		 * controller(IDk || integrityMngr) sets state of state variable multiple times
		 * Integrity manager runs encodeStateToMessage
		 * UartTask getsMessage and sends it
		 *
		 *	UartTask setsMessage
		 *	IntegrityMngr uses decodemesageToState
		 *	and sets IOM controllerState to this /\
		 */


		MessageFrame frameRecv;
		/*
		 * Sets encoder state as @param
		 */
		void setState(InputOutputModel model);
		/*
		 * returns translated message as IOM class
		 */
		InputOutputModel getReceived();
		/*
		 * Decodes received message into IOM class "received"
		 */
		void decodeMessageToState(MessageFrame frame);
		/*
		 * Sets state of encoder
		 * Packs IOM statuses
		 * Prepares message to send
		 * into BinaryArr (stupid name)
		 */
		void encodeStateToMessage();


		/*
		 * sets type of message
		 */
		void setMessageType(MessageTypes mess);
		MessageTypes getMessageType() {return messageType;}
		/*
		 * returns message as binary array
		 */
		const uint8_t* getBinaryArr( ) const
		{
			return binaryArr;
		}
		

		uint8_t getArrLen( ) const
		{
			return arrLen;
		}




		/*
		 * public declaration for debug purposes
		 * DEPRECATED, replace in MainScreenView and OutputsScreenView
		 */
		uint8_t binaryArr[30]= {0};
		uint8_t binaryArr2[20] = { 0x7E, 0x00, 0x10, 0x01, 0x00, 0x00, 0x20, 0x00, 0x44, 0xD0, 0x18, 0xA9, 0xA9, 0xC2, 0x32, 0x32, 0x01, 0x32, 0x32, 0xD5};
		uint8_t offset = 0;
		uint8_t tmpArr[20] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD0, 0x18, 0xA9, 0xA9, 0xC2, 0x32, 0x32, 0x01, 0x32, 0x32, 0x00};
	private:
		MessageTypes messageType = MessageTypes::messageD;
		uint8_t arrLen;
		uint16_t n=0;
		uint16_t tempLen=0;
		uint8_t compoundStatus,vehicleStatus,trailerStatus,lightsStatus,lights2Status;
		InputOutputModel state,received;


		// this sh be #define START_BYTE 0x7E
		const uint8_t startByte = 0x7E;
		const uint8_t escapeByte = 0x7D;
		const uint8_t xON = 0x11;
		const uint8_t xOFF = 0x13;
		const uint8_t messageIdentifier = 0x44;

		/*
		 * Calculates xBee specific checksum given an array of data
		 */
		uint8_t xbeeChecksum(uint8_t *arr);
		/*
		 * Given bool array[8] calculates uint8_t and returns
		 */
		uint8_t toByte(bool b[8]);
		/*
		 * Packs status(IOM) into bool arrays[8]
		 */
		void packStatuses( );
		/*
		 * Generates temp frame for further modifications
		 */
		void prepareMessage( );
		/*
		 *  Checks for escape characters and assignment tempArr->binArr
		 */
		void tableAssignment();
		/*
		 * calculates offset of bytes (debug only)
		 */
		void calculateOffset();
		/*
		 * Reverses order of bytes
		 */
		uint8_t reverseByte(uint8_t b);
		/*
		 * Takes byte and slits its content into boolean array
		 */
		void fromByte(uint8_t c, uint8_t b[8]);


		////// Frame generators
		/*
		 * generates basic D frame for communication
		 */
		void generateFrameD();
		/*
		 * generates frame that checks for active vehicles
		 */
		void generateFrameQ();
};

#endif /* MESSAGEENCODER_HPP_ */
