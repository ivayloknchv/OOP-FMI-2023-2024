#include "CommisionEmployee.h"

CommisionEmployee::CommisionEmployee(const char* name, double salary, double commision) : Employee(name, salary)
{
	setCommision(commision);
}

void CommisionEmployee::setCommision(double commision)
{
	this->commision = commision;
}

double CommisionEmployee::getCommision() const
{
	return commision;
}

double CommisionEmployee::calculateSalary() const
{
	return salary + salary * commision;
}
