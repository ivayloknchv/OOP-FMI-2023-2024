#include "Helpers.h"
#include <exception>
#include <iostream>

bool isLower(char ch)
{
	return ch>'a' && ch<'z';
}

bool isSymbol(char ch)
{
	return ch>='a' && ch <= 'z' || ch >= 'A' && ch <= 'Z';
}
void toUpper(char* str)
{
	if (!str)
	{
		throw std::invalid_argument("The given string doesn't exist");
	}

	static int diff = 'a' - 'A';
	while (*str != '\0')
	{
		if (!isSymbol(*str))
		{
			throw std::bad_cast();
		}

		if (isLower(*str))
		{
			*str -= diff;
		}

		str++;
	}
}

unsigned convertToNum(char* str)
{
	if (!str)
	{
		throw std::invalid_argument("The given string doesn't exist");
	}

	unsigned toReturn = 0;

	while (*str != '\0')
	{
		toReturn *= 10;
		toReturn += charToDigit(*str);
		str++;
	}

	return toReturn;
}

char charToDigit(char ch)
{
	if (ch < '0' || ch > '9')
	{
		throw std::bad_cast();
	}
	return ch-'0';
}
