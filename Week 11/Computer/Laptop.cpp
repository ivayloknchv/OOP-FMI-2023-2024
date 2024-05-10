#include "Laptop.h"
#include <iostream>
Laptop::Laptop(double newCPUpower, const char* newGraphicCard, int newChargePower)
	: Computer(newCPUpower, newGraphicCard, newChargePower)
{}

void Laptop::printType() const
{
	std::cout << "Laptop" << std::endl;
}

const char* Laptop::getDevices() const
{
	return periferia;
}

