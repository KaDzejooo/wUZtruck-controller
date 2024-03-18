/*
 * classTruck.cpp
 *
 *  Created on: 9 maj 2023
 *       Author: KaDzejoo i MrDevelopeer
 */

#include <class/classTruck.h>

classTruck::classTruck(short int netId, int iconIndex, char* name, char isActive,char isOnline) {
	this->netId =netId;
	this->iconIndex =iconIndex;
	this->name = name;
	this->isActive = isActive;
	this->isOnline = isOnline;
}

// setters
void classTruck::setIsOnline(char state)
{
	isOnline = state;
}
void classTruck::setIsActive(char state)
{
	isActive = state;
}
// getters
char classTruck::getIsActive()
{
	return isActive;
}
char classTruck::getIsOnline()
{
	return isOnline;
}
int classTruck::getIconIndex()
{
	return iconIndex;
}
char classTruck::getName()
{
	return *name;
}
short int classTruck::getNetId()
{
	return netId;
}
