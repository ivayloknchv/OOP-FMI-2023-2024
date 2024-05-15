#pragma once
#include "Device.h"

class SmartThermostat : public Device
{
private:

	double _currentTemperature = 0;
	double _targetTemperature = 0;

public:

	SmartThermostat(const char* name, const char* manufacturer, double currentTemperature, double targetTemperature);

	Device* clone() const override;

	void setCurrentTemperature(double temp);
	void setTargetTemperature(double temp);

	double getCurrentTemperature() const;
	double getTargetTemperature() const;

	void turnOn() const override;
	void turnOff() const override;
	void printInfo() const override;
};

