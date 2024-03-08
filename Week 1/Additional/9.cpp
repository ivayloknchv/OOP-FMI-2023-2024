#include <iostream>

struct Vector {
	int first;
	int second;
	int third;
};

Vector sumVectors(const Vector& v1,const Vector& v2)
{
	Vector sum ;
	sum.first = v1.first + v2.first;
	sum.second = v1.second + v2.second;
	sum.third = v1.third + v2.third;

	return sum;
}

void printCoordinates(const Vector& v)
{
	std::cout << '(' << v.first << ',' << v.second << ',' << v.third << ')'<<std::endl;
}

bool checkLD(const Vector& v1, const Vector& v2)
{
	if (v1.first * v2.second - v1.second * v2.first == 0)
	{
		if (v1.second * v2.third - v1.third * v2.second == 0)
		{
			if (v1.first * v2.third - v1.third * v2.first == 0)
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{
	Vector v1 = { 2,0,5 };
	Vector v2 = { 4,0,10 };

	printCoordinates(v1);
	printCoordinates(v2);

	Vector sumVector = sumVectors(v1, v2);
	printCoordinates(sumVector);

	std::cout << checkLD(v1, v2);
	return 0;
}
