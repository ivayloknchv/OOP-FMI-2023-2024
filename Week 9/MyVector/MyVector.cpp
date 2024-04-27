#include "MyVector.h"
#include <stdexcept>

void MyVector::copyFrom(const MyVector& other)
{
	size = other.size;
	capacity = other.capacity;
	data = new int[capacity] {};

	for (int i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

void MyVector::moveFrom(MyVector&& other)
{
	data = other.data;
	size = other.size;
	capacity = other.capacity;

	other.data = nullptr;
	other.size = 0;
	other.capacity = 0;
}

void MyVector::free()
{
	delete[] data;
	data = nullptr;
	size = 0;
	capacity = 0;
}

void MyVector::resizeHelper(int newCapacity, int defVal=0)
{
	int* temp = new int[newCapacity] {};

	for (int i = 0; i < size; i++)
	{
		temp[i] = data[i];
	}

	delete[] data;
	data = temp;
	temp = nullptr;
	capacity = newCapacity;

	if (defVal != 0)
	{
		fillDefaultValues(defVal);
	}
}

void MyVector::fillDefaultValues(int defVal)
{
	for (int i = size; i < capacity; i++)
	{
		data[i] = defVal;
	}
}

void MyVector::rearrange(const int* arr, int arrSize, int idx)
{
	int newSize = this->size+ arrSize;
	int newCap = 2 * newSize;
	int *temp = new int[newCap] {};

	int counter = 0;

	for (counter; counter<idx; counter++)
	{
		temp[counter] = data[counter];
	}

	for (int i = 0; i < arrSize; i++)
	{
		temp[counter++] = arr[i];
	}

	for (int i = idx; i < size; i++)
	{
		temp[counter++] = data[i];
	}

	size = newSize;
	capacity = newCap;

	delete[] data;
	data = temp;
	temp = nullptr;
}

MyVector::MyVector()
{
	capacity = 8;
	data = new int[capacity] {};
}

MyVector::MyVector(const MyVector& other)
{
	copyFrom(other);
}

MyVector& MyVector::operator=(const MyVector& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

MyVector::MyVector(MyVector&& other) noexcept
{
	moveFrom(std::move(other));
}

MyVector& MyVector::operator=(MyVector&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

MyVector::~MyVector() noexcept
{
	free();
}

bool MyVector::isEmpty() const
{
	return (size == 0);
}

void MyVector::pushBack(int element)
{
	if (size == capacity)
	{
		resizeHelper(2 * capacity);
	}

	data[size++] = element;
}

void MyVector::popBack()
{
	if (isEmpty())
	{
		throw std::logic_error("Your vector object is empty");
	}

	--size;
	data[size] = 0;
}

int MyVector::at(int idx) const
{
	if (idx >= size)
	{
		throw std::out_of_range("Index out of range!");
	}

	return data[idx];
}

int& MyVector::at(int idx)
{
	if (idx >= size)
	{
		throw std::out_of_range("Index out of range!");
	}

	return data[idx];
}

int& MyVector::front() const
{
	if (isEmpty())
	{
		throw std::logic_error("Your vector object is empty!");
	}

	return data[0];
}

int& MyVector::back() const
{
	if (isEmpty())
	{
		throw std::logic_error("Your vector object is empty!");
	}

	return data[size-1];
}

int MyVector::getSize() const
{
	return size;
}

int MyVector::getCapacity() const
{
	return capacity;
}

void MyVector::reserve(int newCapacity)
{
	if (newCapacity > capacity)
	{
		resizeHelper(newCapacity);
	}
}

void MyVector::clear()
{
	for (int i = 0; i < size; i++)
	{
		data[i] = 0;
	}

	size = 0;
}

void MyVector::insert(int element, int idx)
{
	if (size == capacity)
	{
		resizeHelper(2 * capacity);
	}
	
	if (idx >= size)
	{
		data[size++] = element;

		return;
	}

	data[idx] = element;
}

void MyVector::insertRange(const MyVector& other, int idx=0)
{
	if (idx >= size)
	{
		idx = size;
	}

	insertRange(other.data, other.size, idx);
}

void MyVector::insertRange(const int* arr, int size, int idx)
{
	if (!arr)
	{
		throw std::invalid_argument("Nullptr detected!");
	}

	if (idx >= size)
	{
		idx = size;
	}

	rearrange(arr, size, idx);

}

void MyVector::erase(int element, bool allOccurances = false)
{
	int* temp = new int[capacity] {};

	int newSize = 0;

	bool firstDetected = false;

	for (int i = 0; i < size; i++)
	{
		if (data[i] == element)
		{
			if (allOccurances || (!allOccurances && !firstDetected))
			{
				firstDetected = true;
				continue;
			}
		}

		temp[newSize++] = data[i];
	}

	delete[] data;
	data = temp;
	temp = nullptr;
	size = newSize;
}

void MyVector::resize(int newCount)
{
	if (size == newCount)
	{
		return;
	}

	else if (newCount < size)
	{
		size = newCount;

		resizeHelper(size);
	}

	else
	{
		resizeHelper(newCount);
		size = newCount;
	}
}

void MyVector::resize(int newCount, int value)
{
	if (size == newCount)
	{
		return;
	}

	else if (newCount < size)
	{
		size = newCount;

		resizeHelper(size);
	}

	else
	{
		resizeHelper(newCount, value);
		size = newCount;
	}
}

int MyVector::operator[](int idx) const
{
	return data[idx];
}

int& MyVector::operator[](int idx)
{
	return data[idx];
}


void MyVector::shrinkToFit()
{
	if (size != 0)
	{
		resizeHelper(size);
	}
}

bool operator==(const MyVector& lhs, const MyVector& rhs)
{
	if (lhs.size != rhs.size)
	{
		return false;
	}

	for (int i = 0; i < lhs.size; i++)
	{
		if (lhs.data[i] != rhs.data[i])
		{
			return false;
		}
	}

	return true;
}

bool operator!=(const MyVector& lhs, const MyVector& rhs)
{
	return !(lhs==rhs);
}

bool operator<(const MyVector& lhs, const MyVector& rhs)
{
	if (lhs.size != rhs.size)
	{
		return false;
	}

	for (int i = 0; i < lhs.size; i++)
	{
		if (lhs.data[i] >= rhs.data[i])
		{
			return false;
		}
	}

	return true;
}

bool operator<=(const MyVector& lhs, const MyVector& rhs)
{
	if (lhs.size != rhs.size)
	{
		return false;
	}

	for (int i = 0; i < lhs.size; i++)
	{
		if (lhs.data[i] > rhs.data[i])
		{
			return false;
		}
	}

	return true;
}

bool operator>(const MyVector& lhs, const MyVector& rhs)
{
	if (lhs.size != rhs.size)
	{
		return false;
	}

	for (int i = 0; i < lhs.size; i++)
	{
		if (lhs.data[i] <= rhs.data[i])
		{
			return false;
		}
	}

	return true;
}

bool operator>=(const MyVector& lhs, const MyVector& rhs)
{
	if (lhs.size != rhs.size)
	{
		return false;
	}

	for (int i = 0; i < lhs.size; i++)
	{
		if (lhs.data[i] < rhs.data[i])
		{
			return false;
		}
	}

	return true;
}

std::ostream& operator<<(std::ostream& os, const MyVector& obj)
{
	for (int i = 0; i < obj.size; i++)
	{
		os << obj.data[i] << ' ';
	}
	os << std::endl;
	return os;
}
