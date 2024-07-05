#include "MinPartialFunctions.h"
#include <stdexcept>

MinPartialFunctions::MinPartialFunctions(PartialFunction** funcs, size_t count) : FunctionsContainer(funcs, count)
{
}

PartialFunction* MinPartialFunctions::clone() const
{
	return new MinPartialFunctions(*this);
}

int32_t MinPartialFunctions::operator()(int32_t num) const
{
	if (!isDefined(num))
	{
		throw std::exception("Your function isn't defined at this point!");
	}

	int32_t min = funcs[0]->operator()(num);

	for (int32_t i = 0; i < size; i++)
	{
		int32_t res = funcs[i]->operator()(num);
		if (res < min)
		{
			min = res;
		}
	}
	return min;
}
