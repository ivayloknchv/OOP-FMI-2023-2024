#pragma once
#include "Bitset.h"

class SetByCriteria : private Bitset
{
	struct Criteria
	{
		bool(*incl)(int num) = nullptr;
		bool(*excl)(int num) = nullptr;

		bool isValidNum(int num) const;
	};

	Criteria cr;
	int setCount = 0;

	void fillSet();

public:

	SetByCriteria(int limit, bool(*incl)(int num), bool (*excl)(int num));
	
	void setIncl(bool(*incl)(int num));
	void setExcl(bool (*excl)(int num));

	bool containsNum(int num) const;
	int getCount() const;
	void printSet() const;
};

