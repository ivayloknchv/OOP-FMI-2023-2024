#pragma once
#include "Animal.h"

class Dog : public Animal
{
public:

	Dog();

	Animal* clone() const override;

	void roar() const override;
};

