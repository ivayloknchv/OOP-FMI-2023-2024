#include <iostream>
#include "Bar.h"

int main()
{
	Bar b;

	b.addDrink("Coke", 330, 2); //2x Coca cola 330 ml

	b.addDrink("Fanta", 500);   //1x Fanta 500 ml

	b.addAlcDrink("Zagorka", 500,5); //1x Zagorka, 5% alc,  500 ml

	b.getAlcDrink(); // Zagorka 

	b.getDrink(); // Coke
	b.getDrink(); // Coke
	b.getDrink(); // Fanta
	b.getDrink();
	std::cout << b.getAlcSold() << std::endl; // 1
	std::cout << b.getMlSold() << std::endl; // 830

	return 0;
}