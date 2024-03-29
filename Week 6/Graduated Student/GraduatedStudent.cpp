#include "GraduatedStudent.h"
#include <cstring>

#pragma warning (disable : 4996)

void GraduatedStudent::copyFrom(const GraduatedStudent& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	grades = new int[other.gradesCount];
	
	for (int i = 0; i < other.gradesCount; i++)
	{
		grades[i] = other.grades[i];
	}

	gradesCount = other.getGradesCount();

	strcpy(quote, other.quote);
}

void GraduatedStudent::free()
{
	delete[] name;
	delete[] grades;

	name = nullptr;
	grades = nullptr;
	gradesCount = 0;
	strcpy(quote, "");
}

GraduatedStudent::GraduatedStudent(const char* newName, const int* newGrades, int newGradesCount, const char* newQuote)
{
	setName(newName);
	setGrades(newGrades, newGradesCount);
	setQuote(newQuote);
}

GraduatedStudent::GraduatedStudent(const GraduatedStudent& other)
{
	copyFrom(other);
}

GraduatedStudent& GraduatedStudent::operator=(const GraduatedStudent& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

void GraduatedStudent::setName(const char* newName)
{
	if (!newName)
	{
		return;
	}

	delete[] name;

	name = new char[strlen(newName) + 1];

	strcpy(name, newName);
}

void GraduatedStudent::setGrades(const int* newGrades, int newGradesCount)
{
	if (!newGrades)
	{
		return;
	}

	delete[] grades;

	grades = new int[newGradesCount];

	for (int i = 0; i < newGradesCount; i++)
	{
		grades[i] = newGrades[i];
	}

	gradesCount = newGradesCount;
}

void GraduatedStudent::setQuote(const char* newQuote)
{
	if (!newQuote)
	{
		return;
	}

	if (strlen(newQuote) > 30)
	{
		return;
	}

	strcpy(quote, newQuote);
}

const char* GraduatedStudent::getName() const
{
	return name;
}

const int* GraduatedStudent::getGrades() const
{
	return grades;
}

const int GraduatedStudent::getGradesCount() const
{
	return gradesCount;
}

const char* GraduatedStudent::getQuote() const
{
	return quote;
}

GraduatedStudent::~GraduatedStudent()
{
	free();
}
