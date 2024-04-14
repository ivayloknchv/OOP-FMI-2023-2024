#include <iostream>
#include "helperFunctions.h"
#include "parseFunctions.h"
#include "manipulationFunctions.h"

int main()
{
	htmlTable tbl;

	char fileName[Constants::MAX_BUFFER_SIZE]{};
	std::cout << "Enter file name: ";

	std::cin >> fileName;

	if (!parseFromFile(fileName, tbl))
	{
		return -1;
	}

	manipulateTable(tbl, fileName);

	return 0;
}