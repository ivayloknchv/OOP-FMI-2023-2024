#include "Minotaur.h"
#include <iostream>

Monster* Minotaur::clone() const
{
	return new Minotaur(*this);
}

int Minotaur::fight(Monster* monster)
{
	return monster->fightWithMinotaur(this) * (-1) ;
}

int Minotaur::fightWithMinotaur(Minotaur* minotaur)
{
	return 0;
}

int Minotaur::fightWithSphynx(Sphynx* other) 
{
	return 1;
}

int Minotaur::fightWithCentaur(Centaur* centaur) 
{
	return -1;
}
