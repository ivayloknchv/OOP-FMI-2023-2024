#include "SmartSpeaker.h"
#include <iostream>

SmartSpeaker::SmartSpeaker(const char* name, const char* manufacturer, unsigned volume) : Device(name, manufacturer)
{
	setVolume(volume);
}

Device* SmartSpeaker::clone() const
{
	return new (std::nothrow) SmartSpeaker(*this);
}

void SmartSpeaker::setVolume(unsigned volume)
{
	_volume = volume;
}

unsigned SmartSpeaker::getVolume() const
{
	return _volume;
}

void SmartSpeaker::turnOn() const
{
	std::cout << "SmartSpeaker " << getName() << " turning on..." << std::endl;
}

void SmartSpeaker::turnOff() const
{
	std::cout << "SmartSpeaker " << getName() << " turning off..." << std::endl;
}

void SmartSpeaker::printInfo() const
{
	Device::printInfo();
	std::cout << "Volume Level: " << _volume << std::endl;
}
