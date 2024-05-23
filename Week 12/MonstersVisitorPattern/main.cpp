#include <iostream>
#include "MonstersCollection.h"
#include "Monster.h"
#include "Minotaur.h"
#include "Centaur.h"
#include "Sphynx.h"

int main()
{
	MonstersCollection mc;

	mc.addMonster(MonsterType::Sphynx);
	mc.addMonster(MonsterType::Sphynx);
	mc.addMonster(MonsterType::Sphynx);
	mc.addMonster(MonsterType::Minotaur);
	mc.addMonster(MonsterType::Centaur);

	std::cout << mc.monsterBattle(2);

	return 0;
}