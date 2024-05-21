#pragma once
#include <cstring>
#include <stdexcept>
#include <utility>

#pragma warning (disable : 4996)

template<class T>
class KeyValuePairs
{
	struct Node
	{
		char* key;
		T value;

		void setKey(const char* newKey);
		void setValue(const T& newValue);
	};

	Node* nodes = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void copyFrom(const KeyValuePairs& other);
	void moveFrom(KeyValuePairs&& other);
	void free();

	void resize(size_t newCapacity);

	size_t findByKey(const char* key);

public:

	KeyValuePairs();
	KeyValuePairs(const KeyValuePairs& other);
	KeyValuePairs& operator=(const KeyValuePairs& other);
	KeyValuePairs(KeyValuePairs&& other)noexcept;
	KeyValuePairs& operator=(KeyValuePairs&& other) noexcept;
	~KeyValuePairs() noexcept;

	void set(const char* newKey, const T& newValue);
	const T& get(const char* key);
	void remove(const char* key);
	size_t count() const;
};

template<class T>
void KeyValuePairs<T>::Node::setKey(const char* newKey)
{
	if (!newKey || newKey == key)
	{
		return;
	}

	delete[] key;
	key = new char[strlen(newKey) + 1]{};
	strcpy(key, newKey);
}

template<class T>
void KeyValuePairs<T>::Node::setValue(const T& newValue)
{
	value = newValue;
}

template<class T>
void KeyValuePairs<T>::copyFrom(const KeyValuePairs& other)
{
	size = other.size;
	capacity = other.capacity;
	nodes = new T[capacity]{};

	for (size_t i = 0; i < size; i++)
	{
		nodes[i].setKey(other.nodes[i].key);
		nodes[i].setValue(other.nodes[i].value);
	}
}

template<class T>
void KeyValuePairs<T>::moveFrom(KeyValuePairs&& other)
{
	nodes = other.nodes;
	other.nodes = nullptr;

	size = other.size;
	other.size = 0;

	capacity = other.capacity;
	other.capacity = 0;
}

template<class T>
void KeyValuePairs<T>::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete[] nodes[i].key;
		nodes[i].key = nullptr;
	}

	delete[] nodes;
	nodes = nullptr;

	size = 0;
	capacity = 0;
}

template<class T>
void KeyValuePairs<T>::resize(size_t newCapacity)
{
	Node* temp = new Node[newCapacity]{};

	for (size_t i = 0; i < size; i++)
	{
		temp[i] = nodes[i];
	}

	delete[] nodes;
	nodes = temp;
	capacity = newCapacity;
	temp = nullptr;
}

template<class T>
size_t KeyValuePairs<T>::findByKey(const char* key)
{
	for (size_t i = 0; i < size; i++)
	{
		if (!strcmp(key, nodes[i].key))
		{
			return i;
		}
	}

	return size;
}

template<class T>
KeyValuePairs<T>::KeyValuePairs()
{
	capacity = 8;
	nodes = new Node[capacity]{};
}

template<class T>
KeyValuePairs<T>::KeyValuePairs(const KeyValuePairs& other)
{
	copyFrom(other);
}

template<class T>
KeyValuePairs<T>& KeyValuePairs<T>::operator=(const KeyValuePairs& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template<class T>
KeyValuePairs<T>::KeyValuePairs(KeyValuePairs&& other) noexcept
{
	moveFrom(std::move(other));
}

template<class T>
KeyValuePairs<T>& KeyValuePairs<T>::operator=(KeyValuePairs&& other) noexcept
{
	if (this != &other)
	{
		free();
		copyFrom(std::move(other));
	}

	return *this;
}

template<class T>
KeyValuePairs<T>::~KeyValuePairs() noexcept
{
	free();
}

template<class T>
void KeyValuePairs<T>::set(const char* newKey, const T& newValue)
{
	if (!newKey)
	{
		return;
	}

	size_t idx = findByKey(newKey);

	if (idx < size)
	{
		nodes[idx].setValue(newValue);
	}

	else
	{
		if (size == capacity)
		{
			resize(2 * capacity);
		}

		nodes[size].setKey(newKey);
		nodes[size].setValue(newValue);
		size++;
	}
}

template<class T>
const T& KeyValuePairs<T>::get(const char* key)
{
	try
	{
		if (!key)
		{
			throw std::invalid_argument("Nullptr detected!");
		}
	}

	catch (std::invalid_argument& exc)
	{
		std::cout << exc.what() << std::endl;
	}

	size_t idx = findByKey(key);



	try
	{
		if (idx == size)
		{
			throw std::invalid_argument("Such key doesn't exist!");
		}

	}

	catch (std::invalid_argument& exc)
	{
		std::cout << exc.what() << std::endl;
	}

	return nodes[idx].value;
}

template<class T>
void KeyValuePairs<T>::remove(const char* key)
{
	if (!key)
	{
		return;
	}

	size_t idx = findByKey(key);

	if (idx == size)
	{
		return;
	}

	std::swap(nodes[idx], nodes[size - 1]);
	delete[] nodes[size-1].key;
	--size;
}

template<class T>
size_t KeyValuePairs<T>::count() const
{
	return size;
}