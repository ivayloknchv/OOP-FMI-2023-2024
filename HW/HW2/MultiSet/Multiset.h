#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>

class Multiset
{
private:
	static constexpr short BITS_IN_BYTE = 8;
	static constexpr short MIN_BITS = 1;
	static constexpr short MAX_BITS= 8;
	uint8_t* buckets = nullptr;
	int maxNum = 0;
	int bucketsCount = 0;
	int maxBitsNum = 0;

	void copyFrom(const Multiset& other);
	void moveFrom(Multiset&& other);
	void free();

	int getBucketsCount(int num, int bits) const;
	unsigned generateBitMask(int bits) const;

	int getCurrentBucket(int num) const;
	int getPosition(int num) const;

	int shift(int num) const;
	void updateCount(int num, unsigned count);

	void printBucketBinary(int idx) const;
	void printNum(int num) const;


	void saveToFile(std::ofstream& ofs) const;
	void readFromFile(std::ifstream& ifs);

public:

	Multiset();
	Multiset(const Multiset& other);
	Multiset(Multiset&& other) noexcept;
	Multiset& operator=(const Multiset& other);
	Multiset& operator=(Multiset&& other) noexcept;
	~Multiset();

	Multiset(int n, int k);

	void addNum(int num);

	unsigned getOccurances(int num) const;

	void printSet() const;

	void printBinary() const;

	void saveToFile(const char* filePath) const;

	void readFromFile(const char* filePath);

	friend Multiset getIntersection(const Multiset& lhs, const Multiset& rhs);

	friend Multiset getDifference(const Multiset& lhs, const Multiset& rhs);

	friend Multiset getComplement(const Multiset& set);
};