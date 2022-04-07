#pragma once
#include <string>

class Creature
{
protected:
	std::string m_name;
	char m_symbol = 'A';
	int m_health = 0;
	int m_damage = 0;
	int m_gold = 0;
public:
	Creature(const std::string& name, const char symbol, const int health, const int damage, const int gold);

	std::string getName() const;

	char getSymbol() const;

	int getHealth() const;

	int getDamage() const;

	int getGold() const;

	void reduceHealth(const int value);

	bool isDead() const;

	void addGold(const int value);
};