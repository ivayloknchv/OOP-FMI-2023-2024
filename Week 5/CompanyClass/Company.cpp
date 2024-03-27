#include "Company.h"
#include <cstring>

#pragma warning (disable : 4996)

bool Company::departmentExists(const char* name) const
{
	for (int i = 0; countOfDepartments; i++)
	{
		if (strcmp(departments[i].getDepartmentName(), name))
		{
			return true;
		}
	}

	return false;
}

void Company::removeMyDepartment(const char* name)
{
	for (unsigned i = 0; i < countOfDepartments; i++)
	{
		if (strcmp(departments[i].getDepartmentName(), name))
		{
			swap(departments[i], departments[countOfDepartments - 1]);
			countOfDepartments--;
			return;
		}
	}
}

void Company::swap(Department& lhs, Department& rhs)
{
	Department temp = lhs;
	lhs = rhs;
	rhs = temp;
}

int Company::getDepartmentPosition(const char* name)
{
		for (unsigned i = 0; i < countOfDepartments; i++)
		{
			if (strcmp(departments[i].getDepartmentName(), name))
			{
				return i;
			}
		}

		return -1;
}

ErrorCode Company::addDepartment(const char* name)
{
	if (!name)
	{
		return ErrorCode::InvalidInput;
	}

	if (departmentExists(name))
	{
		return ErrorCode::Duplicate;
	}

	if (countOfDepartments == Constants::MAX_DEPARTMENTS)
	{
		return ErrorCode::FullCapacity;
	}
	
	departments[countOfDepartments++].setName(name);

	return ErrorCode::OK;
}

ErrorCode Company::removeDepartment(const char* name)
{
	if (!name)
	{
		return ErrorCode::InvalidInput;
	}

	if (!departmentExists(name))
	{
		return ErrorCode::NotFound;
	}

	removeMyDepartment(name);

	return ErrorCode::OK;
}

ErrorCode Company::addEmployeeToDepartment(const char* departmentName, const Employee& employee)
{
	if (!departmentName)
	{
		return ErrorCode::InvalidInput;
	}

	if (!departmentExists(departmentName))
	{
		return ErrorCode::NotFound;
	}

	int pos = getDepartmentPosition(departmentName);

	departments[pos].addEmployee(employee);
	return ErrorCode::OK;
}

ErrorCode Company::removeEmployeeFromDepartment(const char* departmentName, unsigned id)
{

	if (!departmentName)
	{
		return ErrorCode::InvalidInput;
	}

	if (!departmentExists(departmentName))
	{
		return ErrorCode::NotFound;
	}

	int pos = getDepartmentPosition(departmentName);

	departments[pos].removeEmployee(id);

	return ErrorCode::OK;
}
