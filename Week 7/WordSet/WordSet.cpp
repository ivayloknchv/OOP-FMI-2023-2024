#include "WordSet.h"
#include <cstring>
#include <utility>
#include <stdexcept>

#pragma warning (disable : 4996)

void WordSet::StringNode::allocateData(const char* newData)
{
	data = new char[strlen(newData) + 1]{};
	strcpy(data, newData);
}

void WordSet::copyFrom(const WordSet& other)
{
	size = other.size;
	capacity = other.capacity;
	nodes = new StringNode[capacity]{};

	for (int i = 0; i < size; i++)
	{
		nodes[i].allocateData(other.nodes[i].data);
	}
}

void WordSet::moveFrom(WordSet&& other)
{
	nodes = other.nodes;
	other.nodes = nullptr;

	size = other.size;
	other.size = 0;

	capacity = other.capacity;
	other.capacity = 0;
}

void WordSet::free()
{
	for (int i = 0; i < capacity; i++)
	{
		delete[] nodes[i].data;
		nodes[i].data = nullptr;
	}

	delete[] nodes;

	nodes = nullptr;

	size = capacity = 0;
}

int WordSet::findWord(const char* word, bool& isFound) const
{
	int left = 0;
	int right = size - 1;

	isFound = false;

	while (left <= right)
	{
		int mid = (right - left) / 2 + left;

		int compare = strcmp(word, nodes[mid].data);

		if (compare == 0)
		{
			isFound = true;
			return mid;
		}

		else if (compare < 0)
		{
			right = mid - 1;
		}

		else if (compare > 0)
		{
			left = mid + 1;
		}
	}

	return left;
}


void WordSet::resize(int newCapacity)
{
	StringNode* temp = new StringNode[newCapacity]{};

	for (int i = 0; i < size; i++)
	{
		temp[i] = nodes[i];
	}

	delete[] nodes;

	nodes = temp;
	temp = nullptr;
	capacity = newCapacity;
}

void WordSet::addString(const char* word, int idx)
{
	if (size == capacity)
	{
		resize(2 * size);
	}

	for (int i = size - 1; i >= idx; i--)
	{
		nodes[i + 1] = nodes[i];
	}

	nodes[idx].allocateData(word);

	size++;
}

void WordSet::removeString(const char* word, int idx)
{
	delete[] nodes[idx].data;
	nodes[idx].data = nullptr;
	for (int i = idx; i < size - 1; i++)
	{
		nodes[i] = nodes[i + 1];
	}

	nodes[size - 1].data = nullptr;
	size--;
}

WordSet::WordSet()
{
	capacity = 8;
	nodes = new StringNode[8]{};
}

WordSet::WordSet(const WordSet& other)
{
	copyFrom(other);
}

WordSet& WordSet::operator=(const WordSet& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

WordSet::WordSet(WordSet&& other) noexcept
{
	moveFrom(std::move(other));
}

WordSet& WordSet::operator=(WordSet&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

WordSet::~WordSet() noexcept
{
	free();
}

WordSet& WordSet::operator+=(const WordSet& other)
{
	for (int i = 0; i < other.size; i++)
	{
		this->operator*=(other.nodes[i].data);
	}
	return *this;
}

WordSet& WordSet::operator-=(const WordSet& other)
{
	for (int i = 0; i < other.size; i++)
	{
		this->operator/=(other.nodes[i].data);
	}
	return *this;
}

bool WordSet::operator[](const char* word) const
{
	if (!word)
	{
		throw std::invalid_argument("Nullptr detected!");
	}

	bool toReturn = false;
	int idx = findWord(word, toReturn);

	return toReturn;
}

WordSet& WordSet::operator*=(const char* word)
{

	if (!word)
	{
		throw std::invalid_argument("Nullptr detected!");
	}

	bool isFound = false;

	int idx = findWord(word, isFound);


	if (!isFound)
	{
		addString(word, idx);
	}

	return *this;
}

WordSet& WordSet::operator/=(const char* word)
{
	if (!word)
	{
		throw std::invalid_argument("Nullptr detected!");
	}

	bool isFound = false;

	int idx = findWord(word, isFound);

	if (isFound)
	{
		removeString(word, idx);
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const WordSet& obj)
{
	os << "{ ";

		for (int i = 0; i < obj.size; i++)
		{
			os << obj.nodes[i].data;

			if (i != obj.size - 1)
			{
				os << ", ";
			}
		}

		os << " }"<<std::endl;

		return os;
}

std::istream& operator>>(std::istream& is, WordSet& obj)
{
	char buff[1024]{};

	is >> buff;

	obj *= buff;
	return is;
}

WordSet operator+(const WordSet& lhs, const WordSet& rhs)
{
	WordSet toReturn = lhs;
	toReturn += rhs;

	return toReturn;
}

WordSet operator-(const WordSet& lhs, const WordSet& rhs)
{
	WordSet toReturn = lhs;
	toReturn -= rhs;

	return toReturn;
}
