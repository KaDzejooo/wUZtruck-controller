/*
 * Notification.cpp
 *
 *  Created on: Aug 25, 2023
 *      Author: KaDzejoo
 */

#include <Notification.hpp>

Notification::Notification( )
{
}

Notification::~Notification( )
{
}

int Notification::getBarValue( ) const
{
	return barValue;
}

void Notification::setBarValue(int barValue)
{
	this->barValue = barValue;
}

touchgfx::Bitmap Notification::getIcon24dp( ) const
{
	return icon24dp;
}

void Notification::setIcon24dp(touchgfx::Bitmap icon24dp)
{
	this->icon24dp = icon24dp;
}

touchgfx::Bitmap Notification::getIcon48dp( ) const
{
	return icon48dp;
}

void Notification::setIcon48dp(touchgfx::Bitmap icon48dp)
{
	this->icon48dp = icon48dp;
}



const std::string& Notification::getSubText( ) const
{
	return subText;
}

void Notification::setSubText(const std::string &subText)
{
	this->subText = subText;
}

const std::string& Notification::getSubText2( ) const
{
	return subText2;
}

void Notification::setSubText2(const std::string &subText2)
{
	this->subText2 = subText2;
}

const std::string& Notification::getTitle( ) const
{
	return title;
}

void Notification::setTitle(const std::string &title)
{
	//assert(title.length() < 34);
	this->title = title;
}

notification::notificationType Notification::getType( ) const
{
	return type;
}

void Notification::setType(notification::notificationType type)
{
	this->type = type;
}

bool Notification::isVisible( ) const
{
	return visible;
}

void Notification::setVisible(bool visible)
{
	this->visible = visible;
}

notification::priorityColor Notification::getPriorityColor( ) const
{
	return priorityColor;
}

void Notification::setPriorityColor(notification::priorityColor priorityColor)
{
	this->priorityColor = priorityColor;
}

int Notification::getPriority( ) const
{
	return priority;
}

void Notification::setPriority(int priority)
{
	this->priority = priority;
}

bool Notification::isBlink( ) const
{
	return blink;
}

void Notification::setBlink(bool blink)
{
	this->blink = blink;
}

bool Notification::isDynamic( ) const
{
	return dynamic;
}

void Notification::setDynamic(bool dynamic)
{
	this->dynamic = dynamic;
}

const std::string& Notification::getVehicle( ) const
{
	return vehicle;
}

void Notification::setVehicle(const std::string &vehicle)
{
	this->vehicle = vehicle;
}
