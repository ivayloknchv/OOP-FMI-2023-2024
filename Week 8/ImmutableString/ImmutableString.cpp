#include "ImmutableString.h"
#include <cstring>
#include <stdexcept>

#pragma warning (disable : 4996)

StringPool ImmutableString::strPool;

ImmutableString::ImmutableString()
{
	str = strPool.getString("");
}

ImmutableString::ImmutableString(const ImmutableString& other)
{
	str = strPool.getString(other.c_str());
	len = other.len;
}

ImmutableString& ImmutableString::operator=(const ImmutableString& other)
{
	if (this != &other)
	{
		strPool.removeString(c_str());
		str = strPool.getString(other.c_str());
		len = other.length();
	}

	return*this;
}

ImmutableString::~ImmutableString()
{
	strPool.removeString(c_str());
	len = 0;
}

ImmutableString::ImmutableString(const char* str)
{
	this->str = strPool.getString(str);
	len = strlen(str);
}

const char* ImmutableString::c_str() const
{
	return str;
}

int ImmutableString::length() const
{
	return len;
}

const char ImmutableString::operator[](int idx) const
{
	if (idx < 0 || idx >= len)
	{
		throw std::invalid_argument("Index out of range!");
	}

	return str[idx];
}

bool operator==(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return (strcmp(lhs.c_str(), rhs.c_str()) == 0);
}

bool operator!=(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& os, const ImmutableString& str)
{
	return os << str.c_str();
}
