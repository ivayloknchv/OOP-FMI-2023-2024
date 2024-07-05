#pragma once
#include <cstdint>
class PartialFunction
{
public:

	virtual bool isDefined(int32_t num) const = 0;
	virtual int32_t operator()(int32_t num) const = 0;
	virtual PartialFunction* clone() const = 0;
	virtual ~PartialFunction() = default;
};

