#pragma once

struct Point
{
	int x = 0;
	int y = 0;
};

class DynamicPointersArray
{
private:

	Point** data = nullptr;
	size_t count = 0;
	size_t capacity = 8;

	void copyFrom(const DynamicPointersArray& other);
	void moveFrom(DynamicPointersArray&& other);
	void free();

	void resize(size_t newCapacity);
	size_t getFirstFreeIndex() const;

public:

	DynamicPointersArray();
	DynamicPointersArray(const DynamicPointersArray& other);
	DynamicPointersArray(DynamicPointersArray&& other) noexcept;
	DynamicPointersArray& operator=(const DynamicPointersArray& other);
	DynamicPointersArray& operator=(DynamicPointersArray&& other) noexcept;
	~DynamicPointersArray();

	void addAtFirstFreeIndex(const Point& other);
	void addAtFirstFreeIndex(Point&& other);

	bool ContainstAt(size_t idx) const;
	void popBack();
	void removeAt(size_t idx);

	void setAtIndex(size_t idx, const Point& obj);
	void setAtIndex(size_t idx, Point&& obj);

	size_t getSize() const;
	const Point& operator[](size_t idx) const;
	Point& operator[](size_t idx);
};

