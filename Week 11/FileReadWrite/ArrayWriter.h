#pragma once
#include "FileWriter.h"

class ArrayWriter : public FileWriter
{
public:

	ArrayWriter() = default;
	ArrayWriter(const MyString& filePath);
	void write(const int* arr, size_t size) const override;
};

