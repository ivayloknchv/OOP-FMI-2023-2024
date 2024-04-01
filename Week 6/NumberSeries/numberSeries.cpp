#include "numberSeries.h"

void numberSeries::copyFrom(const numberSeries& other)
{
	size = other.size;
	a0 = other.a0;
	formulaPtr = other.formulaPtr;

	series = new int[size];

	for (int i = 0; i < size; i++)
	{
		series[i] = other.series[i];
	}
}

void numberSeries::free()
{
	delete[] series;

	series = nullptr;
	formulaPtr = nullptr;
	a0 = 0;
	size = 0;
	nextIdx = 0;
}

void numberSeries::reAllocateSeries(int newSize)
{
	int* temp = new int[newSize]{};

	for (int i = 0; i < size; i++)
	{
		temp[i] = series[i];
	}

	delete[] series;
	series = temp;
	temp = nullptr;

	size = newSize;
}

void numberSeries::addToSeries(int startIdx)
{
	if (startIdx == 0)
	{
		startIdx++;
	}

	for (int i = nextIdx; i < size; i++)
	{
		series[i] = formulaPtr(series[i - 1]);
	}
	nextIdx = size;
}

numberSeries::numberSeries() = default;

numberSeries::numberSeries(const numberSeries & other)
{
	copyFrom(other);
}

numberSeries& numberSeries::operator=(const numberSeries& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

numberSeries::~numberSeries()
{
	free();
}

numberSeries::numberSeries(int(*formulaPtr)(int), int newStart)
{
	setStart(newStart);
	setFormula(formulaPtr);
}


void numberSeries::setStart(int newStart)
{
	delete[] series;
	series = new int[1];
	a0 = newStart;
	series[0] = a0;
	size = 1;
	nextIdx = 1;
}

void numberSeries::setFormula(int(*newFormulaPtr)(int))
{
	delete[] series;
	formulaPtr = newFormulaPtr;
	series = new int[1];
	series[0] = a0;
	size = 1;
	nextIdx = 1;
}

int numberSeries::getNumByIndex(int idx)
{
	if (idx < size)
	{
		return series[idx];
	}

	reAllocateSeries(idx + 1);

	addToSeries(idx);


	return series[idx];
}

bool numberSeries::isNumInSeries(int n) const
{
	for (int i = 0; i < nextIdx; i++)
	{
		if (series[i] == n)
		{
			return true;
		}
	}
	return false;
}
