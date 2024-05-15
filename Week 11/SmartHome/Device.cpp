#include "Device.h"
#include <cstring>
#include <exception>
#include <utility>
#include <iostream>

#pragma warning (disable : 4996)

void Device::copyFrom(const Device& other)
{
	_name = new char[strlen(other._name) + 1]{};
	strcpy(_name, other._name);

	
	_manufacturer = new char[strlen(other._manufacturer) + 1]{};
	strcpy(_manufacturer, other._manufacturer);
}

void Device::moveFrom(Device&& other)
{
	_name = other._name;
	_manufacturer = other._manufacturer;

	other._name = nullptr;
	other._manufacturer = nullptr;
}

void Device::free()
{
	delete[] _name;
	delete[] _manufacturer;

	_name = nullptr;
	_manufacturer = nullptr;
}

Device::Device(const Device& other)
{
	copyFrom(other);
}

Device& Device::operator=(const Device& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Device::Device(Device&& other) noexcept
{
	moveFrom(std::move(other));
}

Device& Device::operator=(Device&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Device::~Device()
{
	free();
}

Device::Device(const char* name, const char* manufacturer)
{
	setName(name);
	setManufacturer(manufacturer);
}

void Device::setName(const char* name)
{
	if (!name || name == _name)
	{
		return;
	}

	delete[] _name;
	_name = new char[strlen(name) + 1]{};
	strcpy(_name, name);
}

void Device::setManufacturer(const char* manufacturer)
{
	if (!manufacturer || manufacturer == _manufacturer)
	{
		return;
	}

	delete[] _manufacturer;
	_manufacturer = new char[strlen(manufacturer) + 1]{};
	strcpy(_manufacturer, manufacturer);
}

const char* Device::getManufacturer() const
{
	return _manufacturer;
}

void Device::printInfo() const
{
	std::cout << "Name: " << getName() << std::endl;
	std::cout << "Manufacturer: " << getManufacturer() << std::endl;
}

const char* Device::getName() const
{
	return _name;
}