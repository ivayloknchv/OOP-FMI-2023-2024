#include "MonsterCard.h"
#include <cstring>

#pragma warning (disable : 4996)

void MonsterCard::copyFrom(const MonsterCard& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	attack = other.attack;
	defense = other.defense;
}

void MonsterCard::free()
{
	delete[] name;

	name = nullptr;
	attack = 0;
	defense = 0;
}

MonsterCard::MonsterCard() = default;

MonsterCard::MonsterCard(const MonsterCard & other)
{
	copyFrom(other);
}

MonsterCard& MonsterCard::operator=(const MonsterCard& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

MonsterCard::~MonsterCard()
{
	free();
}

MonsterCard::MonsterCard(const char* newName, unsigned newAttack, unsigned newDefense)
{
	setName(newName);
	setAttack(newAttack);
	setDefense(newDefense);
}

void MonsterCard::setName(const char* newName)
{
	if (!newName || newName == name)
	{
		return;
	}

	delete[] name;
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
}

void MonsterCard::setAttack(unsigned newAttack)
{
	attack = newAttack;
}

void MonsterCard::setDefense(unsigned newDefense)
{
	defense = newDefense;
}

const char* MonsterCard::getName() const
{
	return name;
}

unsigned MonsterCard::getAttack() const
{
	return attack;
}

unsigned MonsterCard::getDefense() const
{
	return defense;
}
