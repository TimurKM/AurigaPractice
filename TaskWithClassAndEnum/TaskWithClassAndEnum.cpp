#include <iostream>
#include <time.h>

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
		std::string type;
		switch (m_type)
		{
		case Monster::MonsterType::DRAGON:
			type = "Dragon";
			break;
		case Monster::MonsterType::GOBLIN:
			type = "Goblin";
			break;
		case Monster::MonsterType::OGRE:
			type = "Ogre";
			break;
		case Monster::MonsterType::ORC:
			type = "Orc";
			break;
		case Monster::MonsterType::SKELETON:
			type = "Skeleton";
			break;
		case Monster::MonsterType::TROLL:
			type = "Troll";
			break;
		case Monster::MonsterType::VAMPIRE:
			type = "Vampire";
			break;
		case Monster::MonsterType::ZOMBIE:
			type = "Zombie";
			break;
		default:
			break;
		}

		return type;
	}

	void print()
	{
		std::cout << m_name << " is the " << getTypeString() << " that has " << m_health << " health points." << std::endl;
	}
private:
	MonsterType m_type = MonsterType::MAX_MONSTER_TYPES;
	std::string m_name = "Jack";
	int m_health = 50;
};

class MonsterGenerator
{
public:
	static Monster generateMonster()
	{
		Monster::MonsterType type = static_cast<Monster::MonsterType>(getRandomNumber(0, static_cast<int>(Monster::MonsterType::MAX_MONSTER_TYPES)));

		int health = getRandomNumber(1, 100);

		static std::string s_names[6]{ "John", "Brad", "Alex", "Ron", "Hulk", "Asnee" };

		return Monster(type, s_names[getRandomNumber(0, 5)], health);
	}

	static int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}
};

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	rand();

	Monster m = MonsterGenerator::generateMonster();

	m.print();

	return 0;
}
