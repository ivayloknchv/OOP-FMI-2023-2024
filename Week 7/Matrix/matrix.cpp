#include "Matrix.h"

void Matrix::allocateMatrix(int rows, int cols)
{
	matrix = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols] {0};
	}
}

void Matrix::copyFrom(const Matrix& other)
{
	rowsCount = other.rowsCount;
	colsCount = other.colsCount;

	matrix = new int* [rowsCount];

	for (int i = 0; i < rowsCount; i++)
	{
		matrix[i] = new int[colsCount] {0};

		for (int j = 0; j < colsCount; j++)
		{
			matrix[i][j] = other.matrix[i][j];
		}
	}
}

void Matrix::free()
{
	for (int i = 0; i < rowsCount; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;

	matrix = nullptr;
	rowsCount = 0;
	colsCount = 0;
}

Matrix::Matrix(): Matrix(2,2){}

Matrix::Matrix(const Matrix& other)
{
	copyFrom(other);
}

Matrix& Matrix::operator=(const Matrix& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Matrix::~Matrix()
{
	free();
}

Matrix::Matrix(int rows, int cols): rowsCount(rows), colsCount(cols)
{
	allocateMatrix(rows, cols);
}

Matrix& Matrix::operator+=(const Matrix& other)
{
	assert(rowsCount == other.rowsCount && colsCount == other.colsCount);

	for (int i = 0; i < rowsCount; i++)
	{
		for (int j = 0; j < colsCount; j++)
		{
			matrix[i][j] += other.matrix[i][j];
		}
	}

	return *this;
}

Matrix& Matrix::operator-=(const Matrix& other)
{
	assert(rowsCount == other.rowsCount && colsCount == other.colsCount);

	for (int i = 0; i < rowsCount; i++)
	{
		for (int j = 0; j < colsCount; j++)
		{
			matrix[i][j] += other.matrix[i][j];
		}
	}

	return *this;
}

Matrix& Matrix::operator*=(int scalar)
{
	for (int i = 0; i < rowsCount; i++)
	{
		for (int j = 0; j < colsCount; j++)
		{
			matrix[i][j] *= scalar;
		}
	}

	return *this;
}

Matrix& Matrix::operator*=(const Matrix& other)
{
	assert(colsCount == other.rowsCount);

	Matrix product(rowsCount, other.colsCount);

	for (int i = 0; i < rowsCount; i++)
	{
		for (int j = 0; j < other.colsCount; j++)
		{
			for (int k = 0; k < colsCount; k++)
			{
				product.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
			}
		}
	}
	*this = product;
	return *this;
}

int* Matrix::operator[](int row) const
{
	assert(row > 0 && row < rowsCount);

	return matrix[row];
}

int*& Matrix::operator[](int row)
{
	assert(row > 0 && row < rowsCount);

	return matrix[row];
}

bool operator==(const Matrix& lhs, const Matrix& rhs)
{
	if (lhs.rowsCount != rhs.rowsCount || lhs.colsCount != lhs.colsCount)
	{
		return false;
	}

	for (int i = 0 ; i < rhs.rowsCount; i++)
	{
		for (int j = 0; j < rhs.colsCount; j++)
		{
			if (lhs.matrix[i][j] != rhs.matrix[i][j])
			{
				return false;
			}
		}
	}

	return true;
}

std::ostream& operator<<(std::ostream& os, const Matrix& rhs)
{
	for (int i = 0; i < rhs.rowsCount; i++)
	{
		for (int j = 0; j < rhs.colsCount; j++)
		{
			os << rhs.matrix[i][j] << ' ';
		}
		os << std::endl;
	}
	return os;
}

std::istream& operator>>(std::istream& is, Matrix& rhs)
{
	for (int i = 0; i < rhs.rowsCount; i++)
	{
		for (int j = 0; j < rhs.colsCount; j++)
		{
			is >> rhs.matrix[i][j];
		}
	}
	return is;
}

bool operator~(const Matrix& matrix)
{
	Matrix copy(matrix.rowsCount, matrix.colsCount);
	return (matrix == copy);
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs)
{
	Matrix toReturn(lhs);
	toReturn += rhs;

	return toReturn;
}

Matrix operator-(const Matrix& lhs, const Matrix& rhs)
{
	Matrix toReturn(lhs);
	toReturn -= rhs;

	return toReturn;
}

Matrix operator*(const Matrix& lhs, int scalar)
{
	Matrix toReturn(lhs);
	toReturn *= scalar;

	return toReturn;
}

Matrix operator*(int scalar, const Matrix& rhs)
{
	Matrix toReturn(rhs);
	toReturn *= scalar;

	return toReturn;
}

Matrix operator*(const Matrix& lhs, const Matrix& rhs)
{
	Matrix toReturn(lhs);
	toReturn *= rhs;

	return toReturn;
}

bool operator!=(const Matrix& lhs, const Matrix& rhs)
{
	return !(lhs == rhs);
}

