#pragma once
#include "Person.h"

class Student : public Person
{
private:

	size_t fn = 0;

public:

	Student() = default;
	Student(const char* newName, int newAge, size_t newFn);

	void setFn(size_t newFn);
	size_t getFn() const;
};

