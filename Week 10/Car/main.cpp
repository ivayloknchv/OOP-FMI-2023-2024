#include "Car.h"

Car::Car(Engine* engine,Tyre* t1, Tyre* t2, Tyre* t3,Tyre* t4, 
	 Accumulator* accumulator, double dist, double weight, double fuelCapacity): tank(fuelCapacity)
{
	this->engine = engine;
	this->tyres[0] = t1;
	this->tyres[1] = t2;
	this->tyres[2] = t3;
	this->tyres[3] = t4;
	this->accumulator = accumulator;
	this->dist = dist;
	this->weight = weight;
}

const FuelTank& Car::getFuelTank() const
{
	return tank;
}

void Car::drive(double km)
{
	try
	{
		tank.use(km);
	}

	catch (std::logic_error e)
	{
		std::cout<<e.what();
	}

	dist += km;

}

Car* dragRace(Car* car1, Car* car2)
{
	if (!car1 || !car2)
	{
		return nullptr;
	}

	if (car1->getFuelTank().getQuantity() < 0.4)
	{
		return car2;
	}
	else if (car2->getFuelTank().getQuantity() < 0.4)
	{
		return car1;
	}
	else if(car1->getFuelTank().getQuantity() < 0.4 && car2->getFuelTank().getQuantity() < 0.4)
	{
		return nullptr;
	}

	car1->drive(0.4);
	car2->drive(0.4);

	double ratio1 = car1->weight / car1->engine->getHorsePowers();
	double ratio2 = car2->weight / car2->engine->getHorsePowers();

	return (ratio1 > ratio2) ? car1 : car2;
}
