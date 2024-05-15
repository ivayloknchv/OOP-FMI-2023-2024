#include "SmartThermostat.h"
#include <iostream>

SmartThermostat::SmartThermostat(const char* name, const char* manufacturer, double currentTemperature, double targetTemperature) 
	: Device(name, manufacturer)
{
	setTargetTemperature(targetTemperature);
	setCurrentTemperature(currentTemperature);
}

Device* SmartThermostat::clone() const
{
	return new (std::nothrow) SmartThermostat(*this);
}

void SmartThermostat::setCurrentTemperature(double temp)
{
	_currentTemperature = temp;
}

void SmartThermostat::setTargetTemperature(double temp)
{
	_targetTemperature = temp;
}

double SmartThermostat::getCurrentTemperature() const
{
	return _currentTemperature;
}

double SmartThermostat::getTargetTemperature() const
{
	return _targetTemperature;
}

void SmartThermostat::turnOn() const
{
	std::cout << "SmartThermostat " << getName() << " turning on..." << std::endl;
}

void SmartThermostat::turnOff() const
{
	std::cout << "SmartThermostat " << getName() << " turning off..." << std::endl;
}

void SmartThermostat::printInfo() const
{
	Device::printInfo();
	std::cout << "Current Temperature: " << _currentTemperature << std::endl;
	std::cout << "Target Temperature: " << _targetTemperature << std::endl;
}
