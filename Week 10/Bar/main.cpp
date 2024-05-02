#include <iostream>
#include "Bar.h"

int main()
{
	Bar b;

	b.addDrink("Coke", 330, 2); 

	b.addDrink("Fanta", 500);  

	b.addAlcDrink("Zagorka", 500,5); 

	b.getAlcDrink(); 

	b.getDrink(); 
	b.getDrink(); 
	b.getDrink(); 
	b.getDrink();
	std::cout << b.getAlcSold() << std::endl; 
	std::cout << b.getMlSold() << std::endl; 

	return 0;
}
