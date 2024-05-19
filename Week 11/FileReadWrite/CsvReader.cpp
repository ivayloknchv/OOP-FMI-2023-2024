#include "CsvReader.h"
#include <fstream>


CsvReader::CsvReader(const MyString& filePath) : FileReader(filePath)
{
}

int* CsvReader::read(size_t& size) const
{
	std::ifstream ifs(filePath.c_str());

	if (!ifs.is_open())
	{
		return nullptr;
	}

	size = Helpers::getSymbolsCount(ifs, ',') + 1;

	int* arr = new int[size] {};

	for (size_t i = 0; i < size; i++)
	{
		ifs >> arr[i];
		ifs.ignore();
	}

	ifs.close();
	return arr;
}
