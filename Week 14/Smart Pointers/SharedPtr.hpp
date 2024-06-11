#pragma once
#include <iostream>
#include <stdexcept>

struct Counter
{
	int use_count = 0;
	int weak_count = 0;

	void removeSharedPtr()
	{
		use_count--;

		if (use_count == 0)
		{
			weak_count--;
		}
	}

	void addSharedPtr()
	{
		use_count++;

		if (use_count == 1)
		{
			weak_count++;
		}
	}

	void removeWeakPtr()
	{
		weak_count--;
	}

	void addWeakPtr()
	{
		weak_count++;
	}
};

template<class T>
class SharedPtr
{
	template <class T> 
	friend class WeakPtr;

	T* ptr = nullptr;
	Counter* counter = 0;

	void copyFrom(const SharedPtr<T>& other);
	void moveFrom(SharedPtr<T>&& other);
	void free();

public:

	SharedPtr() = default;

	SharedPtr(T* ptr);
	SharedPtr(const SharedPtr<T>& other);
	SharedPtr<T>& operator=(const SharedPtr<T>& other);
	SharedPtr(SharedPtr<T>&& other) noexcept;
	SharedPtr<T>& operator=(SharedPtr<T>&& other) noexcept;
	~SharedPtr();

	const T& operator*() const;
	T& operator*();

	const T* operator->() const;
	T* operator->();

	bool isInitialized() const;
};

template<class T>
void SharedPtr<T>::copyFrom(const SharedPtr<T>& other)
{
	ptr = other.ptr;
	counter = other.counter;

	if (counter)
	{
		counter->addSharedPtr();
	}
}

template<class T>
void SharedPtr<T>::moveFrom(SharedPtr<T>&& other)
{
	ptr = other.ptr;
	other.ptr = nullptr;

	counter = other.counter;
	other.counter = nullptr;
}

template<class T>
void SharedPtr<T>::free()
{
	if (!ptr || !counter)
	{
		return;
	}

	counter->removeSharedPtr();

	if (counter->use_count == 0)
	{
		delete data;
	}

	if (counter->weak_count == 0)
	{
		delete counter;
	}
}

template<class T>
SharedPtr<T>::SharedPtr(T* ptr)
{
	if (ptr)
	{
		this->ptr = ptr;

		counter = new Counter();
		counter->addSharedPtr();
	}
}

template<class T>
SharedPtr<T>::SharedPtr(const SharedPtr<T>& other)
{
	copyFrom(other);
}

template<class T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template<class T>
SharedPtr<T>::SharedPtr(SharedPtr<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template<class T>
SharedPtr<T>& SharedPtr<T>::operator=(SharedPtr<T>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<class T>
SharedPtr<T>::~SharedPtr()
{
	free();
}

template<class T>
const T& SharedPtr<T>::operator*() const
{
	if (!ptr)
	{
		throw std::exception("Nullptr");
	}

	return *ptr;
}

template<class T>
T& SharedPtr<T>::operator*()
{
	if (!ptr)
	{
		throw std::exception("Nullptr");
	}

	return *ptr;
}

template<class T>
const T* SharedPtr<T>::operator->() const
{
	return ptr;
}

template<class T>
T* SharedPtr<T>::operator->()
{
	return ptr;
}

template<class T>
bool SharedPtr<T>::isInitialized() const
{
	return ptr != nullptr;
}

