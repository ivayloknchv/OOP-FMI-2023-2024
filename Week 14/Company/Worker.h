#pragma once
#include "Employee.h"

class Worker : virtual public Employee
{
private:
	unsigned _workingMonths;

public:

	Worker(const MyString& name, unsigned age, double salary, unsigned workingMonths);

	Employee* clone() const override;
};

