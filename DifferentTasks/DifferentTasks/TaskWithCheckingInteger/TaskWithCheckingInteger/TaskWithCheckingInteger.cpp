#include <iostream>
#include <string>

std::string getUserInput();

int main()
{
	auto number = getUserInput();

	bool result = true;

	for (const auto& element : number)
	{
		if (!std::isdigit(element))
		{
			result = false;
			break;
		}
	}

	result ? std::cout << "It is an integer" : std::cout << "It is not an integer";

	return 0;
}

std::string getUserInput()
{
	std::string number;

	std::cout << "Enter number: ";

	std::cin >> number;

	return number;
}
