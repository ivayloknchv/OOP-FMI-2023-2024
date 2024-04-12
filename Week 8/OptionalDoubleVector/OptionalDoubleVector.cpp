#include "OptionalDoubleVector.h"

void OptionalDoubleVector::copyFrom(const OptionalDoubleVector& other)
{
	size = other.size;
	capacity = other.capacity;

	vector = new OptionalDouble[capacity];

	for (size_t i = 0; i < size; i++)
	{
		vector[i] = other.vector[i];
	}
}

void OptionalDoubleVector::free()
{
	delete[] vector;
	size = 0;
	capacity = 0;
}

size_t OptionalDoubleVector::calculateCapacity(size_t size) const
{
	return 2 * size;
}

void OptionalDoubleVector::resize()
{
	capacity = calculateCapacity(size);

	OptionalDouble* temp = new OptionalDouble[capacity];

	for (size_t i = 0; i < size; i++)
	{
		temp[i] = vector[i];
	}

	delete[] vector;
	vector = temp;
	temp = nullptr;
}

OptionalDoubleVector::OptionalDoubleVector():OptionalDoubleVector(8)
{}

OptionalDoubleVector::OptionalDoubleVector(const OptionalDoubleVector & other)
{
	copyFrom(other);
}

OptionalDoubleVector& OptionalDoubleVector::operator=(const OptionalDoubleVector& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

OptionalDoubleVector::~OptionalDoubleVector()
{
	free();
}

OptionalDoubleVector::OptionalDoubleVector(size_t size)
{
	this->size = size;
	capacity = calculateCapacity(size);
	vector = new OptionalDouble[capacity];
}

void OptionalDoubleVector::push_back(const OptionalDouble& other)
{
	if (size == capacity)
	{
		resize();
	}

	vector[size++] = other;
}

void OptionalDoubleVector::pop_back(const OptionalDouble& other)
{

}

bool OptionalDoubleVector::isEmpty() const
{
	return (size==0);
}
