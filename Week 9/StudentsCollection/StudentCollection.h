#pragma once
#include "Student.h"

class StudentCollection
{
	Student** data = nullptr;
	int capacity = 0;
	int size = 0;

	void copyFrom(const StudentCollection& other);
	void moveFrom(StudentCollection&& other);
	void free();

	void resize(int newCapacity);
	int getFirstFreeIndex() const;
public:

	StudentCollection();
	StudentCollection(const StudentCollection& other);
	StudentCollection& operator= (const StudentCollection& other);
	StudentCollection(StudentCollection&& other) noexcept;
	StudentCollection& operator= (StudentCollection&& other) noexcept;
	~StudentCollection();

	void push(const Student& obj);
	void push(Student&& obj);

	void pushAt(int idx, const Student& obj);
	void pushAt(int idx, Student&& obj);

	void removeAt(int idx);
	const Student& getAt(int idx) const;

	int getNumberInClass(const Student& obj) const;
	int getNumberInClass(const MyString& name) const;
	
	bool containsAt(int idx) const;
};

