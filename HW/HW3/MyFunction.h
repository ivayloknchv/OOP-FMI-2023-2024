#pragma once
#include <cstdint>
#include "Pair.hpp"

class MyFunction
{
public:

	virtual Pair<bool, int32_t> operator()(int32_t num) const = 0;
	virtual MyFunction* clone() const = 0;
	virtual ~MyFunction() = default;
};

