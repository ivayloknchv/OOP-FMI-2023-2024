#include "NormalCollection.h"
#include <utility>

void NormalCollection::add(int num)
{
	if (size == capacity)
	{
		resize(2 * capacity);
	}

	data[size++] = num;
}

void NormalCollection::remove(int num)
{
	int idx = -1;

	for (int i = 0; i < size; i++)
	{
		if (data[i] == num)
		{
			idx = i;
			break;
		}
	}

	if (idx == -1)
	{
		return;
	}
	std::swap(data[idx], data[size - 1]);
	--size;
}

int NormalCollection::count(int num) const
{
	int toReturn = 0;

	for (int i = 0; i < size; i++)
	{
		if (data[i] == num)
		{
			toReturn++;
		}
	}
	return toReturn;
}

bool NormalCollection::contains(int num) const
{
	for (int i = 0; i < size; i++)
	{
		if (data[i] == num)
		{
			return true;
		}
	}
	return false;
}
