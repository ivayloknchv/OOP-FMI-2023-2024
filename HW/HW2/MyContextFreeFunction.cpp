#include "MyContextFreeFunction.h"

MyContextFreeFunction::MyContextFreeFunction(int32_t(*ptr)(int32_t num)) : func(ptr)
{
}

MyFunction* MyContextFreeFunction::clone() const
{
	return new MyContextFreeFunction(*this);
}

Pair<bool, int32_t> MyContextFreeFunction::operator()(int32_t num) const
{
	Pair<bool, int32_t> toReturn = Pair<bool, int32_t>(true, func(num));
	return toReturn;
}
