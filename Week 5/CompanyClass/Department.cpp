#include "Department.h"
#include <cstring>

#pragma warning (disable : 4996)

bool Department::isValidId(unsigned id) const
{
	for (unsigned i = 0; i < countOfEmployees; i++)
	{
		if (employees[i].getId() == id)
		{
			return true;
		}
	}
	return false;
}

void Department::removeAt(int id)
{
	for (unsigned i = 0; i < countOfEmployees - 1; i++)
	{
		if (employees[i].getId() == id)
		{
			swap(employees[i], employees[countOfEmployees-1]);
			countOfEmployees--;
			return;
		}
	}
}

void Department::swap(Employee& lhs, Employee& rhs)
{
	Employee temp = lhs;
	lhs = rhs;
	rhs = temp;
}

Department::Department(const char* name, const Employee* employees, unsigned countOfEmployees)
{
	setName(name);
	setEmployees(employees, countOfEmployees);
}

void Department::setName(const char* name)
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

void Department::setEmployees(const Employee* employees, unsigned countOfEmployees)
{
	if (!employees)
	{
		return;
	}

	if (countOfEmployees<1 || countOfEmployees>Constants::MAX_EMPLOYEES)
	{
		return;
	}

	for (unsigned i = 0; i < countOfEmployees; i++)
	{
		this->employees[i] = employees[i];
	}
	this->countOfEmployees = countOfEmployees;
}

const char* Department::getDepartmentName() const
{
	return name;
}

ErrorCode Department::addEmployee(const Employee& employee)
{
	if (countOfEmployees == Constants::MAX_EMPLOYEES)
	{
		return ErrorCode::FullCapacity;
	}

	employees[countOfEmployees++] = employee;

	return ErrorCode::OK;
}

ErrorCode Department::removeEmployee(unsigned id)
{
	if (!isValidId(id))
	{
		return ErrorCode::NotFound;
	}
	
	removeAt(id);

	return ErrorCode::OK;
}
