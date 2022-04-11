#include <iostream>
#include <random>
#include "Player.h"

Player::Player(const std::string& name) : Creature(name, '@', 10, 1, 0)
{

}

void Player::levelUp()
{
	++m_level;
	++m_health;
	++m_damage;
}

int Player::getLevel() const
{
	return m_level;
}

bool Player::hasWon() const
{
	return (m_level >= 10) ? true : false;
}

void Player::attack(Monster& monster)
{
	if (isDead() == true)
	{
		return;
	}

	std::cout << "You hit the " << monster.getName() << " for " << getDamage() << " damage" << std::endl;

	monster.reduceHealth(getDamage());

	if (monster.isDead() == true)
	{
		std::cout << "You killed the " << monster.getName() << std::endl;
		levelUp();
		std::cout << "You are now level " << getLevel() << std::endl;
		std::cout << "You found " << monster.getGold() << " gold." << std::endl;
		addGold(monster.getGold());
	}
}

void Player::fight()
{
	Monster* monster = Monster::getRandomMonster();

	std::cout << "You have encountered a " << monster->getName() << " (" << monster->getSymbol() << ")." << std::endl;

	while (!isDead() && !monster->isDead())
	{
		std::cout << "(R)un or (F)ight: ";

		auto choice = 'F';

		std::cin >> choice;

		if (choice == 'R' || choice == 'r')
		{
			std::random_device dev;
			std::mt19937 rng(dev());
			std::uniform_int_distribution<std::mt19937::result_type> dist(0, 1);

			auto escape = dist(rng);

			if (escape == 0)
			{
				std::cout << "You didn't successfully flee" << std::endl;
				monster->attack(*this);
				continue;
			}
			else
			{
				std::cout << "You successfully fled" << std::endl;
				break;
			}
		}

		if (choice == 'F' || choice == 'f')
		{
			attack(*monster);
			monster->attack(*this);
		}
	}

	delete monster;
}