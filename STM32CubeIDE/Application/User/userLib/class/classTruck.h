/*
 * classTruck.h
 *
 *  Created on: 9 maj 2023
 *      Author: KaDzejoo i MrDevelopeer
 */
#ifndef APPLICATION_USER_USERLIB_CLASS_CLASSTRUCK_H_
#define APPLICATION_USER_USERLIB_CLASS_CLASSTRUCK_H_

class classTruck {
	private:
		short int netId;
		int iconIndex;
		char* name;
		char isOnline;
		char isActive;

	public:
		classTruck(short int netId, int iconIndex, char* name,char isActive,char isOnline);

	// setters
		void setIsOnline(char state);
		void setIsActive(char state);
	// getters
		char getIsActive();
		char getIsOnline();
		int getIconIndex();
		char getName();
		short int getNetId();

};

#endif /* APPLICATION_USER_USERLIB_CLASS_CLASSTRUCK_H_ */
