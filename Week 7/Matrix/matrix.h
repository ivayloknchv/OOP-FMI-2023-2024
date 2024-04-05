#pragma once
#include <iostream>
#include <cassert>

class Matrix
{
private:

	int** matrix;
	int rowsCount;
	int colsCount;

	void allocateMatrix(int rows, int cols);

	void copyFrom(const Matrix& other);
	void free();

public:

	Matrix();
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);
	~Matrix();

	Matrix(int rows, int cols);

	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix& operator*=(int scalar);
	Matrix& operator*=(const Matrix& other);

	int* operator[](int row) const;
	int*& operator[](int row);

	friend bool operator==(const Matrix& lhs, const Matrix& rhs);
	friend std::ostream& operator<<(std::ostream& os, const Matrix & rhs);
	friend std::istream& operator>>(std::istream& is, Matrix& rhs);
	friend bool operator ~(const Matrix& matrix);
};

Matrix operator+(const Matrix& lhs, const Matrix& rhs);
Matrix operator-(const Matrix& lhs, const Matrix& rhs);
Matrix operator*(const Matrix& lhs,int scalar);
Matrix operator*(int scalar, const Matrix& rhs);
Matrix operator*(const Matrix& lhs, const Matrix& rhs);
bool operator!=(const Matrix& lhs, const Matrix& rhs);
