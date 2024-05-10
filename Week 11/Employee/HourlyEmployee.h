#pragma once
#include "Employee.h"

class HourlyEmployee : public Employee
{
	double overtime = 0;

public:

	HourlyEmployee(const char* name, double salary, double overtime);

	void setOvertime(double overtime);

	double getOvertime() const;

	double calculateSalary() const override;
};

