#pragma once
#include "Computer.h"

class PC : public Computer
{
	char periferia[50] = "Mouse, keyboard, mic, headphones" ;

public:

	PC(double newCPUpower, const char* newGraphicCard, int newChargePower);

	void printType() const  override;

	const char* getDevices() const override;
};

