#include <iostream>

template<class T>
class UniquePtr
{
	T* data = nullptr;

	void moveFrom(const UniquePtr<T>&& other);
	void free();

public:

	UniquePtr(T* obj);

	UniquePtr(const UniquePtr<T>& other) = delete;
	UniquePtr<T>& operator=(const UniquePtr<T>& other) = delete;

	UniquePtr(UniquePtr<T>&& other) noexcept;
	UniquePtr<T> operator=(UniquePtr<T>&& other) noexcept;

	~UniquePtr();

	const T& operator*() const;
	T& operator*();

	const T* operator->() const;
	T* operator->();
};


template<class T>
void UniquePtr<T>::moveFrom(const UniquePtr<T>&& other)
{
	ptr = other.ptr;
	other.ptr = nullptr;
}

template<class T>
void UniquePtr<T>::free()
{
	delete ptr;
}

template<class T>
UniquePtr<T>::UniquePtr(T* obj)
{
	ptr = obj;
}

template<class T>
UniquePtr<T>::UniquePtr(UniquePtr<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template<class T>
UniquePtr<T> UniquePtr<T>::operator=(UniquePtr<T>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<class T>
UniquePtr<T>::~UniquePtr()
{
	free();
}

template<class T>
const T& UniquePtr<T>::operator*() const
{
	*ptr;
}

template<class T>
T& UniquePtr<T>::operator*()
{
	return *ptr;
}

template<class T>
const T* UniquePtr<T>::operator->() const
{
	return ptr;
}

template<class T>
T* UniquePtr<T>::operator->()
{
	return ptr;
}
