#include "MaxPartialFunctions.h"
#include <stdexcept>

MaxPartialFunctions::MaxPartialFunctions(PartialFunction** funcs, size_t count) : FunctionsContainer(funcs, count)
{
}

PartialFunction* MaxPartialFunctions::clone() const
{
	return new MaxPartialFunctions(*this);
}


int32_t MaxPartialFunctions::operator()(int32_t num) const
{
	if (!isDefined(num))
	{
		throw std::invalid_argument("Your function isn't defined in this point!");
	}

	int32_t max = funcs[0]->operator()(num);

	for (int32_t i = 0; i < size; i++)
	{
		int32_t res = funcs[i]->operator()(num);

		if ( res > max)
		{
			max = res;
		}
	}
	return max;
}
