#include <cstring>
#include "String.h"
#include <cassert>

#pragma warning (disable : 4996)

void String::copyFrom(const String& other)
{
	size = other.size;
	capacity = other.capacity;
	data = new char[size];
	strcpy(data, other.data);
}

void String::free()
{
	delete[] data;
	size = 0;
	capacity = 0;
}

int String::calculateCapacity(int size) const
{
	return (size< 16) ? 16: size+size/2;
}

String::String():String(""){}

String::String(const String& other)
{
	copyFrom(other);
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

String::~String()
{
	free();
}

String::String(const char* str)
{
	size = strlen(str);
	capacity = calculateCapacity(size);
	data = new char[capacity];
	strcpy(data, str);
}

String& String::operator+=(const String& other)
{
	if (size + other.size > capacity)
	{
		size += other.size;
		capacity = calculateCapacity(size);
		
		char* temp = new char[capacity];
		strcpy(temp, data);

		delete[] data;
		data = temp;
		temp = nullptr;

		strcat(data, other.data);
	}

	else
	{
		size += other.size;
		strcat(data, other.data);
	}

	return *this;
}

char String::operator[](int idx) const
{
	assert(idx < size);
	return data[idx];
}

char& String::operator[](int idx)
{
	assert(idx < size);
	return data[idx];
}

bool operator==(const String& lhs, const String& rhs)
{
	return strcmp(lhs.data,rhs.data)==0;
}

bool operator!=(const String& lhs, const String& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const String& lhs, const String& rhs)
{
	return strcmp(lhs.data, rhs.data);
}

std::ostream& operator<<(std::ostream& os, const String& other)
{
	return os << other.data;
}

std::istream& operator>>(std::istream& is, String& other)
{
	char buff[1024];

	is >> buff;

	other = buff;

	return is;
}

String operator+(const String& lhs, const String& rhs)
{
	String toReturn = lhs;
	toReturn += rhs;

	return toReturn;
}
