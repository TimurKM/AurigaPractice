#include <iostream>
#include <string>

static size_t getUserInput();

int main()
{
	std::string string;

	auto number = getUserInput();

	string = std::to_string(number);

	if (string[1] == string[2] && string[0] == string[3])
	{
		std::cout << "It is palindrome";
	}
	else
	{
		std::cout << "It is not palindrome";
	}

	return 0;
}

size_t getUserInput()
{
	size_t number = 0;

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
	} while (number < 1000 || number > 9999);

	return number;
}
