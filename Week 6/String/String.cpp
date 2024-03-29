#include "String.h"
#include <cstring>

#pragma warning (disable : 4996)

void String::copyFrom(const String& other)
{
	size = strlen(other.str);

	str = new char[size + 1];

	strcpy(str, other.str);
}

void String::free()
{
	delete[] str;
	str = nullptr;
	size = 0;
}

void String::setStr(const char* newStr)
{
	if (!newStr)
	{
		return;
	}

	delete[] str;

	this->size = strlen(newStr);

	str = new char[size + 1];

	strcpy(str, newStr);

}

String::String(const char* newStr)
{
	setStr(newStr);
}

String::String(const String& other)
{
	copyFrom(other);
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

String& String::concat(const String& other)
{
	char* concatStr = new char[size + other.size + 1];

	strcpy(concatStr, str);

	strcpy(&concatStr[size], other.str);

	delete[] str;

	str = concatStr;

	size += other.size;

	return*this;
}

unsigned String::strLen() const
{
	return size;
}

const char* String::getStr() const
{
	return str;
}

String::~String()
{
	free();
}
