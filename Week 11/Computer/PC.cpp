#include "PC.h"
#include "Computer.h"
#include <iostream>

PC::PC(double newCPUpower, const char* newGraphicCard, int newChargePower)
	: Computer(newCPUpower, newGraphicCard, newChargePower)
{
}

void PC::printType() const
{
	std::cout << "PC" << std::endl;
}

const char* PC::getDevices() const
{
	return periferia;
}
