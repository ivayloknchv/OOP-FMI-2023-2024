#pragma once
#include "Employee.h"

class CommisionEmployee : public Employee
{
	double commision = 0;

public:

	CommisionEmployee(const char* name, double salary, double commision);

	void setCommision(double commision);

	double getCommision() const;

	double calculateSalary() const override;
};


