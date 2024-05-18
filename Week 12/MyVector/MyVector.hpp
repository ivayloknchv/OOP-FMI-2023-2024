#pragma once
#include <iostream>
#include <utility>

template <typename T>
class MyVector
{
private:

	T* _data = nullptr;
	size_t _size = 0;
	size_t _capacity = 0;

	void copyFrom(const MyVector& other);
	void moveFrom(MyVector&& other);
	void free();

	void resize(size_t newCapacity);
	void shiftRightIntrernal(size_t idx);

public:

	MyVector();
	MyVector(const MyVector& other);
	MyVector& operator=(const MyVector& other);
	MyVector(MyVector&& other) noexcept;
	MyVector& operator=(MyVector&& other) noexcept;
	~MyVector() noexcept;

	void push_back(const T& obj);
	void push_back(T&& obj);

	void pop_back();
	void insert(const T& obj, size_t idx);
	void insert(T&& obj, size_t idx);
	void erase(size_t idx);
	void clear();
	size_t size() const;
};

template<typename T>
void MyVector<T>::free()
{
	delete[] _data;
	_data = nullptr;
	_size = _capacity = 0;
}

template<typename T>
void MyVector<T>::copyFrom(const MyVector& other)
{
	_size = other._size;
	_capacity = other._capacity;
	_data = new T[_capacity]{};

	for (int i = 0; i < _size; i++)
	{
		_data[i] = other._data[i];
	}
}

template<typename T>
void MyVector<T>::moveFrom(MyVector&& other)
{
	_data = other._data;
	other._data = nullptr;

	_size = other._size;
	other._size = 0;

	_capacity = other._capacity;
	other._capacity = 0;
}

template<typename T>
void MyVector<T>::resize(size_t newCapacity)
{
	T* temp = new T[newCapacity]{};

	for (int i = 0; i < _size; i++)
	{
		temp[i] = _data[i];
	}

	delete[] _data;
	_data = temp;
	temp = nullptr;
	_capacity = newCapacity;
}

template<typename T>
void MyVector<T>::shiftRightIntrernal(size_t idx)
{
	if (_size == _capacity)
	{
		resize(2 * _capacity);
	}

	for (int i = size - 1; i >= idx; i--)
	{
		_data[i + 1] = _data[i];
	}
}

template<typename T>
MyVector<T>::MyVector()
{
	_capacity = 8;
	_data = new T[_capacity]{};
}

template<typename T>
MyVector<T>::MyVector(const MyVector& other)
{
	copyFrom(other);
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
MyVector<T>::MyVector(MyVector&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(MyVector&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<typename T>
MyVector<T>::~MyVector() noexcept
{
	free();
}

template<typename T>
void MyVector<T>::push_back(const T& obj)
{
	if (_size == _capacity)
	{
		resize(2 * _capacity);
	}

	_data[_size++] = obj;
}

template<typename T>
void MyVector<T>::push_back(T&& obj)
{
	if (_size == _capacity)
	{
		resize(2 * _capacity);
	}

	_data[_size++] = std::move(obj);
}

template<typename T>
void MyVector<T>::pop_back()
{
	if (_size > 0)
	{
		--_size;
	}
}

template<typename T>
void MyVector<T>::insert(const T& obj, size_t idx)
{
	if (idx < 0 || idx >= size)
	{
		return;
	}

	shiftRightIntrernal(idx);

	_data[idx] = obj;
	size++;
}

template<typename T>
void MyVector<T>::insert(T&& obj, size_t idx)
{
	if (idx < 0 || idx >= size)
	{
		return;
	}

	shiftRightIntrernal(idx);

	_data[idx] = std::move(obj);
	size++;
}

template<typename T>
void MyVector<T>::erase(size_t idx)
{
	if (idx < 0 || idx >= _size)
	{
		return;
	}

	for (int i = idx; i < size - 1; i++)
	{
		_data[i] = _data[i + 1];
	}

	--size;
}

template<typename T>
void MyVector<T>::clear()
{
	delete[] _data;
	_size = 0;
	_capacity = 8;

	_data = new T[_capacity]{};
}

template<typename T>
size_t MyVector<T>::size() const
{
	return _size;
}
