#pragma once
#include "FileReader.h"

class BinaryReader : public FileReader
{
public:

	BinaryReader() = default;

	BinaryReader(const MyString& filePath);

	int* read(size_t& size) const override;
};

