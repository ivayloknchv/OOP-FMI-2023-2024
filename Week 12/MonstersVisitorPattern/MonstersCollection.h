#pragma once
#include "Monster.h"
#include "Centaur.h"
#include "Minotaur.h"
#include "Sphynx.h"

class MonstersCollection
{
	static constexpr unsigned MAX_SIZE = 15;
	Monster* data[MAX_SIZE]{};
	size_t currentSize = 0;

	void copyFrom(const MonstersCollection& other);
	void moveFrom(MonstersCollection&& other);
	void free();

public:

	MonstersCollection() = default;
	MonstersCollection(const MonstersCollection& other);
	MonstersCollection& operator=(const MonstersCollection& other);
	MonstersCollection(MonstersCollection&& other) noexcept;
	MonstersCollection& operator=(MonstersCollection&& other) noexcept;
	~MonstersCollection() noexcept;

	int monsterBattle(int idx) const;

	void addMonster(MonsterType type);
};

