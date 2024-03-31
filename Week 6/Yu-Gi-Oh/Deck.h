#include "MonsterCard.h"
#include "SpellCard.h"
#pragma once

constexpr int MAX_CARDS = 20;

class Deck
{
	MonsterCard monsters[MAX_CARDS]{};
	SpellCard spells[MAX_CARDS]{};
	int monstersCount = 0;
	int spellsCount = 0;

	bool checkIfMonsterExists(const MonsterCard& other) const;
	bool checkIfSpellExists(const SpellCard& other) const;

	void swapMonsters(MonsterCard& lhs, MonsterCard& rhs);
	void swapSpells(SpellCard& lhs, SpellCard& rhs);

public:

	unsigned getSpellsCount() const;
	unsigned getMonsterCount() const;

	void addMonster(const MonsterCard& monster);
	void addSpell(const SpellCard& spell);

	void changeMonster(int idx, const MonsterCard& monster);
	void changeSpell(int idx, const SpellCard& spell);

	void removeMonster(int idx);
	void removeSpell(int idx);
};
