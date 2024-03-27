#include "Department.h"
#pragma once

class Company
{
	Department departments[Constants::MAX_DEPARTMENTS]{};
	unsigned countOfDepartments = 0;

	bool departmentExists(const char* name) const;

	void removeMyDepartment(const char* name);

	void swap(Department& lhs, Department& rhs);

	int getDepartmentPosition(const char* name);

public:

	Company() = default;

	ErrorCode addDepartment(const char* name);

	ErrorCode removeDepartment(const char* name);

	ErrorCode addEmployeeToDepartment(const char* departmentName, const Employee& employee);

	ErrorCode removeEmployeeFromDepartment(const char* departmentName, unsigned id);
};