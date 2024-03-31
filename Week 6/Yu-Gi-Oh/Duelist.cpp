#include "Duelist.h"
#include <cstring>

#pragma warning (disable: 4996)

void Duelist::copyFrom(const Duelist& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}

void Duelist::free()
{
	delete[] name;
	name = nullptr;
}

Duelist::Duelist() = default;

Duelist::Duelist(const Duelist& other)
{
	copyFrom(other);
}

Duelist& Duelist:: operator = (const Duelist& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Duelist::~Duelist()
{
	free();
}

Duelist::Duelist(const char* newName, const Deck& newDeck)
{
	setName(newName);
	setDeck(newDeck);
}

void Duelist::setName(const char* newName)
{
	if (!newName)
	{
		return;
	}

	delete[] name;

	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
}

void Duelist::setDeck(const Deck& newDeck)
{
	deck = newDeck;
}

void Duelist::removeSpellFromDeck(int idx)
{
	deck.removeSpell(idx);
}

void Duelist::removeMonsterFromDeck(int idx)
{
	deck.removeMonster(idx);
}

void Duelist::changeSpellInDeck(int idx, const SpellCard& spell)
{
	deck.changeSpell(idx, spell);
}

void Duelist::changeMonsterInDeck(int idx, const MonsterCard& monster)
{
	deck.changeMonster(idx, monster);
}

void Duelist::addSpellInDeck(const SpellCard& spell)
{
	deck.addSpell(spell);
}


void Duelist::addMonsterInDeck(const MonsterCard& monster)
{
	deck.addMonster(monster);
}



