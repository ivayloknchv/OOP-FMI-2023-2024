#include "Bar.h"
#include <stdexcept>

static int getMaxIdx(const int* arr, int size)
{
	int toReturn = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[toReturn] < arr[i])
		{
			toReturn = i;
		}
	}
	return toReturn;
}

void Bar::addDrink(const char* name, int ml, int count)
{
	if (drinkSize == MAX_SIZE)
	{
		return;
	}

	drinks[drinkSize] = Drink(name, ml);
	drinkCount[drinkSize] = count;
	drinkSize++;
}

void Bar::addAlcDrink(const char* name, int ml, int percent, int count)
{
	if (alcSize == MAX_SIZE)
	{
		return;
	}

	alcDrinks[alcSize] = Alcohol(name, ml, percent);
	alcCount[alcSize] = count;
	alcSize++;
}

const Drink& Bar::getDrink()
{
	int idx = getMaxIdx(drinkCount, drinkSize);

	if (drinkCount[idx] == 0)
	{
		throw std::logic_error("No drink in the bar left!");
	}

	drinkCount[idx]--;
	stat.drinksSold++;
	stat.mlSold += drinks[idx].getMl();

	return drinks[idx];
}

const Alcohol& Bar::getAlcDrink()
{
	int idx = getMaxIdx(alcCount, alcSize);

	if (alcCount[idx] == 0)
	{
		throw std::logic_error("No drink in the bar left!");
	}

	alcCount[idx]--;
	stat.alcSold++;
	stat.mlSold += alcDrinks[idx].getMl();

	return alcDrinks[idx];
}

int Bar::getDrinksSold() const
{
	return stat.drinksSold;
}

int Bar::getAlcSold() const
{
	return stat.alcSold;
}

int Bar::getMlSold() const
{
	return stat.mlSold;
}


