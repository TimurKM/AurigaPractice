#include <iostream>
#include <string>

static size_t getUserInput();
static std::string getRightForm(size_t);

int main()
{
	setlocale(LC_ALL, "rus");

	auto number = getUserInput();

	std::cout << number << getRightForm(number);

	return 0;
}

size_t getUserInput()
{
	size_t number;

	do
	{
		std::cout << "Enter number: ";

		std::cin >> number;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}
	} while (number < 1 || number > 99);

	return number;
}

std::string getRightForm(size_t number)
{
	std::string result;

	switch (number % 10)
	{
	case 0:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		result = " копеек";
		break;
	case 1:
		result = " копейка";
		break;
	case 2:
	case 3:
	case 4:
		result = " копейки";
		break;
	default:
		break;
	}

	return result;
}