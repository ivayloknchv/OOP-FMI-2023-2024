#pragma once
#include "RestaurantItem.h"

class Drink : public RestaurantItem
{
	double _alcoholPercent = 0;

public:

	Drink();

	Drink(const char* name, double alcoholPercent, unsigned count, double price);

	void setAlcoholPercent(double alcoholPercent);

	RestaurantItem* clone() const override;
	void print() const override;

	friend bool operator > (const Drink& lhs, const Drink& rhs);
};

