#include "OptionalDouble.h"
#pragma once

class OptionalDoubleVector
{
private:

	OptionalDouble* vector = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void copyFrom(const OptionalDoubleVector& other);
	void free();

	size_t calculateCapacity(size_t size) const;

	void resize();

public:

	OptionalDoubleVector();
	OptionalDoubleVector(const OptionalDoubleVector& other);
	OptionalDoubleVector& operator=(const OptionalDoubleVector& other);
	~OptionalDoubleVector();

	OptionalDoubleVector(size_t size);

	void push_back(const OptionalDouble& other);
	void pop_back(const OptionalDouble& other);
	void insert(const OptionalDouble& other, size_t index);
	void erase(size_t index);
	void clear();

	int getSize() const;
	int getCapacity() const;
	bool isEmpty() const;

	OptionalDouble& operator[](int index);
	const OptionalDouble& operator[](size_t index) const;
};
