#include <iostream>

static void getUserInput(int&, double&, int&);
static double getCost(const int&, const double&, const int&);

int main()
{
	auto distance = 0;

	auto expenditure = 0.0;

	auto gasPrice = 0;

	getUserInput(distance, expenditure, gasPrice);

	std::cout << getCost(distance, expenditure, gasPrice) << std::endl;

	return 0;
}

void getUserInput(int& distance, double& expenditure, int& gasPrice)
{
	while (1)
	{
		do
		{
			std::cout << "Enter distance: ";
			std::cin >> distance;
		} while (distance < 0);

		do
		{
			std::cout << "Enter expenditure: ";
			std::cin >> expenditure;
		} while (expenditure < 0);

		do
		{
			std::cout << "Enter gasPrice: ";
			std::cin >> gasPrice;
		} while (gasPrice < 0);

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}

		break;
	}
}

double getCost(const int& distance, const double& expenditure, const int& gasPrice)
{
	return distance * (expenditure / 100) * gasPrice * 2;
}
