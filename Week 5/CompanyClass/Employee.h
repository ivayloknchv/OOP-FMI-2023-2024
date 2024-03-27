#pragma once
#include "Constants.h"
#include "ErrorList.h"
#include <cstring>
#pragma warning (disable : 4996)

class Employee
{
	double salary=0;
	char name[Constants::MAX_STR_LEN + 1]{};
	char position[Constants::MAX_STR_LEN + 1]{};
	unsigned id = 0;

public:

	Employee() = default;

	Employee(const char* name, const char* postion, double salary, unsigned id);

	void setName(const char* name);

	void setPosition(const char* position);

	void setSalary(double salary);

	void setId(unsigned id);

	double getSalary() const;

	unsigned getId() const;

	ErrorCode updateSalary(double amount);
};