#pragma once
#include "CollectionsSuperSetOperation.h"

class Intersection : public CollectionsSuperSetOperation
{
public:

	Intersection(Collection& l, Collection& r);

	void add(int num) override;
	void remove(int num) override;
	int count(int num) const override;
	bool contains(int num) const override;
};

