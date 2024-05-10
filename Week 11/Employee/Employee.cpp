#include "Employee.h"
#include <cstring>

#pragma warning (disable : 4996)

void Employee::copyFrom(const Employee& other)
{
	name = new char[strlen(other.name) + 1]{};
	strcpy(name, other.name);
	salary = other.salary;
}

void Employee::moveFrom(Employee&& other)
{
	name = other.name;
	other.name = nullptr;
	salary = other.salary;
	other.salary = 0;
}

void Employee::free()
{
	delete[] name;
	name = nullptr;
	salary = 0;
}

Employee::Employee(const Employee& other)
{
	copyFrom(other);
}

Employee& Employee::operator=(const Employee& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Employee::Employee(Employee&& other) noexcept
{
	moveFrom(std::move(other));
}

Employee& Employee::operator=(Employee&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Employee::~Employee()
{
	free();
}

Employee::Employee(const char* name, double salary)
{
	setName(name);
	setSalary(salary);
}

void Employee::setName(const char* name)
{
	if (!name || this->name == name)
	{
		return;
	}

	delete[] this->name;
	this->name = new char[strlen(name) + 1]{};
	strcpy(this->name, name);
}

void Employee::setSalary(double salary)
{
	if (salary <= 1000)
	{
		salary = 1000;
	}

	this->salary = salary;
}

const char* Employee::getName() const
{
	return name;
}

double Employee::getSalary() const
{
	return salary;
}

std::ostream& operator<<(std::ostream& os, const Employee& obj)
{
	return os << obj.getName() << ' ' << obj.getSalary() << std::endl;
}
