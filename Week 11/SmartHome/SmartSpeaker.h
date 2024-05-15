#pragma once
#include "Device.h"

class SmartSpeaker : public Device
{
	unsigned _volume = 0;

public:

	SmartSpeaker(const char* name, const char* manufacturer, unsigned volume);
	Device* clone() const override;

	void setVolume(unsigned volume);
	unsigned getVolume() const;

	void turnOn() const override;
	void turnOff() const override;
	void printInfo() const override;
};

