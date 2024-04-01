#include <iostream>
#include "Interval.h"

int main()
{
    Interval i1(10, 33);
    Interval i2(20, 85);

    Interval i3 = i1.intersection(i2);

    std::cout << i1.getPalindromesCount() << std::endl;;
    std::cout << i2.isInInterval(31)<<std::endl;
	return 0;
}
