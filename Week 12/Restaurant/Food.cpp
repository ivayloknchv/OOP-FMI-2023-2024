#include "Food.h"
#include <cstring>
#include <utility>
#include <iostream>

#pragma warning (disable : 4996)

Food::Food()
{
	setProduct(Product::FOOD);
}

Food::Food(const char* name, double weight, unsigned count, double price) : RestaurantItem(Product::FOOD, name, count, price)
{
	setWeight(weight);
}


void Food::setWeight(double weight)
{
	_weight = weight;
}

RestaurantItem* Food::clone() const
{
	return new Food(*this);
}

void Food::print() const
{
	RestaurantItem::print();
	std::cout << "Weight: "<<_weight << std::endl;
}


bool operator>(const Food& lhs, const Food& rhs)
{
	return (lhs._weight>rhs._weight);
}
