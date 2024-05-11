#include "SortedCollection.h"

int SortedCollection::lowerBound(int num) const
{
	int left = 0;
	int right = size - 1;

	int idx = size;
	while (left <= right)
	{
		int mid = (right - left) / 2 + left;

		if (num > data[mid])
		{
			left = mid + 1;
		}
		else
		{
			idx = mid;
			right = mid - 1;
		}
	}
	return idx;
}

int SortedCollection::upperBound(int num) const
{
	int left = 0;
	int right = size - 1;

	int idx = size;

	while (left <= right)
	{
		int mid = (right - left) / 2 + left;

		if (num < data[mid])
		{
			left = mid + 1;
		}

		else
		{
			right = mid - 1;
			idx = mid;
		}
	}
	return 0;
}

void SortedCollection::add(int num)
{
	if (size == capacity)
	{
		resize(2 * capacity);
	}

	int idx = size;

	while (idx != 0 && data[idx - 1] > num)
	{
		data[idx] = data[idx - 1];
		idx--;
	}
	data[idx] = num;
	size++;
}

void SortedCollection::remove(int num)
{
	int idx = upperBound(num);

	if (idx == size)
	{
		return;
	}

	for (int i = idx; i < size-1; i++)
	{
		data[i] = data[i + 1];
	}

	--size;
}

int SortedCollection::count(int num) const
{
	int lower = lowerBound(num);
	
	if (lower == size)
	{
		return -1;
	}

	int upper = upperBound(num);
	return upper-lower+1;
}

bool SortedCollection::contains(int num) const
{
	return lowerBound(num) != 0;
}
