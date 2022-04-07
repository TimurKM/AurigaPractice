#pragma once
#include "Creature.h"
#include "Monster.h"

class Monster;

class Player : public Creature
{
private:
	int m_level = 1;

public:
	Player(const std::string& name);

	void levelUp();

	int getLevel() const;

	bool hasWon() const;

	void attackMonster(Monster& monster);

	void fightMonster();
};