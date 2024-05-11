#pragma once
#include "Collection.h"

class CollectionsOperation : public Collection
{
protected:

	Collection& left;
	Collection& right;

public:

	CollectionsOperation(Collection& l, Collection& r);
};

