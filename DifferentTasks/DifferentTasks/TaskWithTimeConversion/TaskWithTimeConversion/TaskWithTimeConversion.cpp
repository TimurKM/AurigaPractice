#include <iostream>
#include <string>

static size_t getUserInput();
static void conversionTime(size_t&, size_t&, const size_t);

int main()
{
	size_t hours = 0;

	size_t minutes = 0;

	size_t time = getUserInput();

	conversionTime(hours, minutes, time);

	std::cout << time << " minutes =  " << hours << " hours " << minutes << " minutes" << std::endl;

	return 0;
}

size_t getUserInput()
{
	size_t time = 0;

	while (1)
	{
		do
		{
			std::cout << "Enter time in minutes: ";

			std::cin >> time;
		} while (time < 0);

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

void conversionTime(size_t& hours, size_t& minutes, const size_t time)
{
	hours = time / 60;

	minutes = time % 60;
}