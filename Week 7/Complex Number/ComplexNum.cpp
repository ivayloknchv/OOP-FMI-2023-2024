#include "ComplexNum.h"

ComplexNum::ComplexNum() = default;

ComplexNum::ComplexNum(double newRe, double newIm)
{
	setReal(newRe);
	setIm(newIm);
}

void ComplexNum::setReal(double newRe)
{
	re = newRe;
}

void ComplexNum::setIm(double newIm)
{
	im = newIm;
}

double ComplexNum::getReal() const
{
	return re;
}

double ComplexNum::getIm() const
{
	return im;
}

double ComplexNum::getModulus() const
{
	return re*re + im*im;
}

ComplexNum ComplexNum::getConjugated() const
{
	ComplexNum conjugated(*this);
	conjugated.im = -1 * im;
	return conjugated;
}

ComplexNum& ComplexNum::operator+=(const ComplexNum& other)
{
	re += other.re;
	im += other.im;

	return *this;
}

ComplexNum& ComplexNum::operator-=(const ComplexNum& other)
{
	re -= other.re;
	im -= other.im;

	return *this;
}

ComplexNum& ComplexNum::operator*=(const ComplexNum& other)
{
	double oldRe = re;
	re = oldRe * other.re - im * other.im;
	im = im * other.re + oldRe * other.im;

	return *this;
}

ComplexNum& ComplexNum::operator/=(const ComplexNum& other)
{
	double modulus = other.getModulus();

	if (modulus <= 0.00001)
	{
		return *this;
	}

	ComplexNum conjugated = other.getConjugated();

	*this *= conjugated;

	re /= modulus;
	im /= modulus;

	return *this;
}

std::ostream& operator<<(std::ostream& os, const ComplexNum& complex)
{
	return os << complex.re << '+' << complex.im << 'i' << std::endl;
}

std::istream& operator>>(std::istream& is, ComplexNum& complex)
{
	return is >> complex.re >> complex.im;
}

ComplexNum operator+(const ComplexNum& lhs, const ComplexNum& rhs)
{
	ComplexNum copy(lhs);

	copy += rhs;

	return copy;
}

ComplexNum operator-(const ComplexNum& lhs, const ComplexNum& rhs)
{
	ComplexNum copy(lhs);

	copy -= rhs;

	return copy;
}

ComplexNum operator*(const ComplexNum& lhs, const ComplexNum& rhs)
{
	ComplexNum copy(lhs);

	copy *= rhs;

	return copy;
}

ComplexNum operator/(const ComplexNum& lhs, const ComplexNum& rhs)
{
	ComplexNum copy(lhs);
	copy /= rhs;
	return copy;
}

bool operator==(const ComplexNum& lhs, const ComplexNum& rhs)
{
	return (lhs.getReal() == rhs.getReal() && lhs.getIm() == lhs.getIm());
}

bool operator!=(const ComplexNum& lhs, const ComplexNum& rhs)
{
	return !(lhs == rhs);
}
