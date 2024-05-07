#pragma once
#include <iostream>
class GrString
{
	static constexpr int MAX_SYMBOLS = 128;
	char* data = nullptr;
	int size = 0;
	int capacity = 0;

	void copyFrom(const GrString& other);
	void moveFrom(GrString&& other);
	void free();

	void resize(int newCapacity);

	explicit GrString(int size);

public:

	GrString();
	GrString(const GrString& other);
	GrString& operator=(const GrString& other);
	GrString(GrString&& other) noexcept;
	GrString& operator=(GrString&& other) noexcept;
	~GrString() noexcept;

	GrString(const char* str);
	const char* c_str() const;
	int getSize() const;

	GrString& operator+=(const GrString& other);
	GrString& operator/=(const GrString& other);

	friend std::istream& operator>>(std::istream& is, GrString& obj);
	friend std::ostream& operator<<(std::ostream& os, const GrString& obj);

	friend GrString operator + (const GrString& lhs, const GrString& rhs);
	friend GrString operator / (const GrString& lhs, const GrString& rhs);
};


bool operator == (const GrString& lhs, const GrString& rhs);

