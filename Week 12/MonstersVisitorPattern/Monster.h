#pragma once

class Minotaur;
class Sphynx;
class Centaur;

enum class MonsterType
{
	Minotaur,
	Sphynx,
	Centaur
};

class Monster
{
public:

	virtual Monster* clone()  const = 0;

	virtual int fight(Monster* monster) = 0;
	virtual int fightWithMinotaur(Minotaur* minotaur) = 0;
	virtual int fightWithSphynx(Sphynx* other) = 0;
	virtual int fightWithCentaur(Centaur* centaur) = 0;

	virtual ~Monster() = default;
};

