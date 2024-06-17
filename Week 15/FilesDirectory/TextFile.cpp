#include "TextFile.h"
#include <iostream>

TextFile::TextFile(const char* name, double size) : File(name), size(size)
{
}

File* TextFile::clone() const
{
	return new TextFile(*this);
}

void TextFile::print() const
{
	std::cout << "	File: " << fileName << std::endl;
}

double TextFile::getSize() const
{
	return size;
}
