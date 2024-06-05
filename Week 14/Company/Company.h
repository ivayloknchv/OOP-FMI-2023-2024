#pragma once
#include "Employee.h"
#include "Worker.h"
#include "Trainee.h"
#include "PaidTrainee.h"

class Company
{
private:

	static constexpr unsigned INITIAL_CAPACITY = 8;
	static constexpr double EPSILON = 0.00001;
	Employee** _data = nullptr;
	size_t _size = 0;
	size_t _capacity = 0;

	void copyFrom(const Company& other);
	void moveFrom(Company&& other);
	void free();

	void resize(size_t newCapacity);

	void add(Employee* obj);

public:

	Company();
	Company(const Company& other);
	Company& operator=(const Company& other);
	Company(Company&& other) noexcept;
	Company& operator=(Company&& other) noexcept;
	~Company();

	void addWorker(const MyString& name, unsigned age, double salary, unsigned workingMonths);
	void addTrainee(const MyString& name, unsigned age, double salary, unsigned daysLeft);
	void addPaidTrainee(const MyString& name, unsigned age, double salary, unsigned workingMonths, unsigned daysLeft, double rating);

	bool twoSum(double val) const;

	double getAvgSalary() const;
};

