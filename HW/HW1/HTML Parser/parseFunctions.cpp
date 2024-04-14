#include <iostream>
#include "parseFunctions.h"
#include "helperFunctions.h"


void readTableCell(std::ifstream& ifs, Row& currentRow)
{
	char currentRead[Constants::MAX_BUFFER_SIZE]{};

	ifs.getline(currentRead, Constants::MAX_BUFFER_SIZE, '<');

	parseField(currentRead, (char*)&currentRow.fields[currentRow.colCount]);
}

void parseFromFile(std::ifstream& ifs, htmlTable& myTable)
{
	char currentRead[Constants::MAX_BUFFER_SIZE]{};

	while (true)
	{
		ifs.getline(currentRead, Constants::MAX_BUFFER_SIZE, '<');

		ifs.getline(currentRead, Constants::MAX_BUFFER_SIZE, '>');

		if (strcmp(currentRead, "td") == 0)
		{
			readTableCell(ifs, myTable.rows[myTable.rowCount]);

			ifs.getline(currentRead, Constants::MAX_BUFFER_SIZE, '>');

			if (strcmp(currentRead, "/td") == 0)
			{
				myTable.rows[myTable.rowCount].colCount++;
			}

			continue;
		}

		else if (strcmp(currentRead, "th") == 0)
		{
			readTableCell(ifs, myTable.rows[myTable.rowCount]);

			ifs.getline(currentRead, Constants::MAX_BUFFER_SIZE, '>');

			if (strcmp(currentRead, "/th") == 0)
			{
				Row& currentRow = myTable.rows[myTable.rowCount];
				currentRow.headingsHistogram[currentRow.colCount] = true;
				currentRow.colCount++;
			}

			continue;
		}

		else if (strcmp(currentRead, "tr") == 0)
		{
			continue;
		}

		else if (strcmp(currentRead, "/tr") == 0)
		{
			myTable.rowCount++;
			continue;
		}

		else if (strcmp(currentRead, "table") == 0)
		{
			continue;
		}

		else if (strcmp(currentRead, "/table") == 0)
		{
			break;
		}
	}
}

bool parseFromFile(const char* fileName, htmlTable& myTable)
{
	if (!fileName)
	{
		return false;
	}

	std::ifstream ifs(fileName, std::ios::in);

	if (!ifs.is_open())
	{
		std::cout << "File is not found!" << std::endl;
		return false;
	}

	parseFromFile(ifs, myTable);

	ifs.close();

	return true;
}