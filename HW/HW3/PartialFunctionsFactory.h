#pragma once
#include <fstream>
#include "PartialFunction.h"
#include "PartialFuncByCriteria.hpp"
#include "MaxPartialFunctions.h"
#include "MinPartialFunctions.h"
#include "MyFunction.h"
#include "MyBoolFunction.h"
#include "MyDefinedPairsFunction.h"
#include "MyExcludedPointsFunction.h"

enum class FuncTypes
{
	DefinedPairsFunc,
	ExcludedPointsFunc,
	BoolFunc,
	MaxFunc,
	MinFunc
};

class PartialFunctionsFactory
{
private:
	static constexpr int32_t MAX_SIZE = 32;
	static constexpr int32_t MAX_REGIME_NUM = 4;

	static PartialFunction* createDefinedPairs(std::ifstream& ifs, uint16_t elementsCount);
	static PartialFunction* createExcludedPoints(std::ifstream& ifs, uint16_t elementsCount);
	static PartialFunction* createBoolFunc(std::ifstream& ifs, uint16_t elementsCount);
	static PartialFunction* createMinMaxFunc(std::ifstream& ifs, uint16_t elementsCount, FuncTypes type);

public:

	static PartialFunction* create(std::ifstream& ifs);
};

