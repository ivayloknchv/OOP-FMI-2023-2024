#include <iostream>
#include "SetByString.h"

int main()
{
	SetByString s(300, "1 2 3");

	s.print(); // {1, 2, 3}

	s.setAt(1, '1');

	s.print(); // {3, 112}
	std::cout << s.getCount();
	return 0;
}