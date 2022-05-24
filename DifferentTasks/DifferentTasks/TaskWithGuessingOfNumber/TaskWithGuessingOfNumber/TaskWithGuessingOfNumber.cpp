#include <iostream>
#include <random>
#include <array>
#include <iterator>
#include <algorithm>

int main()
{
	auto number = 0;

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 999);
	auto result = dist(rng);

	auto guessCount = 0;

	auto guessPlace = 0;

	std::array<size_t, 3> digitsInput;

	std::array<size_t, 3> digitsComputer;

	digitsComputer[2] = result % 10;
	digitsComputer[1] = (result / 10) % 10;
	digitsComputer[0] = result / 100;

	while (number != result)
	{
		do
		{
			std::cout << "Your variant: ";

			std::cin >> number;
		} while (number < 0 || number >= 1000);

		guessCount = 0;

		guessPlace = 0;

		digitsInput[2] = number % 10;
		digitsInput[1] = (number / 10) % 10;
		digitsInput[0] = number / 100;

		for (size_t i = 0; i < digitsInput.size(); ++i)
		{
			if (digitsInput[i] == digitsComputer[i])
			{
				guessPlace++;
			}

			auto search = std::find(digitsComputer.begin(), digitsComputer.end(), digitsInput[i]);

			if (search != digitsComputer.end())
			{
				guessCount++;
			}
		}

		std::cout << "Guess count:" << guessCount << std::endl;

		std::cout << "Guess places:" << guessPlace << std::endl;
	}

	std::cout << "You won!" << std::endl;

	return 0;
}
