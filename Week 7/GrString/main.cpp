#include <iostream>
#include "GrString.h"

int main()
{
	GrString str1="ABCDEF";
	GrString str2="BCDGHJ";
	 str1 /= str2;
	std::cout << str1.c_str();
	return 0;
}
