#include "Polynomial.h"
#include <utility>

static int getPow(int base, int pow)
{
	int toReturn = 1;

	for (int i = 0; i < pow; i++)
	{
		toReturn *= base;
	}

	return toReturn;
}

void Polynomial::copyFrom(const Polynomial& other)
{
	degree = other.degree;

	coeffs = new int[degree + 1]{};

	for (int i = 0; i <= degree; i++)
	{
		coeffs[i] = other.coeffs[i];
	}
}

void Polynomial::moveFrom(Polynomial&& other)
{
	coeffs = other.coeffs;
	other.coeffs = nullptr;

	degree = other.degree;
	other.degree = 0;
}

void Polynomial::free()
{
	delete[] coeffs;
	coeffs = nullptr;

	degree = 0;
}

void Polynomial::setCoeffs(int deg, const int* coeffs)
{
	if (!coeffs)
	{
		throw std::invalid_argument("Nullptr detected!");
	}

	this->degree = deg;

	this->coeffs = new int[deg + 1]{};

	for (int i = 0; i <= deg; i++)
	{
		this->coeffs[i] = coeffs[i];
	}
}

Polynomial::Polynomial(const Polynomial& other)
{
	copyFrom(other);
}

Polynomial& Polynomial::operator=(const Polynomial& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Polynomial::Polynomial(Polynomial&& other) noexcept
{
	moveFrom(std::move(other));
}

Polynomial& Polynomial::operator=(Polynomial&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Polynomial::~Polynomial()
{
	free();
}

Polynomial::Polynomial(int deg, const int* coeffs)
{
	setCoeffs(deg, coeffs);
}

Polynomial& Polynomial::operator+=(const Polynomial& other)
{
	if (other.degree > degree)
	{
		int* temp = new int[other.degree + 1]{};
		int counter = 0;
		for (int i = 0; i <= other.degree; i++)
		{
			if (other.degree - i <= degree)
			{
				temp[i] += coeffs[counter++];
			}
			temp[i] += other.coeffs[i];
		}

		degree = other.degree;
		delete[] coeffs;
		coeffs = temp;
		temp = nullptr;
	}

	else
	{
		int counter = 0;

		for (int i = 0; i <= degree; i++)
		{
			if (degree - i <= other.degree)
			{
				coeffs[i] += other.coeffs[counter++];
			}
		}
	}

	return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& other)
{
	if (other.degree > degree)
	{
		int* temp = new int[other.degree + 1]{};
		int counter = 0;
		for (int i = 0; i <= other.degree; i++)
		{
			if (other.degree - i <= degree)
			{
				temp[i] += coeffs[counter++];
			}
			temp[i] -= other.coeffs[i];
		}

		degree = other.degree;
		delete[] coeffs;
		coeffs = temp;
		temp = nullptr;
	}

	else
	{
		int counter = 0;

		for (int i = 0; i <= degree; i++)
		{
			if (degree - i <= other.degree)
			{
				coeffs[i] -= other.coeffs[counter++];
			}
		}
	}

	return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& other)
{
	int newDeg = degree + other.degree;
	int* temp = new int[newDeg + 1]{};

	for (int i = 0; i <= degree; i++)
	{
		for (int j = 0; j <= other.degree; j++)
		{
			int currentDeg = (degree-i) + (other.degree-j);
			temp[newDeg - currentDeg] += (coeffs[i] * other.coeffs[j]);
		}
	}

	degree = newDeg;

	delete[] coeffs;
	coeffs = temp;
	temp = nullptr;

	return *this;
}

int Polynomial::getDegree() const
{
	return degree;
}

int Polynomial::operator()(int num)
{
	int toReturn = 0;

	for (int i = 0; i <= degree; i++)
	{
		toReturn += coeffs[i] * getPow(num, degree - i);
	}

	return toReturn;
}

int& Polynomial::operator[](int idx)
{
	if (idx<0 || idx>degree)
	{
		throw std::exception("The polynomial doesn't have such degree!");
	}

	return coeffs[degree - idx];
}

const int& Polynomial::operator[](int idx) const
{
	if (idx<0 || idx>degree)
	{
		throw std::exception("The polynomial doesn't have such degree!");
	}

	return coeffs[degree - idx];
}

std::ostream& operator<<(std::ostream& os, const Polynomial& obj)
{
	for (int i = 0; i <= obj.degree; i++)
	{
		if (i == 0 && obj.coeffs[i]!=0)
		{
			os << obj.coeffs[i] << "x^" << (obj.degree - i);
		}

		else
		{
			if (obj.coeffs != 0)
			{
				if (obj.coeffs[i] > 0)
				{
					os << '+';
				}
				if (obj.coeffs[i] != 0)
				{
					os << obj.coeffs[i];

					if (obj.degree - i == 1)
					{
						os << "x";
					}

					else if (obj.degree - i != 0)
					{
						os<< "x^" << (obj.degree - i);
					}
					
				}
			}
		}
		
	}

	os << std::endl;

	return os;
}

bool operator==(const Polynomial& lhs, const Polynomial& rhs)
{
	if (lhs.degree != rhs.degree)
	{
		return false;
	}

	for (int i = 0; i <= lhs.degree; i++)
	{
		if (lhs.coeffs[i] != rhs.coeffs[i])
		{
			return false;
		}
	}

	return true;
}

bool operator!=(const Polynomial& lhs, const Polynomial& rhs)
{
	return !(lhs == rhs);
}

Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs)
{
	Polynomial toReturn = lhs;
	toReturn += rhs;

	return toReturn;
}

Polynomial operator-(const Polynomial& lhs, const Polynomial& rhs)
{
	Polynomial toReturn = lhs;
	toReturn -= rhs;

	return toReturn;
}

Polynomial operator*(const Polynomial& lhs, const Polynomial& rhs)
{
	Polynomial toReturn = lhs;
	toReturn *= rhs;

	return toReturn;
}
