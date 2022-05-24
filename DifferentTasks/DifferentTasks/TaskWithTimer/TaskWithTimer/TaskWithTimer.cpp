#include <iostream>
#include <windows.h>

static size_t getUserInput();

int main()
{
	while (true)
	{
		size_t time = getUserInput();

		Sleep(time * 1000);

		std::cout << "\a" << "It is time" << std::endl;
		break;
	}
	return 0;
}

size_t getUserInput()
{
	size_t time = 0;

	while (1)
	{
		std::cout << "Enter time in seconds: ";

		std::cin >> time;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}

		break;
	}

	return time;
}
