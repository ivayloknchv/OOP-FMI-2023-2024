#include <iostream>
#include <fstream>

int getSymbolsCount(const char* fileName)
{
	std::ifstream inFile(fileName);

	if (!inFile.is_open())
	{
		return -1;
	}

	int counter = 0;

	char ch = 'a';

	while (true)
	{
		ch=inFile.get();

		if (inFile.eof())
		{
			break;
		}	

		if (ch != ' ' && ch != '\n')
		{
			counter++;
		}
	}

	inFile.close();
	return counter;
}

int main()
{
	char myName[] = "zad1.cpp";

	std::cout << getSymbolsCount(myName);
	return 0;
}
