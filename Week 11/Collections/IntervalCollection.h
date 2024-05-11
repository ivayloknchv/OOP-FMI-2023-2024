#pragma once
#include "DynamicCollection.h"

class IntervalCollection : public DynamicCollection
{
private:
	int start = 0;
	int end = 0;

	bool isInInterval(int num) const;

public:

	IntervalCollection(int start, int end);

	void add(int num) override;
	void remove(int num) override;
	int count(int num) const override;
	bool contains(int num) const override;

};

