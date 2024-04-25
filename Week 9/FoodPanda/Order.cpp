#include "Order.h"
#include <iostream>
#include <stdexcept>

void Order::copyFrom(const Order& other)
{
	restaurantName = other.restaurantName;
	productsCount = other.productsCount;
	productsList = new MyString[productsCount];
	currentCount = other.currentCount;

	for (int i = 0; i < productsCount; i++)
	{
		productsList[i] = other.productsList[i];
	}
}

void Order::moveFrom(Order&& other)
{
	restaurantName = other.restaurantName;
	productsCount = other.productsCount;
	productsList = other.productsList;
	currentCount = other.currentCount;

	other.productsCount = 0;
	other.currentCount = 0;
	other.productsList = nullptr;
}

void Order::free()
{
	delete[] productsList;
	productsList = nullptr;
	productsCount = 0;
	currentCount = 0;
}

Order::Order(const Order& other)
{
	copyFrom(other);
}

Order& Order::operator=(const Order& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Order::Order(Order&& other) noexcept
{
	moveFrom(std::move(other));
}

Order& Order::operator=(Order&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return*this;
}

Order::~Order() noexcept
{
	free();
}

const MyString& Order::getRestaurantName() const
{
	return restaurantName;
}

int Order::getCount() const
{
	return currentCount;
}

const MyString* Order::getProductsList() const
{
	return productsList;
}

Order::Order(MyString& restaurantName, int productsCount)
{
	this->restaurantName = restaurantName;
	this->productsCount = productsCount;
	productsList = new MyString[productsCount]{};
}

void Order::addProduct(const MyString& newProd)
{
	if (currentCount == productsCount)
	{
		throw std::out_of_range("Order capacity is full!");
	}

	productsList[currentCount++] = newProd;
}

int Order::getDeliveryTime() const
{
	int time = 0;

	for (int i = 0; i < currentCount; i++)
	{
		time += productsList[i].getSize();
	}

	return time;
}
