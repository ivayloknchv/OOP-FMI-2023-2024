#include <iostream>
#include <fstream>
#include <sstream>

namespace Constants 
{
	const int MAX_FIELD_SIZE = 45;
	const int MAX_FIELDS_ROW = 5;
	const int MAX_ROWS = 60;
	const int MAX_BUFF = 1024;
	const char SEPARATOR = ';';
}

struct Field
{
	char field[Constants::MAX_FIELD_SIZE]{};
};

struct Row
{
	Field fields[Constants::MAX_FIELDS_ROW]{};
};

struct CSV
{
	Row rows[Constants::MAX_ROWS];
	int rowsCount = 0;
	int colsCount = 0;
};

int parseRow(const char* row, Row& currentRow)
{
	if (!row)
	{
		return -1;
	}

	std::stringstream ss(row);

	int currentCol = 0;

	while (!ss.eof())
	{
		ss.getline((char*)&currentRow.fields[currentCol++], Constants::MAX_FIELD_SIZE, Constants::SEPARATOR);
	}
	
	return currentCol;
}

CSV readFromFile(std::ifstream& ifs)
{
	CSV myTable;

	char currentRow[Constants::MAX_BUFF];

	while (!ifs.eof())
	{
		ifs.getline(currentRow, Constants::MAX_BUFF);
		myTable.colsCount = parseRow(currentRow, myTable.rows[myTable.rowsCount++]);
	}

	return myTable;
}

CSV readFromFile(const char* fileName)
{
	if (!fileName)
	{
		return{};
	}

	std::ifstream ifs(fileName);

	if (!ifs.is_open())
	{
		return {};
	}

	return readFromFile(ifs);
}

void saveRow(std::ofstream& ofs, const Row& currentRow, const int size)
{
	for (int i = 0; i < size; i++)
	{
		ofs << (const char*)&currentRow.fields[i];

		if (i != size - 1)
		{
			ofs << Constants::SEPARATOR;
		}
	}
}

void saveToFile(std::ofstream& ofs, const CSV& myTable)
{
	for (int i = 0; i < myTable.rowsCount; i++)
	{
		saveRow(ofs, myTable.rows[i], myTable.colsCount);

		if (i != myTable.rowsCount - 1)
		{
			ofs << '\n';
		}
	}
}

void saveToFile(const char* fileName, const CSV& myTable)
{
	if (!fileName)
	{
		return;
	}

	std::ofstream ofs(fileName);

	if (!ofs.is_open())
	{
		return;
	}

	saveToFile(ofs, myTable);

	ofs.close();
}

void printRow(const Row& currentRow, const int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << (char*)&currentRow.fields[i]<<' ';

		if (i != size - 1)
		{
			std::cout << Constants::SEPARATOR;
		}
	}

	std::cout << '\n';
}

void printTable(const CSV& myTable)
{
	for (int i = 0; i < myTable.rowsCount; i++)
	{
		printRow(myTable.rows[i], myTable.colsCount);
	}
}

int main()
{
	return 0;
}
