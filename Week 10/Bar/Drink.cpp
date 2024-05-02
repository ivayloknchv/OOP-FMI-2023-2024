#include "Drink.h"
#include <cstring>
#include <utility> 
#pragma warning (disable : 4996)


static bool isCapital(char ch)
{
	return (ch >= 'A' && ch <= 'Z');
}

static bool isStringLowercase(const char* str)
{
	while (*str!='\0')
	{
		if (isCapital(*str))
		{
			return false;
		}

		str++;
	}

	return true;
}

void Drink::copyFrom(const Drink& other)
{
	name = new char[strlen(other.name) + 1]{};
	strcpy(name, other.name);
	ml = other.ml;
}

void Drink::moveFrom(Drink&& other)
{
	name = other.name;
	other.name = nullptr;
	ml = other.ml;
	other.ml = 0;
}

void Drink::free()
{
	delete[] name;
	name = nullptr;
	ml = 0;
}

Drink::Drink(const Drink& other)
{
	copyFrom(other);
}

Drink& Drink::operator=(const Drink& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return*this;
}

Drink::Drink(Drink&& other) noexcept
{
	moveFrom(std::move(other));
}

Drink& Drink::operator=(Drink&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Drink::~Drink()
{
	free();
}

Drink::Drink(const char* name, int ml)
{
	setName(name);
	this->ml = ml;
}

void Drink::setName(const char* name)
{
	if (!name || this->name == name)
	{
		return;
	}

	if (isCapital(*name) && isStringLowercase(name + 1))
	{
		this->name = new char[strlen(name) + 1]{};
		strcpy(this->name, name);
	}
}

void Drink::setMl(int ml)
{
	if (ml<MIN_ML || ml>MAX_ML)
	{
		ml = MIN_ML;
	}

	this->ml = ml;
}

const char* Drink::getName() const
{
	return name;
}

int Drink::getMl() const
{
	return ml;
}
