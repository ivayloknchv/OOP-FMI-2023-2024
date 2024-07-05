#pragma once
#include "PartialFunction.h"

class FunctionsContainer : public PartialFunction
{
protected:

	PartialFunction** funcs = nullptr;
	int32_t size = 0;

private:

	void allocateFuncsArr(PartialFunction** arr, int32_t size);

	void copyFrom(const FunctionsContainer& other);
	void moveFrom(FunctionsContainer&& other);
	void free();

public:

	FunctionsContainer(PartialFunction** funcs, size_t size);
	FunctionsContainer(const FunctionsContainer& other);
	FunctionsContainer& operator=(const FunctionsContainer& other);
	FunctionsContainer(FunctionsContainer&& other) noexcept;
	FunctionsContainer& operator=(FunctionsContainer&& other) noexcept;
	~FunctionsContainer();

	bool isDefined(int32_t num) const override;
};

