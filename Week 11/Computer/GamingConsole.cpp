#include "GamingConsole.h"
#include <iostream>

GamingConsole::GamingConsole(double newCPUpower, const char* newGraphicCard, int newChargePower)
	:Computer(newCPUpower, newGraphicCard, newChargePower)
{
}

void GamingConsole::printType() const
{
	std::cout << "Gaming Console" << std::endl;
}

const char* GamingConsole::getDevices() const
{
	return periferia;
}

