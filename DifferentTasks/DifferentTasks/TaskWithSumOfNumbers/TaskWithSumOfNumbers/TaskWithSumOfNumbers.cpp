#include <iostream>

static size_t getUserInput();
static size_t getSum(const size_t);

int main()
{
	auto number = getUserInput();

	std::cout << "The sum of first " << number << " positive even numbers = " << getSum(number);

	return 0;
}

size_t getUserInput()
{
	size_t number = 0;

	while (1)
	{
		do
		{
			std::cout << "Enter a number: ";

			std::cin >> number;
		} while (number < 0);

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}

		break;
	}

	return number;
}

size_t getSum(const size_t number)
{
	return number * (number + 1);
}
