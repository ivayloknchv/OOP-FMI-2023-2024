#include "Alcohol.h"

Alcohol::Alcohol(const char* name, int ml, int percent):Drink(name, ml)
{
	setPercent(percent);
}

void Alcohol::setPercent(int percent)
{
	if (percent<MIN_PERCENT || percent>MAX_PERCENT)
	{
		percent = MIN_PERCENT;
	}

	this->percent = MAX_PERCENT;
}

int Alcohol::getPercent() const
{
	return percent;
}
