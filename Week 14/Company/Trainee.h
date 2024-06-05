#pragma once
#include "Employee.h"

class Trainee : virtual public Employee
{
	unsigned _daysLeft;

public:
	Trainee(const MyString& name, unsigned age, double salary, unsigned daysLeft);

	Employee* clone() const override;
};

