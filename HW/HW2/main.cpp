#include <iostream>
#include "MyBoolFunction.h"

#include "PartialFuncByCriteria.hpp"
int main()
{
	int arr[3] = { 1,2,3 };
	MyBoolFunction f(arr, 3);


	PartialFuncByCriteria<MyBoolFunction> pf(f);

	std::cout << pf(1);
	return 0;
}