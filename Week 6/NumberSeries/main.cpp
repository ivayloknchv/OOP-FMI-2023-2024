#include <iostream>
#include "numberSeries.h"

int func(int num)
{
	return num+3;
}

int main()
{
	numberSeries series(func, 4);
	std::cout << series.getNumByIndex(5)<<std::endl;
	std::cout << series.isNumInSeries(7) << std::endl;
	return 0;
}
