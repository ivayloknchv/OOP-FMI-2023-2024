#include "Sphynx.h"

Monster* Sphynx::clone() const
{
    return new Sphynx(*this);
}

int Sphynx::fight(Monster* monster)
{
    return monster->fightWithSphynx(this) * (-1);
}

int Sphynx::fightWithMinotaur(Minotaur* minotaur)
{
    return -1;
}

int Sphynx::fightWithSphynx(Sphynx* other)
{
    return 0;
}

int Sphynx::fightWithCentaur(Centaur* centaur)
{
    return 1;
}
