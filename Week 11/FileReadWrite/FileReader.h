#pragma once
#include "MyString.h"
#include "Helpers.h"

class FileReader
{
protected:

	MyString filePath;

public:

	FileReader() = default;
	FileReader(const MyString& filePath);
	virtual int* read(size_t& size) const = 0;
	virtual ~FileReader()=default;
};

