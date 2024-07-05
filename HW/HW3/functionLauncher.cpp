#include <iostream>
#include <cstdint>
#include <stdexcept>

#include "PartialFunctionsFactory.h"
#include "functionLauncher.h"
#include "UniquePointer.hpp"

void FunctionLauncher::generateInterval(const PartialFunction* func)
{
	int a, b;
	std::cout << "Enter a: ";
	std::cin >> a;
	std::cout << "Enter b: ";
	std::cin >> b;


	if (b < a)
	{
		throw std::exception("Invalid interval!");
	}

	for (int i = a; i <= b; i++)
	{

		if (func->isDefined(i))
		{
			std::cout << "f(" << i << ")=" << func->operator()(i) << std::endl;
		}
		else
		{
			std::cout << "f isn't defined at " << i << std::endl;
		}
	}
}

void FunctionLauncher::generateRandomValues(const PartialFunction* func)
{
	std::cout << "Enter a value: ";
	int val = 0;
	std::cin >> val;

	while (true)
	{
		if (func->isDefined(val))
		{
			std::cout << "f(" << val << ")=" << func->operator()(val) << std::endl;
		}
		else
		{
			std::cout << "f isn't defined at " << val << std::endl;
		}

		std::cout << "Do you want to keep generating values? Enter 1 for yes, 0 for no!" << std::endl;
		int answer = 0;
		std::cin >> answer;

		if (!answer)
		{
			break;
		}

		std::cout << "Enter a value: ";
		std::cin >> val;
	}
}

void FunctionLauncher::run()
{
	try
	{
		char buff[256]{};

		std::cout << "Enter file path: ";
		std::cin >> buff;

		UniquePointer<PartialFunction> ptr = readFromFile(buff);

		std::cout << "Choose a regime of the program: " << std::endl;
		std::cout << "1) Generate all values in the interval [a ; b]" << std::endl;
		std::cout << "2) Generate values until the user says otherwise" << std::endl;

		int option;
		std::cin >> option;

		switch (option)
		{
		case 1:

			generateInterval(ptr.get());
			break;

		case 2:

			generateRandomValues(ptr.get());
			break;

		default:
			std::cout << "Invalid argument!" << std::endl;
			break;
		}

	}

	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

PartialFunction* FunctionLauncher::readFromFile(const char* filePath)
{
	if (!filePath)
	{
		throw std::exception("Nullptr detected!");
	}

	std::ifstream ifs(filePath, std::ios::binary);

	if (!ifs.is_open())
	{
		throw std::exception("File couldn't open!");
	}

	return PartialFunctionsFactory::create(ifs);
}

