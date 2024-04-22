#include "MyString.h"
#include <cstring>

#pragma warning (disable : 4996)

static unsigned roundToPowOfTwo(unsigned num)
{
	num--;
	num |= num >> 1;
	num |= num >> 2;
	num |= num >> 4;
	num |= num >> 8;
	num |= num >> 16;

	num++;

	return num;

}

static unsigned getCapacity(unsigned strLen)
{
	return std::max(roundToPowOfTwo(strLen + 1), 16u);
}

void MyString::copyFrom(const MyString& other)
{
	size = other.size;
	capacity = other.capacity;
	data = new char[capacity];
	strcpy(data, other.data);
}

void MyString::moveFrom(MyString&& other)
{
	data = other.data;
	size = other.size;
	capacity = other.capacity;

	other.data = nullptr;
	other.size = 0;
	other.capacity = 0;
}

void MyString::free()
{
	delete[] data;
	data = nullptr;
	size = 0;
	capacity = 0;
}

void MyString::resize(size_t newCapacity)
{
	capacity = newCapacity;

	char* temp = new char[capacity + 1];
	strcpy(temp, data);

	delete[] data;
	data = temp;
	temp = nullptr;
}

MyString::MyString(size_t size)
{
	capacity = getCapacity(size);
	data = new char[capacity] {};
}

MyString::MyString()
{
	capacity = 8;
	data = new char[capacity] {};
}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

MyString::MyString(MyString&& other) noexcept
{
	moveFrom(std::move(other));
}

MyString& MyString::operator=(MyString&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

MyString::~MyString()
{
	free();
}

MyString::MyString(const char* str)
{
	size = strlen(str);
	capacity = getCapacity(size);
	data = new char[capacity] {};
	strcpy(data, str);

}

MyString& MyString::operator+=(const MyString& str)
{
	if (size + str.size + 1 > capacity)
	{
		resize(getCapacity(capacity + str.capacity));
	}
	strncat(data, str.data, str.size);
	size += str.size;
	return *this;
}

const char& MyString::operator[](size_t idx) const
{
	return data[idx];
}

char& MyString::operator[](size_t idx)
{
	return data[idx];
}

const char* MyString::c_str() const
{
	return data;
}

size_t MyString::getSize() const
{
	return size;
}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
	return os << str.c_str();
}

std::istream& operator>>(std::istream& is, MyString& str)
{
	char buff[1024]{};
	is >> buff;
	str = buff;

	return is;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString toReturn(lhs.getSize() + rhs.getSize());

	toReturn += lhs;
	toReturn += rhs;

	return toReturn;
}

bool operator<(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
	return (strcmp(lhs.c_str(), rhs.c_str()) <= 0);
}

bool operator>(const MyString& lhs, const MyString& rhs)
{
	return (strcmp(lhs.c_str(), rhs.c_str()) > 0);
}

bool operator>=(const MyString& lhs, const MyString& rhs)
{
	return (strcmp(lhs.c_str(), rhs.c_str()) >= 0);
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
	return (strcmp(lhs.c_str(), rhs.c_str()) == 0);
}

bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return (strcmp(lhs.c_str(), rhs.c_str()) != 0);
}
