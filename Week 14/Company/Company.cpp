#include "Company.h"
#include <utility>

void Company::copyFrom(const Company& other)
{
	_size = other._size;
	_capacity = other._capacity;

	_data = new Employee * [_capacity] {};

	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = other._data[i]->clone();
	}
}

void Company::moveFrom(Company&& other)
{
	_data = other._data;
	other._data = nullptr;

	_size = other._size;
	other._size = 0;

	_capacity = other._capacity;
	other._capacity = 0;
}

void Company::free()
{
	for (size_t i = 0; i < _size; i++)
	{
		delete _data[i];
	}

	delete[] _data;
	_data = nullptr;

	_capacity = _size = 0;
}

void Company::resize(size_t newCapacity)
{
	Employee** temp = new Employee * [newCapacity] {};

	for (size_t i = 0; i < _size; i++)
	{
		temp[i] = _data[i];
	}

	delete _data;
	_data = temp;
	_capacity = newCapacity;
}

void Company::add(Employee* obj)
{
	if (_size == _capacity)
	{
		resize(2 * _capacity);
	}

	size_t idx = _size;

	while (idx > 0 && _data[idx - 1]->getSalary() > obj->getSalary())
	{
		_data[idx] = _data[idx - 1];
		idx--;
	}

	_data[idx] = obj;
	_size++;

}

Company::Company()
{
	_capacity = INITIAL_CAPACITY;
	_data = new Employee * [_capacity] {};
}

Company::Company(const Company& other)
{
	copyFrom(other);
}

Company& Company::operator=(const Company& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Company::Company(Company&& other) noexcept
{
	moveFrom(std::move(other));
}

Company& Company::operator=(Company&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Company::~Company()
{
	free();
}

void Company::addWorker(const MyString& name, unsigned age, double salary, unsigned workingMonths)
{
	add(new Worker(name, age, salary, workingMonths));
}

void Company::addTrainee(const MyString& name, unsigned age, double salary, unsigned daysLeft)
{
	add(new Trainee(name, age, salary, daysLeft));
}

void Company::addPaidTrainee(const MyString& name, unsigned age, double salary, unsigned workingMonths, unsigned daysLeft, double rating)
{
	add(new PaidTrainee(name, age, salary, workingMonths, daysLeft, rating));
}

bool Company::twoSum(double val) const
{
	for (size_t i = 0; i < _size; i++)
	{
		for (size_t j = i + 1; j < _size; j++)
		{
			if ((_data[i]->getSalary() + _data[j]->getSalary()) - val <= EPSILON)
			{
				return true;
			}
		}
	}
	return false;
}

double Company::getAvgSalary() const
{
	double toReturn = 0;
	
	for (size_t i = 0; i < _size; i++)
	{
		toReturn += _data[i]->getSalary();
	}

	return toReturn/_size;
}
