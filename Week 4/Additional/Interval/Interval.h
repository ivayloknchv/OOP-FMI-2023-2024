#pragma once
#include <climits>

class Interval 
{
	int a= INT_MIN;;
	int b= INT_MAX;

	int getCountByCriteria(bool (*pred) (int num)) const;
	
public:

	Interval();
	Interval(int newA, int newB);

	void setA(int newA);
	void setB(int newB);

	int getA() const;
	int getB() const;

	int getIntervalLenght() const;
	bool isInInterval(int num) const;
	int getPrimeNumsCount() const;
	int getPalindromesCount() const;
	int nonRepetetiveNumsCount() const;
	bool areEdgesPowOfTwo() const;

	Interval intersection(const Interval& other) const;
	bool isSubinterval(const Interval& other) const;
};