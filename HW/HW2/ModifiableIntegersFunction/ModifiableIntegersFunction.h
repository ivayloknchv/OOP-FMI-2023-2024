#pragma once
#include <climits>
#include <fstream>

short defaultFunc(short num);

class ModifiableIntegersFunction
{
private:

	constexpr static short minVal = SHRT_MIN;
	constexpr static short maxVal = SHRT_MAX;
	constexpr static int capacity = 2 * maxVal + 2;

	short (*func)(short num) = nullptr;
	short values[capacity]{};
	bool excludedPoints[capacity]{ false };

	void generateValues();
	void countFunctionalValues(int* values) const;

	void writeToBinaryFile(std::ofstream& ofs) const;
	void readFromBinaryFile(std::ifstream& ifs);

	int index(int num) const;
public:

	ModifiableIntegersFunction();

	ModifiableIntegersFunction(short(*func)(short num));

	void excludePoint(short num);

	void writeToBinaryFile(const char* filePath) const;

	void readFromBinaryFile(const char* filePath);

	void predifineValue(short x, short y);

	void drawGraph(short xStart, short yStart) const;

	bool isInjective() const;

	bool isSurjective() const;

	bool isBijective() const;

	ModifiableIntegersFunction& operator+=(const ModifiableIntegersFunction& other);

	ModifiableIntegersFunction& operator-=(const ModifiableIntegersFunction& other);

	ModifiableIntegersFunction& operator()(const ModifiableIntegersFunction& other);

	friend ModifiableIntegersFunction operator+(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);

	friend ModifiableIntegersFunction operator-(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);

	friend ModifiableIntegersFunction operator~(const ModifiableIntegersFunction& other);

	friend bool operator<(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);

	friend bool operator<=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);

	friend bool operator>=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);

	friend bool operator>(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);

	friend bool operator==(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);

	friend bool operator!=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);

	friend bool operator||(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);

	friend ModifiableIntegersFunction operator^(const ModifiableIntegersFunction& func, short k);
};