#pragma once
#include "Bitset.h"

class SetByString : private Bitset
{
	char* data = nullptr;

	void copyFrom(const SetByString& other);
	void moveFrom(SetByString&& other);
	void free();

	void fillSet();

public:

	SetByString() = delete;
	SetByString(const SetByString& other);
	SetByString& operator=(const SetByString& other);
	SetByString(SetByString&& other) noexcept;
	SetByString& operator=(SetByString&& other) noexcept;
	~SetByString() noexcept;

	SetByString(int limit, const char* newData);

	void setString(const char* newData);

	void setAt(int pos, char ch);
	void print() const;
	bool containsNum(int num) const;
	int getCount() const;
};

