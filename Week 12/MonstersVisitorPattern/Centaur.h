#pragma once
#include "Monster.h"

class Centaur : public Monster
{

public:

	Monster* clone() const override;

	int fight(Monster* monster) override;
	int fightWithMinotaur(Minotaur* minotaur) override;
	int fightWithSphynx(Sphynx* other) override;
	int fightWithCentaur(Centaur* centaur) override;
};

