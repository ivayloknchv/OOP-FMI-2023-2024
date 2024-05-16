#pragma once
#include "SubjectInFMI.h"
#include "DIS.h"
#include "DSTR2.h"
#include "Geometry.h"
#include "OOP.h"
#include "UP.h"

class SubjectsContainer
{
private:

	static constexpr unsigned SUBJECTS_COUNT = 5;
	SubjectInFMI** _data = nullptr;
	size_t _size = 0;
	size_t _capacity = 0;
	int _subjectsCounter[SUBJECTS_COUNT]{};

	void copyFrom(const SubjectsContainer& other);
	void moveFrom(SubjectsContainer&& other);
	void free();

	void resize(size_t newCapacity);

	void add(SubjectInFMI* subject);

public:

	SubjectsContainer();
	SubjectsContainer(const SubjectsContainer& other);
	SubjectsContainer& operator=(const SubjectsContainer& other);
	SubjectsContainer(SubjectsContainer&& other) noexcept;
	SubjectsContainer& operator=(SubjectsContainer&& other) noexcept;
	~SubjectsContainer() noexcept;

	void addDIS(const char* lecturer, const char* const* assistants, size_t assistantsCount, size_t pointsToPass);
	void addOOP(const char* lecturer, const char* const* assistants, size_t assistantsCount, size_t pointsToPass, size_t bonusPoints);
	void addDSTR2(const char* lecturer, const char* const* assistants, size_t assistantsCount, size_t pointsToPass);
	void addUP(const char* lecturer, const char* const* assistants, size_t assistantsCount, size_t pointsToPass);
	void addGeometry(const char* lecturer, const char* const* assistants, size_t assistantsCount, size_t pointsToPass);

	size_t getSize() const;
	Subjects getMostFreqSubject() const;
};

