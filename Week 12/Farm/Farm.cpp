#include "Farm.h"
#include <utility>
#include <stdexcept>

void Farm::copyFrom(const Farm& other)
{
	size = other.size;
	capacity = other.capacity;
	data = new Animal * [capacity] {};

	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i]->clone();
	}
}

void Farm::moveFrom(Farm&& other)
{
	data = other.data;
	other.data = nullptr;

	size = other.size;
	capacity = other.capacity;
	other.size = other.capacity = 0;
}

void Farm::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete data[i];
	}

	delete[] data;

	data = nullptr;
	size = capacity = 0;
}

void Farm::resize(size_t newCapacity)
{
	Animal** temp = new Animal *[newCapacity] {};

	for (size_t i = 0; i < size; i++)
	{
		temp[i] = data[i];
	}

	delete[] data;
	data = temp;
	capacity = newCapacity;
	temp = nullptr;
}

Farm::Farm()
{
	capacity = 8;
	data = new Animal * [capacity] {};
}

Farm::Farm(const Farm& other)
{
	copyFrom(other);
}

Farm& Farm::operator=(const Farm& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Farm::Farm(Farm&& other) noexcept
{
	moveFrom(std::move(other));
}

Farm& Farm::operator=(Farm&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Farm::~Farm()
{
	free();
}

void Farm::addAnimal(AnimalType type)
{
	if (size == capacity)
	{
		resize(2 * capacity);
	}

	data[size++] = AnimalFactory::create(type);
}

void Farm::addAnimal(const Animal& other)
{
	if (size == capacity)
	{
		resize(2 * capacity);
	}

	data[size++] = other.clone();
}

void Farm::roarAll() const
{
	for (size_t i = 0; i < size; i++)
	{
		data[i]->roar();
	}
}

AnimalType Farm::getTypeByIndex(size_t idx)
{
	if (idx < 0 || idx >= size)
	{
		throw std::out_of_range("Out of range index!");
	}

	return data[idx]->getType();
}
