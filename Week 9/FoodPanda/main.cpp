#include <iostream>
#include "FoodPanda.h"

int main()
{
	try
	{
		FoodPanda fp(3);

		Restaurant r1("restaurant1", 4);
		Restaurant r2("restaurant2", 4);

		fp.addRestaurant(r1);
		fp.addProduct("Pizza", "restaurant1");
		fp.addProduct("Pasta", "restaurant1");
		fp.addRestaurant(r2);
		fp.addProduct("Salad", "restaurant2");
		fp.addProduct("Soup", "restaurant2");
		fp.readOrder();
	}
	catch (std::invalid_argument& e)
	{
		std::cout << e.what();
	}
	catch (std::out_of_range& e)
	{
		std::cout << e.what();
	}
	catch (std::exception& e)
	{
		std::cout << "Something happended...";
	}

	return 0;
}
