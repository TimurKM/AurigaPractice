#include <iostream>

static void getUserInput(int&);
double getCostWithDiscount(int&, int&);

int main()
{
	auto price = 0;

	auto discount = 0;

	auto firstPriceWithDiscount = 500;

	auto secondPriceWithDiscount = 1000;

	getUserInput(price);

	if (price <= firstPriceWithDiscount)
	{
		discount = 0;
	}
	else if (price > firstPriceWithDiscount && price <= secondPriceWithDiscount)
	{
		std::cout << "Your discount is 3 percents" << std::endl;
		discount = 3;
	}
	else
	{
		std::cout << "Your discount is 5 percents" << std::endl;
		discount = 5;
	}

	std::cout << "Price with discount: " << getCostWithDiscount(price, discount);

	return 0;
}

void getUserInput(int& price)
{
	while (1)
	{
		do
		{
			std::cout << "Enter a price: ";
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
}

double getCostWithDiscount(int& price, int& discount)
{
	auto sum = 0.0;

	sum = static_cast<double>(price) - (static_cast<double>(price * discount) / 100);

	return sum;
}