#include "Triangle.h"


static double getPerimeter(double a, double b, double c)
{
	return a + b + c;
}

static double getSemiPerimeter(double a, double b, double c)
{
	return getPerimeter(a, b, c) / 2.00;
}
Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3) : Shape(3)
{
	setPoint(0, x1, y1);
	setPoint(1, x2, y2);
	setPoint(2, x3, y3);
}

double Triangle::getArea() const
{
	double a = getPointAtIndex(0).getDistance(getPointAtIndex(1));
	double b = getPointAtIndex(1).getDistance(getPointAtIndex(2));
	double c = getPointAtIndex(2).getDistance(getPointAtIndex(0));

	double semi = getSemiPerimeter(a, b, c);
	return sqrt(semi * (semi - a) * (semi - b) * (semi - c));
}

bool Triangle::isPointIn(int x, int y) const
{
	Shape::Point temp(x, y);
	const Shape::Point& p1 = getPointAtIndex(0);
	const Shape::Point& p2 = getPointAtIndex(1);
	const Shape::Point& p3 = getPointAtIndex(2);


	Triangle t1(temp.x, temp.y, p1.x, p1.y, p2.x, p2.y);
	Triangle t2(temp.x, temp.y, p2.x, p2.y, p3.x, p3.y);
	Triangle t3(temp.x, temp.y, p1.x, p1.y, p3.x, p3.y);


	return std::abs((t1.getArea()+t2.getArea()+t3.getArea())-getArea())<= std::numeric_limits<double>::epsilon();
	return false;
}
