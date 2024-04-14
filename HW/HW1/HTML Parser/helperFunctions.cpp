#include "helperFunctions.h"
#include <cstring>

#pragma warning (disable : 4996)

bool isDigit(char ch)
{
	return (ch >= '0' && ch <= '9');
}

bool isValidSymbol(char ch)
{
	return (ch != ' ' && ch != '\n' && ch != '\t' && ch != '\0');
}

int truncStart(const char* str)
{
	if (!str)
	{
		return -1;
	}

	int idxStart = 0;

	while (!isValidSymbol(str[idxStart]))
	{
		idxStart++;
	}

	return idxStart;

}

int truncEnd(const char* str)
{
	if (!str)
	{
		return -1;
	}

	int idxEnd = strlen(str) - 1;

	while (!isValidSymbol(str[idxEnd]))
	{
		idxEnd--;
	}

	return idxEnd;
}

char convertEntityReference(const char* str, int& jumpPositions)
{
	if (!str)
	{
		return ' ';
	}

	char newSymbol = 0;

	while (isDigit(*str))
	{
		newSymbol = newSymbol * 10 + (*str - '0');
		jumpPositions++;
		str++;
	}

	return newSymbol;
}

void parseField(const char* source, char* destination)
{
	if (!source || !destination)
	{
		return;
	}

	int destIdx = 0;
	int jumpPositions = 0;

	int idxStart = truncStart(source);
	int idxEnd = truncEnd(source);

	for (int i = idxStart; i <= idxEnd; i++)
	{
		if (source[i] == '\n')
		{
			continue;
		}
		if (source[i] == '&' && source[i + 1] == '#' && isDigit(source[i + 2]))
		{
			destination[destIdx++] = convertEntityReference(&source[i + 2], jumpPositions);
			i += jumpPositions + 1;
			jumpPositions = 0;
		}
		else
		{
			destination[destIdx++] = source[i];
		}
	}

	destination[destIdx] = '\0';
}


