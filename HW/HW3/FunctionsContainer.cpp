#include "FunctionsContainer.h"
#include <utility>
#include <stdexcept>

void FunctionsContainer::allocateFuncsArr(PartialFunction** arr, int32_t size)
{
	if (!arr)
	{
		throw std::exception("Nullptr detected!");
	}

	funcs = new PartialFunction * [size] {};

	for (int32_t i = 0; i < size; i++)
	{
		funcs[i] = arr[i]->clone();
	}
}

void FunctionsContainer::copyFrom(const FunctionsContainer& other)
{
	size = other.size;
	allocateFuncsArr(other.funcs, size);
}

void FunctionsContainer::moveFrom(FunctionsContainer&& other)
{
	funcs = other.funcs;
	other.funcs = nullptr;

	size = other.size;
	other.size = 0;
}

void FunctionsContainer::free()
{
	for (int32_t i = 0; i < size; i++)
	{
		delete funcs[i];
	}

	delete[] funcs;
	funcs = nullptr;
	size = 0;
}

FunctionsContainer::FunctionsContainer(PartialFunction** funcs, size_t size) : PartialFunction()
{
	this->size = size;

	allocateFuncsArr(funcs, size);
}

FunctionsContainer::FunctionsContainer(const FunctionsContainer& other) : PartialFunction(other)
{
	copyFrom(other);
}

FunctionsContainer& FunctionsContainer::operator=(const FunctionsContainer& other)
{
	if (this != &other)
	{
		PartialFunction::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}

FunctionsContainer::FunctionsContainer(FunctionsContainer&& other) noexcept : PartialFunction(std::move(other))
{
	moveFrom(std::move(other));
}

FunctionsContainer& FunctionsContainer::operator=(FunctionsContainer&& other) noexcept
{
	if (this != &other)
	{
		PartialFunction::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

FunctionsContainer::~FunctionsContainer()
{
	free();
}

bool FunctionsContainer::isDefined(int32_t num) const
{
	for (int32_t i = 0; i < size; i++)
	{
		if (!funcs[i]->isDefined(num))
		{
			return false;
		}
	}
	return true;
}
