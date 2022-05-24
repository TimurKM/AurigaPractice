#include <iostream>
#include <string>

static size_t getUserInput();
static double translate(const size_t);

int main()
{
	auto versts = getUserInput();

	std::cout << versts << " versts = " << translate(versts) << " kilometres";

	return 0;
}

size_t getUserInput()
{
	size_t versts = 0;

	while (1)
	{
		do
		{
			std::cout << "Enter number of versts: ";

			std::cin >> versts;
		} while (versts < 0);

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}

		break;
	}

	return versts;
}

double translate(const size_t versts)
{
	const auto coefficient = 1.0668;

	return versts * coefficient;
}