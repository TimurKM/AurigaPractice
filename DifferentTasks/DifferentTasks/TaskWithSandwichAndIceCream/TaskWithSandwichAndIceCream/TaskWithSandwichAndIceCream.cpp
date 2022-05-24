#include <iostream>

bool isIcecreamSandwich(const std::string&);

int main()
{
	std::string string;
	while (1)
	{
		std::cout << "Enter string: ";
		std::cin >> string;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}

		break;
	}

	std::cout.setf(std::ios::boolalpha);
	std::cout << isIcecreamSandwich(string);
	return 0;
}

bool isIcecreamSandwich(const std::string& string)
{
	auto length = string.length();

	auto center = false;

	if (length >= 3)
	{
		char symbol = string[0];

		for (size_t i = 0; i < (length / 2) + 1; ++i)
		{
			if (string[i] != symbol)
			{
				if (center == true)
				{
					center = false;
					break;
				}

				center = true;

				symbol = string[i];
			}

			if (string[i] != string[length - 1 - i])
			{
				center = false;
				break;
			}
		}
	}

	return center;
}
