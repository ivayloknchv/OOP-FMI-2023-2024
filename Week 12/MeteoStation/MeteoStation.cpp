#include "MeteoStation.h"
#include <cstring>
#include <utility>

#pragma warning (disable : 4996)

void MeteoStation::copyFrom(const MeteoStation& other)
{
	city = new char[strlen(other.city) + 1]{};
	strcpy(city, other.city);

	temperature = other.temperature;

	size = other.size;
	capacity = other.capacity;
	list = new Observer * [capacity] {};

	for (size_t i = 0; i < size; i++)
	{
		list[i] = other.list[i];
	}
}

void MeteoStation::moveFrom(MeteoStation&& other)
{
	city = other.city;
	other.city = nullptr;

	temperature = other.temperature;
	other.temperature = 0;

	list = other.list;
	other.list = nullptr;

	size = other.size;
	other.size = 0;

	capacity = other.capacity;
	other.capacity = 0;

}

void MeteoStation::free()
{
	delete[] city;
	city = nullptr;

	temperature = 0;

	delete[] list;
	list = nullptr;

	size = 0;
	capacity = 0;
}

void MeteoStation::resize(size_t newCapacity)
{
	Observer** temp = new Observer * [newCapacity] {};

	for (size_t i = 0; i < size; i++)
	{
		temp[i] = list[i];
	}

	delete[] list;
	list = temp;
	capacity = newCapacity;
	temp = nullptr;
}

size_t MeteoStation::findObserver(const Observer* obj) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (obj == list[i])
		{
			return i;
		}
	}

	return size;
}

MeteoStation::MeteoStation(const char* city, double temperature)
{
	capacity = 8;
	list = new Observer * [capacity] {};
	setCity(city);
	setTemperature(temperature);
}

MeteoStation::MeteoStation(const MeteoStation& other)
{
	copyFrom(other);
}

MeteoStation& MeteoStation::operator=(const MeteoStation& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

MeteoStation::MeteoStation(MeteoStation&& other) noexcept
{
	moveFrom(std::move(other));
}

MeteoStation& MeteoStation::operator=(MeteoStation&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

MeteoStation::~MeteoStation()
{
	free();
}

void MeteoStation::setCity(const char* city)
{
	if (!city || this->city == city)
	{
		return;
	}

	delete[] this->city;

	this->city = new char[strlen(city) + 1]{};
	strcpy(this->city, city);
}

void MeteoStation::setTemperature(double temperature)
{
	this->temperature = temperature;
	notify();
}

const char* MeteoStation::getCity() const
{
	return city;
}

double MeteoStation::getTemperature() const
{
	return temperature;
}

void MeteoStation::registerObserver(Observer* obj)
{
	if (size == capacity)
	{
		resize(2 * size);
	}

	list[size++] = obj;
}

void MeteoStation::unregisterObserver(Observer* obj)
{
	if (!obj)
	{
		return;
	}

	size_t idx = findObserver(obj);

	if (idx == size)
	{
		return;
	}

	std::swap(list[idx], list[size - 1]);
	list[size - 1] = nullptr;
	--size;
}

void MeteoStation::notify()
{
	for (size_t i = 0; i < size; i++)
	{
		list[i]->update(city, temperature);
	}
}
