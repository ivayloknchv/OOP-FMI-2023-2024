#pragma once

class MonsterCard
{
	char* name = nullptr;
	unsigned attack = 0;
	unsigned defense = 0;

	void copyFrom(const MonsterCard& other);
	void free();

public:

	MonsterCard();
	MonsterCard(const MonsterCard& other);
	MonsterCard& operator=(const MonsterCard& other);
	~MonsterCard();

	MonsterCard(const char* newName, unsigned newAttack, unsigned newDefense);

	void setName(const char* newName);
	void setAttack(unsigned newAttack);
	void setDefense(unsigned newDefense);

	const char* getName() const;
	unsigned getAttack() const;
	unsigned getDefense() const;

};