#include "MonstersCollection.h"
#include <utility>

static Monster* Factory(MonsterType type)
{
	Monster* toReturn = nullptr;

	switch (type)
	{
	case MonsterType::Centaur: 
		toReturn = new Centaur(); 
		break;

	case MonsterType::Sphynx :
		toReturn = new Sphynx();
		break;

	case MonsterType::Minotaur :
		toReturn = new Minotaur();
		break;
	}

	return toReturn;
}

void MonstersCollection::copyFrom(const MonstersCollection& other)
{
	currentSize = other.currentSize;

	for (size_t i = 0; i < currentSize; i++)
	{
		data[i] = other.data[i]->clone();
	}
}

void MonstersCollection::moveFrom(MonstersCollection&& other)
{
	for (size_t i = 0; i < currentSize; i++)
	{
		data[i] = other.data[i];
		other.data[i] = nullptr;
	}

	currentSize = other.currentSize;
	other.currentSize = 0;


}

void MonstersCollection::free()
{
	for (size_t i = 0; i < currentSize; i++)
	{
		delete data[i];
		data[i] = nullptr;
	}

	currentSize = 0;
}

MonstersCollection::MonstersCollection(const MonstersCollection& other)
{
	copyFrom(other);
}

MonstersCollection& MonstersCollection::operator=(const MonstersCollection& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

MonstersCollection::MonstersCollection(MonstersCollection&& other) noexcept
{
	moveFrom(std::move(other));
}

MonstersCollection& MonstersCollection::operator=(MonstersCollection&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

MonstersCollection::~MonstersCollection() noexcept
{
	free();
}

int MonstersCollection::monsterBattle(int idx) const
{
	if (idx < 0 || idx >= currentSize)
	{
		return -1;
	}

	int toReturn = 0;

	for (size_t i = 0; i < currentSize; i++)
	{
		int currentResult = data[idx]->fight(data[i]);

		if (currentResult == 1)
		{
			toReturn++;
		}
	}
	return toReturn;
}

void MonstersCollection::addMonster(MonsterType type)
{
	if (currentSize == MAX_SIZE)
	{
		return;
	}

	data[currentSize++] = Factory(type);
}

