#include <iostream>
#include "Time.h"

int main()
{
	Time t1(20, 59, 59);
	Time t2(19, 59, 57);
	
	Time t3 = t1.getTimeDiff(t2);

	Time t4 (12, 32, 54);

	std::cout << t4.isDinnerTime()<<std::endl;

	t3.printTime();

	return 0;
}