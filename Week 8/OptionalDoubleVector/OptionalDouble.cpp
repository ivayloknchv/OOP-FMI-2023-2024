#include "OptionalDouble.h"
#include <exception>

void OptionalDouble::copyFrom(const OptionalDouble& other)
{
	if (!other.isPresent())
	{
		num = nullptr;

		return;
	}
	num = new double(*other.num);
}

void OptionalDouble::free()
{
	delete num;
	num = nullptr;
}

OptionalDouble::OptionalDouble() = default;

OptionalDouble::OptionalDouble(const OptionalDouble & other)
{
	copyFrom(other);
}

OptionalDouble& OptionalDouble::operator=(const OptionalDouble& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

OptionalDouble::~OptionalDouble()
{
	free();
}

OptionalDouble::OptionalDouble(double newNum)
{
	set(newNum);
}

bool OptionalDouble::isPresent() const
{
	return num;
}

double OptionalDouble::get() const
{
	if (!num)
	{
		throw std::exception("not a valid value!");
	}

	return *num;
}

void OptionalDouble::set(double newNum)
{
	if (num != nullptr)
	{
		*num = newNum;
	}

	else
	{
		num = new double(newNum);
	}
}

void OptionalDouble::empty()
{
	if (isPresent())
	{
		free();
	}

	else
	{
		throw std::exception("not a valid value!");
	}
}
