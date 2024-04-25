#include "Restaurant.h"
#include <cstring>
#include <iostream>

#pragma warning (disable : 4996)

void Restaurant::copyFrom(const Restaurant& other)
{
	strcpy(name, other.name);
	productsCapacity = other.productsCapacity;
	productsSize = other.productsSize;

	productsList = new MyString[productsCapacity]{};

	for (int i = 0; i < productsSize; i++)
	{
		productsList[i] = other.productsList[i];
	}
}

void Restaurant::moveFrom(Restaurant&& other)
{
	strcpy(name, other.name);
	productsCapacity = other.productsCapacity;
	productsSize = other.productsSize;
	productsList = other.productsList;

	other.productsList = nullptr;
	other.productsCapacity = other.productsSize = 0;
}

void Restaurant::free()
{
	delete[] productsList;
	productsList = nullptr;

	productsCapacity = productsSize = 0;
	name[0] = '\0';
}

void Restaurant::resize(int newCapacity)
{
	MyString* temp = new MyString[newCapacity]{};

	for (int i = 0; i < productsSize; i++)
	{
		temp[i] = productsList[i];
	}

	delete[] productsList;
	productsList = temp;
	temp = nullptr;
	productsCapacity = newCapacity;
}

bool Restaurant::containsProduct(const MyString& product) const
{
	for (int i = 0; i < productsSize; i++)
	{
		if (product == productsList[i])
		{
			return true;
		}
	}
	return false;
}

bool Restaurant::checkAllProducts(const Order& order) const
{
	int productsCount = order.getCount();
	const MyString* products = order.getProductsList();

	for (int i = 0; i < productsCount; i++)
	{
		if (!containsProduct(products[i]))
		{
			return false;
		}
	}
	return true;
}

Restaurant::Restaurant(const Restaurant& other)
{
	copyFrom(other);
}

Restaurant& Restaurant::operator=(const Restaurant& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Restaurant::Restaurant(Restaurant&& other) noexcept
{
	moveFrom(std::move(other));
}

Restaurant& Restaurant::operator=(Restaurant&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Restaurant::~Restaurant() noexcept
{
	free();
}

Restaurant::Restaurant(const char* name, int productsCapacity)
{
	strcpy(this->name, name);
	this->productsCapacity = productsCapacity;
	productsList = new MyString[productsCapacity]{};

}

const char* Restaurant::getName() const
{
	return name;
}

void Restaurant::addProduct(const MyString& newProd)
{
	if (productsSize == productsCapacity)
	{
		resize(2 * productsCapacity);
	}

	if (containsProduct(newProd))
	{
		throw std::invalid_argument("The products is already included in the list!");
	}

	productsList[productsSize++] = newProd;
}

void Restaurant::addProduct(MyString&& newProd)
{
	if (productsSize == productsCapacity)
	{
		resize(2 * productsCapacity);
	}

	if (containsProduct(newProd))
	{
		throw std::invalid_argument("The products is already included in the list!");
	}

	productsList[productsSize++] = std::move(newProd);
}

int Restaurant::deliverOrder(const Order& order) const
{
	if (strcmp(order.getRestaurantName().c_str(), name)!=0)
	{
		throw std::invalid_argument("Invalid restaurant name!");
	}

	if (!checkAllProducts(order))
	{
		throw std::invalid_argument("A products from the order isn't available in the restaurant!");
	}

	return order.getDeliveryTime();
}
