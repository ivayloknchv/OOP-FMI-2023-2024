#pragma once
#include "Person.h"

class Teacher : public Person
{
private:
	char** subjects = nullptr;
	size_t subjectsCount = 0;

	void copyFrom(const Teacher& other);
	void moveFrom(Teacher&& other);
	void free();

public:

	Teacher() = default;
	Teacher(const Teacher& other);
	Teacher& operator=(const Teacher& other);
	Teacher(Teacher&& other) noexcept;
	Teacher& operator=(Teacher&& other) noexcept;
	~Teacher();

	Teacher(const char* newName, int newAge, const char* const* newSubjects, size_t newSubjcetsCount);
};

