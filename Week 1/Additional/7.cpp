#include <iostream>

//OK
//nullptrStr
//incorrect string
//overflow

enum class ErrorList {
	OK,
	nullptrStr,
	incorrectStr,
	overflow,
};

struct Result {
	int myNum;
	ErrorList error;
};

Result numToStr(const char* str)
{
	if (!str)
	{
		return { 0, ErrorList::nullptrStr };
	}

	bool isNegative = false;
	int myNum = 0;
	int minInt = 1 << 31;
	if (*str == '-')
	{
		isNegative = true;
		str++;
	}

	while (*str != '\0')
	{
		if (!(*str >= '0' && *str <= '9'))
		{
			return { myNum,ErrorList::incorrectStr };
		}
		myNum = myNum * 10 + (*str - '0');
		str++;

		if (minInt <= myNum)
		{
			return { minInt,ErrorList::overflow };
		}
	}

	return { (isNegative) ? -myNum : myNum, ErrorList::OK };
}

void printResult(const Result& result)
{
	switch (result.error)
	{
	case(ErrorList::OK): std::cout << result.myNum << std::endl; break;
	case(ErrorList::incorrectStr): std::cout << "Incorrect string" << std::endl; break;
	case(ErrorList::nullptrStr): std::cout << "Nullptr" << std::endl; break;
	case(ErrorList::overflow): std::cout << "Overflow" << std::endl; break;
	}
}

int main()
{
	Result result = numToStr("3458909876574657897088999999999999999999999999777765756446");
	printResult(result);
	return 0;
}
