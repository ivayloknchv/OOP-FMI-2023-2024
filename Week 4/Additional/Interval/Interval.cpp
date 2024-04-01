#include "Interval.h"
#include "helperFunctions.h"

Interval::Interval() : Interval(0, 0)
{}

int Interval::getCountByCriteria(bool(*pred)(int num)) const
{
	int counter = 0;

	for (int i = a; i <= b; i++)
	{
		if (pred(i))
		{
			counter++;
		}
	}

	return counter;
}

Interval::Interval(int newA, int newB)
{
	setA(newA);
	setB(newB);

	if (a > b)
	{
		swap(a, b);
	}
}

void Interval::setA(int newA)
{

	a = newA;

	if (a > b)
	{
		swap(a, b);
	}
}

void Interval::setB(int newB)
{
	b = newB;

	if (b < a)
	{
		swap(a, b);
	}
}

int Interval::getA() const
{
	return a;
}

int Interval::getB() const
{
	return b;
}

int Interval::getIntervalLenght() const
{
	return b-a;
}

bool Interval::isInInterval(int num) const
{
	return (num>=a && num<=b);
}

int Interval::getPrimeNumsCount() const
{
	return getCountByCriteria(isPrime);
}

int Interval::getPalindromesCount() const
{
	return getCountByCriteria(isPalindrome);
}

int Interval::nonRepetetiveNumsCount() const
{
	return getCountByCriteria(hasUniqueDigitsOnly);
}

bool Interval::areEdgesPowOfTwo() const
{
	return (isPowOfTwo(a) && isPowOfTwo(b));
}

Interval Interval::intersection(const Interval& other) const
{
	int newStart = (a > other.a) ? a : other.a;
	int newEnd = (b > other.b) ? other.b : b;

	if (newStart > newEnd)
	{
		return Interval(0, 0);
	}

	return Interval(newStart, newEnd);
}

bool Interval::isSubinterval(const Interval& other) const
{
	return (a <= other.a && b >= other.b);
}