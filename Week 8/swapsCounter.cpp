#pragma once
#include <iostream>

class swapsCounter
{
private:
	static int counter;

public:

	static void swap(int& a, int& b)
	{
		int temp = a;
		a = b;
		b = temp;
		counter++;
	}

	static int getCounter()
	{
		return counter;
	}

	static void reset()
	{
		counter = 0;
	}
};

int swapsCounter::counter = 0;

void bubbleSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		bool isSwapped = false;

		for (int j = i + 1; j < size - i - 1; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				swapsCounter::swap(arr[j + 1], arr[j]);
				isSwapped = true;
			}
		}
		if (!isSwapped)
		{
			return;
		}
	}
}

void selectionSort(int* arr, int size)
{
	int min_idx = 0;

	for (int i = 0; i < size - 1; i++)
	{
		min_idx = i;

		for (int j = i + 1; j < size; j++)
		{
			if (arr[min_idx] > arr[j])
			{
				min_idx = j;
			}
		}

		if (i != min_idx)
		{
			swapsCounter::swap(arr[min_idx], arr[i]);
		}
	}
}

int main()
{
	{
		int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
		bubbleSort(arr, 10);
		std::cout << "Bubble sort swaps: " << swapsCounter::getCounter() << std::endl;
	}
	{
		swapsCounter::reset();
		int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
		selectionSort(arr, 10);
		std::cout << "Selection sort swaps: " << swapsCounter::getCounter() << std::endl;
	}
	return 0;
}
