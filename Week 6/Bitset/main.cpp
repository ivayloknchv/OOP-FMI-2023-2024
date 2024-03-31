#include <iostream>
#include "Bitset.h"

int main()
{
	Bitset b1(6);
	b1.addNumber(4);
	b1.addNumber(2);
	b1.print();

	Bitset b2(10);
	b2.addNumber(4);
	b2.addNumber(9);

	Bitset b3 = b1.getUnion(b2);
	b3.print();
	return 0;
}
