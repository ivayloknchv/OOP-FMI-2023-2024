#include "StudentCollection.h"
#include <exception>
void StudentCollection::copyFrom(const StudentCollection& other)
{
	capacity = other.capacity;
	size = other.size;

	data = new Student * [capacity] {};

	for (int i = 0; i < capacity; i++)
	{
		if (other.data[i] == nullptr)
		{
			data[i] = nullptr;
		}

		else
		{
			data[i] = new Student(*other.data[i]);
		}
	}
}

void StudentCollection::moveFrom(StudentCollection&& other)
{
	size = other.size;
	capacity = other.capacity;
	data = other.data;

	other.data = nullptr;
	other.size = other.capacity = 0;
}

void StudentCollection::free()
{
	for (int i = 0; i < capacity; i++)
	{
		delete data[i];
	}

	delete[] data;
	data = nullptr;
	size = 0;
	capacity = 0;
}

void StudentCollection::resize(int newCapacity)
{
	Student** temp = new Student * [newCapacity] {};


	for (int i = 0; i < capacity; i++)
	{
		temp[i] = data[i];
	}

	delete[] data;
	data = temp;
	temp = nullptr;
	capacity = newCapacity;
}

int StudentCollection::getFirstFreeIndex() const
{
	for (int i = 0; i < capacity; i++)
	{
		if (data[i] == nullptr)
		{
			return i;
		}
	}

	return capacity;
}

StudentCollection::StudentCollection()
{
	capacity = 8;
	data = new Student * [capacity] {};
}

StudentCollection::StudentCollection(const StudentCollection& other)
{
	copyFrom(other);
}

StudentCollection& StudentCollection::operator=(const StudentCollection& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

StudentCollection::StudentCollection(StudentCollection&& other) noexcept
{
	moveFrom(std::move(other));
}

StudentCollection& StudentCollection::operator=(StudentCollection&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

StudentCollection::~StudentCollection()
{
	free();
}

void StudentCollection::push(const Student& obj)
{
	int idx = getFirstFreeIndex();

	if (idx == capacity)
	{
		resize(capacity + capacity / 2);
	}

	data[idx] =new Student(obj);
	size++;
}

void StudentCollection::push(Student&& obj)
{
	int idx = getFirstFreeIndex();

	if (idx == capacity)
	{
		resize(capacity + capacity / 2);
	}

	data[idx] = new Student(std::move(obj));
	size++;
}

void StudentCollection::pushAt(int idx,const Student& obj)
{
	if (idx >= capacity)
	{
		throw std::out_of_range("StudentCollection::pushAt index out of range");
	}

	if (data[idx] == nullptr)
	{
		data[idx] = new Student(obj);
		size++;
	}

	else
	{
		*data[idx] = obj;
	}
}

void StudentCollection::pushAt(int idx, Student&& obj)
{
	if (idx >= capacity)
	{
		throw std::out_of_range("StudentCollection::pushAt index out of range");
	}

	if (data[idx] == nullptr)
	{
		data[idx] = new Student(std::move(obj));
		size++;
	}

	else
	{
		*data[idx] = std::move(obj);
	}
}

void StudentCollection::removeAt(int idx)
{
	if (idx >= capacity)
	{
		throw std::out_of_range("StudentCollection::removeAt index out of range");
	}

	if (data[idx] == nullptr)
	{
		throw std::invalid_argument("StudentCollection::removeAt object doesn't exist!");
	}

	else
	{
		delete data[idx];
		size--;
		data[idx] = nullptr;
	}
}

const Student& StudentCollection::getAt(int idx) const
{
	if (idx >= capacity)
	{
		throw std::out_of_range("StudentCollection::getAt index out of range");
	}

	if (data[idx] == nullptr)
	{
		throw std::invalid_argument("StudentCollection::getAt object doesn't exist!");
	}

	return *data[idx];
}

int StudentCollection::getNumberInClass(const Student& obj) const
{
	for (int i = 0; i < capacity; i++)
	{
		if (data[i] != nullptr && data[i]->getName() == obj.getName())
		{
			return i+1;
		}
	}

	throw std::invalid_argument("StudentCollection::getNumberInClass student doesn't exist!");
}

int StudentCollection::getNumberInClass(const MyString& name) const
{
	for (int i = 0; i < capacity; i++)
	{
		if (data[i] != nullptr && data[i]->getName() == name)
		{
			return i+1;
		}
	}

	throw std::invalid_argument("StudentCollection::getNumberInClass student doesn't exist!");
}

bool StudentCollection::containsAt(int idx) const
{
	if (idx >= capacity)
	{
		throw std::out_of_range("StudentCollection::containsAt index out of range");
	}

	return (data[idx] != nullptr);
}

