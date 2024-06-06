#pragma once
#include <utility>
#include <stdexcept>

template <class T>
class polymorphic_ptr
{
	T* ptr = nullptr;

	void copyFrom(const polymorphic_ptr<T>& other);
	void moveFrom(polymorphic_ptr<T>&& other);
	void free();

public:

	polymorphic_ptr(T* obj);

	polymorphic_ptr() = default;
	polymorphic_ptr(const polymorphic_ptr<T>& other);
	polymorphic_ptr<T>& operator=(const polymorphic_ptr<T>& other);
	polymorphic_ptr(polymorphic_ptr<T>&& other) noexcept;
	polymorphic_ptr<T> operator=(polymorphic_ptr<T>&& other) noexcept;
	~polymorphic_ptr();

	const T* operator -> () const;
	T* operator -> ();

	const T& operator* () const;
	T& operator* ();

	void reset();

	const operator bool() const;

	const T* get() const;
	T* get();
};

template<class T>
void polymorphic_ptr<T>::copyFrom(const polymorphic_ptr<T>& other)
{
	ptr = (other.ptr == nullptr) ? nullptr : other.clone();
}

template<class T>
void polymorphic_ptr<T>::moveFrom(polymorphic_ptr<T>&& other)
{
	ptr = other.ptr;
	other.ptr = nullptr;
}

template<class T>
void polymorphic_ptr<T>::free()
{
	delete ptr;
	ptr = nullptr;
}

template<class T>
polymorphic_ptr<T>::polymorphic_ptr(T* obj)
{
	ptr = obj;
}

template<class T>
polymorphic_ptr<T>::polymorphic_ptr(const polymorphic_ptr<T>& other)
{
	copyFrom(other);
}

template<class T>
polymorphic_ptr<T>& polymorphic_ptr<T>::operator=(const polymorphic_ptr<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template<class T>
polymorphic_ptr<T>::polymorphic_ptr(polymorphic_ptr<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template<class T>
polymorphic_ptr<T> polymorphic_ptr<T>::operator=(polymorphic_ptr<T>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<class T>
polymorphic_ptr<T>::~polymorphic_ptr()
{
	free();
}

template<class T>
const T* polymorphic_ptr<T>::operator->() const
{
	return ptr;
}

template<class T>
T* polymorphic_ptr<T>::operator->()
{
	return ptr;
}

template<class T>
const T& polymorphic_ptr<T>::operator*() const
{
	if (!ptr)
	{
		throw std::exception("nullptr");
	}
	return *ptr;
}

template<class T>
T& polymorphic_ptr<T>::operator*()
{
	if (!ptr)
	{
		throw std::exception("nullptr");
	}
	return *ptr;
}

template<class T>
void polymorphic_ptr<T>::reset()
{
	free();
}

template<class T>
polymorphic_ptr<T>::operator bool() const
{
	return (ptr == nullptr);
}

template<class T>
const T* polymorphic_ptr<T>::get() const
{
	return ptr;
}

template<class T>
T* polymorphic_ptr<T>::get()
{
	return ptr;
}
