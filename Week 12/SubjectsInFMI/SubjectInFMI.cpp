#include "SubjectInFMI.h"
#include <cstring>
#include <utility>

#pragma warning (disable : 4996)

static void freeArrOfStrings(const char* const* arr, size_t size)
{
	if (!arr)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		delete[] arr[i];
	}

	delete[] arr;
}

char** allocateArrOfString(const char* const* arr, size_t size)
{
	if (!arr)
	{
		return nullptr;
	}

	char** toReturn = new char* [size];

	for (size_t i = 0; i < size; i++)
	{
		toReturn[i] = new char[strlen(arr[i]) + 1]{};
		strcpy(toReturn[i], arr[i]);
	}

	return toReturn;
}

void SubjectInFMI::copyFrom(const SubjectInFMI& other)
{
	_subject = other._subject;

	_lecturer = new char[strlen(other._lecturer) + 1]{};
	strcpy(_lecturer, other._lecturer);

	_assistants = allocateArrOfString(other._assistants, other._assistantsCount);
	_assistantsCount = other._assistantsCount;

	_pointsToPass = other._pointsToPass;
}

void SubjectInFMI::moveFrom(SubjectInFMI&& other)
{
	_subject = other._subject;
	_lecturer = other._lecturer;
	_assistants = other._assistants;
	_assistantsCount = other._assistantsCount;
	_pointsToPass = other._pointsToPass;

	other._subject = Subjects::UNKNOWN;
	other._lecturer = nullptr;
	other._assistants = nullptr;
	other._assistantsCount = 0;
	other._pointsToPass = 0;
}

void SubjectInFMI::free()
{
	_subject = Subjects::UNKNOWN;

	delete[] _lecturer;
	_lecturer = nullptr;

	freeArrOfStrings(_assistants, _assistantsCount);
	_assistants = nullptr;
	_assistantsCount = 0;

	_pointsToPass = 0;
}

void SubjectInFMI::setSubject(Subjects subject)
{
	if (subject == Subjects::UNKNOWN)
	{
		return;
	}

	_subject = subject;
}

void SubjectInFMI::setLecturer(const char* lecturer)
{
	if (!lecturer || _lecturer == lecturer)
	{
		return;
	}

	delete[] _lecturer;
	_lecturer = new char[strlen(lecturer) + 1]{};
	strcpy(_lecturer, lecturer);
}

void SubjectInFMI::setAssistants(const char* const* assistants, size_t assistantsCount)
{
	if (!assistants || _assistants == assistants)
	{
		return;
	}

	freeArrOfStrings(_assistants, _assistantsCount);
	_assistants = allocateArrOfString(assistants, assistantsCount);
	_assistantsCount = assistantsCount;
}

void SubjectInFMI::setPointsToPass(size_t pointsToPass)
{
	_pointsToPass = pointsToPass;
}

unsigned SubjectInFMI::getPoints() const
{
	return _pointsToPass;
}

unsigned SubjectInFMI::getSubjectIdx() const
{
	return (unsigned)_subject;
}

SubjectInFMI::SubjectInFMI(const SubjectInFMI& other)
{
	copyFrom(other);
}

SubjectInFMI& SubjectInFMI::operator=(const SubjectInFMI& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

SubjectInFMI::SubjectInFMI(SubjectInFMI&& other) noexcept
{
	moveFrom(std::move(other));
}

SubjectInFMI& SubjectInFMI::operator=(SubjectInFMI&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

SubjectInFMI::~SubjectInFMI()
{
	free();
}

SubjectInFMI::SubjectInFMI(Subjects subject, const char* lecturer, const char* const* assistants, size_t assistantsCount, size_t pointsToPass)
{
	setSubject(subject);
	setLecturer(lecturer);
	setAssistants(assistants, assistantsCount);
	setPointsToPass(pointsToPass);
}
