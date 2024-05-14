#include "Rectangle.h"

Rectangle::Rectangle(int x1, int y1, int x3, int y3) : Shape(4)
{
	setPoint(0, x1, y1);
	setPoint(1, x3, y1);
	setPoint(2, x3, y3);
	setPoint(3, x1, y3);
}

double Rectangle::getArea() const
{
	double sideA = getPointAtIndex(0).getDistance(getPointAtIndex(1));
	double sideB = getPointAtIndex(0).getDistance(getPointAtIndex(3));
	return sideA * sideB;
}

bool Rectangle::isPointIn(int x, int y) const
{
	Point temp(x, y);

	return temp.x >= getPointAtIndex(0).x && temp.y <= getPointAtIndex(0).y
		&& temp.y >= getPointAtIndex(2).y && temp.x <= getPointAtIndex(1).x;
}
