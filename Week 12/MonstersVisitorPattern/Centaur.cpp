#include "Centaur.h"

Monster* Centaur::clone() const
{
    return new Centaur(*this);
}

int Centaur::fight(Monster* monster)
{
    return monster->fightWithCentaur(this) * (-1);
}

int Centaur::fightWithMinotaur(Minotaur* minotaur)
{
    return 1;
}

int Centaur::fightWithSphynx(Sphynx* other)
{
    return -1;
}

int Centaur::fightWithCentaur(Centaur* centaur) 
{
    return 0;
}
