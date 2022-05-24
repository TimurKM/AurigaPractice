#include <iostream>
#include <array>
#include <sstream>

static const auto countOfNumbers = 10;

static std::array<int, countOfNumbers> getArray();
static int getNumber();

int main()
{
	std::array<int, countOfNumbers> array;

	auto number = 0;

	std::cout << "Enter ten numbers: ";

	array = getArray();

	std::cout << "Enter number for search: ";

	number = getNumber();

	auto result = std::find(array.begin(), array.end(), number);

	(result != array.end()) ? std::cout << "Number is in array" : std::cout << "Number is not in array";

	return 0;
}

std::array<int, countOfNumbers> getArray()
{
	auto a = 0;
	std::string string;
	std::stringstream strStream;
	size_t index = 0;
	std::array<int, countOfNumbers> array = { 0 };

	while (1)
	{
		getline(std::cin, string);

		bool bValid = true;
		for (size_t i = 0; i < string.length(); ++i)
		{
			if (!isdigit(string[i]) && !isspace(string[i]))
			{
				bValid = false;
				break;
			}
		}

		if (!bValid)
		{
			continue;
		}

		strStream << string;
		while (!strStream.eof())
		{
			strStream >> a;
			strStream.ignore(32767, ' ');
			if (strStream.gcount() > 1)
			{
				bValid = false;
				break;
			}
			array[index] = a;
			index++;
		}
		if (!bValid)
		{
			continue;
		}

		break;
	}

	return array;
}

int getNumber()
{
	auto number = 0;

	while (1)
	{
		std::cin >> number;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}

		std::cin.ignore(32767, '\n');
		if (std::cin.gcount() > 1)
		{
			continue;
		}

		break;
	}

	return number;
}