#include "Monster.h"
#include "Random.h"

Monster::MonsterData Monster::monsterData[Monster::Type::MAX_TYPES] {
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 }
};

Monster::Monster(Type type) : Creature(monsterData[type].name, monsterData[type].symbol, monsterData[type].health, monsterData[type].damage, monsterData[type].gold)
{ }

Monster Monster::getRandomMonster()
{
	return Monster(static_cast<Type>(Random::getRandomNumber(0, Type::MAX_TYPES - 1)));
}
