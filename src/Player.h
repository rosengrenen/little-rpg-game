#pragma once

#include "Creature.h"

class Player : public Creature
{
private:
	int m_level = 1;
public:
	Player(const std::string& name);

	void levelUp();

	bool hasWon();

	const int getLevel() const;
};

