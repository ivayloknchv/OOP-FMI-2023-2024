#pragma once
#include "Animal.h"

class Cat : public Animal
{
public:

	Cat();

	Animal* clone() const override;

	void roar() const override;
};

