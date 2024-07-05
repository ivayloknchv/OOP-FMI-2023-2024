#include "ModifiableIntegersFunction.h"
#include <iostream>
#include <exception>

short defaultFunc(short num)
{
	return num;
}

void ModifiableIntegersFunction::generateValues()
{
	int counter = 0;

	for (int i = minVal; i <=maxVal; i++)
	{
		values[counter++] = func(i);
	}
}

void ModifiableIntegersFunction::countFunctionalValues(int* helperMap) const
{
	if (!helperMap)
	{
		return;
	}

	for (int i = minVal; i <= maxVal; i++)
	{
		if (!excludedPoints[index(i)])
		{
			helperMap[values[index(i)] - minVal] ++;;
		}
	}
}

void ModifiableIntegersFunction::writeToBinaryFile(std::ofstream& ofs) const
{
	ofs.write((const char*)values, capacity * sizeof(short));
	ofs.write((const char*)excludedPoints, capacity * sizeof(bool));
}

void ModifiableIntegersFunction::readFromBinaryFile(std::ifstream& ifs)
{
	func = defaultFunc; // we set a default func ptr
	ifs.read((char*)values, capacity * sizeof(short));
	ifs.read((char*)excludedPoints, capacity * sizeof(bool));
}

int ModifiableIntegersFunction::index(int num) const
{
	return num - minVal;
}

ModifiableIntegersFunction::ModifiableIntegersFunction(): ModifiableIntegersFunction(defaultFunc)
{
}

ModifiableIntegersFunction::ModifiableIntegersFunction(short(*func)(short num))
{
	if (!func)
	{
		throw std::runtime_error("Nullptr!");
	}

	this->func = func;
	generateValues();
}

void ModifiableIntegersFunction::excludePoint(short num)
{
	excludedPoints[index(num)] = true;
}

void ModifiableIntegersFunction::writeToBinaryFile(const char* filePath) const
{
	if (!filePath)
	{
		throw std::runtime_error("Nullptr detected");
	}

	std::ofstream ofs(filePath, std::ios::binary);

	if (!ofs.is_open())
	{
		throw std::runtime_error("File cannot be open");
	}

	writeToBinaryFile(ofs);

	ofs.close();
}

void ModifiableIntegersFunction::readFromBinaryFile(const char* filePath)
{
	if (!filePath)
	{
		throw std::runtime_error("Nullptr detected");
	}

	std::ifstream ifs(filePath, std::ios::binary);

	if (!ifs.is_open())
	{
		throw std::runtime_error("File cannot be open");
	}

	readFromBinaryFile(ifs);

	ifs.close();
}

void ModifiableIntegersFunction::predifineValue(short x, short y)
{
	excludedPoints[index(x)] = false;
	values[index(x)] = y;
}

void ModifiableIntegersFunction::drawGraph(short xStart, short yStart) const
{
	for (int y = yStart + 10; y > yStart - 10; y--)
	{
		for (int x = xStart - 10; x < xStart + 10; x++)
		{
			if (values[index(x)] == y && !excludedPoints[index(x)])
			{
				std::cout << "*";
			}
			else if (x == 0)
			{
				std::cout << "|";
			}
			else if (y == 0)
			{
				std::cout << "-";
			}
			else
			{
				std::cout << " ";
			}
		}
		std::cout<<std::endl;
	}
}

bool ModifiableIntegersFunction::isInjective() const
{
	int helperMap[capacity]{}; // keeps the count of all functional values

	countFunctionalValues(helperMap);

	for (int i = 0; i < capacity; i++)
	{
		if (helperMap[i] > 1)
		{
			return false;
		}
	}

	return true;
}

bool ModifiableIntegersFunction::isSurjective() const
{
	int helperMap[capacity]{}; // keeps the count of all functional values

	countFunctionalValues(helperMap);

	for (int i = 0; i < capacity; i++)
	{
		if (helperMap[i] == 0)
		{
			return false;
		}
	}

	return true;
}

bool ModifiableIntegersFunction::isBijective() const
{
	//we can return isInjective() && isSurejctive() but it's slower

	int helperMap[capacity]{}; 

	countFunctionalValues(helperMap);

	for (int i = 0; i < capacity; i++)
	{
		if (helperMap[i] != 1)
		{
			return false;
		}
	}
	return true;
}

ModifiableIntegersFunction& ModifiableIntegersFunction::operator+=(const ModifiableIntegersFunction& other)
{
	for (unsigned i = 0; i < capacity; i++)
	{
		values[i] += other.values[i];

		if (excludedPoints[i] || other.excludedPoints[i])
		{
			excludedPoints[i] = true;
		}
	}
	return *this;
}

