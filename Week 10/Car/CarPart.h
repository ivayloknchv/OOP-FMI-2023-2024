#pragma once
#include <cstring>
#include <utility>
#include <iostream>
#pragma warning (disable : 4996)

class CarPart
{
private:

	static unsigned idCounter;
	unsigned id = 0;
	char* name = nullptr;
	char* description = nullptr;

	void copyFrom(const CarPart& other);
	void moveFrom(CarPart&& other);
	void free();

public:

	CarPart() = default;
	CarPart(const CarPart& other);
	CarPart& operator=(const CarPart& other);
	CarPart(CarPart&& other) noexcept;
	CarPart& operator=(CarPart&& other) noexcept;
	~CarPart();

	CarPart(const char* newName, const char* newDescription);

	void setName(const char* newName);
	void setDescription(const char* newDescription);

	const char* getName() const;
	const char* getDescription() const;

	friend std::ostream& operator<<(std::ostream& os, const CarPart& obj);
};

