#pragma once
#include "CollectionsOperation.h"
#include "NormalCollection.h"

class CollectionsSuperSetOperation : public CollectionsOperation
{
protected:

	NormalCollection dummy;

public:

	CollectionsSuperSetOperation(Collection& l, Collection& r);
};

