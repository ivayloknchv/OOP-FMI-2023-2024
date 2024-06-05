#include "Trainee.h"

Trainee::Trainee(const MyString& name, unsigned age, double salary, unsigned daysLeft) : Employee(name, age, salary), 
_daysLeft(daysLeft)
{
}

Employee* Trainee::clone() const
{
	return new Trainee(*this);
}
