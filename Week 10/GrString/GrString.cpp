#include "GrString.h"
#include <cstring>
#include <utility>

#pragma warning (disable : 4996)

static unsigned getNextPowOfTwo(unsigned num)
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

static int getCapacity(int num)
{
	return std::max(16u, getNextPowOfTwo(num + 1));
}

static int getAsciiSum(const char* str)
{
	if (!str)
	{
		throw std::invalid_argument("Nullptr detected!");
	}

	int toReturn = 0;

	while (*str != '\0')
	{
		toReturn += (int)*str;
		str++;
	}

	return toReturn;
}

static void getDiffSymbols(bool* arr, const char* str1, const char* str2, int size, int& count)
{
	if (!arr)
	{
		return;
	}

	while (*str1 != '\0')
	{
		arr[*str1] = true;
		str1++;
	}

	while (*str2 != '\0')
	{
		if (arr[*str2] == true)
		{
			arr[*str2] = false;
		}
		str2++;
	}

	count = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i])
		{
			count++;
		}
	}
}

void GrString::copyFrom(const GrString& other)
{
	size = other.size;
	capacity = other.capacity;
	data = new char[capacity + 1]{};

	strcpy(data, other.data);
}

void GrString::moveFrom(GrString&& other)
{
	data = other.data;
	size = other.size;
	capacity = other.capacity;

	other.data = nullptr;
	other.size = 0;
	other.capacity = 0;
}

void GrString::free()
{
	delete[] data;
	data = nullptr;
	size = 0;
	capacity = 0;
}

void GrString::resize(int newCapacity)
{
	char* temp = new char[newCapacity + 1]{};
	strcpy(temp, data);
	delete[] data;
	data = temp;
	temp = nullptr;

	capacity = newCapacity;
}

GrString::GrString(int size)
{
	capacity = getCapacity(size);
	data = new char[capacity] {};
}

GrString::GrString()
{
	data = new char[8]{};
	capacity = 8;
}

GrString::GrString(const GrString& other)
{
	copyFrom(other);
}

GrString& GrString::operator=(const GrString& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

GrString::GrString(GrString&& other) noexcept
{
	moveFrom(std::move(other));
}

GrString& GrString::operator=(GrString&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

GrString::~GrString() noexcept
{
	free();
}

GrString::GrString(const char* str)
{
	size = strlen(str);
	capacity = getCapacity(size);
	data = new char[capacity]{};
	strcpy(data, str);
}

const char* GrString::c_str() const
{
	return data;
}

int GrString::getSize() const
{
	return size;
}

GrString& GrString::operator+=(const GrString& other)
{
	if (size + other.size + 1 > capacity)
	{
		resize(getCapacity(size + other.size));
	}

	size += other.size;
	strncat(data, other.data, other.size);

	return*this;
}

GrString& GrString::operator/=(const GrString& other)
{
	bool usedSymbols[MAX_SYMBOLS]{};
	int count = 0;
	getDiffSymbols(usedSymbols, data, other.data, MAX_SYMBOLS, count);

	char* temp = new char[count + 1]{};
	char* cpy = temp;
	for (int i = 0; i < MAX_SYMBOLS; i++)
	{
		if (usedSymbols[i])
		{
			*temp = i;
			temp++;
		}
	}

	temp = cpy;
	cpy = nullptr;
	delete[] data;
	data = temp;
	temp = nullptr;

	return *this;
}

std::istream& operator>>(std::istream& is, GrString& obj)
{
	char buff[1024]{};

	is >> buff;

	obj = buff;

	return is;
}

std::ostream& operator<<(std::ostream& os, const GrString& obj)
{
	return os << obj;
}

GrString operator+(const GrString& lhs, const GrString& rhs)
{
	int newSize = lhs.getSize() + rhs.getSize();
	GrString toReturn(newSize);
	toReturn += lhs;
	toReturn += rhs;

	return toReturn;
}

GrString operator/(const GrString& lhs, const GrString& rhs)
{
	GrString toReturn = lhs;
	toReturn /= rhs;
	return toReturn;
}

bool operator==(const GrString& lhs, const GrString& rhs)
{
	int lhsAscii = getAsciiSum(lhs.c_str());
	int rhsAscii = getAsciiSum(rhs.c_str());
	return (lhsAscii == rhsAscii);
}
