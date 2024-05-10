#include <iostream>
#include "CommisionEmployee.h"
#include "HourlyEmployee.h"

Employee* createEmployee(std::istream& is)
{
	Employee* toReturn = 0;

	char symbol;
	char name[1024]{};
	double salary = 0;
	double data = 0;

	is >> symbol >> name >> salary >> data;

	if (symbol == 'h')
	{
		toReturn = new HourlyEmployee(name, salary, data);
	}

	else if (symbol == 'c')
	{
		toReturn = new CommisionEmployee(name, salary, data);
	}

	return toReturn;
}

void sortBySalary(Employee** arr, int size)
{
	if (!arr)
	{
		return;
	}

	int min_idx = 0;

	for (int i = 0; i < size; i++)
	{
		min_idx = i;

		for (int j = i + 1; j < size; j++)
		{
			if (arr[min_idx]->getSalary() > arr[j]->getSalary())
			{
				min_idx = j;
			}
		}

		if (min_idx != i)
		{
			std::swap(*arr[min_idx], *arr[i]);
		}
	}
}

double getMinSalary(const Employee* const * arr, int size)
{
	if (!arr)
	{
		return 0;
	}

	int min = arr[0]->getSalary();

	for (int i = 1; i < size; i++)
	{
		if (arr[i]->getSalary() < min)
		{
			min = arr[i]->getSalary();
		}
	}

	return min;
}

double getMaxSalary(const Employee* const* arr, int size)
{
	if (!arr)
	{
		return 0;
	}

	int max = arr[0]->getSalary();

	for (int i = 1; i < size; i++)
	{
		if (arr[i]->getSalary() > max)
		{
			max = arr[i]->getSalary();
		}
	}

	return max;
}

double getAvgSalary(const Employee* const* arr, int size)
{
	if (!arr)
	{
		return 0;
	}

	double toReturn = 0;

	for (int i = 0; i < size; i++)
	{
		toReturn += arr[i]->getSalary();
	}

	toReturn /= size;

	return toReturn;
}

const Employee* findClosestToAvg(const Employee* const* arr, int size)
{
	if (!arr)
	{
		return 0;
	}

	double avg = getAvgSalary(arr, size);

	int closest = 0;

	for (int i = 0; i < size; i++)
	{
		if (std::abs(avg - arr[i]->getSalary()) < arr[closest]->getSalary())
		{
			closest = i;
		}
	}

	return arr[closest];
}

void freeEmployees(Employee** arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		delete arr[i];
	}

	delete[] arr;
}

int main()
{
	return 0;
}