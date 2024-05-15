#include "SmartLight.h"
#include <iostream>

SmartLight::SmartLight(const char* name, const char* manufactutrer, unsigned brightnessLevel) : Device(name, manufactutrer)
{
	setBrightnessLevel(brightnessLevel);
}

void SmartLight::setBrightnessLevel(unsigned brightnessLevel)
{
	_brightnessLevel = brightnessLevel;
}

unsigned SmartLight::getBrightnessLevel() const
{
	return _brightnessLevel;
}

Device* SmartLight::clone() const
{
	return new (std::nothrow) SmartLight(*this);
}

void SmartLight::turnOn() const
{
	std::cout << "SmartLight " << getName() << " turning on..." << std::endl;
}

void SmartLight::turnOff() const
{
	std::cout << "SmartLight " << getName() << " turning off..." << std::endl;
}

void SmartLight::printInfo() const
{
	Device::printInfo();
	std::cout << "Brightness level: " << _brightnessLevel << std::endl;
}
