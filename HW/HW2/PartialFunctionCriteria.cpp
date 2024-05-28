#include "PartialFunctionCriteria.h"
#include <utility>
#include <exception>

void PartialFunctionCriteria::copyFrom(const PartialFunctionCriteria& other)
{
	func = other.func->clone();
}

void PartialFunctionCriteria::moveFrom(PartialFunctionCriteria&& other)
{
	func = other.func;
	other.func = nullptr;
}

void PartialFunctionCriteria::free()
{
	delete func;
	func = nullptr;
}

PartialFunctionCriteria::PartialFunctionCriteria(MyFunction* func)
{
	//????
	this->func = func;
}

PartialFunctionCriteria::PartialFunctionCriteria(const PartialFunctionCriteria& other) : PartialFunction(other)
{
	copyFrom(other);
}

PartialFunctionCriteria& PartialFunctionCriteria::operator=(const PartialFunctionCriteria& other)
{
	if (this != &other)
	{
		PartialFunction::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}

PartialFunctionCriteria::PartialFunctionCriteria(PartialFunctionCriteria&& other) noexcept : PartialFunction(std::move(other))
{
	moveFrom(std::move(other));
}

PartialFunctionCriteria& PartialFunctionCriteria::operator=(PartialFunctionCriteria&& other) noexcept
{
	if (this != &other)
	{
		PartialFunction::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

PartialFunctionCriteria::~PartialFunctionCriteria()
{
	free();
}

PartialFunction* PartialFunctionCriteria::clone() const
{
	return new PartialFunctionCriteria(*this);
}

bool PartialFunctionCriteria::isDefined(int32_t num) const
{
	Pair<bool, int32_t> res = func->operator()(num);

	return res.getLhs();
}

int32_t PartialFunctionCriteria::operator()(int32_t num) const
{
	Pair<bool, int32_t> res = func->operator()(num);

	return res.getRhs();
}
