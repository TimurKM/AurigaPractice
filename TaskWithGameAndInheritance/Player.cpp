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

void Player::attackMonster(Monster& monster)
{
	if (this->isDead() == true)
	{
		return;
	}

	std::cout << "You hit the " << monster.getName() << " for " << this->getDamage() << " damage" << std::endl;

	monster.reduceHealth(this->getDamage());

	if (monster.isDead() == true)
	{
		std::cout << "You killed the " << monster.getName() << std::endl;
		this->levelUp();
		std::cout << "You are now level " << this->getLevel() << std::endl;
		std::cout << "You found " << monster.getGold() << " gold." << std::endl;
		this->addGold(monster.getGold());
	}
}

void Player::fightMonster()
{
	Monster* monster = Monster::getRandomMonster();

	std::cout << "You have encountered a " << monster->getName() << " (" << monster->getSymbol() << ")." << std::endl;

	while (!this->isDead() && !monster->isDead())
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
				monster->attackPlayer(*this);
				continue;
			}
			else
			{
				std::cout << "You successfully fled" << std::endl;
				return;
			}
		}

		if (choice == 'F' || choice == 'f')
		{
			this->attackMonster(*monster);
			monster->attackPlayer(*this);
		}
	}

	delete monster;
}