#include "Tyre.h"
#include <stdexcept>

Tyre::Tyre(const char* newName, const char* newDescription, unsigned newWidth, unsigned newProfile, unsigned newDiameter):CarPart(newName, newDescription)
{
	setWidth(newWidth);
	setProfile(newProfile);
	setDiameter(newDiameter);
}

void Tyre::setWidth(unsigned newWidth)
{
	if (newWidth >= Tyre::MIN_WIDTH && newWidth <= Tyre::MAX_WIDTH)
	{
		width = newWidth;
	}

	else
	{
		throw std::out_of_range("Tyre width is out of range!");
	}
}

void Tyre::setProfile(unsigned newProfile)
{
	if (newProfile >= Tyre::MIN_PROFILE && newProfile <= Tyre::MAX_PROFILE)
	{
		profile = newProfile;
	}

	else
	{
		throw std::out_of_range("Profile size is out of range!");
	}
}

void Tyre::setDiameter(unsigned newDiameter)
{
	if (newDiameter >= Tyre::MIN_DIAMETER && newDiameter <= Tyre::MAX_DIAMETER)
	{
		diameter = newDiameter;
	}

	else
	{
		throw std::out_of_range("Diameter size is out of range!");
	}
}

unsigned Tyre::getWidth() const
{
	return width;
}

unsigned Tyre::getProfile() const
{
	return profile;
}

unsigned Tyre::getDiameter() const
{
	return diameter;
}

std::ostream& operator<<(std::ostream& os, const Tyre& obj)
{
	return os << (CarPart)obj << " - " << obj.width << '/' << obj.profile << 'R' << obj.diameter << std::endl;
}
