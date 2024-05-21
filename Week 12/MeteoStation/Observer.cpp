#include "Observer.h"
#include <cstring>
#include <utility>
#pragma warning (disable : 4996)

void Observer::copyFrom(const Observer& other)
{
	temperature = other.temperature;

	name = new char[strlen(other.name) + 1]{};
	strcpy(name, other.name);

	city = new char[strlen(other.city) + 1]{};
	strcpy(city, other.city);
}

void Observer::moveFrom(Observer&& other)
{
	name = other.name;
	other.name = nullptr;

	city = other.city;
	other.city = nullptr;

	temperature = other.temperature;
	other.temperature = 0;
}

void Observer::free()
{
	delete[] name;
	name = nullptr;

	delete[] city;
	city = nullptr;

	temperature = 0;
}

Observer::Observer(const char* name, const char* city, double temperature)
{
	setName(name);
	setCity(city);
	setTemperature(temperature);
}

Observer::Observer(const Observer& other)
{
	copyFrom(other);
}

Observer& Observer::operator=(const Observer& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return* this;
}

Observer::Observer(Observer&& other) noexcept
{
	moveFrom(std::move(other));
}

Observer& Observer::operator=(Observer&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Observer::~Observer()
{
	free();
}

void Observer::setName(const char* name)
{
	if (!name || this->name == name)
	{
		return;
	}

	delete[] this->name;
	
	this->name = new char[strlen(name) + 1]{};
	strcpy(this->name, name);
}

void Observer::setCity(const char* city)
{
	if (!city || this->city == city)
	{
		return;
	}

	delete[] this->city;

	this->city = new char[strlen(city) + 1]{};
	strcpy(this->city, city);
}

void Observer::setTemperature(double temperature)
{
	this->temperature = temperature;
}
