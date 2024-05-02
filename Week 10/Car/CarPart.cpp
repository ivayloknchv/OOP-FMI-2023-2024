#include "CarPart.h"
#include <stdexcept>

unsigned CarPart::idCounter = 0;

void CarPart::copyFrom(const CarPart& other)
{
	id = other.id;
	
	name = new char[strlen(other.name) + 1] {};
	strcpy(name, other.name);

	description = new char[strlen(other.description) + 1] {};
	strcpy(description, other.description);

}

void CarPart::moveFrom(CarPart&& other)
{
	id = other.id;
	name = other.name;
	description = other.description;

	other.id = 0;
	other.name = nullptr;
	other.description = nullptr;
}

void CarPart::free()
{
	delete[] name;
	delete[] description;

	id = 0;
	name = nullptr;
	description = nullptr;
}

CarPart::CarPart(const CarPart& other)
{
	copyFrom(other);
}

CarPart& CarPart::operator=(const CarPart& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

CarPart::CarPart(CarPart&& other) noexcept
{
	moveFrom(std::move(other));
}

CarPart& CarPart::operator=(CarPart&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

CarPart::~CarPart()
{
	free();
}

CarPart::CarPart(const char* newName, const char* newDescription)
{
	idCounter++;
	id = idCounter;
	setName(newName);
	setDescription(newDescription);
}

void CarPart::setName(const char* newName)
{
	if (!newName)
	{
		throw std::invalid_argument("Nullptr detected!");
	}

	if (name == newName)
	{
		return;
	}

	delete[] name;

	name = new char[strlen(newName) + 1] {};
	strcpy(name, newName);
}

void CarPart::setDescription(const char* newDescription)
{
	if (!newDescription)
	{
		throw std::invalid_argument("Nullptr detected!");
	}

	if (description == newDescription)
	{
		return;
	}

	delete[] description;

	description = new char[strlen(newDescription) + 1] {};
	strcpy(description, newDescription);
}

const char* CarPart::getName() const
{
	return name;
}

const char* CarPart::getDescription() const
{
	return description;
}

std::ostream& operator<<(std::ostream& os, const CarPart& obj)
{
	return os << '(' << obj.id << ')' << " by " << obj.name << " - " << obj.description;
}
