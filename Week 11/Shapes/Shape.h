#pragma once
#include <iostream>

class Shape
{
protected:

	struct Point
	{
		int x = 0;
		int y = 0;

		Point() = default;

		Point(int x, int y): x(x), y(y)
		{}

		double getDistance(const Point& other) const
		{
			int dx = x - other.x;
			int dy = y - other.y;
			return sqrt(dx*dx+dy*dy);
		}
	};

	const Point& getPointAtIndex(size_t index) const;

private:

	Point* points = nullptr;
	size_t pointsCount = 0;

	void copyFrom(const Shape& other);
	void moveFrom(Shape&& other);
	void free();
	
public:

	Shape() = default;
	Shape(const Shape& other);
	Shape& operator=(const Shape& other);
	Shape(Shape&& other) noexcept;
	Shape& operator=(Shape&& other) noexcept;
	virtual ~Shape();

	Shape(int pointsCount);
	void setPoint(size_t idx, int x, int y);

	virtual double getArea() const = 0;
	virtual double getPerimeter() const;
	virtual bool isPointIn(int x, int y) const = 0;
};

