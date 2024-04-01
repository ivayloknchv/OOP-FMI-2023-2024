#include "helperFunctions.h"
#include <iostream>

void swap(int& lhs, int& rhs)
{
	int temp = lhs;
	lhs = rhs;
	rhs = temp;
}

bool isPrime(int num)
{
	int root = sqrt(num);

	if (num == 1)
	{
		return false;
	}

	for (int i = 2; i <= root; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

bool isPalindrome(int num)
{
	return (num==reverseNum(num));
}

bool hasUniqueDigitsOnly(int num)
{
	int histogram[10]{};

	while (num != 0)
	{
		int temp = num % 10;
		histogram[temp]++;
		
		if (histogram[temp] >= 2)
		{
			return false;
		}

		num /= 10;
	}

	return true;
}

int reverseNum(int num)
{
	int newNum = 0;

	while (num != 0)
	{
		newNum = newNum * 10 + num % 10;
		num /= 10;
	}
	return newNum;
}

bool isPowOfTwo(int num)
{
	while (num != 0)
	{
		if (num % 2 != 0)
		{
			return false;
		}

		num /= 2;
	}

	return true;
}
