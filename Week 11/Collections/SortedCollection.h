#pragma once
#include "IntervalCollection.h"

class SortedCollection : public DynamicCollection
{
private:

	int lowerBound(int num) const;
	int upperBound(int num) const;
public:

	void add(int num) override;
	void remove(int num) override;
	int count(int num) const override;
	bool contains(int num) const override;
};

