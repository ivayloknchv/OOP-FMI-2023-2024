#include "Shape.h"
#include <assert.h>

const Shape::Point& Shape::getPointAtIndex(size_t index) const
{
	if (index >= pointsCount)
	{
		throw std::exception("Invalid point index!");
	}
	return points[index];
}

void Shape::copyFrom(const Shape& other)
{
	points = new Point[other.pointsCount]{};
	pointsCount = other.pointsCount;
	for (size_t i = 0; i < pointsCount; i++)
	{
		points[i] = other.points[i];
	}
}

void Shape::moveFrom(Shape&& other)
{
	points = other.points;
	other.points = 0;

	pointsCount = other.pointsCount;
	other.pointsCount = 0;
}

void Shape::free()
{
	delete[] points;
	points = nullptr;

	pointsCount = 0;
}

Shape::Shape(const Shape& other)
{
	copyFrom(other);
}

Shape& Shape::operator=(const Shape& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Shape::Shape(Shape&& other) noexcept
{
	moveFrom(std::move(other));
}

Shape& Shape::operator=(Shape&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return* this;
}

Shape::~Shape()
{
	free();
}

Shape::Shape(int pointsCount)
{
	this->pointsCount = pointsCount;
	points = new Point[pointsCount]{};
}

void Shape::setPoint(size_t idx, int x, int y)
{
	if (idx >= pointsCount)
	{
		throw std::exception("Invalid point index!");
	}

	points[idx] = Point(x, y);
}

double Shape::getPerimeter() const
{
	assert(pointsCount >= 3);

	double toReturn = 0;
	
	for (size_t i = 0; i < pointsCount - 1; i++)
	{
		toReturn += points[i].getDistance(points[i+1]);
	}

	toReturn += points[pointsCount - 1].getDistance(points[0]);

	return toReturn;
}
