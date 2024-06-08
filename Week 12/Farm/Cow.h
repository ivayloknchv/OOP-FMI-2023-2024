#pragma once
#include "Animal.h"

class Cow : public Animal
{
public:

	Cow();
	Animal* clone() const override;
	void roar() const override;
};

