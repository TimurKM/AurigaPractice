#include <iostream>
#include <time.h>
#include <random>

class Monster
{
public:
	enum class MonsterType
	{
		DRAGON,
		GOBLIN,
		OGRE,
		ORC,
		SKELETON,
		TROLL,
		VAMPIRE,
		ZOMBIE,
		MAX_MONSTER_TYPES
	};

	Monster(MonsterType type, std::string name, int health) : m_type(type), m_name(name), m_health(health)
	{

	}

	std::string getTypeString()
	{
		const std::string s_names[static_cast<int>(MonsterType::MAX_MONSTER_TYPES)]{ "Dragon", "Goblin", "Ogre", "Orc", "Skeleton", "Troll", "Vampire", "Zombie" };

		return s_names[static_cast<int>(m_type)];
	}

	void print()
	{
		std::cout << m_name << " is the " << getTypeString() << " that has " << m_health << " health points." << std::endl;
	}
private:
	MonsterType m_type = MonsterType::MAX_MONSTER_TYPES;
	std::string m_name = "";
	int m_health = 50;
};

class MonsterGenerator
{
public:
	static Monster generateMonster()
	{
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist1(0, static_cast<int>(Monster::MonsterType::MAX_MONSTER_TYPES) - 1);
		std::uniform_int_distribution<std::mt19937::result_type> dist2(0, 100);

		Monster::MonsterType type = static_cast<Monster::MonsterType>(dist1(rng));

		int health = dist2(rng);

		static const std::string s_names[]{ "John", "Brad", "Alex", "Ron", "Hulk", "Asnee" };

		std::uniform_int_distribution<std::mt19937::result_type> dist3(0, (std::size(s_names) - 1));

		return Monster(type, s_names[dist3(rng)], health);
	}
};

int main()
{
	Monster m = MonsterGenerator::generateMonster();

	m.print();

	return 0;
}
