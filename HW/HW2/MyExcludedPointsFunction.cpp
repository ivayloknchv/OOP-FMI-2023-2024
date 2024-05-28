#include "MyExcludedPointsFunction.h"

void MyExcludedPointsFunction::setExcludedPoints(const int32_t* excludedPoints, int32_t size)
{
	if (!excludedPoints)
	{
		return;
	}

	for (int32_t i = 0; i < size; i++)
	{
		this->excludedPoints[i] = excludedPoints[i];
	}
}

bool MyExcludedPointsFunction::contains(int32_t num) const
{
	for (int32_t i = 0; i < size; i++)
	{
		if (excludedPoints[i] == num)
		{
			return true;
		}
	}
	return false;
}

MyExcludedPointsFunction::MyExcludedPointsFunction(const int32_t* excludedPoints, int32_t size)
{
	this->size = size;
	setExcludedPoints(excludedPoints, size);
}

MyFunction* MyExcludedPointsFunction::clone() const
{
	return new MyExcludedPointsFunction(*this);
}

Pair<bool, int32_t> MyExcludedPointsFunction::operator()(int32_t num) const
{
	if (contains(num))
	{
		return Pair<bool, int32_t>(false,0);
	}
	
	return Pair<bool, int32_t>(true, num);
}
