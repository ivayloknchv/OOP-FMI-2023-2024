#pragma once
#include "CarPart.h"

class Engine : public CarPart
{
private:
	unsigned horsePowers = 0;

public:

	Engine(const char* newName, const char* newDescription, unsigned newHorsePowers);

	void setHorsePowers(unsigned newHorsePowers);
	unsigned getHorsePowers() const;

	friend std::ostream& operator<<(std::ostream& os, const Engine& obj);
};

