#pragma once
#include <iostream>

class MyVector
{
private:

	int* data = nullptr;
	int size = 0;
	int capacity = 0;

	void copyFrom(const MyVector& other);
	void moveFrom(MyVector&& other);
	void free();

	void resizeHelper(int newCapacity, int defVal);
	void fillDefaultValues(int defVal);
	void rearrange(const int* arr, int size, int idx);
public:
	MyVector();
	MyVector(const MyVector& other);
	MyVector& operator=(const MyVector& other);
	MyVector(MyVector&& other) noexcept;
	MyVector& operator=(MyVector&& other) noexcept;
	~MyVector() noexcept;

	bool isEmpty() const;

	void pushBack(int element);
	void popBack();

	int at(int idx) const;
	int& at(int idx);
	
	int& front() const;
	int& back() const;

	int getSize() const;
	int getCapacity() const;

	void reserve(int newCapacity);
	void shrinkToFit();
	void clear();

	void insert(int element, int idx = 0);

	void insertRange(const MyVector& other, int idx);
	void insertRange(const int* arr, int size, int idx);

	void erase(int element, bool allOccurances);
	void resize(int newCount);
	void resize(int newCount, int value);

	int operator[](int idx) const;
	int& operator[](int idx);

	friend bool operator==(const MyVector& lhs, const MyVector& rhs);
	friend bool operator!=(const MyVector& lhs, const MyVector& rhs);
	friend bool operator<(const MyVector& lhs, const MyVector& rhs);
	friend bool operator<=(const MyVector& lhs, const MyVector& rhs);
	friend bool operator>(const MyVector& lhs, const MyVector& rhs);
	friend bool operator>=(const MyVector& lhs, const MyVector& rhs);

	friend std::ostream& operator<<(std::ostream& os, const MyVector& obj);
};

