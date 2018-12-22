#include <ctime>
#include <iostream>
#include <string>

#include "Monster.h"
#include "Player.h"
#include "Random.h"

int main()
{
	Random::init();

	Monster m(Monster::ORC);
	std::string name;
	std::cout << "Enter your name: ";
	std::cin >> name;
	Player player(name);
	std::cout << "Welcome, " << name << "." << std::endl;
	std::cout << "You have " << player.getHealth() << " health and are carrying " << player.getGold() << " gold." << std::endl;
	while (!player.isDead() && !player.hasWon())
	{
		Monster m = Monster::getRandomMonster();
		std::cout << "You have encountered a " << m.getName() << "(" << m.getSymbol() << ")" << std::endl;
		bool fled = false;
		while (!m.isDead() && !fled && !player.isDead())
		{
			std::cout << "(R)run or (F)ight: ";
			char choice;
			std::cin >> choice;
			for (;;)
			{
				if (choice == 'r')
				{
					if (Random::getRandomNumber(0, 1) == 0)
					{
						std::cout << "You successfully fled." << std::endl;
						fled = true;
					}
					else
					{
						std::cout << "You failed to flee." << std::endl;
						player.reduceHealth(m.getDamage());
						std::cout << "The " << m.getName() << " hits you for " << m.getDamage() << " damage." << std::endl;
						std::cout << "You have " << player.getHealth() << " health left." << std::endl;
					}
					break;
				}
				else if (choice == 'f')
				{
					// Fight
					m.reduceHealth(player.getDamage());
					std::cout << "You hit the " << m.getName() << " for " << player.getDamage() << " damage." << std::endl;
					if (!m.isDead())
					{
						std::cout << "The " << m.getName() << " has " << m.getHealth() << " health left." << std::endl;
						player.reduceHealth(m.getDamage());
						std::cout << "The " << m.getName() << " hit you for " << m.getDamage() << " damage." << std::endl;
						if (!player.isDead())
							std::cout << "You have " << player.getHealth() << " health left." << std::endl;
					}
					else
					{
						std::cout << "You killed the " << m.getName() << std::endl;
						player.levelUp();
						std::cout << "You are now level " << player.getLevel() << "." << std::endl;
						player.addGold(m.getGold());
						std::cout << "You found " << m.getGold() << " gold." << std::endl;
					}
					break;
				}
				else
				{
					std::cout << "Please enter choose a valid action; (R)un or (F)ight: ";
					std::cin >> choice;
				}
			}
		}
	}
	if (player.isDead())
	{

		std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold." << std::endl;
		std::cout << "Too bad you can't take it with you!" << std::endl;
	}
	else if (player.hasWon())
		std::cout << "You won the game with " << player.getGold() << std::endl;
	system("pause");
	return 0;
}