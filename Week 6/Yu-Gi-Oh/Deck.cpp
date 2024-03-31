#include "Deck.h"
#include <cstring>

#pragma warning (disable : 4996)

bool Deck::checkIfMonsterExists(const MonsterCard& other) const
{
	for (int i = 0; i < monstersCount; i++)
	{
		if (strcmp(monsters[i].getName(), other.getName())==0)
		{
			return true;
		}
	}

	return false;
}

bool Deck::checkIfSpellExists(const SpellCard& other) const
{
	for (int i = 0; i < spellsCount; i++)
	{
		if (strcmp(spells[i].getName(), other.getName())==0)
		{
			return true;
		}
	}

	return false;
}

void Deck::swapMonsters(MonsterCard& lhs, MonsterCard& rhs)
{
	MonsterCard temp = lhs;
	lhs = rhs;
	rhs = temp;
}

void Deck::swapSpells(SpellCard& lhs, SpellCard& rhs)
{
	SpellCard temp = lhs;
	lhs = rhs;
	rhs = temp;
}

unsigned Deck::getSpellsCount() const
{
	return spellsCount;
}

unsigned Deck::getMonsterCount() const
{
	return monstersCount;
}

void Deck::addMonster(const MonsterCard& monster)
{
	if (monstersCount == MAX_CARDS)
	{
		return;
	}

	if (checkIfMonsterExists(monster))
	{
		return;
	}
	monsters[monstersCount++] = monster;
}

void Deck::addSpell(const SpellCard& spell)
{
	if (spellsCount == MAX_CARDS)
	{
		return;
	}

	if (checkIfSpellExists(spell))
	{
		return;
	}

	spells[spellsCount++] = spell;
}

void Deck::changeMonster(int idx, const MonsterCard& monster)
{
	if (idx < 0 || idx >= monstersCount)
	{
		return;
	}

	monsters[idx] = monster;
}

void Deck::changeSpell(int idx, const SpellCard& spell)
{
	if (idx < 0 || idx >= spellsCount)
	{
		return;
	}

	spells[idx] = spell;
}

void Deck::removeMonster(int idx)
{
	if (idx < 0 || idx >= monstersCount)
	{
		return;
	}

	swapMonsters(monsters[idx], monsters[monstersCount - 1]);
	monstersCount--;
}

void Deck::removeSpell(int idx)
{
	if (idx < 0 || idx >= spellsCount)
	{
		return;
	}

	swapSpells(spells[idx], spells[spellsCount - 1]);
	spellsCount--;
}
