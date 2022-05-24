#include <iostream>

static void getUserInput(int&);
static void comparison(const int&, const int&);

int main()
{
	auto number1 = 0;

	auto number2 = 0;

	getUserInput(number1);

	getUserInput(number2);

	comparison(number1, number2);

	return 0;
}

void getUserInput(int& number)
{
	while (1)
	{
		do
		{
			std::cout << "Enter integer number: ";

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
}

void comparison(const int& number1, const int& number2)
{
	if (number1 > number2)
	{
		std::cout << number1 << " more than " << number2 << std::endl;
	}
	else if (number1 < number2)
	{
		std::cout << number1 << " less than " << number2 << std::endl;
	}
	else
	{
		std::cout << number1 << " is equal to " << number2 << std::endl;
	}
}