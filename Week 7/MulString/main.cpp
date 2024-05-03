#include <iostream>
#include "MulString.h"

int main()
{
	MulString str1 = "AZZBCDA";
	MulString str2 = "ZXYFABC";
	str1 %= str2;
	std::cout << str1;
	return 0;
}