#pragma once
#include "CarPart.h"

class Tyre: public CarPart
{
private:

	static constexpr unsigned MIN_WIDTH = 155;
	static constexpr unsigned MAX_WIDTH = 365;

	static constexpr unsigned MIN_PROFILE = 30;
	static constexpr unsigned MAX_PROFILE = 80;

	static constexpr unsigned MIN_DIAMETER = 13;
	static constexpr unsigned MAX_DIAMETER = 21;

	unsigned width = 0;
	unsigned profile = 0;
	unsigned diameter = 0;
public:

	Tyre(const char* newName, const char* newDescription, unsigned newWidth, unsigned newProfile, unsigned newDiameter);

	void setWidth(unsigned newWidth);
	void setProfile(unsigned newProfile);
	void setDiameter(unsigned newDiameter);

	unsigned getWidth() const;
	unsigned getProfile() const;
	unsigned getDiameter() const;

	friend std::ostream& operator<<(std::ostream& os, const Tyre& obj);
};

