#include "PartialFunctionsFactory.h"

static void deallocateFuncsArr(PartialFunction** arr, int32_t size)
{
	for (int32_t i = 0; i < size; i++)
	{
		delete arr[i];
	}
	delete[] arr;
}

static void readFileName(char* str, std::ifstream& ifs)
{
	char* iter = str;
	while (true)
	{
		char symbol;
		ifs.read(reinterpret_cast<char*>(&symbol) , sizeof(char));

		if (symbol == '\0')
		{
			break;
		}

		if (ifs.eof())
		{
			break;
		}

		*iter = symbol;
		iter++;
	}
}

PartialFunction* PartialFunctionsFactory::createDefinedPairs(std::ifstream& ifs, uint16_t elementsCount)
{
	int32_t dom[MAX_SIZE]{};
	int32_t ran[MAX_SIZE]{};
	ifs.read(reinterpret_cast<char*>(dom), sizeof(int32_t) * elementsCount);
	ifs.read(reinterpret_cast<char*>(ran), sizeof(int32_t) * elementsCount);
	
	MyDefinedPairsFunction func(dom, ran, elementsCount);
	return new PartialFuncByCriteria<MyDefinedPairsFunction>(func);
}

PartialFunction* PartialFunctionsFactory::createExcludedPoints(std::ifstream& ifs, uint16_t elementsCount)
{
	int32_t dom[MAX_SIZE]{};

	ifs.read(reinterpret_cast<char*>(dom), sizeof(int32_t) * elementsCount);
	MyExcludedPointsFunction excl(dom, elementsCount);

	return new PartialFuncByCriteria<MyExcludedPointsFunction>(excl);
}

PartialFunction* PartialFunctionsFactory::createBoolFunc(std::ifstream& ifs, uint16_t elementsCount)
{
	int32_t dom[MAX_SIZE]{};

	ifs.read(reinterpret_cast<char*>(dom), sizeof(int32_t) * elementsCount);
	MyBoolFunction boolFunc(dom, elementsCount);
	return new PartialFuncByCriteria<MyBoolFunction>(boolFunc);
}

PartialFunction* PartialFunctionsFactory::createMinMaxFunc(std::ifstream& ifs, uint16_t elementsCount, FuncTypes type)
{
	PartialFunction** collection = new PartialFunction * [elementsCount] {};

	for (int32_t i = 0; i < elementsCount; i++)
	{
		char buff[256]{};

		readFileName(buff, ifs);

		std::ifstream temp(buff, std::ios::binary);

		try
		{
			if (!temp.is_open())
			{
				throw std::exception("File couldn't open!");
			}
			collection[i] = create(temp);
		}

		catch(...)
		{
			deallocateFuncsArr(collection, elementsCount);
			throw;
		}

		temp.close();
	}

	if (type == FuncTypes::MinFunc)
	{
		MinPartialFunctions* toReturn = new MinPartialFunctions(collection, elementsCount);
		deallocateFuncsArr(collection, elementsCount);
		return toReturn;
	}

	else if (type == FuncTypes::MaxFunc)
	{
		MaxPartialFunctions* toReturn = new MaxPartialFunctions(collection, elementsCount);
		deallocateFuncsArr(collection, elementsCount);
		return toReturn;
	}

	deallocateFuncsArr(collection, elementsCount);
	return nullptr;
}

PartialFunction* PartialFunctionsFactory::create(std::ifstream& ifs)
{
	uint16_t elementsCount = 0;
	uint16_t regime = 0;

	ifs.read(reinterpret_cast<char*>(&elementsCount), sizeof(uint16_t));
	ifs.read(reinterpret_cast<char*>(&regime), sizeof(uint16_t));

	if (elementsCount < 1 || elementsCount>MAX_SIZE)
	{
		throw std::exception("Elements must be between 1 and 32!");
	}

	if (regime < 0 || regime > MAX_REGIME_NUM)
	{
		throw std::exception("Regime numbers must be between 0 and 4!");
	}

	switch (regime)
	{
	case (int)FuncTypes::DefinedPairsFunc:
	{
		return createDefinedPairs(ifs, elementsCount);
	}

	case (int)FuncTypes::ExcludedPointsFunc:
	{
		return createExcludedPoints(ifs, elementsCount);
	}
	case (int)FuncTypes::BoolFunc:
	{
		return createBoolFunc(ifs, elementsCount);
	}
	case (int)FuncTypes::MaxFunc:
	{
		return createMinMaxFunc(ifs, elementsCount, FuncTypes::MaxFunc);
	}
	case (int)FuncTypes::MinFunc:
	{
		return createMinMaxFunc(ifs, elementsCount, FuncTypes::MinFunc);
	}
	}
	return nullptr;
}
