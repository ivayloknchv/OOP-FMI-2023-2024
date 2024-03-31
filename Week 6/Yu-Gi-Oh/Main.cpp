#include <iostream>
#include "Duelist.h"
int main()
{
	Duelist d;
	d.setName("Seto Kaiba");

	MonsterCard mc("Dark Magician", 2500, 2100);

	d.addMonsterInDeck(mc);
	d.changeMonsterInDeck(0,mc);

	SpellCard sp("Reflection", "Reflects the last played spell", Type::TRAP);
	d.addSpellInDeck(sp);
	return 0;
}
