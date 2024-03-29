#include <iostream>
#include "String.h"

int main()
{
	String str1 = "Hello";

	std::cout << str1.strLen();

	String str2 = " world!";

	String str3 = str1.concat(str2);

	std::cout << str1.getStr();

	std::cout << str3.getStr();
	return 0;
}