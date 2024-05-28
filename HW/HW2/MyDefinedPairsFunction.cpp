#include "MyDefinedPairsFunction.h"

int32_t MyDefinedPairsFunction::findValue(int32_t num) const
{
	for (int32_t i = 0; i < size; i++)
	{
		if (nodes[i].getLhs() == num)
		{
			return i;
		}
	}
	return size;
}

void MyDefinedPairsFunction::setDomain(const int32_t* domain, int32_t size)
{
	if (!domain)
	{
		return;
	}

	for (int32_t i = 0; i < size; i++)
	{
		nodes[i].setLhs(domain[i]);
	}
}

void MyDefinedPairsFunction::setRange(const int32_t* range, int32_t size)
{

	if (!range)
	{
		return;
	}

	for (int32_t i = 0; i < size; i++)
	{
		nodes[i].setRhs(range[i]);
	}
}

MyDefinedPairsFunction::MyDefinedPairsFunction(const int32_t* domain, const int32_t* range, int32_t size)
{
	this->size = size;
	setDomain(domain, size);
	setRange(range, size);
}

Pair<bool, int32_t> MyDefinedPairsFunction::operator()(int32_t num) const
{
	int32_t idx = findValue(num);

	if (idx == size)
	{
		return Pair<bool, int32_t>(false, 0);
	}

	return Pair<bool, int32_t>(true, nodes[idx].getRhs());
}

MyFunction* MyDefinedPairsFunction::clone() const
{
	return new MyDefinedPairsFunction(*this);
}
