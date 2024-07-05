#pragma once
#include "MyFunction.h"

//not really required or used in the solution but I decided to add it for any case

class MyContextFreeFunction : public MyFunction
{
	int32_t(*func)(int32_t num) = nullptr;

public:

	MyContextFreeFunction() = default;

	MyContextFreeFunction(int32_t(*ptr)(int32_t num));

	MyFunction* clone() const override;

	Pair<bool, int32_t> operator()(int32_t num) const override;
};

