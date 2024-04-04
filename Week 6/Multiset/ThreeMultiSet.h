#pragma once
#include <iostream>

namespace Constants
{
	constexpr unsigned elementsInBucket = 16;
}

class MultiSet
{
private:
	unsigned limit = 0;
	uint32_t* buckets = nullptr;
	unsigned bucketsCount=0;

	void copyFrom(const MultiSet& other);
	void free();

	unsigned getBucketsCount() const;
	unsigned getBucketIndex(unsigned num) const;
	unsigned getPosition(unsigned num) const;
	unsigned getOccurances(unsigned bucket, unsigned position) const;
	void printNumber(unsigned num) const;

public:

	MultiSet();
	MultiSet(const MultiSet& other);
	MultiSet& operator=(const MultiSet& other);
	~MultiSet();

	MultiSet(unsigned n);

	void addNum(unsigned num);
	void removeNum(unsigned num);
	void removeAll();
	unsigned getOccurances(unsigned num) const;
	unsigned getTotalCount() const;
	unsigned uniqueCount() const;
	void printSet() const;

	unsigned getMax() const;
	unsigned getMin() const;
};