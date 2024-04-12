#pragma once

class OptionalDouble
{
private:

	double* num = nullptr;

	void copyFrom(const OptionalDouble& other);
	void free();

public:

	OptionalDouble();
	OptionalDouble(const OptionalDouble& other);
	OptionalDouble& operator=(const OptionalDouble& other);
	~OptionalDouble();

	OptionalDouble(double newNum);

	bool isPresent() const;
	double get() const;
	void set(double newNum);
	void empty();
};