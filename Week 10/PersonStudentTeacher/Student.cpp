#include "Student.h"

Student::Student(const char* newName, int newAge, size_t newFn):Person(newName, newAge)
{
}

void Student::setFn(size_t newFn)
{
	if (fn <= 100)
	{
		fn = 100;
		return;
	}

	fn = newFn;
}

size_t Student::getFn() const
{
	return fn;
}
