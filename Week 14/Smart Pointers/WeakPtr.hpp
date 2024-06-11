#pragma once
#include "SharedPtr.hpp"
#include <stdexcept>
#include <utility>

template<class T>
class WeakPtr
{
	T* ptr = nullptr;
	Counter* counter = nullptr;

	void copyFrom(const WeakPtr<T>& other);
	void moveFrom(WeakPtr<T>&& other);
	void free();

public:

	WeakPtr() = default;
	WeakPtr(const SharedPtr<T>& obj);

	WeakPtr(const WeakPtr<T>& other);
	WeakPtr<T>& operator=(const WeakPtr<T>& other);

	WeakPtr(WeakPtr<T>&& other) noexcept;
	WeakPtr<T>& operator=(WeakPtr<T>&& other) noexcept;

	~WeakPtr();

	SharedPtr<T> lock() const;

	bool expired() const;
};

template<class T>
void WeakPtr<T>::copyFrom(const WeakPtr<T>& other)
{
	ptr = other.ptr;
	counter = other.counter;

	if (counter != nullptr)
	{
		counter->addWeakPtr();
	}
}

template<class T>
void WeakPtr<T>::moveFrom(WeakPtr<T>&& other)
{
	ptr = other.ptr;
	other.ptr = nullptr;

	counter = other.counter;
	other.counter = nullptr;
}

template<class T>
void WeakPtr<T>::free()
{
	if (!ptr || !counter)
	{
		return;
	}
	
	counter->removeWeakPtr();

	if (counter->weak_count == 0)
	{
		delete counter;
	}
}

template<class T>
WeakPtr<T>::WeakPtr(const SharedPtr<T>& obj)
{
	ptr = obj.ptr;
	counter = obj.counter;

	if (counter)
	{
		counter->addWeakPtr();
	}
}

template<class T>
WeakPtr<T>::WeakPtr(const WeakPtr<T>& other)
{
	copyFrom(other);
}

template<class T>
WeakPtr<T>& WeakPtr<T>::operator=(const WeakPtr<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template<class T>
WeakPtr<T>::WeakPtr(WeakPtr<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template<class T>
WeakPtr<T>& WeakPtr<T>::operator=(WeakPtr<T>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<class T>
WeakPtr<T>::~WeakPtr()
{
	free();
}

template<class T>
SharedPtr<T> WeakPtr<T>::lock() const
{
	if (!expired())
	{
		return SharedPtr<T>(ptr);
	}

	return SharedPtr<T>();
}

template<class T>
bool WeakPtr<T>::expired() const
{
	return counter && counter->use_count == 0;
}
