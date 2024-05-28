#pragma once
#include "PartialFunction.h"
#include "Pair.hpp"
#include <stdexcept>

template<class T>
class PartialFuncByCriteria : public PartialFunction
{
private:

	T criteria;

public:
	
	PartialFuncByCriteria(const T& criteria);

	PartialFunction* clone() const override;

	bool isDefined(int32_t num) const override;
	int32_t operator()(int32_t num) const override;
};

template<class T>
PartialFuncByCriteria<T>::PartialFuncByCriteria(const T& criteria)
{
	this->criteria = criteria;
}

template<class T>
PartialFunction* PartialFuncByCriteria<T>::clone() const
{
	return new PartialFuncByCriteria<T>(*this);
}

template<class T>
bool PartialFuncByCriteria<T>::isDefined(int32_t num) const
{
	Pair<bool, int32_t> res = criteria(num);

	return res.getLhs();
}

template<class T>
int32_t PartialFuncByCriteria<T>::operator()(int32_t num) const
{
	if (!isDefined(num))
	{
		throw std::invalid_argument("Your function isn't defined in this point!");
	}

	Pair<bool, int32_t> res = criteria(num);

	return res.getRhs();
}
