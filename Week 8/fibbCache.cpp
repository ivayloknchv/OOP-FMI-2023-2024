#include <iostream>
#include <exception>

class NumbersCache
{
private:

	const static int MAX_SIZE = 100;
	int arr[MAX_SIZE]{};
	int size = 0;

public:

	NumbersCache()
	{
		for (int i = 0; i < MAX_SIZE; i++)
		{
			arr[i] = -1;
		}
	}

	bool isEmpty() const
	{
		return (size == 0);
	}

	int get(int index) const
	{
		if (index >= MAX_SIZE || arr[index] == -1)
		{
			throw std::exception("Out of range!");
		}

		return arr[index];
	}

	void insert(int index, int num)
	{
		if (index >= MAX_SIZE)
		{
			throw std::exception("Out of range!");
		}

		if (arr[index] == -1)
		{
			size++;
		}

		arr[index] = num;
	}

	bool contains(int index) const
	{
		if (index >= MAX_SIZE)
		{
			throw std::exception("Out of range!");
		}

		return (arr[index] != -1);
	}
};

int fibb(int index)
{
	NumbersCache fibbCache;
	
	if (fibbCache.isEmpty())
	{
		fibbCache.insert(0, 0);
		fibbCache.insert(1, 1);
	}

	if(!fibbCache.contains(index))
	{
		fibbCache.insert(index, fibb(index-1)+fibb(index-2));
	}

	return fibbCache.get(index);
}

int main()
{
	try
	{
		std::cout << fibb(10);
	}

	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
	return 0;
}
