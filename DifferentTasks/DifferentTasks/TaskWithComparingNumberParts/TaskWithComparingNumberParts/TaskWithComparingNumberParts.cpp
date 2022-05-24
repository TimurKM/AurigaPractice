#include <iostream>
#include <array>
#include <valarray>
#include <string>

static int getUserInput();

static std::valarray<size_t> split(size_t);

static const auto countOfElements = 3;

int main()
{
	auto number = abs(getUserInput());

	auto number1 = number / 1000;

	auto number2 = number % 1000;

	std::valarray<size_t> array1;

	array1.resize(countOfElements);

	std::valarray<size_t> array2;

	array2.resize(countOfElements);

	array1 = split(number1);

	array2 = split(number2);

	if (array1.sum() == array2.sum())
	{
		std::cout << "Sum of parts are equal";
	}
	else
	{
		std::cout << "Sum of parts are not equal";
	}

	return 0;
}

int getUserInput()
{
	auto number = 0;

	while (1)
	{
		do
		{
			std::cout << "Enter six-digit number: ";

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
		} while ((number < -999999 || number > -100000) && (number > 999999 || number < 100000));

		break;
	}

	return number;
}

std::valarray<size_t> split(size_t number)
{
	std::valarray<size_t> array;

	array.resize(countOfElements);

	for (auto& element : array)
	{
		element = number % 10;
		number /= 10;
	}

	return array;
}