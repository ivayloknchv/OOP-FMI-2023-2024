#include <iostream>
#include <fstream>

const unsigned MAX_SIZE = 1024;

unsigned getSize(const char* str)
{
	if (!str)
	{
		return 0;
	}

	unsigned size = 0;

	while (*str != '\0')
	{
		size++;
		str++;
	}

	return size;
}

void addToNewFile(std::ofstream& outFile, const char* str)
{
	if (!str)
	{
		return;
	}

	unsigned size = getSize(str);

	for (int i = size - 1; i >= 0; i--)
	{
		outFile << str[i];
	}

	outFile << '\n';
}
void reverse(const char* original, const char* reverse)
{
	if (!original || !reverse)
	{
		return;
	}

	std::ifstream inFile(original);
	std::ofstream outFile(reverse);

	if (!inFile.is_open() || !outFile.is_open())
	{
		return;
	}

	char buffer[MAX_SIZE] = {};

	while (true)
	{
		inFile.getline(buffer, MAX_SIZE);

		addToNewFile(outFile, buffer);

		if (inFile.eof())
		{
			break;
		}	
	}

	inFile.close();
	outFile.close();
}

int main()
{
	reverse("original.txt", "reverse.txt");
	return 0;
}
