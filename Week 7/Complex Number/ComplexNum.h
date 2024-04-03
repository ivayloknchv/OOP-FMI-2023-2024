#pragma once
#include <iostream>

class ComplexNum
{
private:

	double re=0;
	double im = 0;

public:

	ComplexNum();
	ComplexNum(double newRe, double newIm);

	void setReal(double newRe);
	void setIm(double newIm);

	double getReal() const;
	double getIm() const;

	double getModulus() const;
	ComplexNum getConjugated() const;

	ComplexNum& operator+=(const ComplexNum& other);
	ComplexNum& operator-=(const ComplexNum& other);
	ComplexNum& operator*=(const ComplexNum& other);
	ComplexNum& operator/=(const ComplexNum& other);

	friend std::ostream& operator<<(std::ostream& os, const ComplexNum& complex);
	friend std::istream& operator>>(std::istream& is, ComplexNum& complex);
};

ComplexNum operator+(const ComplexNum& lhs, const ComplexNum& rhs);
ComplexNum operator-(const ComplexNum& lhs, const ComplexNum& rhs);
ComplexNum operator*(const ComplexNum& lhs, const ComplexNum& rhs);
ComplexNum operator/(const ComplexNum& lhs, const ComplexNum& rhs);

bool operator==(const ComplexNum& lhs, const ComplexNum& rhs);
bool operator!=(const ComplexNum& lhs, const ComplexNum& rhs);