#include "Employee.h"

Employee::Employee(const char* name, const char* postion, double salary, unsigned id)
{
	setName(name);
	setPosition(position);
	setSalary(salary);
	setId(id);
}

void Employee::setName(const char* name)
{
	if (!name)
	{
		strcpy(this->name, "Unknown");
		return;
	}

	if (strlen(name) < 1 || strlen(name) > Constants::MAX_STR_LEN)
	{
		strcpy(this->name, "Unknown");
		return;
	}

	strcpy(this->name, name);
}

void Employee::setPosition(const char* position)
{
	if (!position)
	{
		strcpy(this->position, "Unknown");
		return;
	}

	if (strlen(position) < 1 || strlen(position) > Constants::MAX_STR_LEN)
	{
		strcpy(this->position, "Unknown");
		return;
	}

	strcpy(this->position, position);
}

void Employee::setSalary(double salary)
{
	if (salary < 1000)
	{
		this->salary = 1000;
		return;
	}
	this->salary = salary;
}

void Employee::setId(unsigned id)
{
	this->id = id;
}

double Employee::getSalary() const
{
	return salary;
}

unsigned Employee::getId() const
{
	return id;
}

ErrorCode Employee::updateSalary(double amount)
{
	if (amount + salary < 1000)
	{
		this->salary = 1000;
		return ErrorCode::InvalidInput;
	}
	salary += amount;

	return ErrorCode::OK;
}