ModifiableIntegersFunction& ModifiableIntegersFunction::operator-=(const ModifiableIntegersFunction& other)
{
	for (unsigned i = 0; i < capacity; i++)
	{
		values[i] -= other.values[i];

		if (excludedPoints[i] || other.excludedPoints[i])
		{
			excludedPoints[i] = true;
		}
	}

	return *this;
}

ModifiableIntegersFunction& ModifiableIntegersFunction::operator()(const ModifiableIntegersFunction& other)
{
	for (unsigned i = 0; i < capacity; i++)
	{
		values[i] = func(other.values[i]);

		if (excludedPoints[i] || other.excludedPoints[i])
		{
			excludedPoints[i] = true;
		}
	}
	return *this;
}

ModifiableIntegersFunction operator+(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs)
{
	ModifiableIntegersFunction toReturn(lhs);
	toReturn += rhs;
	return toReturn;
}

ModifiableIntegersFunction operator-(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs)
{
	ModifiableIntegersFunction toReturn(lhs);
	toReturn -= rhs;
	return toReturn;
}

ModifiableIntegersFunction operator~(const ModifiableIntegersFunction& other)
{
	if (!other.isInjective())
	{
		throw std::invalid_argument("Your function isn't injective");
	}
	ModifiableIntegersFunction toReturn;

	for (int i = 0; i <ModifiableIntegersFunction::capacity; i++)
	{
		short currentX = i + ModifiableIntegersFunction::minVal;
		int currentY = other.values[i];

		toReturn.values[other.index(currentY)] = currentX;

		if (other.excludedPoints[i])
		{
			toReturn.excludedPoints[other.index(currentY)] = true;
		}
	}

	return toReturn;
}

bool operator<(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs)
{
	for (int i = 0; i < ModifiableIntegersFunction::capacity; i++)
	{
		if (lhs.excludedPoints[i] == false && rhs.excludedPoints[i] == true)
		{
			return false;
		}
		if (lhs.values[i] >= rhs.values[i] && lhs.excludedPoints[i] == false && rhs.excludedPoints[i] == false)
		{
			return false;
		}
	}
	return true;
}

bool operator<=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs)
{	
	for (int i = 0; i < ModifiableIntegersFunction::capacity; i++)
	{
		if (lhs.excludedPoints[i] == false && rhs.excludedPoints[i] == true)
		{
			return false;
		}
		if (lhs.values[i] > rhs.values[i] && lhs.excludedPoints[i] == false && rhs.excludedPoints[i] == false)
		{
			return false;
		}
	}
	return true;
}

bool operator>=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs)
{
	for (int i = 0; i < ModifiableIntegersFunction::capacity; i++)
	{
		if (lhs.excludedPoints[i] == true && rhs.excludedPoints[i] == false)
		{
			return false;
		}
		if (lhs.values[i] < rhs.values[i] && lhs.excludedPoints[i] == false && rhs.excludedPoints[i] == false)
		{
			return false;
		}
	}
	return true;
}

bool operator>(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs)
{
	for (int i = 0; i < ModifiableIntegersFunction::capacity; i++)
	{
		if (lhs.excludedPoints[i] == true && rhs.excludedPoints[i] == false)
		{
			return false;
		}
		if (lhs.values[i] <= rhs.values[i] && lhs.excludedPoints[i] == false && rhs.excludedPoints[i] == false)
		{
			return false;
		}
	}
	return true;
}

bool operator==(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs)
{
	for (int i = 0; i < ModifiableIntegersFunction::capacity; i++)
	{
		if (lhs.excludedPoints[i] && rhs.excludedPoints[i])
		{
			continue;
		}

		if (lhs.excludedPoints[i] || rhs.excludedPoints[i])
		{
			return false;
		}

		else if (lhs.values[i] != rhs.values[i])
		{
			return false;
		}
	}

	return true;
}

bool operator!=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs)
{
	return !(lhs == rhs);
}

bool operator||(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs)
{
	short diff = 0;
	bool isDiffSet = false;
	
	for (int i = 0; i < ModifiableIntegersFunction::capacity; i++)
	{
		if (lhs.excludedPoints[i] && rhs.excludedPoints[i])
		{
			continue;
		}

		if (lhs.excludedPoints[i] || rhs.excludedPoints[i])
		{
			return false;
		}
		
		if (!isDiffSet) //we compare all diffs with the diff of the first pair of non-excluded values
		{
			diff = lhs.values[i] - rhs.values[i];
			isDiffSet = true;
		}

		else if(lhs.values[i]-rhs.values[i] !=diff)
		{
			return false;
		}
	}

	return true;
}

ModifiableIntegersFunction operator^(const ModifiableIntegersFunction& func, short k)
{
	ModifiableIntegersFunction toReturn = func;

	if (k == 1)
	{
		return toReturn;
	}

	for (short i = 1; i <= k; i++)
	{
		toReturn(toReturn);
	}

	return toReturn;
}
