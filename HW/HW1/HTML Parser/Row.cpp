#include <iostream>
#include <sstream>
#include "Row.h"
#include "helperFunctions.h"
#pragma once

void Row::emptyRow()
{
	//clear the whole row to prevent any problems
	for (int i = 0; i < colCount; i++)
	{
		fields[i].field[0] = '\0';
		headingsHistogram[i] = false;
	}
	colCount = 0;
}

void Row::fillRow(const char* information)
{
	std::stringstream ss(information);

	int counter = 0;

	char tempBuffer[Constants::MAX_BUFFER_SIZE]{};
	while (true)
	{
		if (counter == Constants::MAX_ROW_SIZE)
		{
			std::cout << "Max columns reached!" << std::endl;
			colCount = counter;
			break;
		}

		ss.getline(tempBuffer, Constants::MAX_BUFFER_SIZE, Constants::SEPARATOR);

		if (ss.eof())
		{
			colCount = counter;
			break;
		}

		ss.getline(tempBuffer, Constants::MAX_BUFFER_SIZE, Constants::SEPARATOR);
		parseField(tempBuffer, (char*)&fields[counter]);
		counter++;
	}
	colCount = counter;
}

void Row::printWhiteSpaces(int count) const
	{
		for (int i = 0; i < count; i++)
		{
			std::cout << ' ';
		}
	}

	void Row::printIfHeading(bool pred) const
	{
		if (pred)
		{
			std::cout << '*';
		}
		else
		{
			std::cout << ' ';
		}
	}

	void Row::printRow(const int* colSizes, int maxColSize) const
	{
		int strLen;

		for (int i = 0; i < maxColSize; i++)
		{
			std::cout << '|';

			printIfHeading(headingsHistogram[i]);

			std::cout << (const char*)&fields[i];

			strLen = strlen((const char*)&fields[i]);

			printWhiteSpaces(colSizes[i] - strLen);

			printIfHeading(headingsHistogram[i]);
		}

		std::cout << '|' << std::endl;
	}