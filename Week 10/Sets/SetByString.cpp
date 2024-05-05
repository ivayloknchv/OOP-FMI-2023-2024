#include "SetByString.h"
#include <utility>
#include <cstring>
#include <stdexcept>
#include <sstream>

#pragma warning (disable : 4996)

void SetByString::copyFrom(const SetByString& other)
{
	data = new char[strlen(other.data)+1]{};
	strcpy(data, other.data);
}

void SetByString::moveFrom(SetByString&& other)
{
	data = other.data;
	other.data = nullptr;
}

void SetByString::free()
{
	delete[] data;
	data = nullptr;
}

void SetByString::fillSet()
{
	std::stringstream ss(data);

	Bitset::clean();

	int limit = Bitset::getSetLimit();

	int currentNum = 0;

	while (true)
	{

		ss >> currentNum;

		if (currentNum >= limit)
		{
			throw std::out_of_range("Number out of range!");
		}

		Bitset::addNum(currentNum);

		if (ss.eof())
		{
			break;
		}
	}
}

SetByString::SetByString(const SetByString& other) : Bitset(other)
{
	copyFrom(other);
}

SetByString& SetByString::operator=(const SetByString& other)
{
	if (this != &other)
	{
		Bitset::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}

SetByString::SetByString(SetByString&& other) noexcept : Bitset(std::move(other))
{
	moveFrom(std::move(other));
}

SetByString& SetByString::operator=(SetByString&& other) noexcept
{
	if (this != &other)
	{
		Bitset::operator=(std::move(other));
		free();
		copyFrom(other);
	}

	return *this;
}

SetByString::~SetByString() noexcept
{
	free();
}

SetByString::SetByString(int limit, const char* newData) : Bitset(limit)
{
	setString(newData);
}

void SetByString::setString(const char* newData)
{
	if (!newData || data == newData)
	{
		return;
	}

	delete[] data;
	data = new char[strlen(newData) + 1]{};
	strcpy(data, newData);

	fillSet();
}

void SetByString::setAt(int pos, char ch)
{
	if (ch < '0' || ch > '9')
	{
		throw std::invalid_argument("The symbol isn't a digit!");
	}

	if (pos < 0 || pos >= strlen(data))
	{
		throw std::out_of_range("Index out of range!");
	}

	data[pos] = ch;

	fillSet();
}

void SetByString::print() const
{
	Bitset::print();
}

bool SetByString::containsNum(int num) const
{
	return Bitset::containsNum(num);
}

int SetByString::getCount() const
{
	int toReturn = 0;
	int limit = Bitset::getSetLimit();

	for (int i = 0; i < limit; i++)
	{
		if (containsNum(i))
		{
			toReturn++;
		}
	}

	return toReturn;
}
