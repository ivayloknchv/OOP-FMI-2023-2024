#include "Helpers.h"

size_t Helpers::getFileSize(std::ifstream& ifs)
{
	size_t current = ifs.tellg();
	ifs.seekg(0, std::ios::end);
	size_t toReturn = ifs.tellg();
	ifs.seekg(current);

	return toReturn;
}

size_t Helpers::getSymbolsCount(std::ifstream& ifs, char ch)
{
	size_t toReturn = 0;
	size_t current = ifs.tellg();

	char symbol;

	while (true)
	{
		symbol = ifs.get();

		if (ifs.eof())
		{
			break;
		}

		if (symbol == ch)
		{
			toReturn++;
		}
	}

	ifs.clear();
	ifs.seekg(current);

	return toReturn;
}
