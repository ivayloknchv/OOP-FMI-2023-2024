#include "Teacher.h"
#include <cstring>
#include <utility>

#pragma warning (disable : 4996)

static void freeStringArray(const char* const* arr, size_t count)
{
	for (size_t i = 0; i < count; i++)
	{
		delete[] arr[i];
	}

	delete[] arr;
}

static char** allocateStringArray(const char* const* arr, size_t count)
{
	char** toReturn = new char* [count] {};

	for (size_t i = 0; i < count; i++)
	{
		toReturn[i] = new char[strlen(arr[i]) + 1]{};
		strcpy(toReturn[i], arr[i]);
	}

	return toReturn;
}

void Teacher::copyFrom(const Teacher& other)
{
	subjectsCount = other.subjectsCount;
	subjects=allocateStringArray(other.subjects, other.subjectsCount);
}

void Teacher::moveFrom(Teacher&& other)
{
	subjects = other.subjects;
	subjectsCount = other.subjectsCount;

	other.subjects = nullptr;
	other.subjectsCount = 0;
}

void Teacher::free()
{
	freeStringArray(subjects, subjectsCount);
	subjects = nullptr;
	subjectsCount = 0;
}

Teacher::Teacher(const Teacher& other) : Person(other)
{
	copyFrom(other);
}

Teacher& Teacher::operator=(const Teacher& other)
{
	if (this != &other)
	{
		Person::operator=(other);
		free();
		copyFrom(other);
	}

	return* this;
}

Teacher::Teacher(Teacher&& other)  noexcept : Person(std::move(other))
{
	moveFrom(std::move(other));
}

Teacher& Teacher::operator=(Teacher&& other)  noexcept
{
	if (this != &other)
	{
		Person::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}

	return*this;
}

Teacher::~Teacher()
{
	free();
}

Teacher::Teacher(const char* newName, int newAge, const char* const* newSubjects, size_t newSubjcetsCount) : Person(newName,newAge)
{
	subjects = allocateStringArray(newSubjects, newSubjcetsCount);
	subjectsCount = newSubjcetsCount;
}
