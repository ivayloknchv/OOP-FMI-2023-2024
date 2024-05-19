#include "BinaryReader.h"
#include <fstream>
static size_t getFileSize(std::ifstream& ifs)
{
	size_t current = ifs.tellg();
	ifs.seekg(0, std::ios::end);
	size_t toReturn = ifs.tellg();
	ifs.seekg(current);

	return toReturn;
}

BinaryReader::BinaryReader(const MyString& filePath) : FileReader(filePath)
{
}

int* BinaryReader::read(size_t& size) const
{
	std::ifstream ifs(filePath.c_str(), std::ios::binary);

	if (!ifs.is_open())
	{
		return nullptr;
	}

	size = Helpers::getFileSize(ifs);
	int* arr = new int[size] {};

	ifs.read((char*)arr, sizeof(int) * size);

	ifs.close();
	return arr;
}
