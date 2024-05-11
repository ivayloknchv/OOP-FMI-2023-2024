#pragma once
#include "DynamicCollection.h"

class NormalCollection : public DynamicCollection
{
public:

	void add(int num) override;
	void remove(int num) override;
	int count(int num) const override;
	bool contains(int num) const override;
};

