#include <iostream>
#include <fstream>

void fileOut(const char* fileName)
{
	std::ofstream outFile(fileName);

	if (!outFile.is_open())
	{
		return;
	}

	int a = 0, b = 0, c = 0;

	std::cin >> a >> b >> c;

	int sum = a + b + c;
	int product = a * b * c;

	outFile << sum <<' '<<product;

	outFile.close();
}

int getDiff(const char* fileName)
{
	std::ifstream inFile(fileName);

	if (!inFile.is_open())
	{
		return -1;
	}

	int a = 0, b = 0;

	inFile >> a >> b;
	
	inFile.close();

	return a - b;
}

int main()
{
	std::cout << getDiff("result.txt");
	return 0;
}
