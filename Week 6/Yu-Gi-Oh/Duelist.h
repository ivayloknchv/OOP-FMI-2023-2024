#include "Deck.h"
#pragma once

class Duelist
{
	char* name = nullptr;
	Deck deck;

	void copyFrom(const Duelist& other);
	void free();

public:

	Duelist();
	Duelist(const Duelist& other);
	Duelist& operator=(const Duelist & other);
	~Duelist();

	Duelist(const char* newName, const Deck& newDeck);

	void setName(const char* newName);
	void setDeck(const Deck& newDeck);

	void addMonsterInDeck(const MonsterCard& monster);
	void addSpellInDeck(const SpellCard& spell);

	void changeMonsterInDeck(int idx, const MonsterCard& monster);
	void changeSpellInDeck(int idx, const SpellCard& spell);

	void removeMonsterFromDeck(int idx);
	void removeSpellFromDeck(int idx);
};

