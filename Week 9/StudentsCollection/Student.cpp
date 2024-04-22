#include "Student.h"

Student::Student(const MyString& name, int age)
{
	this->name = name;
	this->age = age;
}

const MyString& Student::getName() const
{
	return name;
}

int Student::getAge() const
{
	return age;
}
