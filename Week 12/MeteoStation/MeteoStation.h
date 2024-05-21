#pragma once
#include "Observer.h"

class MeteoStation
{
	char* city = nullptr;
	double temperature = 0;

	Observer** list = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void copyFrom(const MeteoStation& other);
	void moveFrom(MeteoStation&& other);
	void free();

	void resize(size_t newCapacity);


	size_t findObserver(const Observer* obj) const;
public:

	MeteoStation(const char* city, double temperature);
	MeteoStation(const MeteoStation& other);
	MeteoStation& operator=(const MeteoStation& other);
	MeteoStation(MeteoStation&& other) noexcept;
	MeteoStation& operator=(MeteoStation&& other) noexcept;
	~MeteoStation();

	void setCity(const char* city);
	void setTemperature(double temperature);

	const char* getCity() const;
	double getTemperature() const;

	void registerObserver(Observer* obj);
	void unregisterObserver(Observer* obj);

	void notify();

};

