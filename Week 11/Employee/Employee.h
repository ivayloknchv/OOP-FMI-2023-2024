#pragma once
#include <iostream>
class Employee
{
	
private:

	void copyFrom(const Employee& other);
	void moveFrom(Employee&& other);
	void free();

protected:

	char* name = nullptr;
	double salary;

public:

	Employee() = default;
	Employee(const Employee& other);
	Employee& operator=(const Employee& other);
	Employee(Employee&& other) noexcept;
	Employee& operator=(Employee&& other) noexcept;
	virtual~Employee();

	Employee(const char* name, double salary);

	void setName(const char* name);
	void setSalary(double salary);

	const char* getName() const;
	double getSalary() const;

	virtual double calculateSalary() const = 0;
	friend std::ostream& operator<<(std::ostream& os, const Employee& obj);
	
};

