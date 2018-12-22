#pragma once

#include "Creature.h"

class Monster : public Creature
{
public:
	enum Type
	{
		DRAGON,
		ORC,
		SLIME,
		MAX_TYPES
	};
private:
	struct MonsterData
	{
		std::string name;
		char symbol;
		int health;
		int damage;
		int gold;
	};
	static MonsterData monsterData[Type::MAX_TYPES];
public:
	Monster(Type type);

	static Monster getRandomMonster();
};

