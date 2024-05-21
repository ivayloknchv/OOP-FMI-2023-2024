#include "NewspaperObserver.h"
#include <iostream>

NewspaperObserver::NewspaperObserver(const char* name, const char* city, double temperature) : Observer(name, city, temperature)
{
}

void NewspaperObserver::update(const char* city, double temperature)
{
	setCity(city);
	setTemperature(temperature);

	std::cout << "Update " << name << ": The temperature in city " << city << " is " << temperature << std::endl;
}

Observer* NewspaperObserver::clone() const
{
	return new NewspaperObserver(*this);
}

void NewspaperObserver::printMeteo() const
{
	std::cout << "Newspaper " << name << ": The temperature in city " << city << " is " << temperature << std::endl;
}
