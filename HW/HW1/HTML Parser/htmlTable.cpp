#include <iostream>
#include <sstream>
#include "htmlTable.h"
#include "helperFunctions.h"

int htmlTable::getMaxColSize() const
{
	int max = rows[0].colCount;

	for (int i = 0; i <rowCount; i++)
	{
		if (max < rows[i].colCount)
		{
			max = rows[i].colCount;
		}
	}

	return max;
}

bool htmlTable::validateEdit(int row, int col, const char* newStr) const
{
	if (row<1 || row>rowCount)
	{
		std::cout << "Invalid row!" << std::endl;
		return false;
	}

	if (col<1 || col>getMaxColSize())
	{
		std::cout << "Invalid column!" << std::endl;
		return false;
	}

	if (strlen(newStr) > Constants::MAX_FIELD_SIZE)
	{
		std::cout << "The new field is longer than 50 symbols!" << std::endl;
		return false;
	}

	return true;
}

bool htmlTable::editCell(int row, int col, const char* newStr)
{
	if (!newStr)
	{
		return false;
	}

	if (validateEdit(row, col, newStr))
	{
		parseField(newStr, (char*)&rows[row - 1].fields[col - 1]);

		if (col > rows[row - 1].colCount) //change the number of cols in case we edit an empty cell
		{
			rows[row - 1].colCount = col;
		}

		return true;
	}

	return false;

}

void htmlTable::editCell()
{
	int row = 0, col = 0;
	char newStr[Constants::MAX_BUFFER_SIZE];
	std::cin >> row >> col;

	std::cin.getline(newStr, Constants::MAX_BUFFER_SIZE, Constants::SEPARATOR);

	std::cin.getline(newStr, Constants::MAX_BUFFER_SIZE, Constants::SEPARATOR);

	if (editCell(row, col, newStr))
	{
		std::cout << "Cell edited successfully!" << std::endl;
	}

}

bool htmlTable::validateRow(int row) const
{
	if (row < 1 || row > rowCount)
	{
		std::cout << "Invalid row!" << std::endl;
		return false;
	}

	return true;
}

bool htmlTable::removeRow(int rowToRemove)
{
	if (!validateRow(rowToRemove))
	{
		return false;
	}

	for (int i = rowToRemove - 1; i < rowCount; i++)
	{
		rows[i] = rows[i + 1];
	}

	rowCount -= 1;

	return true;
}

void htmlTable::removeRow()
{
	int rowToRemove;
	std::cin >> rowToRemove;

	if (removeRow(rowToRemove))
	{
		std::cout << "Successfully removed Row " << rowToRemove << std::endl;
	}
}

void htmlTable::shiftTableDown(int row)
{
	for (int i = rowCount; i >= row; i--)
	{
		rows[i] = rows[i - 1];
	}
	rowCount++;
}

void htmlTable::addRow()
{
	int currentRow = 0;

	std::cin >> currentRow;

	if (currentRow<1 || currentRow>rowCount + 1)
	{
		std::cout << "Invalid row!" << std::endl;
		return;
	}

	shiftTableDown(currentRow);

	rows[currentRow - 1].emptyRow();

	char information[Constants::MAX_BUFFER_SIZE];

	std::cin.getline(information, Constants::MAX_BUFFER_SIZE);

	rows[currentRow - 1].fillRow(information);

	std::cout << "New row added successfully!" << std::endl;
}

int htmlTable::getMaxSizeOfSingleColumn(int currentCol) const
{
	int max = strlen((const char*)&rows[0].fields[currentCol]);

	for (int j = 0; j < rowCount; j++)
	{
		int currentLen = strlen((const char*)&rows[j].fields[currentCol]);

		if (currentLen > max)
		{
			max = currentLen;
		}
	}

	return max;
}

void htmlTable::getSizeOfColums(int* colSizes, int size) const
{
	if (!colSizes)
	{
		return;
	}

	for (int i = 0; i < size; i++)
	{
		colSizes[i] = getMaxSizeOfSingleColumn(i);
	}
}

void htmlTable::printTable() const
{
	int maxColSize = getMaxColSize();

	int* colSizes = new int[maxColSize];

	getSizeOfColums(colSizes, maxColSize);

	for (int i = 0; i < rowCount; i++)
	{
		rows[i].printRow(colSizes, maxColSize);
	}

	delete[] colSizes;
}