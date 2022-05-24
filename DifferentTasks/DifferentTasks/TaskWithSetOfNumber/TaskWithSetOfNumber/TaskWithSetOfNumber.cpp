#include <iostream>
#include <array>
#include <random>
#include <numeric>

static const size_t numberOfSets = 5;

static const size_t numbersInSets = 3;

static size_t getUserInput();

int main()
{
	const std::array<std::array<int, numbersInSets>, numberOfSets> array = { {{6, 7, 8}, {7, 8, 9}, {6, 9, 10}, {6, 9, 8}, {7, 6, 10}} };

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, array.size() - 1);

	auto computerChoice = array[dist(rng)];

	auto userChoice = array[getUserInput()];

	auto userSum = std::accumulate(userChoice.begin(), userChoice.end(), 0);

	auto computerSum = std::accumulate(computerChoice.begin(), computerChoice.end(), 0);

	if (userSum > computerSum)
	{
		std::cout << "Your set wins";
	}
	else if (userSum == computerSum)
	{
		std::cout << "Sums of sets are equal";
	}
	else
	{
		std::cout << "Computer set wins";
	}

	return 0;
}

size_t getUserInput()
{
	size_t choice = 0;

	while (1)
	{
		do
		{
			std::cout << "Choose one of sets 1-{6, 7, 8}, 2-{7, 8, 9}, 3-{6, 9, 10}, 4-{6, 9, 8}, 5-{7, 6, 10}: ";

			std::cin >> choice;

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				continue;
			}

			std::cin.ignore(32767, '\n');
			if (std::cin.gcount() > 1)
			{
				continue;
			}
		} while (choice < 1 || choice > numberOfSets);

		break;
	}

	return choice - 1;
}