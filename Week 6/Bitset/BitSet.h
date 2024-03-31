#pragma once

class Bitset
{
	unsigned char* buckets= nullptr;
	int limit = 0;
	int bucketsCount = 0;

	void copyFrom(const Bitset& other);
	void free();
	
	int getBucketsCount(int num) const;
	int getBucketNeeded(int num) const;
	int getPosition(int num) const;
public:

	Bitset();
	Bitset(const Bitset& other);
	Bitset& operator=(const Bitset& other);
	~Bitset();

	Bitset(int newLimit);

	void addNumber(int num);
	void removeNumber(int num);
	void print() const;
	bool contains(int num) const;
	Bitset getIntersection(const Bitset& other) const;
	Bitset getUnion(const Bitset& other) const;
};