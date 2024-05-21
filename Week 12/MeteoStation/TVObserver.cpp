#include "TVObserver.h"
#include <iostream>

TVObserver::TVObserver(const char* name, const char* city, double temperature) : Observer(name, city, temperature)
{
}

void TVObserver::update(const char* city, double temperature)
{
	setCity(city);
	setTemperature(temperature);

	std::cout << "Update " << name << ": The temperature in city " << city << " is " << temperature << std::endl;
}

Observer* TVObserver::clone() const
{
	return new TVObserver(*this);
}

void TVObserver::printMeteo() const
{
	std::cout << "TV " << name << ": The temperature in city " << city << " is " << temperature << std::endl;
}
