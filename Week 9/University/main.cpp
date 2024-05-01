#include <iostream>
#include "Student.h"
#include "University.h"

int main()
{
	Student st1("Alice", 1001, 20, 3.8);
	Student st2("Bob", 1002, 21, 3.5);
	Student st3("Charlie", 1003, 22, 3.9);
	Student st4("David", 1004, 19, 3.7);
	Student st5("Eva", 1005, 20, 3.6);
	Student st6("Frank", 1006, 21, 4.0);
	Student st7("Grace", 1007, 22, 3.8);
	Student st8("Hannah", 1008, 20, 3.9);
	Student st9("Ian", 1009, 21, 3.2);
	Student st10("Jessica", 1010, 22, 3.1);

	University uni;
	uni += st1;
	uni += st2;
	uni += st3;
	uni += st4;
	uni += st5;
	uni += st6;
	uni += st7;
	uni += st8;
	uni += st9;
	uni += st10;

	
	return 0;
}
