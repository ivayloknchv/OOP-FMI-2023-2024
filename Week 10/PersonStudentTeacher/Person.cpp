#include "Person.h"
#include <cstring>
#include <utility>
#include <iostream>

#pragma warning (disable : 4996)

void Person::copyFrom(const Person& other)
{
	name = new char[strlen(other.name) + 1]{};
	strcpy(name, other.name);
	age = other.age;
}

void Person::moveFrom(Person&& other)
{
	name = other.name;
	age = other.age;

	other.name = nullptr;
	other.age = 0;
}

void Person::free()
{
	delete[] name;
	name = nullptr;
	age = 0;
}

Person::Person(const Person& other)
{
	copyFrom(other);
}

Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return* this;
}

Person::Person(Person&& other) noexcept
{
	moveFrom(std::move(other));
}

Person& Person::operator=(Person&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Person::~Person()
{
	free();
}

Person::Person(const char* newName, int newAge)
{
	setName(newName);
	setAge(newAge);
}

const char* Person::getName() const
{
	return name;
}

int Person::getAge() const
{
	return age;
}

void Person::print() const
{
	std::cout << name << " " << age << std::endl;
}

void Person::setName(const char* newName)
{
	if (!newName || name == newName)
	{
		return;
	}

	delete[] name;
	name = new char[strlen(newName) + 1]{};
	strcpy(name, newName);
}

void Person::setAge(int newAge)
{
	age = newAge;
}
