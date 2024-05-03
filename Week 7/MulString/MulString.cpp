#include "MulString.h"
#include <cstring>
#include <utility>

#pragma warning (disable : 4996)

static void searchAllSymbolsUsed(bool* arr, const char* str)
{
	while (*str != '\0')
	{
		arr[*str] = true;
		str++;
	}
}
static int getCountTrues(bool* arr,int size)
{
	int toReturn = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i])
		{
			toReturn++;
		}
	}

	return toReturn;
}
static int getAsciiSum(const char* str)
{
	if (!str)
	{
		return -1;
	}

	int toReturn = 0;

	while (*str != '\0')
	{
		toReturn += *str;
		str++;
	}

	return toReturn;
}

void MulString::copyFrom(const MulString& other)
{
	str = new char[strlen(other.str) + 1]{};
	strcpy(str, other.str);
	size = strlen(str);
}

void MulString::moveFrom(MulString&& other)
{
	str = other.str;
	size = other.size;
	other.str = nullptr;
	other.size = 0;
}

void MulString::free()
{
	delete[] str;
	str = nullptr;

	size = 0;
}

MulString::MulString(const MulString& other)
{
	copyFrom(other);
}

MulString& MulString::operator=(const MulString& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

MulString::MulString(MulString&& other) noexcept
{
	moveFrom(std::move(other));
}

MulString& MulString::operator=(MulString&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

MulString::~MulString() noexcept
{
	free();
}

MulString::MulString(const char* str)
{
	setString(str);
}

void MulString::setString(const char* str)
{
	if (!str || this->str == str)
	{
		return;
	}

	delete[] this->str;
	this->str = new char[strlen(str) + 1]{};
	strcpy(this->str, str);
	size = strlen(str);
}

const char* MulString::getString() const
{
	return str;
}

int MulString::getSize() const
{
	return size;
}

MulString& MulString::operator*=(int k)
{
	size *= k;
	char* temp = new char[size + 1]{};

	for (int i = 0; i < k; i++)
	{
		strncat(temp, str,strlen(str));
	}

	delete[] str;
	str = temp;
	temp = nullptr;

	return *this;
}

MulString& MulString::operator%=(const MulString& other)
{
	
	bool usedSymbols[MAX_SYMBOLS]{};

	searchAllSymbolsUsed(usedSymbols, str);
	searchAllSymbolsUsed(usedSymbols, other.str);

	int totalUniqueSymbols = getCountTrues(usedSymbols,MAX_SYMBOLS);

	char* temp = new char[totalUniqueSymbols + 1]{};
	int counter = 0;

	for (int i = 0; i < MAX_SYMBOLS; i++)
	{
		if (usedSymbols[i])
		{
			temp[counter++] = i;
		}
	}
	delete[] str;
	str = temp;
	temp = nullptr;

	return *this;
}

std::ostream& operator<<(std::ostream& os, const MulString& str)
{
	return os << str.getString();
}

MulString operator*(int k, const MulString& str)
{
	MulString toReturn=str;
	toReturn *= k;
	return toReturn;
}

MulString operator*(const MulString& str, int k)
{
	MulString toReturn = str;
	toReturn *= k;
	return toReturn;
}

MulString operator%(const MulString& lhs, const MulString& rhs)
{
	MulString toReturn(lhs);
	toReturn %= rhs;

	return toReturn;
}

bool operator!=(const MulString& lhs, const MulString& rhs)
{
	return getAsciiSum(lhs.getString()) != getAsciiSum(rhs.getString());
}

