#include <iostream>
#include "FiniteStack.hpp"

int main()
{
	FiniteStack<int, 20> stack;
	stack.push(2);
	stack.push(4);
	stack.push(5);
	std::cout << stack.size();
	stack.pop();
	stack.pop();
	std::cout << stack.top();
	stack.pop();
	std::cout << stack.empty();
	return 0;
}
