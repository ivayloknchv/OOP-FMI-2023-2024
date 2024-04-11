#pragma once
#include <iostream>

class String
{
private:
	char* data = nullptr;
	unsigned size = 0;
	unsigned capacity = 0;

	void copyFrom(const String& other);
	void free();

	int calculateCapacity(int size) const;

public:

	String();
	String(const String& other);
	String& operator=(const String& other);
	~String();

	String(const char* str);

	String& operator+=(const String& other);

	char operator[](int idx) const;
	char& operator[](int idx);
	const char* c_style() const;

	friend bool operator==(const String& lhs, const String& rhs);
	friend bool operator!=(const String& lhs, const String& rhs);
	friend bool operator<(const String& lhs, const String& rhs);

	friend std::ostream& operator<<(std::ostream& os, const String& other);
	friend std::istream& operator>>(std::istream& is, String& other);
};

String operator+(const String& lhs, const String& rhs);