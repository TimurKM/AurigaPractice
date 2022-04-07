#include <iostream>
#include <random>
#include "Creature.h"
#include "Player.h"
#include "Monster.h"

int main()
{
	auto answer = 'Y';

	std::cout << "Enter your name: ";

	std::string name;

	std::cin >> name;

	do
	{
		Player* player = new Player(name);

		std::cout << "Welcome, " << player->getName() << std::endl;

		while (!player->isDead() && !player->hasWon())
		{
			player->fightMonster();
		}

		if (player->isDead())
		{
			std::cout << "You died at level " << player->getLevel() << " and with " << player->getGold() << " gold." << std::endl;

			std::cout << "Too bad you can't take it with you!" << std::endl;
		}

		if (player->hasWon())
		{
			std::cout << "You won with " << player->getGold() << " gold." << std::endl;
		}

		delete player;

		std::cout << "Do you want to play again? (Enter Y or N)";

		std::cin >> answer;
	} while (answer == 'Y' || answer == 'y');

	return 0;
}
