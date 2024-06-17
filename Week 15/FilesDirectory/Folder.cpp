#include "Folder.h"
#include <utility>
#include <iostream>

void Folder::copyFrom(const Folder& other)
{
	files = new File * [other.capacity]{};

	for (size_t i = 0; i < size; i++)
	{
		files[i] = other.files[i]->clone();
	}

	capacity = other.capacity;
	size = other.size;
}

void Folder::moveFrom(Folder&& other)
{
	files = other.files;
	other.files = nullptr;

	size = other.size;
	other.size = 0;

	capacity = other.capacity;
	other.capacity = 0;
}

void Folder::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete files[i];
	}

	delete[] files;
	files = nullptr;

	size = capacity = 0;
}

void Folder::resize(size_t newCapacity)
{
	File** temp = new File * [newCapacity] {};

	for (size_t i = 0; i < size; i++)
	{
		temp[i] = files[i];
	}

	delete[] files;
	files = temp;
	capacity = newCapacity;
	temp = nullptr;
}

Folder::Folder(const char* name) : File(name)
{
	capacity = 8;
	files = new File * [capacity] {};
}

Folder::Folder(const Folder& other) : File(other)
{
	copyFrom(other);
}

Folder& Folder::operator=(const Folder& other)
{
	if (this != &other)
	{
		File::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}

Folder::Folder(Folder&& other) noexcept : File(std::move(other))
{
	moveFrom(std::move(other));
}

Folder& Folder::operator=(Folder&& other) noexcept 
{
	if (this != &other)
	{
		File::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Folder::~Folder()
{
	free();
}

File* Folder::clone() const
{
	return new Folder(*this);
}

void Folder::print() const
{
	std::cout << "Folder: " << fileName<<std::endl;
	for (size_t i = 0; i < size; i++)
	{
		std::cout << "	";
		files[i]->print();
	}
}

void Folder::addFile(File* other)
{
	if (size == capacity)
	{
		resize(2 * size);
	}

	files[size++] = other;
}

double Folder::getSize() const
{
	double toReturn = 0;

	for (size_t i = 0; i < size; i++)
	{
		toReturn += files[i]->getSize();
	}
	return toReturn;
}