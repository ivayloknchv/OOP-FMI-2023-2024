#include "FuelTank.h"
#include <stdexcept>

FuelTank::FuelTank(double newCapacity)
{
	capacity = newCapacity;
	quantity = capacity;
}

void FuelTank::use(double toUse)
{
	if (toUse > quantity)
	{
		throw std::logic_error("insufficient_fuel_error");
	}

	quantity -= toUse;
}

void FuelTank::fill(double toFill)
{
	if (toFill + quantity > capacity)
	{
		quantity = capacity;

		return;
	}

	quantity += toFill;
}

double FuelTank::getQuantity() const
{
	return quantity;
}

double FuelTank::getCapacity() const
{
	return capacity;
}
