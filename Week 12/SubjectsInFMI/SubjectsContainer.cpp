#include "SubjectsContainer.h"
#include <utility>

static size_t getIndexOfMaxElement(const int* arr, size_t size)
{
	size_t max = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] > arr[max])
		{
			max = i;
		}
	}

	return max;
}

void SubjectsContainer::copyFrom(const SubjectsContainer& other)
{
	_size = other._size;
	_capacity = other._capacity;

	_data = new SubjectInFMI*[_capacity]{};

	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = other._data[i]->clone();
	}

	for (size_t i = 0; i < SUBJECTS_COUNT; i++)
	{
		_subjectsCounter[i] = other._subjectsCounter[i];
	}
}

void SubjectsContainer::moveFrom(SubjectsContainer&& other)
{
	_data = other._data;
	other._data = nullptr;

	_size = other._size;
	other._size = 0;

	_capacity = other._capacity;
	other._capacity = 0;

	for (size_t i = 0; i < SUBJECTS_COUNT; i++)
	{
		_subjectsCounter[i] = other._subjectsCounter[i];
		other._subjectsCounter[i] = 0;
	}

}

void SubjectsContainer::free()
{
	for (size_t i = 0; i < _size; i++)
	{
		delete _data[i];
	}

	delete[] _data;
}

void SubjectsContainer::resize(size_t newCapacity)
{
	SubjectInFMI** temp = new SubjectInFMI * [newCapacity] {};

	for (unsigned i = 0; i < _size; i++)
	{
		temp[i] = _data[i];
	}

	delete[] _data;
	_data = temp;
	temp = nullptr;
	_capacity = newCapacity;
}

void SubjectsContainer::add(SubjectInFMI* subject)
{
	if (_size == _capacity)
	{
		resize(2 * _capacity);
	}

	_subjectsCounter[subject->getSubjectIdx()]++;
	_data[_size++] = subject;
}

SubjectsContainer::SubjectsContainer()
{
	_capacity = 8;
	_data = new SubjectInFMI*[_capacity]{};
}

SubjectsContainer::SubjectsContainer(const SubjectsContainer& other)
{
	copyFrom(other);
}

SubjectsContainer& SubjectsContainer::operator=(const SubjectsContainer& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

SubjectsContainer::SubjectsContainer(SubjectsContainer&& other) noexcept
{
	moveFrom(std::move(other));
}

SubjectsContainer& SubjectsContainer::operator=(SubjectsContainer&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

SubjectsContainer::~SubjectsContainer() noexcept
{
	free();

}

void SubjectsContainer::addDIS(const char* lecturer, const char* const* assistants, size_t assistantsCount, size_t pointsToPass)
{
	SubjectInFMI* obj = new DIS(lecturer, assistants, assistantsCount, pointsToPass);

	add(obj);
}

void SubjectsContainer::addOOP(const char* lecturer, const char* const* assistants, size_t assistantsCount, size_t pointsToPass, size_t bonusPoints)
{
	SubjectInFMI* obj = new OOP(lecturer, assistants, assistantsCount, pointsToPass, bonusPoints);

	add(obj);
}

void SubjectsContainer::addDSTR2(const char* lecturer, const char* const* assistants, size_t assistantsCount, size_t pointsToPass)
{
	SubjectInFMI* obj = new DSTR2(lecturer, assistants, assistantsCount, pointsToPass);

	add(obj);
}

void SubjectsContainer::addUP(const char* lecturer, const char* const* assistants, size_t assistantsCount, size_t pointsToPass)
{
	SubjectInFMI* obj = new UP(lecturer, assistants, assistantsCount, pointsToPass);

	add(obj);
}

void SubjectsContainer::addGeometry(const char* lecturer, const char* const* assistants, size_t assistantsCount, size_t pointsToPass)
{
	SubjectInFMI* obj = new Geometry(lecturer, assistants, assistantsCount, pointsToPass);

	add(obj);
}

size_t SubjectsContainer::getSize() const
{
	return _size;
}

Subjects SubjectsContainer::getMostFreqSubject() const
{
	int toReturn = getIndexOfMaxElement(_subjectsCounter, SUBJECTS_COUNT);
	return (Subjects)toReturn;
}
