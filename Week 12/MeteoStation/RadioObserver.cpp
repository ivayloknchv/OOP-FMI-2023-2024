#include "RadioObserver.h"
#include <iostream>

RadioObserver::RadioObserver(const char* name, const char* city, double temperature) : Observer(name, city, temperature)
{
}

void RadioObserver::update(const char* city, double temperature)
{
	setCity(city);
	setTemperature(temperature);

	std::cout << "Update " << name << ": The temperature in city " << city << " is " << temperature << std::endl;
}

Observer* RadioObserver::clone() const
{
	return new RadioObserver(*this);
}

void RadioObserver::printMeteo() const
{
	std::cout << "Radio " << name << ": The temperature in city " << city << " is " << temperature << std::endl;
}
