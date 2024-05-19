#include <iostream>
#include "ArrayReader.h"
#include "ArrayWriter.h"
#include "BinaryReader.h"
#include "BinaryWriter.h"
#include "CsvReader.h"
#include "CsvWriter.h"
#include "FilePath.h"
#include "MyString.h"

FileReader* readerFactory(const MyString& readPath)
{
	FilePath path = readPath;

	if (path.getExtension() == ".dat")
	{
		return new BinaryReader(readPath);
	}

	else if (path.getExtension() == ".csv")
	{
		return new CsvReader(readPath);
	}

	else if (path.getExtension() == ".arr")
	{
		return new ArrayReader(readPath);
	}

	throw std::exception("Invalid file path!");
}
FileWriter* writerFactory(const MyString& writePath)
{
	FilePath path = writePath;

	if (path.getExtension() == ".dat")
	{
		return new BinaryWriter(writePath);
	}

	else if (path.getExtension() == ".csv")
	{
		return new CsvWriter(writePath);
	}

	else if (path.getExtension() == ".arr")
	{
		return new ArrayWriter(writePath);
	}

	throw std::exception("Invalid file path!");
}
void transfer(const MyString& readPath, const MyString& writePath)
{
	FileReader* reader = readerFactory(readPath);
	FileWriter* writer = writerFactory(writePath);

	size_t size = 0;
	int* arr = reader->read(size);
	writer->write(arr, size);

	delete reader;
	delete writer;
	delete[] arr;
}

int main()
{
	return 0;
}