#pragma once

class Observer
{
	void copyFrom(const Observer& other);
	void moveFrom(Observer&& other);
	void free();

protected:

	char* name = nullptr;
	char* city = nullptr;
	double temperature = 0;

public:

	Observer(const char* name, const char* city, double temperature);
	Observer(const Observer& other);
	Observer& operator=(const Observer& other);
	Observer(Observer&& other) noexcept;
	Observer& operator=(Observer&& other) noexcept;
	virtual ~Observer();


	void setName(const char* name);
	void setCity(const char* city);
	void setTemperature(double temperature);

	virtual Observer* clone() const = 0;

	virtual void update(const char* city, double temperature) = 0;
	virtual void printMeteo() const = 0;
};
