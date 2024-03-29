#pragma once

class String
{
	char* str = nullptr;
	unsigned size = 0;

	void copyFrom(const String& other);
	void free();

	void setStr(const char* newStr);
public:

	String() = default;

	String(const char* newStr);

	String(const String& other);

	String& operator=(const String& other);

	String& concat(const String& other);

	unsigned strLen() const;

	const char* getStr() const;

	~String();
};