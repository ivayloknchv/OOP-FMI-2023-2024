#include "ArrayReader.h"
#include <fstream>
ArrayReader::ArrayReader(const MyString& filePath) : FileReader(filePath)
{
}

int* ArrayReader::read(size_t& size) const
{
	std::ifstream ifs(filePath.c_str());

	if (!ifs.is_open())
	{
		return nullptr;
	}

	size = Helpers::getSymbolsCount(ifs, ' ') + 1;

	int* arr = new int[size] {};

	ifs.ignore();

	for (size_t i = 0; i < size; i++)
	{
		ifs >> arr[i];
	}

	ifs.close();
	return arr;
}
