#include "RestaurantItem.h"
#include <iostream>
#include <cstring>

#pragma warning (disable : 4996)

RestaurantItem::RestaurantItem(Product product, const char* name, unsigned count, double price)
{
	setProduct(product);
	setCount(count);
	setPrice(price);
	setName(name);
}

void RestaurantItem::setProduct(Product product)
{
	_product = product;
}

void RestaurantItem::setCount(unsigned count)
{
	_count = count;
}

void RestaurantItem::setPrice(double price)
{
	_price = price;
}

void RestaurantItem::setName(const char* name)
{
	if (!name || _name == name)
	{
		return;
	}

	delete[] _name;
	_name = new char[strlen(name) + 1]{};
	strcpy(_name, name);
}

Product RestaurantItem::getProduct() const
{
	return _product;
}

unsigned RestaurantItem::getCount() const
{
	return _count;
}

double RestaurantItem::getPrice() const
{
	return _price;
}

const char* RestaurantItem::getName() const
{
	return _name;
}

void RestaurantItem::print() const
{
	std::cout << "Name: " << _name << std::endl;
	std::cout <<"Count: "<< _count << std::endl;
	std::cout <<"Price: "<< _price << std::endl;
}

void RestaurantItem::copyFrom(const RestaurantItem& other)
{
	_product = other._product;

	_name = new char[strlen(other._name) + 1]{};
	strcpy(_name, other._name);

	_count = other._count;
	_price = other._price;
}

void RestaurantItem::moveFrom(RestaurantItem&& other)
{
	_product = other._product;
	other._product = Product::DEFAULT;

	_name = other._name;
	other._name = nullptr;

	_count = other._count;
	other._count = 0;

	_price = other._price;
	other._price = 0;
}

void RestaurantItem::free()
{
	_product = Product::DEFAULT;

	delete[] _name;
	_name = nullptr;

	_count = 0;
	_price = 0;
}

RestaurantItem::RestaurantItem(const RestaurantItem& other)
{
	copyFrom(other);
}

RestaurantItem& RestaurantItem::operator=(const RestaurantItem& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

RestaurantItem::RestaurantItem(RestaurantItem&& other) noexcept
{
	moveFrom(std::move(other));
}

RestaurantItem& RestaurantItem::operator=(RestaurantItem&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

RestaurantItem::~RestaurantItem()
{
	free();
}
