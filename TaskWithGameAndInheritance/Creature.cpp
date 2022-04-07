#include "Creature.h"

Creature::Creature(const std::string& name, const char symbol, const int health, const int damage, const int gold) :
	m_name(name), m_symbol(symbol), m_health(health), m_damage(damage), m_gold(gold)
{

}

std::string Creature::getName() const
{
	return m_name;
}

char Creature::getSymbol() const
{
	return m_symbol;
}

int Creature::getHealth() const
{
	return m_health;
}

int Creature::getDamage() const
{
	return m_damage;
}

int Creature::getGold() const
{
	return m_gold;
}

void Creature::reduceHealth(const int value)
{
	m_health -= value;
}

bool Creature::isDead() const
{
	return (m_health <= 0) ? true : false;
}

void Creature::addGold(const int value)
{
	m_gold += value;
}