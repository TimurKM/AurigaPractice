#include <iostream>

static void getUserInput(size_t&, double&);

int main()
{
	size_t scholarship = 0;

	auto discharge = 0.0;

	auto result = 0.0;

	auto incrisingPercent = 0.03;

	size_t countOfMonth = 10;

	getUserInput(scholarship, discharge);

	for (size_t i = 0; i < countOfMonth; ++i)
	{
		discharge += (discharge * incrisingPercent);
		result += discharge;
	}

	std::cout << "For 10 month your dicharge is " << result << " with scholarship " << scholarship << " per month. You need "
		<< result - scholarship * countOfMonth << " for 10 month" << std::endl;

	return 0;
}

void getUserInput(size_t& scholarship, double& discharge)
{
	while (1)
	{
		std::cout << "Enter scholarship: ";

		std::cin >> scholarship;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}

		do
		{
			std::cout << "Enter discharge: ";

			std::cin >> discharge;

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				continue;
			}
		} while (discharge <= scholarship);



		break;
	}
}
