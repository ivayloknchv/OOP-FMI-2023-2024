#include "Computer.h"
#include <cstring>
#include <utility>
#include <stdexcept>
#include <iostream>
#pragma warning (disable : 4996)


void Computer::copyFrom(const Computer& other)
{
	cpuPower = other.cpuPower;
	graphicsCardModel = new char[strlen(other.graphicsCardModel) + 1] {};
	strcpy(graphicsCardModel, other.graphicsCardModel);
}

void Computer::moveFrom(Computer&& other)
{
	cpuPower = other.cpuPower;
	graphicsCardModel = other.graphicsCardModel;
	chargePower = other.chargePower;

	other.graphicsCardModel = nullptr;
}

void Computer::free()
{
	delete[] graphicsCardModel;
	graphicsCardModel = nullptr;
	cpuPower = 0;
	chargePower = 0;
}

Computer::Computer(const Computer& other)
{
	copyFrom(other);
}

Computer& Computer::operator=(const Computer& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Computer::Computer(Computer&& other) noexcept
{
	moveFrom(std::move(other));
}

Computer& Computer::operator=(Computer&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Computer::~Computer() noexcept
{
	free();
}

Computer::Computer(double newCPUpower, const char* newGraphicCard, int newChargePower)
{
	setCPU(newCPUpower);
	setGrapicCard(newGraphicCard);
	setChargePower(newChargePower);
}

void Computer::setCPU(double newCPUpower)
{
	cpuPower = newCPUpower;
}

void Computer::setGrapicCard(const char* newGraphicCard)
{
	if (!newGraphicCard || graphicsCardModel == newGraphicCard)
	{
		return;
	}

	delete[] graphicsCardModel;
	graphicsCardModel = new char[strlen(newGraphicCard) + 1]{};
	strcpy(graphicsCardModel, newGraphicCard);
}

void Computer::setChargePower(int newChargePower)
{
	chargePower = newChargePower;
}

