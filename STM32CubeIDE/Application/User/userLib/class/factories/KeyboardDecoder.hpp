/*
 * KeyboardDecoder.hpp
 *
 *  Created on: Sep 14, 2023
 *      Author: KaDzejoo
 */

#ifndef KEYBOARDDECODER_HPP_
#define KEYBOARDDECODER_HPP_
#include <string>
/*
 *
 */
class KeyboardDecoder
{
	public:
		KeyboardDecoder( );
		void decode(std::string code, bool &executed);

	private:
		bool opValues(std::string actualCode,int value);
		bool opCodes(std::string actualCode);
		bool opLock(std::string actualCode);

		std::string functionCodePrefix = "00";
// Opcodes
		std::string opcodeSleep = "SL"; // screen 51eep
		std::string opcodeTimeout = "ST"; // screen timeout

		std::string opcodeVehi = "TR"; // set truck adress
		std::string opcodeType = "TT"; // set truck type
		std::string opcodeMess = "MS"; // message camx edit debug

//security codes
		std::string opcodeLock = "LO"; // controllerLock
		std::string opcodeUser = "OP"; // Operator login code
// Specific codes
		std::string lockCode = "80085"; // lock enable
		std::string unlockCode = "080085"; // lock disable

		std::string userCodeD = "0000"; // default user
		std::string userCodeDbg = "3333"; // debug user
		std::string userCodeK = "1337"; // kadzejoo
		std::string userCodeP = "2137"; // pope itself
		std::string userCodeF = "4444"; // cptFrost itself

// Free floating codes
		//std::string secretCode1 = "2137";
		//std::string secretCode2 = "02137";
};

#endif /* KEYBOARDDECODER_HPP_ */
