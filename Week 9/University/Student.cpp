#include "Student.h"
#include <cstring>
#include <iostream>
#pragma warning (disable : 4996)

void Student::copyFrom(const Student& other)
{
	name = new char[strlen(other.name) + 1]{};
	strcpy(name, other.name);
	fn = other.fn;
	group = other.group;
	avgGrade = other.avgGrade;
}

void Student::moveFrom(Student&& other)
{
	name = other.name;
	fn = other.fn;
	group = other.group;
	avgGrade = other.avgGrade;

	other.name = nullptr;
	other.fn = 0;
	other.group = 0;
	other.avgGrade = 0;
}

void Student::free()
{
	delete[] name;
	name = nullptr;

	fn = 0;
	group = 0;
	avgGrade = 0;
}

Student::Student(const Student& other)
{
	copyFrom(other);
}

Student& Student::operator=(const Student& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Student::Student(Student&& other) noexcept
{
	moveFrom(std::move(other));
}

Student& Student::operator=(Student&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Student::~Student() noexcept
{
	free();
}

Student::Student(const char* name, int fn, int group, double avgGrade)
{
	setName(name);
	setFn(fn);
	setGroup(group);
	setAvgGrade(avgGrade);
}

void Student::setName(const char* name)
{
	if (!name || this->name == name)
	{
		return;
	}

	delete[] this->name;

	this->name = new char[strlen(name) + 1]{};
	strcpy(this->name, name);
}

void Student::setFn(int fn)
{
	if (fn < 100)
	{
		fn = 100;
	}

	this->fn = fn;
}

void Student::setGroup(int group)
{
	this->group = group;
}

void Student::setAvgGrade(double avgGrade)
{
	if (avgGrade <= 2.00 || avgGrade >= 6.00)
	{
		avgGrade = 2.00;
	}

	this->avgGrade = avgGrade;
}

const char* Student::getName() const
{
	return name;
}

int Student::getFn() const
{
	return fn;
}

int Student::getGroup() const
{
	return group;
}

double Student::getAvgGrade() const
{
	return avgGrade;
}

std::ostream& operator<<(std::ostream& os, const Student& obj)
{
	return os<<obj.name<<", "<<obj.fn<<", "<<obj.group<<", "<<obj.avgGrade<<std::endl;
}

std::istream& operator>>(std::istream& is, Student& obj)
{
	char buff[1024]{};
	int fn = 0;
	int group = 0;
	double avg = 0;

	is.getline(buff, 1024, ',');

	is >> fn;
	is.ignore();
	is >> group;
	is.ignore();
	is >> avg;

	obj.setName(buff);
	obj.setFn(fn);
	obj.setGroup(group);
	obj.setAvgGrade(avg);

	return is;
}

bool operator<(const Student& lhs, const Student& rhs)
{
	if (lhs.avgGrade == rhs.avgGrade)
	{
		return (lhs.fn < rhs.fn);
	}
	
	return lhs.avgGrade < rhs.avgGrade;
}

bool operator==(const Student& lhs, const Student& rhs)
{
	return (strcmp(lhs.name,rhs.name)==0 && lhs.fn == rhs.fn && lhs.group==rhs.group && lhs.avgGrade==rhs.avgGrade);
}
