#pragma once

#include <string>

class Creature
{
protected:
	std::string m_name;
	char m_symbol;
	int m_health;
	int m_damage;
	int m_gold;
public:
	Creature(const std::string& name, char symbol, int health, int damage, int gold);

	void reduceHealth(int amount);

	bool isDead() const;

	void addGold(int amount);

	const std::string& getName() const;

	const char getSymbol() const;

	const int getHealth() const;

	const int getDamage() const;

	const int getGold() const;
};