#include <iostream>
#include <fstream>

const unsigned MAX_SIZE = 64;
const char* fileName = "list.txt";

void fillArrFromFile(int arr[], unsigned& size,const char* fileName)
{
	std::ifstream inFile(fileName);

	if (!inFile.is_open())
	{
		return;
	}

	int temp = 0;

	while (true)
	{
		inFile >> temp;

		arr[size++] = temp;

		if (inFile.eof())
		{
			break;
		}

	}

	inFile.close();
}

int getMostFreq(int arr[], const unsigned size)
{
	bool* histogram = new bool[size] {};

	int currentCount = 1;
	int maxCount = 1;
	int mostFreqNum = arr[0];

	for (unsigned i = 0; i < size-1; i++)
	{
		if (histogram[i])
		{
			continue;
		}

		for (unsigned j = i + 1; j < size; j++)
		{
			if ((arr[i] == arr[j]) && (histogram[j]==false))
			{
				histogram[j] = true;
				currentCount++;
			}
		}

		if (currentCount > maxCount)
		{
			maxCount = currentCount;
			mostFreqNum = arr[i];
		}

		currentCount = 1;
	}

	delete[] histogram;
	return mostFreqNum;
}

int main()
{
	int arr[MAX_SIZE] = {};

	unsigned size = 0;

	fillArrFromFile(arr, size, fileName);

	std::cout << getMostFreq(arr, size);

	return 0;
}
