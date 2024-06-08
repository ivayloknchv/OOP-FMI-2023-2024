#pragma once
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "Cow.h"

class AnimalFactory
{
public:

	static Animal* create(AnimalType type);
};

