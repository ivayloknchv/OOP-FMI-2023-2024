#pragma once
#include "FileWriter.h"

class CsvWriter : public FileWriter
{
public:

	CsvWriter() = default;
	CsvWriter(const MyString& filePath);
	void write(const int* arr, size_t size) const override;
};

