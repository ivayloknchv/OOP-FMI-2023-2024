#include "SmartHome.h"
#include <iostream>

void SmartHome::copyFrom(const SmartHome& other)
{
	size = other.size;
	capacity = other.capacity;

	data = new Device * [capacity] {};

	for (size_t i = 0; i < size; i++)
	{
		if (other.data != nullptr)
		{
			data[i] = other.data[i]->clone();
		}
	}
}

void SmartHome::moveFrom(SmartHome&& other)
{
	data = other.data;
	other.data = nullptr;
	size = other.size;
	capacity = other.capacity;

	other.size = 0;
	other.capacity = 0;
}

void SmartHome::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete data[i];
	}

	delete[] data;
	data = nullptr;

	size = 0;
	capacity = 0;
}

void SmartHome::resize(size_t newCapacity)
{
	Device** temp = new Device * [newCapacity] {};

	for (size_t i = 0; i < size; i++)
	{
		temp[i] = data[i];
	}

	delete[] data;
	data = temp;
	capacity = newCapacity;
}

SmartHome::SmartHome()
{
	capacity = 8;
	data = new Device * [capacity] {};
}

SmartHome::SmartHome(const SmartHome& other)
{
	copyFrom(other);
}

SmartHome& SmartHome::operator=(const SmartHome& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

SmartHome::SmartHome(SmartHome&& other) noexcept
{
	moveFrom(std::move(other));
}

SmartHome& SmartHome::operator=(SmartHome&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

SmartHome::~SmartHome()
{
	free();
}

void SmartHome::add(Device* device)
{
	if (size == capacity)
	{
		resize(2 * capacity);
	}

	data[size++] = device->clone();
}

void SmartHome::addLight(const char* name, const char* manufacturer, unsigned brightnessLevel)
{
	if (size == capacity)
	{
		resize(2 * capacity);
	}

	data[size++] = new SmartLight(name, manufacturer, brightnessLevel);
}

void SmartHome::addTheromstat(const char* name, const char* manufacturer, double currentTemperature, double targetTemperature)
{
	if (size == capacity)
	{
		resize(2 * capacity);
	}

	data[size++] = new SmartThermostat(name, manufacturer, currentTemperature, targetTemperature);
}

void SmartHome::addSpeaker(const char* name, const char* manufacturer, unsigned volume)
{
	if (size == capacity)
	{
		resize(2 * capacity);
	}

	data[size++] = new SmartSpeaker(name, manufacturer, volume);
}

void SmartHome::removeByIdx(size_t idx)
{
	if (idx >= size)
	{
		return;
	}

	delete data[idx];
	data[idx] = nullptr;
	std::swap(data[idx], data[size - 1]);
	--size;
}

void SmartHome::showAll() const
{
	for (size_t i = 0; i < size; i++)
	{
		data[i]->printInfo();

		if (i != size - 1)
		{
			std::cout << "------------------" << std::endl;
		}
	}
}
