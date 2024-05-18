#include <iostream>
#include "Food.h"
#include "Drink.h"
#include "Restaurant.h"

int main()
{
	Restaurant r;

	Food f;
	f.setName("Pizza");
	f.setWeight(0.4);
	f.setCount(30);
	f.setPrice(5.50);

	Drink d;
	d.setName("Water");
	d.setAlcoholPercent(0);
	d.setCount(100);
	d.setPrice(2.80);

	r.addProduct(f);
	r.addProduct(d);
	r.printAll();

	r.changePrice(1, 1.30);

	r.removeProduct(0);
	r.printAll();
	return 0;
}
