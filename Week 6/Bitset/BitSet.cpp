#include "BitSet.h"

#include <iostream>
#pragma once

void Bitset::copyFrom(const Bitset& other)
{
	buckets = new unsigned char[other.bucketsCount];
	limit = other.limit;
	bucketsCount = other.bucketsCount;

	for (int i = 0; i < other.bucketsCount; i++)
	{
		buckets[i] = other.buckets[i];
	}
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
	int count = num / 8;

	if (num % 8 != 0)
	{
		count++;
	}

	return count;
}

int Bitset::getBucketNeeded(int num) const
{
	return num / 8;
}

int Bitset::getPosition(int num) const
{
	return 7- (num % 8);
}

Bitset::Bitset() = default;

Bitset::Bitset(const Bitset & other)
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

Bitset::~Bitset()
{
	free();
}

Bitset::Bitset(int newLimit)
{
	limit = newLimit;
	bucketsCount = getBucketsCount(newLimit);
	buckets = new unsigned char[bucketsCount] {};
}

void Bitset::addNumber(int num)
{
	if (num >= limit)
	{
		return;
	}

	int currentBucket = getBucketNeeded(num);
	int position = getPosition(num);

	buckets[currentBucket] |= 1 << position;
}

void Bitset::removeNumber(int num)
{
	if (num >= limit)
	{
		return;
	}

	int currentBucket = getBucketNeeded(num);
	int position = getPosition(num);

	buckets[currentBucket] &= ~(1 << position);
}

void Bitset::print() const
{
	std::cout << "{ ";
	for (int i = 0; i < limit; i++)
	{
		if (contains(i))
		{
			std::cout << i << " ";
		}
	}
	std::cout << "}";
}

bool Bitset::contains(int num) const
{
	if (num >= limit)
	{
		return false;
	}
	int currentBucket = getBucketNeeded(num);
	int position = getPosition(num);

	return (buckets[currentBucket] & (1 << position))!=0;
}

Bitset Bitset::getIntersection(const Bitset& other) const
{
	const Bitset& minBitset = (limit < other.limit) ? *this : other;

	Bitset intersectionSet(minBitset.limit);

	for (int i = 0; i < intersectionSet.bucketsCount; i++)
	{
		minBitset.buckets[i] = buckets[i] & other.buckets[i];
	}

	return minBitset;
}

Bitset Bitset::getUnion(const Bitset& other) const
{
	const Bitset& minSet = (limit < other.limit) ? *this : other;
	const Bitset& maxSet = (limit > other.limit) ? *this : other;

	Bitset unionSet(maxSet.limit);

	for (int i = 0; i < minSet.bucketsCount; i++)
	{
		unionSet.buckets[i] = buckets[i] | other.buckets[i];
	}

	for (int i = minSet.bucketsCount; i < maxSet.bucketsCount; i++)
	{
		unionSet.buckets[i] = maxSet.buckets[i];
	}

	return unionSet;
}
