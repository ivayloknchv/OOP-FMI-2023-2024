#pragma once
#include "RestaurantItem.h"
#include "Food.h"
#include "Drink.h"

class Restaurant
{
	RestaurantItem** _data = nullptr;
	size_t _size = 0;
	size_t _capacity = 0;

	void copyFrom(const Restaurant& other);
	void moveFrom(Restaurant&& other);
	void free();

	void resize(size_t newCapacity);

public:

	Restaurant();
	Restaurant(const Restaurant& other);
	Restaurant& operator=(const Restaurant& other);
	Restaurant(Restaurant&& other) noexcept;
	Restaurant& operator=(Restaurant&& other) noexcept;
	~Restaurant();

	void addProduct(const RestaurantItem& other);
	void removeProduct(size_t idx);
	void changePrice(size_t idx, double newPrice);
	void changeName(size_t idx, const char* newName);

	void printAll() const;
	void printAllSoftDrinks() const;
};

