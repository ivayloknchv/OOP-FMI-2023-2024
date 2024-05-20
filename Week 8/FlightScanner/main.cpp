#include <iostream>
#include "FlightScanner.h"
int main()
{
	FlightScanner f("input.txt", "output.txt");
	f.run();
	return 0;
}