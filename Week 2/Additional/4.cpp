#include <iostream>
#include <fstream>

const char fileName[] = "result1.txt";

void printOnFile(const char* fileName)
{
	std::ofstream outFile(fileName);

	if (!outFile.is_open())
	{
		return;
	}

	int a = 0, b = 0;

	std::cin >> a >> b;

	outFile << a + b << ' ' << a - b;

	outFile.close();
}

void getOriginalNums(const char* fileName)
{
	std::ifstream inFile(fileName);

	if (!inFile.is_open())
	{
		return;
	}

	int x = 0, y = 0;

	inFile >> x >> y;

	std::cout << (x + y) / 2 << ' ' << (x - y) / 2 << std::endl;
}

int main()
{
	printOnFile(fileName);
	getOriginalNums(fileName);
	return 0;
}
