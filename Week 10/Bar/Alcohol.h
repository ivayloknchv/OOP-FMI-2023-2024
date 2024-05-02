#pragma once
#include "Drink.h"

class Alcohol : public Drink
{
	static constexpr int MIN_PERCENT = 5;
	static constexpr int MAX_PERCENT = 98;

	int percent = 0;

public:

	Alcohol() = default;
	Alcohol(const char* name, int ml, int percent);

	void setPercent(int percent);

	int getPercent() const;
};

