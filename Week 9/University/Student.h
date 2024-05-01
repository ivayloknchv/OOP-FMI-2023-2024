#pragma once
#include <iostream>

class Student
{
private:

	char* name = nullptr;
	int fn = 0;
	int group = 0;
	double avgGrade = 0;

	void copyFrom(const Student& other);
	void moveFrom(Student&& other);
	void free();

public:

	Student() = default;
	Student(const Student& other);
	Student& operator=(const Student& other);
	Student(Student&& other) noexcept;
	Student& operator=(Student&& other) noexcept;
	~Student() noexcept;

	Student(const char* name, int fn, int group, double avgGrade);
	
	void setName(const char* name);
	void setFn(int fn);
	void setGroup(int group);
	void setAvgGrade(double avgGrade);

	const char* getName() const;
	int getFn() const;
	int getGroup() const;
	double getAvgGrade() const;

	friend std::ostream& operator<<(std::ostream& os, const Student& obj);
	friend std::istream& operator>>(std::istream& is, Student& obj);

	friend bool operator<(const Student& lhs, const Student& rhs);
	friend bool operator==(const Student& lhs, const Student& rhs);
};

