#pragma once
#include "Computer.h"

class GamingConsole : public Computer
{
	char periferia[30] = "Joystick, monitor";

public:

	GamingConsole(double newCPUpower, const char* newGraphicCard, int newChargePower);

	void printType() const override;

	const char* getDevices() const override;
};
