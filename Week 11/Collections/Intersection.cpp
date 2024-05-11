#include "Intersection.h"

Intersection::Intersection(Collection& l, Collection& r) : CollectionsSuperSetOperation(l,r)
{
}

void Intersection::add(int num)
{
	dummy.add(num);
}

void Intersection::remove(int num)
{
	dummy.remove(num);
}

int Intersection::count(int num) const
{
	return left.count(num)+right.count(num)+dummy.count(num);
}

bool Intersection::contains(int num) const
{
	return (left.contains(num) && right.contains(num));
}
