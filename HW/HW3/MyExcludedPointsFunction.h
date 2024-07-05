#pragma once
#include "MyFunction.h"

class MyExcludedPointsFunction : public MyFunction
{
private:

	static constexpr int32_t MAX_SIZE = 32;

	int32_t excludedPoints[MAX_SIZE]{};
	int32_t size = 0;

	void setExcludedPoints(const int32_t* excludedPoints, int32_t size);

	bool contains(int32_t num) const;

public:

	MyExcludedPointsFunction() = default;

	MyExcludedPointsFunction(const int32_t* excludedPoints, int32_t size);

	MyFunction* clone() const override;

	Pair<bool, int32_t> operator()(int32_t num) const override;
};

