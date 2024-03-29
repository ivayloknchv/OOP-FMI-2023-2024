#include <iostream>
#include "GraduatedStudent.h"
int main()
{
	int grades[] = { 3,3,4,4,5,5 };
	GraduatedStudent gr1("Test Student", grades, sizeof(grades) / sizeof(int), "Winning!");

	GraduatedStudent gr2; 
	gr2 = gr1;

	std::cout << gr2.getName();
	return 0;
}