#pragma once
#include "RestaurantItem.h"

class Food : public RestaurantItem
{
	double _weight = 0;

public:

	Food();
	Food(const char* name, double weight, unsigned count, double price);

	void setWeight(double weight);
	friend bool operator>(const Food& lhs, const Food& rhs);

	RestaurantItem* clone() const override;
	void print() const override;
};



