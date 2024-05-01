#pragma once
#include "Student.h"

class University
{
private:

	Student** students = nullptr;
	int size = 0;
	int capacity = 0;

	void copyFrom(const University& other);
	void moveFrom(University&& other);
	void free();

	int getStudentByFn(int fn);
	void resize(int newCapacity);

public:

	University();
	University(const University& other);
	University& operator=(const University& other);
	University(University&& other) noexcept;
	University& operator=(University&& other) noexcept;
	~University() noexcept;

	void sort(bool(*pred)(const Student& lhs, const Student& rhs));
	void filter(bool(*pred)(const Student& obj)) const;

	University& operator+=(const Student& st);
	University& operator-=(int fn);

	Student& operator[](int idx);
	const Student& operator[](int idx) const;

	friend std::ostream& operator<<(std::ostream& os, const University& obj);
	friend std::istream& operator>>(std::istream& is, University& obj);
};

