#include "DynamicPointersArray.h"
#include <iostream>

void DynamicPointersArray::copyFrom(const DynamicPointersArray& other)
{
	count = other.count;
	capacity = other.capacity;

	data = new Point*[capacity]{};

	for (size_t i = 0; i < capacity; i++)
	{
		if (!other.data[i])
		{
			data[i] = nullptr;
		}

		else
		{
			data[i] = new Point(*other.data[i]);
		}
	}
}

void DynamicPointersArray::moveFrom(DynamicPointersArray&& other)
{
	count = other.count;
	capacity = other.capacity;
	data = other.data;

	other.data = nullptr;
	other.count = 0;
	other.capacity = 0;
}

void DynamicPointersArray::free()
{
	for (size_t i = 0; i < capacity; i++)
	{
		delete data[i];
	}

	delete[] data;
	data = nullptr;
}

void DynamicPointersArray::resize(size_t newCapacity)
{
	capacity = newCapacity;

	Point** temp = new Point * [capacity] {};

	for (size_t i = 0; i < capacity; i++)
	{
		temp[i] = data[i];
	}

	delete[] data;
	data = temp;
}

size_t DynamicPointersArray::getFirstFreeIndex() const
{
	for (size_t i = 0; i < capacity; i++)
	{
		if (data[i] == nullptr)
		{
			return i;
		}
	}

	return -1;
}

DynamicPointersArray::DynamicPointersArray()
{
	capacity = 8;
	data = new Point * [capacity] {nullptr};
}

DynamicPointersArray::DynamicPointersArray(const DynamicPointersArray& other)
{
	copyFrom(other);
}

DynamicPointersArray::DynamicPointersArray(DynamicPointersArray&& other) noexcept
{
	moveFrom(std::move(other));
}

DynamicPointersArray& DynamicPointersArray::operator=(const DynamicPointersArray& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

DynamicPointersArray& DynamicPointersArray::operator=(DynamicPointersArray&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

DynamicPointersArray::~DynamicPointersArray()
{
	free();
}

void DynamicPointersArray::addAtFirstFreeIndex(const Point& other)
{
	if (count == capacity)
	{
		resize(2 * capacity);
	}

	size_t idx = getFirstFreeIndex();

	data[idx] = new Point(other);
	count++;
}

void DynamicPointersArray::addAtFirstFreeIndex(Point&& other)
{
	if (count == capacity)
	{
		resize(2 * capacity);
	}

	size_t idx = getFirstFreeIndex();

	data[idx] = new Point(std::move(other));
	count++;
}

bool DynamicPointersArray::ContainstAt(size_t idx) const
{
	return idx < capacity&& data[idx] != nullptr;
}

void DynamicPointersArray::popBack()
{
	if (count == 0)
	{
		return;
	}

	delete data[count -1];
	data[count - 1] = nullptr;
	count--;

	if (count == capacity / 4 && capacity / 2 > 8)
	{
		resize(capacity / 2);
	}
}

void DynamicPointersArray::removeAt(size_t idx)
{
	if (idx >= count)
	{
		return;
	}

	delete data[idx];
	data[idx] = nullptr;

	count--;

	if (count == capacity / 4 && capacity / 2 > 8)
	{
		resize(capacity / 2);
	}
}

void DynamicPointersArray::setAtIndex(size_t idx, const Point& obj)
{
	if (idx >= capacity)
	{
		resize(2 * capacity);
	}

	if (data[idx] != nullptr)
	{
		*data[idx] = obj;
	}
	else
	{
		data[idx] = new Point(obj);
		count++;
	}

}

void DynamicPointersArray::setAtIndex(size_t idx, Point&& obj)
{
	if (idx >= capacity)
	{
		resize(2 * capacity);
	}

	if (data[idx] != nullptr)
	{
		*data[idx] =obj;
	}
	else
	{
		data[idx] = new Point(std::move(obj));
		count++;
	}
}

size_t DynamicPointersArray::getSize() const
{
	return count;
}

const Point& DynamicPointersArray::operator[](size_t idx) const
{
	return *data[idx];
}

Point& DynamicPointersArray::operator[](size_t idx)
{
	return *data[idx];
}
