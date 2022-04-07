#include <iostream>
#include <random>
#include "Monster.h"

Monster::Monster(Type type) : Creature(monsterData[static_cast<int>(type)].name,
	monsterData[static_cast<int>(type)].symbol,
	monsterData[static_cast<int>(type)].health,
	monsterData[static_cast<int>(type)].damage,
	monsterData[static_cast<int>(type)].gold)
{

}

Monster* Monster::getRandomMonster()
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, static_cast<int>(Monster::Type::Max_types) - 1);

	Type type = static_cast<Type>(dist(rng));
	Monster* monster = new Monster(type);
	return monster;
}

void Monster::attackPlayer(Player& player)
{
	if (this->isDead() == true)
	{
		return;
	}

	player.reduceHealth(this->getDamage());

	std::cout << "The " << this->getName() << " hit you for " << this->getDamage() << " damage" << std::endl;
}

Monster::MonsterData Monster::monsterData[static_cast<int>(Type::Max_types)]
{
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 }
};