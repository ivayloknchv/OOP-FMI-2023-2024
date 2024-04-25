#include "FoodPanda.h"
#include <cstring>

#pragma warning (disable: 4996)

void FoodPanda::copyFrom(const FoodPanda& other)
{
	size = other.size;
	capacity = other.capacity;
	restaurantsList = new Restaurant[capacity]{};

	for (int i = 0; i < size; i++)
	{
		restaurantsList[i] = other.restaurantsList[i];
	}
}

void FoodPanda::moveFrom(FoodPanda&& other)
{
	size = other.size;
	capacity = other.capacity;
	restaurantsList = other.restaurantsList;

	other.restaurantsList = nullptr;
	other.size = other.capacity = 0;
}

void FoodPanda::free()
{
	delete[] restaurantsList;
	restaurantsList = nullptr;
	size = capacity = 0;
}

int FoodPanda::getRestaurantIdx(const char* currentRestaurant)
{
	for (int i = 0; i < size; i++)
	{
		if (!strcmp(currentRestaurant, restaurantsList[i].getName()))
		{
			return i;
		}
	}
	return size;
}

void FoodPanda::resize(int newCapacity)
{
	Restaurant* temp = new Restaurant[newCapacity]{};

	for (int i = 0; i < capacity; i++)
	{
		temp[i] = restaurantsList[i];
	}

	delete[] restaurantsList;
	restaurantsList = temp;
	temp = nullptr;
	capacity = newCapacity;
}

FoodPanda::FoodPanda(const FoodPanda& other)
{
	copyFrom(other);
}

FoodPanda& FoodPanda::operator=(const FoodPanda& other)
{
	if(this!=&other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

FoodPanda::FoodPanda(FoodPanda&& other) noexcept
{
	moveFrom(std::move(other));
}

FoodPanda& FoodPanda::operator=(FoodPanda&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

FoodPanda::~FoodPanda() noexcept
{
	free();
}

FoodPanda::FoodPanda(int capacity)
{
	this->capacity = capacity;
	restaurantsList = new Restaurant[capacity]{};
}

void FoodPanda::addRestaurant(const Restaurant& other)
{
	int idx = getRestaurantIdx(other.getName());

	if (idx != size)
	{
		throw std::invalid_argument("No such restaurant exists in the system!");
	}

	if (size == capacity)
	{
		resize(2 * capacity);
	}

	restaurantsList[size++] = other;
}

void FoodPanda::addRestaurant(Restaurant&& other)
{
	int idx = getRestaurantIdx(other.getName());

	if (idx != size)
	{
		throw std::invalid_argument("The restaurant already exists in the system!");
	}

	if (size == capacity)
	{
		resize(2 * capacity);
	}

	restaurantsList[size++] = std::move(other);
}

void FoodPanda::addProduct(const MyString& productToAdd, const char* restautantToAdd)
{
	int idx = getRestaurantIdx(restautantToAdd);

	if (idx == size)
	{
		throw std::invalid_argument("No such restaurant exists in the system!");
	}

	restaurantsList[idx].addProduct(productToAdd);
}

void FoodPanda::readOrder()
{
	MyString restName;
	int orderCapacity = 0;
	std::cin >> restName;

	int restIdx = getRestaurantIdx(restName.c_str());

	if ( restIdx == size)
	{
		throw std::invalid_argument("Such restaurant doesn't exist");
	}


	std::cin >> orderCapacity;

	Order currentOrder(restName,orderCapacity);
	MyString product;

	for (int i = 0; i < orderCapacity; i++)
	{
		std::cin >> product;
		currentOrder.addProduct(product);
	}

	int mins = restaurantsList[restIdx].deliverOrder(currentOrder);
	std::cout << "Order from " << restaurantsList[restIdx].getName() << " will be delivered in " << mins << " minutes!";
}
