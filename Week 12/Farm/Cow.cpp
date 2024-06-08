#include "Cow.h"
#include <iostream>

Cow::Cow() : Animal(AnimalType::Cow)
{
}

Animal* Cow::clone() const
{
	return new Cow(*this);
}

void Cow::roar() const
{
	std::cout << "Muu muu!" << std::endl;
}
