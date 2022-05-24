#include <iostream>

static double getUserInput();
static void printCost(const double);

int main()
{
	auto price = getUserInput();

	printCost(price);

	return 0;
}

double getUserInput()
{
	auto price = 0.0;

	while (1)
	{
		do
		{
			std::cout << "Enter price of 1 kg: ";

			std::cin >> price;
		} while (price < 0);

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}

		break;
	}

	return price;
}

void printCost(const double price)
{
	auto countOfKg = 1;

	std::cout << "Weight" << " " << "Cost" << std::endl;

	for (double i = 0.1; i <= countOfKg; i += 0.1)
	{
		std::cout << i * 1000 << " " << price * i << std::endl;
	}
}