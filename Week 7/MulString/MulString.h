#pragma once
#include <iostream>

class MulString
{
private:
	static constexpr int MAX_SYMBOLS = 128;
	char* str;
	int size = 0;

	void copyFrom(const MulString& other);
	void moveFrom(MulString&& other);
	void free();

public:

	MulString() = default;
	MulString(const MulString& other);
	MulString& operator=(const MulString& other);
	MulString(MulString&& other) noexcept;
	MulString& operator=(MulString&& other) noexcept;
	~MulString() noexcept;

	MulString(const char* str);

	void setString(const char* str);
	const char* getString() const;
	int getSize() const;

	MulString& operator*=(int k);
	MulString& operator%=(const MulString& other);

	friend std::ostream& operator<<(std::ostream& os, const MulString& str);

};

MulString operator*(int k, const MulString& str);
MulString operator*(const MulString& str, int k);
MulString operator%(const MulString& lhs, const MulString& rhs);
bool operator!=(const MulString& lhs, const MulString& rhs);

