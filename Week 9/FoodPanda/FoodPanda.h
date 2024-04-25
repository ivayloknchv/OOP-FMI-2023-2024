#pragma once
#include "Restaurant.h"

class FoodPanda
{
private:

	Restaurant* restaurantsList = nullptr;
	int size = 0;
	int capacity = 0;

	void copyFrom(const FoodPanda& other);
	void moveFrom(FoodPanda&& other);
	void free();

	int getRestaurantIdx(const char* currentRestaurant);
	void resize(int newCapacity);

public:

	FoodPanda() = default;
	FoodPanda(const FoodPanda& other);
	FoodPanda& operator=(const FoodPanda& other);
	FoodPanda(FoodPanda&& other) noexcept;
	FoodPanda& operator=(FoodPanda&& other) noexcept;
	~FoodPanda() noexcept;

	FoodPanda(int capacity);

	void addRestaurant(const Restaurant& other);
	void addRestaurant(Restaurant&& other);
	void addProduct(const MyString& productToAdd, const char* restautantToAdd);

	void readOrder(); 
};

