#include "Drink.h"
#include <iostream>



Drink::Drink()
{
	setProduct(Product::DRINK);
}

Drink::Drink(const char* name, double alcoholPercent, unsigned count, double price) : RestaurantItem(Product::DRINK, name, count, price)
{
	setAlcoholPercent(alcoholPercent);
}

void Drink::setAlcoholPercent(double alcoholPercent)
{
	_alcoholPercent = alcoholPercent;
}


RestaurantItem* Drink::clone() const
{
	return new Drink(*this);
}

void Drink::print() const
{
	RestaurantItem::print();
	std::cout << "Alcohol Percent: " << _alcoholPercent << "%" << std::endl;

}

bool operator>(const Drink& lhs, const Drink& rhs)
{
	return lhs._alcoholPercent>rhs._alcoholPercent;
}
