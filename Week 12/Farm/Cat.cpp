#include "Cat.h"
#include <iostream>

Cat::Cat() : Animal(AnimalType::Cat)
{
}

Animal* Cat::clone() const
{
	return new Cat(*this);
}

void Cat::roar() const
{
	std::cout << "Meow meow!" << std::endl;
}
