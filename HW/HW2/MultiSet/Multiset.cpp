#include "Multiset.h"


void Multiset::copyFrom(const Multiset& other)
{
	maxNum = other.maxNum;
	bucketsCount = other.bucketsCount;
	maxBitsNum = other.maxBitsNum;
	buckets = new uint8_t[bucketsCount];

	for (int i = 0; i < bucketsCount; i++)
	{
		buckets[i] = other.buckets[i];
	}
}

void Multiset::moveFrom(Multiset&& other)
{
	maxNum = other.maxNum;
	bucketsCount = other.bucketsCount;
	maxBitsNum = other.maxBitsNum;
	buckets = other.buckets;

	other.maxNum = 0;
	other.bucketsCount = 0;
	other.maxBitsNum = 0;
	other.buckets = nullptr;
}

void Multiset::free()
{
	delete[] buckets;
	buckets = nullptr;
	maxNum = 0;
	bucketsCount = 0;
	maxBitsNum = 0;
}

int Multiset::getBucketsCount(int num, int bits) const
{
	int totalBits = bits * (num + 1);

	int toReturn = totalBits / BITS_IN_BYTE;

	if (totalBits % BITS_IN_BYTE != 0)
	{
		++toReturn;
	}

	return toReturn;
}

unsigned Multiset::generateBitMask(int bits) const
{
	unsigned toReturn = 0; 

	for (int i = 0; i < bits; i++)
	{
		toReturn |= 1 << i;
	}

	return toReturn;
}

int Multiset::getCurrentBucket(int num) const
{
	return num / BITS_IN_BYTE;
}

int Multiset::getPosition(int num) const
{
	return num % BITS_IN_BYTE;
}

int Multiset::shift(int num) const
{
	return BITS_IN_BYTE - 1 - num;
}

Multiset::Multiset() = default;

Multiset::Multiset(const Multiset & other)
{
	copyFrom(other);
}

Multiset::Multiset(Multiset&& other) noexcept
{
	moveFrom(std::move(other));
}

