#include "fileReader.h"
#include <iostream>
#include <fstream>
#include <cstdint>

PartialFunction* readFromFile(std::ifstream& ifs)
{
	uint16_t elementsCount = 0;
	uint16_t regime = 0;

	ifs.read((char*)&elementsCount, sizeof(uint16_t));
	ifs.read((char*)&regime, sizeof(uint16_t));

	return nullptr;
}

PartialFunction* readFromFile(const char* filePath)
{
	if (!filePath)
	{
		return nullptr;
	}

	std::ifstream ifs(filePath, std::ios::binary);

	if (!ifs.is_open())
	{
		return nullptr;
	}

	PartialFunction* toReturn = nullptr;

	ifs.close();

	return toReturn;
}