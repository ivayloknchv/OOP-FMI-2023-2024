#pragma once
#include <stdexcept>

template <typename T, unsigned S>
class FiniteStack
{
	T _data[S] = {};
	size_t _size = 0;
	size_t _capacity = S;

public:

	void push(const T& arg);
	void pop();
	const T& top() const;
	const bool empty() const;
	size_t size() const;
};

template<typename T, unsigned S>
void FiniteStack<T, S>::push(const T& arg)
{
	if (_size == _capacity)
	{
		return;
	}

	_data[_size++] = arg;
}

template<typename T, unsigned S>
void FiniteStack<T, S>::pop()
{
	if (_size == 0)
	{
		return;
	}

	--_size;
}

template<typename T, unsigned S>
const T& FiniteStack<T, S>::top() const
{
	if (empty())
	{
		throw std::exception("Empty stack");
	}
	return _data[_size - 1];
}

template<typename T, unsigned S>
const bool FiniteStack<T, S>::empty() const
{
	return _size == 0;
}

template<typename T, unsigned S>
inline size_t FiniteStack<T, S>::size() const
{
	return _size;
}


