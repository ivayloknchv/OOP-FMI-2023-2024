#include "Employee.h"
#pragma once

class Department
{
	char name[Constants::MAX_STR_LEN + 1]{};

	Employee employees[Constants::MAX_EMPLOYEES]{};

	unsigned countOfEmployees = 0;

	bool isValidId(unsigned id) const;

	void removeAt(int id);

	void swap(Employee& lhs, Employee& rhs);

public:

	Department() = default;

	Department(const char* name, const Employee* employees, unsigned countOfEmployees);

	void setName(const char* name);

	void setEmployees(const Employee* employees, unsigned countOfEmployees);

	const char* getDepartmentName() const;

	ErrorCode addEmployee(const Employee& employee);

	ErrorCode removeEmployee(unsigned id);

};