#include "AnimalFactory.h"

Animal* AnimalFactory::create(AnimalType type)
{
	switch (type)
	{
	case AnimalType::Dog:
		return new Dog();
		break;
	case AnimalType::Cat:
		return new Cat();
		break;
	case AnimalType::Cow:
		return new Cow();
		break;
	default:
		break;
	}
    return nullptr;
}
