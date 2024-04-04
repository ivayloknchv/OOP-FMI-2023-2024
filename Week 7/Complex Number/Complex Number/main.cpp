#include <iostream>
#include "ComplexNum.h"

int main()
{
	ComplexNum c1(7, 2);
	ComplexNum c2(2, -4);
	
	std::cout << (c1/c2);
	return 0;
}
