#include "Creature.h"


Creature::Creature(const std::string& name, char symbol, int health, int damage, int gold) :
	m_name(name),
	m_symbol(symbol),
	m_health(health),
	m_damage(damage),
	m_gold(gold)
{ }

void Creature::reduceHealth(int amount)
{
	m_health -= amount;
}

bool Creature::isDead() const
{
	return (m_health <= 0);
}

void Creature::addGold(int amount)
{
	m_gold += amount;
}

const std::string& Creature::getName() const
{
	return m_name;
}

const char Creature::getSymbol() const
{
	return m_symbol;
}

const int Creature::getHealth() const
{
	return m_health;
}

const int Creature::getDamage() const
{
	return m_damage;
}

const int Creature::getGold() const
{
	return m_gold;
}