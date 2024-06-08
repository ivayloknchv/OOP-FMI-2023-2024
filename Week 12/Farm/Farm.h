#pragma once
#include "Animal.h"
#include "AnimalFactory.h"

class Farm
{
	Animal** data = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void copyFrom(const Farm& other);
	void moveFrom(Farm&& other);
	void free();
	void resize(size_t newCapacity);

public:

	Farm();
	Farm(const Farm& other);
	Farm& operator=(const Farm& other);
	Farm(Farm&& other) noexcept;
	Farm& operator=(Farm&& other) noexcept;
	~Farm();

	void addAnimal(AnimalType type);

	void addAnimal(const Animal& other);

	void roarAll() const;

	AnimalType getTypeByIndex(size_t idx);
};

