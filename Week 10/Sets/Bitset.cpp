#include "Bitset.h"
#include <utility>
#include <cstring>

#pragma warning (disable : 4996)

void Bitset::copyFrom(const Bitset& other)
{
	limit = other.limit;
	bucketsCount = other.bucketsCount;
	buckets = new uint8_t[other.bucketsCount]{};
	strcpy((char*)buckets, (const char*)other.buckets);
}

void Bitset::moveFrom(Bitset&& other)
{
	buckets = other.buckets;
	other.buckets = nullptr;

	limit = other.limit;
	other.limit = 0;

	bucketsCount = other.bucketsCount;
	other.bucketsCount = 0;
}

void Bitset::free()
{
	delete[] buckets;
	buckets = nullptr;

	limit = 0;
	bucketsCount = 0;
}

int Bitset::getBucketsCount(int num) const
{
	int toReturn = num / BITS_IN_BYTE;

	if (num % 8 != 0)
	{
		toReturn++;
	}
	return toReturn;
}

int Bitset::getCurrentBucket(int num) const
{
	return num/BITS_IN_BYTE;
}

int Bitset::getCurrentPos(int num) const
{
	return BITS_IN_BYTE-1-num%BITS_IN_BYTE;
}

void Bitset::printBucket(uint8_t bucket) const
{
	for (int i = BITS_IN_BYTE - 1; i >= 0; i--)
	{
		if (bucket & 1 << i)
		{
			std::cout << '1';
		}
		else
		{
			std::cout << '0';
		}
	}
}

Bitset::Bitset(const Bitset& other)
{
	copyFrom(other);
}

Bitset& Bitset::operator=(const Bitset& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Bitset::Bitset(Bitset&& other) noexcept
{
	moveFrom(std::move(other));
}

Bitset& Bitset::operator=(Bitset&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Bitset::~Bitset() noexcept
{
	free();
}

Bitset::Bitset(int limit)
{
	this->limit = limit;
	bucketsCount = getBucketsCount(limit-1);
	buckets = new uint8_t[bucketsCount]{};
}

void Bitset::addNum(int num)
{
	if (num >= limit)
	{
		return;
	}

	int currentBucket = getCurrentBucket(num);
	int currentPosition = getCurrentPos(num);

	buckets[currentBucket] |= (1 << currentPosition);
}

void Bitset::removeNum(int num)
{
	if (num >= limit)
	{
		return;
	}

	int currentBucket = getCurrentBucket(num);
	int currentPosition = getCurrentPos(num);

	buckets[currentBucket] &= ~(1 << currentPosition);
}

bool Bitset::containsNum(int num) const
{
	if (num >= limit)
	{
		return false;
	}

	int currentBucket = getCurrentBucket(num);
	int currentPosition = getCurrentPos(num);

	return ((buckets[currentBucket] & (1 << currentPosition)) != 0 );
}

int Bitset::getSetLimit() const
{
	return limit;
}

void Bitset::clean()
{
	for (int i = 0; i < bucketsCount; i++)
	{
		buckets[i] = 0;
	}
}

void Bitset::print() const
{
	for (int i = 0; i < limit; i++)
	{
		if (containsNum(i))
		{
			std::cout << i << " ";
		}
	}
	std::cout << std::endl;
}

void Bitset::printBinary() const
{
	for (int i = 0; i < bucketsCount; i++)
	{
		printBucket(buckets[i]);
		std::cout << ' ';
	}
	std::cout << std::endl;
}

Bitset unionSets(const Bitset& lhs, const Bitset& rhs)
{
	int newLimit = std::max(lhs.limit, rhs.limit);

	Bitset toReturn(newLimit);

	const Bitset& minSet = (lhs.bucketsCount < rhs.bucketsCount) ? lhs : rhs;

	const Bitset& maxSet = (lhs.bucketsCount > rhs.bucketsCount) ? lhs : rhs;

	for (int i = 0; i < minSet.bucketsCount; i++)
	{
		toReturn.buckets[i] |= minSet.buckets[i];
		toReturn.buckets[i] |= maxSet.buckets[i];
	}

	for (int i = minSet.bucketsCount; i < maxSet.bucketsCount; i++)
	{
		toReturn.buckets[i] |= maxSet.buckets[i];
	}

	return toReturn;
}

Bitset intersectSets(const Bitset& lhs, const Bitset& rhs)
{
	int newLimit = std::min(lhs.limit, rhs.limit);
	Bitset toReturn(newLimit);

	for (int i = 0; i < toReturn.bucketsCount; i++)
	{
		toReturn.buckets[i] = lhs.buckets[i] & rhs.buckets[i];
	}

	return toReturn;
}
