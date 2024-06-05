#include "Worker.h"

Worker::Worker(const MyString& name, unsigned age, double salary, unsigned workingMonths) : Employee(name, age, salary),
_workingMonths(workingMonths)
{
}

Employee* Worker::clone() const
{
	return new Worker(*this);
}
