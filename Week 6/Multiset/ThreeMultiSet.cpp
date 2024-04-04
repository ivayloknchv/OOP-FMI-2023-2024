#include "ThreeMultiSet.h"

MultiSet::MultiSet(unsigned n)
{
	limit = n;
	bucketsCount = getBucketsCount();
	buckets = new uint32_t [bucketsCount] {0};
	
}

void MultiSet::addNum(unsigned num)
{
	if (num >= limit)
	{
		return;
	}

	unsigned bucket=getBucketIndex(num);
	unsigned position = getPosition(num);

	unsigned occurances = getOccurances(bucket, position);

	switch (occurances)
	{
	case 0: 
		buckets[bucket] |= 1 << position; 
		break;

	case 1:
		buckets[bucket] &= ~(1 << position);
		buckets[bucket] |= 1 << (position + 1);
		break;

	case 2:
		buckets[bucket] |= 1 << position;
	}
}

void MultiSet::removeNum(unsigned num)
{
if (num >= limit)
{
	return;
}

unsigned bucket = getBucketIndex(num);
unsigned position = getPosition(num);

unsigned occurances = getOccurances(bucket, position);

switch (occurances)
{

case 0: break;

case 1:
	buckets[bucket] &= ~(1 << position);
	break;

case 2:
	buckets[bucket] &= ~(1 << (position + 1));
	buckets[bucket] |= 1 << position;
	break;

case 3:
	buckets[bucket] &= ~(1 << position);
	break;
}
}

void MultiSet::removeAll()
{
	for (unsigned i = 0; i < bucketsCount; i++)
	{
		buckets[i] = 0;
	}
}

unsigned MultiSet::getOccurances(unsigned num) const
{
	if (num >= limit)
	{
		return -1;
	}

	unsigned bucket = getBucketIndex(num);
	unsigned position = getPosition(num);

	return getOccurances(bucket, position);
}

unsigned MultiSet::getTotalCount() const
{
	unsigned count = 0;

	for (unsigned i = 0; i < limit;i++)
	{
		count += getOccurances(i);=
	}

	return count;
}

void MultiSet::printSet() const
{
	std::cout << "{ ";

	for (unsigned i = 0; i < limit; i++)
	{
		printNumber(i);
	}

	std::cout << '}' << std::endl;
}

unsigned MultiSet::getMax() const
{
	unsigned max = 0;

	for (unsigned i = 0; i < limit; i++)
	{
		if (getOccurances(i) != 0 && i > max)
		{
			max = i;
		}
	}
	return max;
}

unsigned MultiSet::getMin() const
{

	unsigned min = limit-1;

	for (unsigned i = 0; i < limit; i++)
	{
		if (getOccurances(i) != 0 && i< min)
		{
			min = i;
		}
	}
	return min;
}

void MultiSet::copyFrom(const MultiSet& other)
{
	limit = other.limit;
	bucketsCount = other.bucketsCount;

	buckets = new uint32_t[bucketsCount]{ 0 };

	for (unsigned i = 0; i < bucketsCount; i++)
	{
		buckets[i] = other.buckets[i];
	}
}

void MultiSet::free()
{
	delete[] buckets;
	buckets = nullptr;

	limit = 0;
	bucketsCount = 0;
}

unsigned MultiSet::getBucketsCount() const
{
	return limit / Constants::elementsInBucket + 1;
}

unsigned MultiSet::getBucketIndex(unsigned num) const
{
	return num / Constants::elementsInBucket;
}

unsigned MultiSet::getPosition(unsigned num) const
{
	return 2 * ((Constants::elementsInBucket - 1) - (num % Constants::elementsInBucket));
}

unsigned MultiSet::getOccurances(unsigned bucket, unsigned position) const
{
	unsigned firstBit = ((buckets[bucket] & (1 << (position + 1))) != 0) ? 1 : 0;
	unsigned secondBit = ((buckets[bucket] & (1 << position)) != 0) ? 1 : 0;

	return 2 * firstBit + secondBit;
}

void MultiSet::printNumber(unsigned num) const
{
	unsigned occurances = getOccurances(num);


	for (unsigned i = 0; i < occurances;i++)
	{
		std::cout << num << ' ';
	}
}

MultiSet::MultiSet() = default;

MultiSet::MultiSet(const MultiSet & other)
{
	copyFrom(other);
}

MultiSet& MultiSet::operator=(const MultiSet& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

MultiSet::~MultiSet()
{
	free();
}
