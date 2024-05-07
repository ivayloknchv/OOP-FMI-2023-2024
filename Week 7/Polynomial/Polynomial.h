#pragma once
#include <iostream>

class Polynomial
{
	int degree = 0;
	int* coeffs = nullptr;

	void copyFrom(const Polynomial& other);
	void moveFrom(Polynomial&& other);
	void free();

	void setCoeffs(int deg, const int* coeffs);

public:

	Polynomial() = default;
	Polynomial(const Polynomial& other);
	Polynomial& operator=(const Polynomial& other);
	Polynomial(Polynomial&& other) noexcept;
	Polynomial& operator=(Polynomial&& other) noexcept;
	~Polynomial();

	Polynomial(int deg, const int* coeffs);

	Polynomial& operator+=(const Polynomial& other);
	Polynomial& operator-=(const Polynomial& other);
	Polynomial& operator*=(const Polynomial& other);	

	int getDegree() const;

	int operator()(int num);
	int& operator[](int idx);
	const int& operator[](int idx) const;

	friend std::ostream& operator<<(std::ostream& os, const Polynomial& obj);
	friend bool operator == (const Polynomial& lhs, const Polynomial& rhs);
	friend bool operator != (const Polynomial& lhs, const Polynomial& rhs);

};

Polynomial operator + (const Polynomial& lhs, const Polynomial& rhs);
Polynomial operator - (const Polynomial& lhs, const Polynomial& rhs);
Polynomial operator * (const Polynomial& lhs, const Polynomial& rhs);

bool operator == (const Polynomial& lhs, const Polynomial& rhs);
bool operator != (const Polynomial& lhs, const Polynomial& rhs);

