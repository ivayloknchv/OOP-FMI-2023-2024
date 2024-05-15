#pragma once
#include "Device.h"

class SmartLight : public Device
{
	unsigned _brightnessLevel = 0;

public:

	SmartLight(const char* name, const char* manufactutrer, unsigned brightnessLevel);

	void setBrightnessLevel(unsigned brightnessLevel);
	unsigned getBrightnessLevel() const;

	Device* clone() const override;

	void turnOn() const override;
	void turnOff() const override;
	void printInfo() const override;
};

