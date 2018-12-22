#include "Player.h"

Player::Player(const std::string& name) : Creature(name, '@', 10, 1, 0)
{ }

void Player::levelUp()
{
	m_level++;
	m_damage++;
}

bool Player::hasWon()
{
	return m_level >= 20;
}

const int Player::getLevel() const
{
	return m_level;
}
