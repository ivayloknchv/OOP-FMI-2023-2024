#pragma 
#include "FileReader.h"

class CsvReader : public FileReader
{
public:

	CsvReader() = default;
	CsvReader(const MyString& filePath);
	int* read(size_t& size) const override;
};

