#pragma once
#include "Drink.h"
#include "Alcohol.h"

class Bar
{
	struct Statistics
	{
		int drinksSold = 0;
		int alcSold = 0;
		int mlSold = 0;
	};

	static constexpr int MAX_SIZE = 100;

	Drink drinks[MAX_SIZE]{};
	int drinkCount[MAX_SIZE]{};
	int drinkSize = 0;

	Alcohol alcDrinks[MAX_SIZE]{};
	int alcCount[MAX_SIZE]{};
	int alcSize = 0;

	Statistics stat;

public:

	void addDrink(const char* name, int ml, int count=1);
	void addAlcDrink(const char* name, int ml, int percent, int count=1);

	const Drink& getDrink();
	const Alcohol& getAlcDrink();

	int getDrinksSold() const;
	int getAlcSold() const;
	int getMlSold() const;
};

