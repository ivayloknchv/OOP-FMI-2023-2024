#include "Circle.h"

Circle::Circle(int x, int y, double radius) : Shape(1), radius(radius)
{
	setPoint(0, x, y);
}

double Circle::getArea() const
{
	return PI * PI * radius;
}

double Circle::getPerimeter() const
{
	return 2 * PI * radius;
}

bool Circle::isPointIn(int x, int y) const
{
	Point temp(x, y);
	return getPointAtIndex(0).getDistance(temp) <= radius;
}
