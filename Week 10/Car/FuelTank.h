#pragma once

class FuelTank
{
private:

	double quantity = 0;
	double capacity = 0;

public:
	
	FuelTank() = default;
	FuelTank(double newCapacity);

	void use(double toUse);
	void fill(double toFill);

	double getQuantity() const;
	double getCapacity() const;
};

