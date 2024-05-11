#pragma once
#include "Collection.h"

class DynamicCollection : public Collection
{
protected:

	int* data = 0;
	int size = 0;
	int capacity = 0;


	void copyFrom(const DynamicCollection& other);
	void moveFrom(DynamicCollection&& other);
	void free();
	void resize(int newCapacity);

public:

	DynamicCollection();
	DynamicCollection(const DynamicCollection& other);
	DynamicCollection& operator=(const DynamicCollection& other);
	DynamicCollection(DynamicCollection&& other) noexcept;
	DynamicCollection& operator=(DynamicCollection&& other) noexcept;
	~DynamicCollection();

	
};