Multiset& Multiset::operator=(const Multiset& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Multiset& Multiset::operator=(Multiset&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Multiset::~Multiset()
{
	free();
}

Multiset::Multiset(int n, int k)
{
	if (!(k >= MIN_BITS && k <= MAX_BITS))
	{
		throw std::out_of_range("Bits count must be between 1 and 8!");
	}

	maxNum = n;
	maxBitsNum = k;
	bucketsCount = getBucketsCount(n, k);
	buckets = new uint8_t[bucketsCount]{0};
}

void Multiset::addNum(int num)
{
	if (num<0 || num>maxNum)
	{
		throw std::out_of_range("Number out of range!");
	}
	
	unsigned occurances = getOccurances(num);

	if (occurances == ((1 << maxBitsNum) - 1))
	{
		return;
	}
	occurances++;

	updateCount(num, occurances);
}

void Multiset::updateCount(int num, unsigned count)
{
	int startBit = num * maxBitsNum;
	int endBit = startBit + maxBitsNum - 1;

	int startBucket = getCurrentBucket(startBit);
	int endBucket = getCurrentBucket(endBit);

	int startPos = getPosition(startBit);
	int endPos = getPosition(endBit);

	if (startBucket == endBucket)
	{
		buckets[startBucket] &= ~(generateBitMask(maxBitsNum) << shift(endPos));
		buckets[startBucket] |= count << shift(endPos);
	}
	else
	{
		int tempShifter = maxBitsNum - 1;

		for (int i = startPos; i < BITS_IN_BYTE; i++)
		{
			buckets[startBucket] &= ~(1 << shift(i));

			if (count & 1 << tempShifter)
			{
				buckets[startBucket] |= (1 << shift(i));
			}
			tempShifter--;
		}

		for (int i = 0; i <= endPos; i++)
		{
			buckets[endBucket] &= ~(1 << shift(i));

			if (count & 1 << tempShifter)
			{
				buckets[endBucket] |= (1 << shift(i));
			}
			tempShifter--;
		}
	}
}

void Multiset::printBucketBinary(int idx) const
{
	for (int i = 0; i < BITS_IN_BYTE; i++)
	{
		if (buckets[idx] & 1 << shift(i))
		{
			std::cout << 1;
		}
		else
		{
			std::cout << 0;
		}
	}
}

void Multiset::printNum(int num) const
{
	int occurances = getOccurances(num);

	while (occurances > 0)
	{
		std::cout << num << ' ';
		occurances--;
	}
}

void Multiset::saveToFile(std::ofstream& ofs) const
{
	ofs.write((const char*)&maxNum, sizeof(maxNum));
	ofs.write((const char*)&bucketsCount, sizeof(bucketsCount));
	ofs.write((const char*)buckets, bucketsCount * sizeof(uint8_t));
	ofs.write((const char*)&maxBitsNum, sizeof(maxBitsNum));
}

void Multiset::readFromFile(std::ifstream& ifs)
{
	free(); //in case dynamic memory is allocated

	ifs.read((char*)&maxNum, sizeof(maxNum));
	ifs.read((char*)&bucketsCount, sizeof(bucketsCount));

	buckets = new uint8_t[bucketsCount]{};

	ifs.read((char*)buckets, bucketsCount * sizeof(uint8_t));
	ifs.read((char*)&maxBitsNum, sizeof(maxBitsNum));
}

unsigned Multiset::getOccurances(int num) const
{
	if (num < 0 || num > maxNum)
	{
		throw std::out_of_range("Number out of range!");
	}

	unsigned toReturn = 0;

	int startBit = num * maxBitsNum;
	int endBit = startBit + maxBitsNum - 1;

	int startBucket = getCurrentBucket(startBit);
	int endBucket = getCurrentBucket(endBit);

	int startPos = getPosition(startBit);
	int endPos = getPosition(endBit);

	if (startBucket == endBucket)
	{
		toReturn |= (buckets[startBucket] & (generateBitMask(maxBitsNum) << shift(endPos)))>>shift(endPos);
	}

	else
	{
		for (int i = startPos; i < BITS_IN_BYTE; i++)
		{
			toReturn = toReturn << 1;

			if (buckets[startBucket] & 1 << shift(i))
			{
				toReturn |= 1;
			}
		}

		for (int i = 0; i <= endPos; i++)
		{
			toReturn = toReturn << 1;

			if (buckets[endBucket] & 1 << shift(i))
			{
				toReturn |= 1;
			}
		}
	}
	return toReturn;
}

void Multiset::printSet() const
{
	std::cout << "{ ";

	for (int i = 0; i <= maxNum; i++)
	{
		printNum(i);
		
	}
	std::cout << "}"<<std::endl;
}

void Multiset::printBinary() const
{
	for (int i = 0; i < bucketsCount; i++)
	{
		printBucketBinary(i);
		std::cout << " ";
	}
	std::cout << std::endl;
}

void Multiset::saveToFile(const char* filePath) const
{
	if (!filePath)
	{
		throw std::runtime_error("Nullptr detected!");
	}

	std::ofstream ofs(filePath, std::ios::binary);

	if (!ofs.is_open())
	{
		throw std::runtime_error("Cannot open file!");
	}

	saveToFile(ofs);

	ofs.close();
}

void Multiset::readFromFile(const char* filePath)
{
	if (!filePath)
	{
		throw std::runtime_error("Nullptr detected!");
	}

	std::ifstream ifs(filePath, std::ios::binary);

	if (!ifs.is_open())
	{
		throw std::runtime_error("Cannot open file!");
	}

	readFromFile(ifs);

	ifs.close();
}

Multiset getIntersection(const Multiset& lhs, const Multiset& rhs)
{
	int newNum = std::min(lhs.maxNum, rhs.maxNum);
	int newBits = std::min(lhs.maxBitsNum, rhs.maxBitsNum);

	Multiset toReturn(newNum, newBits);

	for (int i = 0; i <= newNum; i++)
	{
		unsigned minOccurances = std::min(lhs.getOccurances(i), rhs.getOccurances(i));
		toReturn.updateCount(i, minOccurances);
	}

	return toReturn;
}

Multiset getDifference(const Multiset& lhs, const Multiset& rhs)
{
	Multiset toReturn = lhs;
	int minLimit = std::min(lhs.maxNum, rhs.maxNum);

	for (int i = 0; i <= minLimit; i++)
	{
		unsigned lhsCount = lhs.getOccurances(i);
		unsigned rhsCount = rhs.getOccurances(i);

		if (lhsCount < rhsCount) // in case rhs contains more digits we remove ALL
		{
			toReturn.updateCount(i, 0);
		}

		else
		{
			toReturn.updateCount(i, lhsCount-rhsCount);
		}		
	}

	return toReturn;
}

Multiset getComplement(const Multiset& set)
{
	Multiset toReturn = set;

	for (int i = 0; i <toReturn.bucketsCount; i++)
	{
		toReturn.buckets[i]=~(toReturn.buckets[i]);
	}

	//now we need to take take of the "trash" bits that flipped to 1

	int lastBit = toReturn.maxNum * toReturn.maxBitsNum + toReturn.maxBitsNum - 1;
	int lastPos = toReturn.getPosition(lastBit);
	toReturn.buckets[toReturn.bucketsCount-1] &= ~(toReturn.generateBitMask(Multiset::BITS_IN_BYTE - lastPos));  

	// the "trash" symbols in the last bucket are flipped back to 0
	return toReturn;
}
