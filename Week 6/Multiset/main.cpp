#include <iostream>
#include "ThreeMultiSet.h"

int main()
{
	MultiSet set(54);
	set.addNum(5);
	set.addNum(32);
	set.addNum(52);
	set.addNum(5);
	set.printSet();
	return 0;
}