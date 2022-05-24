#include <iostream>
#include <string>

static void getUserInput(std::string&);

int main()
{
	std::string era;

	getUserInput(era);

	std::string number = era.substr(0, era.find(" "));

	auto year = stoi(number);

	year % 4 == 0 ? std::cout << "Is a leap year" : std::cout << "Is not a leap year";

	return 0;
}

void getUserInput(std::string& era)
{
	while (1)
	{
		std::cout << "Enter year and era (oe or boe): ";

		getline(std::cin, era);

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}

		break;
	}
}
