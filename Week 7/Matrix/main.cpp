#include "matrix.h"
#include <iostream>

int main()
{
	Matrix m(2, 3);
	std::cin >> m;
	Matrix n(3, 2);
	std::cin >> n;

	Matrix p = (m * n);

	std::cout << p;
	return 0;
}
