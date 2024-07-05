#pragma once
#include "MyFunction.h"

class MyBoolFunction : public MyFunction
{
private:

	static constexpr int32_t MAX_SIZE = 32;
	int32_t arguments[MAX_SIZE]{};
	int32_t size = 0;

	bool contains(int32_t num) const;

	void setArguments(const int32_t* arguments, int32_t size);

public:

	MyBoolFunction() = default;

	MyBoolFunction(const int32_t* arguments, int32_t size);

	MyFunction* clone() const override;

	Pair<bool, int32_t> operator()(int32_t num) const override;
};

