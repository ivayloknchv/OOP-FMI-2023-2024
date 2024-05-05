#include "SetByCriteria.h"

void SetByCriteria::fillSet()
{
	Bitset::clean();
	setCount = 0;
	int limit = Bitset::getSetLimit();

	for (int i = 0; i < limit; i++)
	{
		if (cr.isValidNum(i))
		{
			Bitset::addNum(i);
			setCount++;
		}
	}
}

SetByCriteria::SetByCriteria(int limit, bool(*incl)(int num), bool(*excl)(int num)) : Bitset(limit)
{
	cr.incl = incl;
	cr.excl = excl;

	fillSet();
}

void SetByCriteria::setIncl(bool(*incl)(int num))
{
	cr.incl = incl;
	fillSet();
}

void SetByCriteria::setExcl(bool(*excl)(int num))
{
	cr.excl = excl;
	fillSet();
}

bool SetByCriteria::containsNum(int num) const
{
	return Bitset::containsNum(num);
}

int SetByCriteria::getCount() const
{
	return setCount;
}

void SetByCriteria::printSet() const
{
	Bitset::print();
}

bool SetByCriteria::Criteria::isValidNum(int num) const
{
	return (incl(num) && !excl(num));
}
