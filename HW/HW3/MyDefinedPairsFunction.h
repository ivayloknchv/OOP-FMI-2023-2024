#pragma once
#include "MyFunction.h"

class MyDefinedPairsFunction : public MyFunction
{
	static constexpr int32_t MAX_SIZE = 32;

	Pair<int32_t, int32_t> nodes[MAX_SIZE]{};
	int32_t size = 0;

	int32_t findValue(int32_t num) const;

	void setDomainRange(const int32_t* domain, const int32_t* range, int32_t size);

public:

	MyDefinedPairsFunction() = default;

	MyDefinedPairsFunction(const int32_t* domain, const int32_t* range, int32_t size);

	Pair<bool, int32_t> operator() (int32_t x) const override;

	MyFunction* clone() const override;
};

