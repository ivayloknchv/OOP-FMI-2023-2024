#pragma once
#include "FileReader.h"

class ArrayReader : public FileReader
{
public:

	ArrayReader() = default;
	ArrayReader(const MyString& filePath);
	int* read(size_t& size) const override;
};

