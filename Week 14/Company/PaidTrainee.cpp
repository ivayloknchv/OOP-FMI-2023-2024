#include "PaidTrainee.h"

PaidTrainee::PaidTrainee(const MyString& name, unsigned age, double salary, unsigned workingMonths, unsigned daysLeft, double rating)
	: Employee(name, age, salary), Worker(name,age, salary, workingMonths), Trainee(name, age, salary, daysLeft), _rating(rating)
{
}

Employee* PaidTrainee::clone() const
{
	return new PaidTrainee(*this);
}
