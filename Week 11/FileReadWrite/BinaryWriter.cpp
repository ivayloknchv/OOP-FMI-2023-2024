#include "BinaryWriter.h"
#include <fstream>

BinaryWriter::BinaryWriter(const MyString& filePath) : FileWriter(filePath)
{
	
}

void BinaryWriter::write(const int* arr, size_t size) const
{
	if (!arr)
	{
		return;
	}

	std::ofstream ofs(filePath.c_str(), std::ios::binary);

	if (!ofs.is_open())
	{
		return;
	}

	ofs.write((const char*)arr, size * sizeof(int));
	ofs.close();
}
