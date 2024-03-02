#include <iostream>
#include <fstream>

const unsigned MAX_SIZE = 25;

struct pair 
{
	int x;
	int y;
};

struct relation
{
	unsigned size=0;
	pair arr[MAX_SIZE]{};
};

pair createPair(int x, int y)
{
	return { x,y };
}

void initPair(pair& toInit, int x, int y)
{
	toInit.x = x;
	toInit.y = y;
}

pair readPairFromFile(std::ifstream& inFile)
{
	int x = 0, y = 0;

	inFile >> x;
	inFile.ignore();
	inFile >> y;
	
	return createPair(x, y);
}

void writePairToFile(std::ofstream& outFile, const pair& toWrite)
{
	outFile << toWrite.x << ',' << toWrite.y << '\n';
}

bool addPair(relation& arg, pair& toInsert)
{
	if (arg.size == MAX_SIZE)
	{
		return false;
	}

	arg.arr[arg.size] = toInsert;

	arg.size++;

	return true;
}

bool writeRelation(const relation& arg, const char* filePath)
{
	std::ofstream outFile(filePath);

	if (!outFile.is_open())
	{
		return false;
	}

	for (unsigned i = 0; i < arg.size; i++)
	{
		writePairToFile(outFile, arg.arr[i]);
	}

	outFile.close();
	return false;
}

bool readRelation(relation& arg, const char* filePath)
{
	std::ifstream inFile(filePath);

	if (!inFile.is_open())
	{
		return false;
	}

	while (true)
	{
		pair temp = readPairFromFile(inFile);

		if (inFile.eof())
		{
			break;
		}

		if (!addPair(arg, temp))
		{
			break;
		}
	}
	return true;
}

int main()
{
	return 0;
}