#include "File.h"
#include <cstring>
#include <utility>

#pragma warning (disable : 4996)

void File::copyFrom(const File& other)
{
	fileName = new char[strlen(other.fileName) + 1]{};
	strcpy(fileName, other.fileName);
}

void File::moveFrom(File&& other)
{
	fileName = other.fileName;
	other.fileName = nullptr;
}

void File::free()
{
	delete[] fileName;
	fileName = nullptr;
}

File::File(const char* name)
{
	if (!name)
	{
		return;
	}
	fileName = new char[strlen(name) + 1]{};
	strcpy(fileName, name);
}

File::File(const File& other)
{
	copyFrom(other);
}

File& File::operator=(const File& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

File::File(File&& other) noexcept
{
	moveFrom(std::move(other));
}

File& File::operator=(File&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

File::~File()
{
	free();
}
