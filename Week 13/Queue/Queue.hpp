#pragma once
#include <utility>
#include <iostream>

template<class T>
class Queue
{
	T* data = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	size_t put = 0;
	size_t get = 0;

	void copyFrom(const Queue& other);
	void moveFrom(Queue&& other);
	void free();

	void resize(size_t newCapacity);

public:

	Queue();
	Queue(const Queue& other);
	Queue<T>& operator=(const Queue& other);
	Queue(Queue&& other) noexcept;
	Queue<T> operator=(Queue&& other) noexcept;
	~Queue();

	void push(const T& obj);
	void push(T&& obj);
	void pop();


	const T& peek();
	bool isEmpty() const;

};

template<class T>
void Queue<T>::copyFrom(const Queue& other)
{
	size = other.size;
	capacity = other.capacity;

	put = other.put;
	get = other.get;

	data = new T[capacity]{};

	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

template<class T>
void Queue<T>::moveFrom(Queue&& other)
{
	data = other.data;
	other.data = nullptr;

	size = other.size;
	other.size = 0;

	capacity = other.capacity;
	other.capacity = 0;

	put = other.put;
	other.put = 0;

	get = other.get;
	other.get = 0;
}

template<class T>
void Queue<T>::free()
{
	delete[] data;
	data = nullptr;

	size = 0;
	capacity = 0;
	put = 0;
	get = 0;
}

template<class T>
void Queue<T>::resize(size_t newCapacity)
{
	T* temp = new T[newCapacity]{};

	for (size_t i = 0; i < size; i++)
	{
		temp[i] = data[get];
		(++get) %= capacity;
	}

	delete[] data;
	data = temp;
	put = size;
	get = 0;
	capacity = newCapacity;
}

template<class T>
Queue<T>::Queue()
{
	capacity = 4;
	data = new T[capacity]{};
}

template<class T>
Queue<T>::Queue(const Queue& other)
{
	copyFrom(other);
}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template<class T>
Queue<T>::Queue(Queue&& other) noexcept
{
	moveFrom(std::move(other));
}

template<class T>
Queue<T> Queue<T>::operator=(Queue&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<class T>
Queue<T>::~Queue()
{
	free();
}

template<class T>
void Queue<T>::push(const T& obj)
{
	if (size == capacity)
	{
		resize(2 * size);
	}

	data[put] = obj;
	(++put) = % capacity;
	size++;
}

template<class T>
void Queue<T>::push(T&& obj)
{
	if (size == capacity)
	{
		resize(2 * size);
	}

	data[put] = std::move(obj);
	(++put) = % capacity;
	size++;
}

template<class T>
void Queue<T>::pop()
{
	if (isEmpty())
	{
		throw std::logic_error("Empty queue!");
	}

	(++get) = % capacity;
	size--;
}

template<class T>
const T& Queue<T>::peek()
{
	if (isEmpty())
	{
		throw std::logic_error("Empty queue!");
	}

	return data[get];
}

template<class T>
bool Queue<T>::isEmpty() const
{
	return size == 0;
}
