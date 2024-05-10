#include "HourlyEmployee.h"

HourlyEmployee::HourlyEmployee(const char* name, double salary, double overtime) : Employee(name, salary)
{
	setOvertime(overtime);
}

void HourlyEmployee::setOvertime(double overtime)
{
	this->overtime = overtime;
}

double HourlyEmployee::getOvertime() const
{
	return overtime;
}

double HourlyEmployee::calculateSalary() const
{
	return (40 * 4 * salary + salary * 0.5 * overtime);
}
