#pragma once
#include "StringPool.h"
#include <iostream>

class ImmutableString
{
	const char* str = nullptr;
	int len = 0;

	static StringPool strPool;

public:

	ImmutableString();
	ImmutableString(const ImmutableString& other);
	ImmutableString& operator=(const ImmutableString& other);
	~ImmutableString();

	ImmutableString(const char* str);

	const char* c_str() const;
	int length() const;

	const char operator[](int idx) const;
};

bool operator==(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator!=(const ImmutableString& lhs, const ImmutableString& rhs);
std::ostream& operator<<(std::ostream& os, const ImmutableString& str);