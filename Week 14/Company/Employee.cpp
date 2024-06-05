#include "Employee.h"

Employee::Employee(const MyString& name, unsigned age, double salary) : _name(name), _age(age), _salary(salary)
{
}

double Employee::getSalary() const
{
	return _salary;
}
