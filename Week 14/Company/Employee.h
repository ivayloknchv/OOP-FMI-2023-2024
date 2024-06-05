#pragma once
#include "MyString.h"

class Employee
{
private:
	MyString _name;
	unsigned _age;
	double _salary;

public:

	Employee(const MyString& name, unsigned age, double salary);

	virtual Employee* clone() const = 0;

	double getSalary() const;

	virtual ~Employee() = default;
};

