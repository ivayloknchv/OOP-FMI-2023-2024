#include "DynamicCollection.h"
#include <utility>

void DynamicCollection::resize(int newCapacity)
{
	int* temp = new int[newCapacity] {};

	for (int i = 0; i < size; i++)
	{
		temp[i] = data[i];
	}

	delete[] data;
	data = temp;
	temp = nullptr;
	capacity = newCapacity;
}

DynamicCollection::DynamicCollection()
{
	capacity = 8;
	data = new int[8]{};
}

DynamicCollection::DynamicCollection(const DynamicCollection& other) : Collection(other)
{
	copyFrom(other);
}

DynamicCollection& DynamicCollection::operator=(const DynamicCollection& other)
{
	if (this != &other)
	{
		Collection::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}

DynamicCollection::DynamicCollection(DynamicCollection&& other) noexcept :Collection(std::move(other))
{
	moveFrom(std::move(other));
}

DynamicCollection& DynamicCollection::operator=(DynamicCollection&& other) noexcept
{
	if (this != &other)
	{
		Collection::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

DynamicCollection::~DynamicCollection()
{
	free();
}

void DynamicCollection::copyFrom(const DynamicCollection& other)
{
	size = other.size;
	capacity = other.capacity;

	data = new int[other.capacity]{};

	for (int i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

void DynamicCollection::moveFrom(DynamicCollection&& other)
{
	data = other.data;
	size = other.size;
	capacity = other.capacity;

	other.data = nullptr;
	other.size = 0;
	other.capacity = 0;
}

void DynamicCollection::free()
{
	delete[] data;
	data = nullptr;
	size = 0;
	capacity = 0;
}
