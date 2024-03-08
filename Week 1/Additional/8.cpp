#include <iostream>

struct Rational {
	int numerator = 0;
	int denominator = 0;
};

int getGCD(int a, int b)
{
	if (b == 0)
	{
		return a;
	}

	return getGCD(b, a % b);
}

Rational getRat(const int& numerator,const int& denominator)
{
	Rational rat= { numerator, denominator };

	if (denominator == 0)
	{
		rat.denominator = 1;
	}

	int gcd = getGCD(numerator, denominator);
	rat.numerator /= gcd;
	rat.denominator /= gcd;

	if ((rat.numerator < 0 && rat.denominator<0) || (rat.numerator>0 && rat.denominator<0))
	{
		rat.numerator *= -1;
		rat.denominator *= -1;
	}

	return rat;
}

Rational sumRat(const Rational& r1, const Rational& r2)
{
	return getRat(r1.numerator * r2.denominator + r2.numerator * r1.denominator, r1.denominator * r2.denominator);
}

Rational subtractRat(const Rational& r1, const Rational& r2)
{
	return sumRat(r1,getRat(r2.numerator,-r2.denominator));
}

Rational multiplyRat(const Rational& r1, const Rational& r2)
{
	return getRat(r1.numerator * r2.numerator, r1.denominator * r2.denominator);
}

Rational divideRat(const Rational& r1, const Rational& r2)
{
	return multiplyRat(r1, getRat(r2.denominator, r2.numerator));
}
void printRat(const Rational& rat)
{
	std::cout << rat.numerator << '/' << rat.denominator << std::endl;
}

int main()
{
	Rational r1 = getRat(-3, 18);
	Rational r2 = getRat(3, 4);

	Rational r3=multiplyRat(r1, r2);
	printRat(r3);
	return 0;
}
