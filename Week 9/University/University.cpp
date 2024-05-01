#include "University.h"
#include <stdexcept>

void University::copyFrom(const University& other)
{
	size = other.size;
	capacity = other.capacity;
	students = new Student * [capacity] {nullptr};

	for (int i = 0; i < size; i++)
	{
		if (other.students[i] == nullptr)
		{
			students[i] = nullptr;
		}

		else
		{
			students[i] = new Student(*other.students[i]);
		}
	}
}

void University::moveFrom(University&& other)
{
	students = other.students;
	size = other.size;
	capacity = other.capacity;

	other.students = nullptr;
	other.size = 0;
	other.capacity = 0;
}

void University::free()
{
	for (int i = 0; i < size; i++)
	{
		delete students[i];
	}
	delete[] students;
	
	students = nullptr;
	size = 0;
	capacity = 0;
}

int University::getStudentByFn(int fn)
{
	for (int i = 0; i < size; i++)
	{
		if (students[i]->getFn() == fn)
		{
			return i;
		}
	}

	return -1;
}

void University::resize(int newCapacity)
{
	Student** temp = new Student * [newCapacity] {};

	for (int i = 0; i < size; i++)
	{
		temp[i] = students[i];
	}

	delete[] students;
	students = temp;
	temp = nullptr;
	capacity = newCapacity;
}

University::University()
{
	capacity = 8;
	students = new Student * [capacity] {};
}

University::University(const University& other)
{
	copyFrom(other);
}

University& University::operator=(const University& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

University::University(University&& other) noexcept
{
	moveFrom(std::move(other));
}

University& University::operator=(University&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

University::~University() noexcept
{
	free();
}

void University::sort(bool(*pred)(const Student& lhs, const Student& rhs))
{
	int min_idx = 0;

	for (int i = 0; i < size-1; i++)
	{
		min_idx = i;

		for (int j = i + 1; j < size; j++)
		{
			if (pred(*students[min_idx], *students[j]))
			{
				min_idx = j;
			}
		}

		if (min_idx != i)
		{
			std::swap(students[i], students[min_idx]);
		}
	}
}

void University::filter(bool(*pred)(const Student& obj)) const
{
	for (int i = 0; i < size; i++)
	{
		if (pred(*students[i]))
		{
			std::cout << *students[i];
		}
	}
}

University& University::operator+=(const Student& st)
{
	if(size==capacity)
	{
		resize(2 * capacity);
	}

	students[size] = new Student(st);

	size++;
	return *this;
}

University& University::operator-=(int fn)
{
	int idx = getStudentByFn(fn);

	if (idx == -1)
	{
		throw std::invalid_argument("No student with such FN exists!");
	}

	std::swap(students[idx], students[size - 1]);
	
	delete students[size - 1];

	students[size - 1] = nullptr;
	size--;

	if (size == capacity / 4 && capacity / 2 > 8)
	{
		resize(capacity / 2);
	}

	return *this;
}

Student& University::operator[](int idx)
{
	if (idx<0 || idx>size)
	{
		throw std::invalid_argument("Invalid index!");
	}

	return *students[idx];
}

const Student& University::operator[](int idx) const
{
	if (idx<0 || idx>size)
	{
		throw std::invalid_argument("Invalid index!");
	}

	return *students[idx];
}

std::ostream& operator<<(std::ostream& os, const University& obj)
{
	for (int i = 0; i < obj.size; i++)
	{
		os << *obj.students[i];
	}
	return os;
}

std::istream& operator>>(std::istream& is, University& obj)
{
	University temp;

	while (true)
	{
		Student st;

		is >> st;

		if (is.eof())
		{
			break;
		}

		temp += st;
	}

	obj = temp;

	return is;
}
