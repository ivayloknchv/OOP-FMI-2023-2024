#include "Union.h"

Union::Union(Collection& l, Collection& r) : CollectionsSuperSetOperation(l,r)
{
}

void Union::add(int num)
{
	dummy.add(num);
}

void Union::remove(int num)
{
	dummy.remove(num);
}

int Union::count(int num) const
{
	return right.count(num) + left.count(num) + dummy.count(num);
}

bool Union::contains(int num) const
{
	return (left.contains(num) || right.contains(num));
}
