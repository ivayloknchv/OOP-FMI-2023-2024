#include <iostream>
#include "Computer.h"
#include "GamingConsole.h"
#include "Laptop.h"
#include "PC.h"
int main()
{
	Computer* arr[3];
	arr[0] = new PC(234, "one", 3);
	arr[1] = new Laptop(2434, "two", 4);
	arr[2] = new GamingConsole(464, "three", 342);

	for (int i = 0; i < 3; i++)
	{
		arr[i]->printType();
		std::cout << arr[i]->getDevices() << std::endl;
	}

	for (int i = 0; i < 3; i++)
	{
		delete arr[i];
	}

	return 0;
}