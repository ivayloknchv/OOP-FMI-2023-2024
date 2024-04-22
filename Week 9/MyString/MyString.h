#pragma once
#include <iostream>
class MyString
{
private:

	char* data = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void copyFrom(const MyString& other);
	void moveFrom(MyString&& other);
	void free();

	void resize(size_t newCapacity);
	explicit MyString(size_t capacity);
public:

	MyString();
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	MyString(MyString&& other) noexcept;
	MyString& operator=(MyString&& other) noexcept;
	~MyString();

	MyString(const char* str);

	MyString& operator+=(const MyString& str);

	const char& operator[](size_t idx) const;
	char& operator[](size_t idx);

	const char* c_str() const;
	size_t getSize() const;
	friend std::ostream& operator << (std::ostream& os, const MyString& str);
	friend std::istream& operator >> (std::istream& is, MyString& str);
	friend MyString operator +(const MyString& lhs, const MyString& rhs);
};

bool operator < (const MyString& lhs, const MyString& rhs);
bool operator <= (const MyString& lhs, const MyString& rhs);
bool operator > (const MyString& lhs, const MyString& rhs);
bool operator >= (const MyString& lhs, const MyString& rhs);
bool operator == (const MyString& lhs, const MyString& rhs);
bool operator != (const MyString& lhs, const MyString& rhs);

