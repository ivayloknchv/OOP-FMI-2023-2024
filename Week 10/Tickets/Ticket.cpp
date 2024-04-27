#include "Ticket.h"
#include <cstring>
#include <utility>
#include <stdexcept>
#include <iostream>

#pragma warning (disable : 4996)

void Ticket::copyFrom(const Ticket& other)
{
	name = new char[strlen(other.name) + 1]{};
	strcpy(name, other.name);
	price = other.price;
}

void Ticket::moveFrom(Ticket&& other)
{
	name = other.name;
	other.name = nullptr;

	price = other.price;
	other.price = 0;
}

void Ticket::free()
{
	delete[] name;
	name = nullptr;

	price = 0;
}

Ticket::Ticket(const Ticket& other)
{
	copyFrom(other);
}

Ticket& Ticket::operator=(const Ticket& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Ticket::Ticket(Ticket&& other) noexcept
{
	moveFrom(std::move(other));
}

Ticket& Ticket::operator=(Ticket&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Ticket::~Ticket()
{
	free();
}

Ticket::Ticket(const char* newName, double newPrice)
{
	setName(newName);
	setPrice(newPrice);
}

void Ticket::setName(const char* newName)
{
	if (!newName)
	{
		throw std::invalid_argument("Nullptr");
	}

	if (name == newName)
	{
		return;
	}

	delete[] name;
	name = new char[strlen(newName)+1]{};
	strcpy(name, newName);
}

void Ticket::setPrice(double newPrice)
{
	price = newPrice;
}

const char* Ticket::getName() const
{
	return name;
}

double Ticket::getPrice() const
{
	return price;
}

void Ticket::printInfo() const
{
	std::cout << name << ' ' << price;
}
