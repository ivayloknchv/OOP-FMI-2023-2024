#pragma once
#include <iostream>

class Bitset
{
private:

	static constexpr int BITS_IN_BYTE = 8;

	uint8_t* buckets = nullptr;
	int limit = 0;
	int bucketsCount = 0;

	void copyFrom(const Bitset& other);
	void moveFrom(Bitset&& other);
	void free();

	int getBucketsCount(int num) const;
	int getCurrentBucket(int num) const;
	int getCurrentPos(int num) const;

	void printBucket(uint8_t bucket) const;

public:


	Bitset(const Bitset& other);
	Bitset& operator=(const Bitset& other);
	Bitset(Bitset&& other) noexcept;
	Bitset& operator=(Bitset&& other) noexcept;
	~Bitset() noexcept;

	Bitset(int limit);

	void addNum(int num);
	void removeNum(int num);

	bool containsNum(int num) const;
	int getSetLimit() const;

	void clean();
	void print() const;
	void printBinary() const;

	friend Bitset unionSets(const Bitset& lhs, const Bitset& rhs);
	friend Bitset intersectSets(const Bitset& lhs, const Bitset& rhs);
};

