#include "StringPool.h"
#include <cstring>
#include <stdexcept>

#pragma warning (disable : 4996)

void StringPool::resize(int newCapacity)
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

int StringPool::findString(const char* str, bool& isFound) const
{
	int left = 0;
	int right = size - 1;

	isFound = false;

	while (left <= right)
	{
		int mid = (right - left) / 2 + left;

		int cmp = strcmp(str, nodes[mid].data);

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

void StringPool::insertInternal(const char* str, int idx)
{
	if (size == capacity)
	{
		resize(2 * capacity);
	}

	for (int i = size-1; i >= idx; i--)
	{
		nodes[i + 1] = nodes[i];
	}

	size++;
	nodes[idx].allocateData(str);
	nodes[idx].refCount=1;
}

void StringPool::removeInternal(int idx)
{
	delete[] nodes[idx].data;
	nodes[idx].data = nullptr;
	for (int i = idx; i < size-1; i++)
	{
		nodes[i] = nodes[i + 1];
	}

	nodes[size - 1].data = nullptr;
	nodes[size - 1].refCount = 0;

	size--;

}

StringPool::StringPool()
{
	capacity = 8;
	nodes = new StringNode[capacity]{};
}

StringPool::~StringPool()
{
	for (int i = 0; i < size; i++)
	{
		delete[] nodes[i].data;
		nodes[i].data = nullptr;
		nodes[i].refCount = 0;
	}

	delete[] nodes;
	nodes = nullptr;
	size = 0;
	capacity = 0;
}

const char* StringPool::getString(const char* str)
{
	if (!str)
	{
		throw std::invalid_argument("Nullptr detected!");
	}

	bool isFound = false;
	int idx = findString(str, isFound);

	if (isFound)
	{
		nodes[idx].refCount++;
		return nodes[idx].data;
	}

	else
	{
		insertInternal(str, idx);
	}
	return nodes[idx].data;
}

void StringPool::removeString(const char* str)
{
	if (!str)
	{
		throw std::invalid_argument("Nullptr detected!");
	}

	bool isFound = false;
	int idx = 0;

	if (isFound)
	{
		nodes[idx].refCount--;

		if (nodes[idx].refCount == 0)
		{
			removeInternal(idx);
		}
	}
}

void StringPool::StringNode::allocateData(const char* newData)
{
	data = new char[strlen(newData) + 1]{};
	strcpy(data, newData);
}
