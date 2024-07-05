#pragma once
#include "FunctionsContainer.h"

class MinPartialFunctions : public FunctionsContainer
{
public:

	MinPartialFunctions(PartialFunction** funcs, size_t count);

	PartialFunction* clone() const override;

	int32_t operator()(int32_t num) const override;
};

