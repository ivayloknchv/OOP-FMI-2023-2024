#include <iostream>

const int MAX_SIZE = 10;

struct Triplet{
	int first;
	int second;
	int third;
};

Triplet readTriplet()
{
	Triplet tr;
	std::cin >> tr.first;
	std::cin >> tr.second;
	std::cin >> tr.third;

	return tr;
}

int Compare(const Triplet& lhs, const Triplet& rhs)
{
	if (lhs.first == rhs.first)
	{
		if (lhs.second == rhs.second)
		{
			return (lhs.third - rhs.third);
		}
		return (lhs.second - rhs.second);
	}
	return (lhs.first - rhs.first);
}

int findMinTripletIndex(const Triplet* triplets, int size)
{
	if (!triplets)
	{
		return -1;
	}
	int minIndex = 0;

	for (int i= 1; i < size; i++)
	{
		if (Compare(triplets[minIndex], triplets[i])>0)
		{
			minIndex = i;
		}
	}

	return minIndex;
}

int findMaxTripletIndex(const Triplet* triplets, int size)
{
	if (!triplets)
	{
		return -1;
	}
	int maxIndex = 0;

	for (int i = 1; i < size; i++)
	{
		if (Compare(triplets[maxIndex], triplets[i]) < 0)
		{
			maxIndex = i;
		}
	}

	return maxIndex;
}
void printTriplet(const Triplet trip)
{
	std::cout <<'('<<trip.first << ',' << trip.second << ',' << trip.third<<')';
}
int main()
{
	Triplet tripArr[MAX_SIZE] = {};
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		tripArr[i] = readTriplet();
	}

	std::cout << "Min triplet: ";
	Triplet minTrip = tripArr[findMinTripletIndex(tripArr,n)];
	printTriplet(minTrip);
	
	std::cout << std::endl;

	std::cout << "Max triplet: ";
	Triplet maxTrip = tripArr[findMaxTripletIndex(tripArr, n)];
	printTriplet(maxTrip);

	return 0;
}
