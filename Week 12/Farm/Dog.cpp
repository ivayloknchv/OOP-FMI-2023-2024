#include "Dog.h"
#include <iostream>

Dog::Dog() : Animal(AnimalType::Dog)
{
}

Animal* Dog::clone() const
{
	return new Dog(*this);
}

void Dog::roar() const
{
	std::cout << "Woof woof!"<<std::endl;
}
