#include <iostream>

struct Pair {
	int first;
	int second;
};

Pair readPair()
{
	Pair p;
	std::cin >> p.first;
	std::cin >> p.second;

	return p;
}

int comparePairs(const Pair& lhs, const Pair& rhs)
{
	if (lhs.first == rhs.first)
	{
		return lhs.second - rhs.second;
	}
	return lhs.first - rhs.first;
}

Pair getMax(const Pair arr[], const int size = 100)
{
	int max = 0;

	for (int i = 1; i < size; i++)
	{
		if (comparePairs(arr[max], arr[i])<0)
		{
			max = i;
		}
	}

	return arr[max];
}

void structSwap(Pair& lhs, Pair& rhs)
{
	Pair temp = lhs;
	lhs = rhs;
	rhs = lhs;
}

void selectionSort(Pair* arr, const int size)
{
	if (!arr)
	{
		return;
	}
	int minIdx = 0;
	for (int i = 0; i < size-1; i++)
	{
		minIdx = i;

		for (int j = i + 1; j < size; j++)
		{
			if (comparePairs(arr[minIdx], arr[j])>0)
			{
				minIdx = j;
			}
		}

		if (minIdx != i)
		{
			structSwap(arr[minIdx], arr[i]);
		}
	}
}
int main()
{
	return 0;
}
