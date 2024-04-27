#include <iostream>
#include "MyVector.h"
#include "main.h"

int main()
{

	MyVector v;
	v.pushBack(5);

	MyVector v2;
	v2.pushBack(3);
	v2.pushBack(4);
	v2.pushBack(6);

	v.insertRange(v2, 1);
	v.pushBack(6);
	v.shrinkToFit();
	std::cout << v;
	return 0;
}
