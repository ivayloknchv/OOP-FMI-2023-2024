#include <iostream>
#include <fstream>

unsigned getSize(std::ifstream& ifs)
{
	unsigned currentPos = (unsigned)ifs.tellg();

	ifs.seekg(0, std::ios::end);

	unsigned size = (unsigned)ifs.tellg();

	ifs.seekg(0, currentPos);

	return size / sizeof(unsigned);
}

unsigned* readRawMessage(std::ifstream& ifs, unsigned& size)
{
	size = getSize(ifs);

	unsigned* nums = new unsigned[size];

	ifs.read((char*)nums, (long long)size * sizeof(unsigned));

	return nums;
}

unsigned* readRawMessage(const char* rawMessageFileName, unsigned& size)
{
	std::ifstream ifs(rawMessageFileName, std::ios::in | std::ios::binary);

	if (!ifs.is_open())
	{
		return 0;
	}

	return readRawMessage(ifs,size);
}

unsigned readSecretNum(std::ifstream& ifs)
{
	unsigned num;

	ifs.read((char*)&num, sizeof(unsigned));

	return num;
}

unsigned readSecretNum(const char* keyFileName)
{
	std::ifstream ifs(keyFileName, std::ios::in | std::ios::binary);

	if (!ifs.is_open())
	{
		return 0;
	}

	return readSecretNum(ifs);
}

void decypherMessage(const unsigned* nums, const unsigned size, const unsigned secretNum)
{
	for (unsigned i = 0; i < size; i++)
	{
		std::cout << nums[i] + secretNum << ' ';
	}
}

void decypherMessage(const char* rawMessageFileName, const char* keyFileName)
{
	if (!rawMessageFileName || !keyFileName)
	{
		return;
	}

	unsigned size;

	unsigned* nums = readRawMessage(rawMessageFileName, size);

	unsigned secretNum = readSecretNum(keyFileName);

	decypherMessage(nums, size, secretNum);

	delete[] nums;
}

int main()
{
	decypherMessage("nums.dat", "secret.dat");
	return 0;
}
