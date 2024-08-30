#include "Restaurant.h"
#include <utility>
#include <iostream>

void Restaurant::copyFrom(const Restaurant& other)
{
	_size = other._size;
	_capacity = other._capacity;
	_data = new RestaurantItem*[_capacity]{};

	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = other._data[i]->clone();
	}
}

void Restaurant::moveFrom(Restaurant&& other)
{
	_data = other._data;
	other._data = nullptr;

	_size = other._size;
	other._size = 0;

	_capacity = other._capacity;
	other._capacity = 0;
}

void Restaurant::free()
{
	for (size_t i = 0; i < _size; i++)
	{
		delete _data[i];
	}

	delete[] _data;
	
	_data = nullptr;

	_size = 0;
	_capacity = 0;
}

void Restaurant::resize(size_t newCapacity)
{
	RestaurantItem** temp = new RestaurantItem * [newCapacity] {};

	for (size_t i = 0; i < _size; i++)
	{
		temp[i] = _data[i];
	}

	delete[] _data;
	_data = temp;
	temp = nullptr;
	_capacity = newCapacity;
}

Restaurant::Restaurant()
{
	_capacity = 8;

	_data = new RestaurantItem * [_capacity] {};
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

Restaurant::~Restaurant()
{
	free();
}

void Restaurant::addProduct(const RestaurantItem& other)
{
	if (_size == _capacity)
	{
		resize(2 * _size);
	}

	_data[_size++] = other.clone();
}

void Restaurant::removeProduct(size_t idx)
{
	if (idx < 0 || idx >= _size)
	{
		return;
	}

	std::swap(_data[idx], _data[_size - 1]);
	delete _data[_size-1];
	--_size;
}

void Restaurant::changePrice(size_t idx, double newPrice)
{
	if (idx < 0 || idx >= _size)
	{
		return;
	}

	_data[idx]->setPrice(newPrice);
}

void Restaurant::changeName(size_t idx, const char* newName)
{
	if (idx < 0 || idx >= _size || !newName)
	{
		return;
	}

	_data[idx]->setName(newName);
}

void Restaurant::printAll() const
{
	for (size_t i = 0; i < _size; i++)
	{
		_data[i]->print();
		if (i != _size - 1)
		{
			std::cout << "--------------------"<<std::endl;
		}
	}
}

void Restaurant::printAllSoftDrinks() const
{
	Drink validator;
	validator.setAlcoholPercent(0);

	bool flag = false;

	for (size_t i = 0; i < _size; i++)
	{
		if (_data[i]->getProduct() == Product::DRINK)
		{
			if (!(*dynamic_cast<Drink*>(_data[i]) > validator))
			{
				if (flag)
				{
					std::cout << "---------------------" << std::endl;
				}

				_data[i]->print();

				flag = true;
			}
		}
	}
}
