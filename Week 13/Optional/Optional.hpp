#pragma once
#include <iostream>
#include <exception>

template <class T>

class Optional
{
	T* data = nullptr;

	void copyFrom(const Optional<T>& other);
	void moveFrom(Optional<T>&& other);
	void free();

public:

	Optional()=default;
	Optional(const Optional<T>& other);
	Optional<T>& operator=(const Optional<T>& other);
	Optional(Optional<T>&& other) noexcept;
	Optional<T>& operator=(Optional<T>&& other) noexcept;
	~Optional();

	bool containsData() const;
	const T& getData() const;
	void setData(const T& obj);
	void clear();


};

template<class T>
void Optional<T>::copyFrom(const Optional<T>& other)
{
	if (other.data == nullptr)
	{
		data = nullptr;
		return;
	}

	data = new T(other.data);
}

template<class T>
void Optional<T>::moveFrom(Optional<T>&& other)
{
	data = other.data;
	other.data = nullptr;
}

template<class T>
void Optional<T>::free()
{
	delete data;
	data = nullptr;
}

template<class T>
Optional<T>::Optional(const Optional<T>& other)
{
	copyFrom(other);
}

template<class T>
Optional<T>& Optional<T>::operator=(const Optional<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template<class T>
Optional<T>::Optional(Optional<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template<class T>
 Optional<T>& Optional<T>::operator=(Optional<T>&& other) noexcept
{
	 if (this != &other)
	 {
		 free();
		 moveFrom(std::move(other));
	}
}

template<class T>
Optional<T>::~Optional()
{
	free();
}

template<class T>
bool Optional<T>::containsData() const
{
	return data != nullptr;
}

template<class T>
const T& Optional<T>::getData() const
{
	if (!data)
	{
		throw std::logic_error("No data in optional");
	}
	return *data;
}

template<class T>
void Optional<T>::setData(const T& obj)
{
	delete data;
	data = new T(obj);
}

template<class T>
void Optional<T>::clear()
{
	free();
}
