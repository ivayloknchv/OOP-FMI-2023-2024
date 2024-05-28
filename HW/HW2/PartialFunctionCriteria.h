#pragma once
#include "PartialFunction.h"
#include "MyFunction.h"

class PartialFunctionCriteria : public PartialFunction
{
private:
	
	MyFunction* func = nullptr;

	void copyFrom(const PartialFunctionCriteria& other);
	void moveFrom(PartialFunctionCriteria&& other);
	void free();

public:
	PartialFunctionCriteria(MyFunction* func);
	PartialFunctionCriteria(const PartialFunctionCriteria& other);
	PartialFunctionCriteria& operator=(const PartialFunctionCriteria& other);
	PartialFunctionCriteria(PartialFunctionCriteria&& other) noexcept;
	PartialFunctionCriteria& operator=(PartialFunctionCriteria&& other) noexcept;
	~PartialFunctionCriteria();

	PartialFunction* clone() const override;

	bool isDefined(int32_t num) const override;
	int32_t operator()(int32_t num) const override;
};

