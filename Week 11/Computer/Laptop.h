#pragma once
#include "Computer.h"

class Laptop : public Computer
{
	char periferia[30] = "Mouse Pad, Keyboard, Monitor";
public:

	Laptop(double newCPUpower, const char* newGraphicCard, int newChargePower);

	void printType() const override;
	const char* getDevices() const override;
};

