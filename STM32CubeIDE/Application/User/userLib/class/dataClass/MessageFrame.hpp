/*
 * MessageFrame.hpp
 *
 *  Created on: Mar 13, 2024
 *      Author: KaDzejoo
 */

#ifndef MESSAGEFRAME_HPP_
#define MESSAGEFRAME_HPP_

#define MESSAGE_LENGTH 100


//#if MESSAGE_LENGTH > 255
//	#define MESSAGE_TYPE int
//#else
//	#define MESSAGE_TYPE uint8_t
//#endif

// TODO ?

/*
 *
 */
class MessageFrame
{
	public:
		MessageFrame( );

		///Receiver part
		///
		/*
		 * Returns pointer to an array that contains unchanged message taken from xbee
		 */
		uint8_t* getRecvUndecoded() {return recv;}
		/*
		 * returns pointer to an array that contains array with eliminated escape chars
		 */
		uint8_t* getRecvEscaped(){eliminateEscapeChars();return recvEscaped;};
		/*
		 * Returns single byte from message at position "index"
		 */
		uint8_t getByte(uint8_t index){eliminateEscapeChars();return recvEscaped[index];};
		/*
		 * Returns single boolean value at "byte" at "index"
		 */
		bool getBoolAtByte(uint8_t byte, uint8_t index);
		/*
		 * Sets state of an undecoded array
		 */
		void setRecvArray(uint8_t* recv, uint8_t len);

		/// Sender Part
		///
		/*
		 * Sets array that contains message in it;
		 */
		void setSendArray(uint8_t* src, uint8_t srcLen = 0);
		/*
		 * Returns pointer to an message array;
		 */
		uint8_t* getSendArray(){return send;};
		/*
		 * Sets single byte and increments length value
		 */
		void appendByte(uint8_t byte){send[length] = byte; length++;};
		/*
		 * Sets byte at index in send array
		 */
		void setByteAt(uint8_t byte, uint8_t index){send[index] = byte;};
		/*
		 * Returns length of an "send" array
		 */
		uint8_t getLength(){return length;};
		/*
		 * Sets lengthof message,
		 * WARNING: it could lead to overwriting some data in send array;
		 */
		void setLength(uint8_t len){length = len;};

	private:
		void eliminateEscapeChars( );
		uint8_t toByte(bool b [8]);
		void fromByte(uint8_t c, uint8_t b [8]);
		uint8_t xbeeChecksum(uint8_t *arr);

		uint8_t recv [MESSAGE_LENGTH] =
		{0};
		uint8_t recvEscaped [MESSAGE_LENGTH] =
		{0};
		uint8_t send [MESSAGE_LENGTH] =
		{0};
		uint8_t length=0;

		typedef struct{
				uint8_t startByte = 0x7E;
				uint8_t escapeByte = 0x7D;
				uint8_t xON = 0x11;
				uint8_t xOFF = 0x13;
				uint8_t messageIdentifier = 0x44;
		}messageConst;


};

#endif /* MESSAGEFRAME_HPP_ */
