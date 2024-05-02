#pragma once

class Drink
{
	static constexpr int MIN_ML = 200;
	static constexpr int MAX_ML = 1000;
	char* name = nullptr;
	int ml = 0;

	void copyFrom(const Drink& other);
	void moveFrom(Drink&& other);
	void free();

public:

	Drink() = default;
	Drink(const Drink& other);
	Drink& operator=(const Drink& other);
	Drink(Drink&& other) noexcept;
	Drink& operator=(Drink&& other) noexcept;
	~Drink();

	Drink(const char* name, int ml);

	void setName(const char* name);
	void setMl(int ml);

	const char* getName() const;
	int getMl() const;
};

