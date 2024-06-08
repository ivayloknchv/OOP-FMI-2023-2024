#pragma once

enum class AnimalType
{
	Dog,
	Cat,
	Cow
};

class Animal
{
private:
	AnimalType type;

public:

	Animal(AnimalType type);

	virtual Animal* clone() const = 0;
	virtual ~Animal() = default;

	virtual void roar() const =0;

	AnimalType getType() const;
};

