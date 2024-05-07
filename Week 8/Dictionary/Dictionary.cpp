#include "Dictionary.h"
#include <cstring>
#include <stdexcept>
#include <utility>
#include <iostream>

#pragma warning (disable : 4996)

void Dictionary::Pair::setKey(const char* key)
{
	this->key = new char[strlen(key) + 1]{};
	strcpy(this->key, key);
}

void Dictionary::Pair::setValue(const char* value)
{
	this->value = new char[strlen(value) + 1]{};
	strcpy(this->value, value);
}

void Dictionary::copyFrom(const Dictionary& other)
{
	size = other.size;
	capacity = other.capacity;

	pairs = new Pair[capacity]{};

	for (int i = 0; i < size; i++)
	{
		pairs[i].setKey(other.pairs[i].key);
		pairs[i].setValue(other.pairs[i].value);
	}
}

void Dictionary::moveFrom(Dictionary&& other)
{
	pairs = other.pairs;
	other.pairs = nullptr;

	size = other.size;
	other.size = 0;

	capacity = other.capacity;
	other.capacity = 0;
}

void Dictionary::free()
{
	for (int i = 0; i < size; i++)
	{
		delete[] pairs[i].key;
		delete[] pairs[i].value;
	}

	delete[] pairs;
	pairs = nullptr;

	size = 0;
	capacity = 0;
}

void Dictionary::resize(int newCapacity)
{
	Pair* temp = new Pair[newCapacity]{};

	for (int i = 0; i < size; i++)
	{
		temp[i] = pairs[i];
	}

	delete[] pairs;
	pairs = temp;
	capacity = newCapacity;
	temp = nullptr;
}

int Dictionary::findWord(const char* word, bool& isFound)
{
	isFound = 0;

	int left = 0;
	int right = size - 1;

	while (left <= right)
	{
		int mid = (right - left) / 2 + left;

		int cmp = strcmp(word, pairs[mid].key);

		if (cmp == 0)
		{
			isFound = true;
			return mid;
		}

		else if (cmp == -1)
		{
			right = mid - 1;
		}

		else if (cmp == 1)
		{
			left = mid + 1;
		}
	}

	return left;
}

Dictionary::Dictionary()
{
	capacity = 8;

	pairs = new Pair[capacity]{};
}

Dictionary::Dictionary(const Dictionary& other)
{
	copyFrom(other);
}

Dictionary& Dictionary::operator=(const Dictionary& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Dictionary::Dictionary(Dictionary&& other) noexcept
{
	moveFrom(std::move(other));
}

Dictionary& Dictionary::operator=(Dictionary&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Dictionary::~Dictionary() noexcept
{
	free();
}

void Dictionary::add(const char* word, const char* description)
{
	if (!word || !description)
	{
		throw std::invalid_argument("Nullptr detected!");
	}

	bool isFound = false;

	int idx = findWord(word, isFound);

	if (isFound)
	{
		delete[] pairs[idx].value;
		pairs[idx].setValue(description);
	}

	else
	{
		addInternal(idx, word, description);
	}
}

void Dictionary::remove(const char* word)
{
	bool isFound = false;

	int idx = findWord(word, isFound);

	if (!isFound)
	{
		return;
	}

	else
	{
		removeInternal(idx);
	}
}

void Dictionary::print() const
{
	for (int i = 0; i < size; i++)
	{
		std::cout << i + 1 << ") " << pairs[i].key << " - " << pairs[i].value << std::endl;
	}
	std::cout << std::endl;
}

const char* Dictionary::operator()(const char* word)
{
	if (!word)
	{
		throw std::invalid_argument("Nullptr detected!");
	}

	bool isFound = false;
	int idx = findWord(word, isFound);

	if (isFound)
	{
		return pairs[idx].value;
	}

	else
	{
		return "The word doesn't exist";
	}
}

Dictionary& Dictionary::operator+=(const Dictionary& other)
{
	for (int i = 0; i < other.size; i++)
	{
		add(other.pairs[i].key, other.pairs[i].value);
	}

	return *this;
}

void Dictionary::addInternal(int idx, const char* word, const char* description)
{
	if (size == capacity)
	{
		resize(2 * capacity);
	}

	for (int i = size - 1; i >= idx; i--)
	{
		pairs[i + 1] = pairs[i];
	}

	pairs[idx].setKey(word);
	pairs[idx].setValue(description);
	size++;
}

void Dictionary::removeInternal(int idx)
{
	delete[] pairs[idx].key;
	delete[] pairs[idx].value;
	pairs[idx].key = nullptr;
	pairs[idx].value = nullptr;

	for (int i = idx; i < size-1; i++)
	{
		pairs[i] = pairs[i + 1];
	}

	pairs[size - 1].key = nullptr;
	pairs[size - 1].value = nullptr;

	size--;
}

Dictionary operator+(const Dictionary& lhs, const Dictionary& rhs)
{
	Dictionary toReturn = lhs;
	toReturn += rhs;

	return toReturn;
}
