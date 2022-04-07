#pragma once
#include "Creature.h"
#include "Player.h"

class Player;

class Monster : public Creature
{
private:
	enum class Type
	{
		Dragon,
		Orc,
		Slime,
		Max_types
	};

	struct MonsterData
	{
		std::string name;
		char symbol = 'A';
		int health = 0;
		int damage = 0;
		int gold = 0;
	};

	static MonsterData monsterData[static_cast<int>(Type::Max_types)];

public:

	Monster(Type type);

	static Monster* getRandomMonster();

	void attackPlayer(Player& player);
};