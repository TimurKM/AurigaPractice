#include <iostream>

static double getUserInput();
static double translate(const double);

int main()
{
	auto pounds = getUserInput();

	std::cout << pounds << " pounds = " << translate(pounds) << " kilograms";

	return 0;
}

double getUserInput()
{
	double pounds = 0.0;

	while (1)
	{
		std::cout << "Enter number of pounds: ";

		std::cin >> pounds;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}

		break;
	}

	return pounds;
}

double translate(const double pounds)
{
	const auto coefficient = 0.453;

	return pounds * coefficient;
}
