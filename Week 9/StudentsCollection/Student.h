#pragma once
#include "MyString.h"

class Student
{
	MyString name;
	int age;

public:

	Student() = delete;
	Student(const MyString& name, int age);

	const MyString& getName() const;
	int getAge() const;
};

