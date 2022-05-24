#include <iostream>

static void getUserInput(double&, double&);

int main()
{
	auto averageGrade = 0.0;

	double experience = 0.0;

	size_t coefficient = 0;

	const auto passScore = 45;

	getUserInput(averageGrade, experience);

	if (experience == 0)
	{
		coefficient = 11;
	}
	else if (experience < 2)
	{
		coefficient = 13;
	}
	else
	{
		coefficient = 16;
	}

	averageGrade* coefficient >= passScore ? std::cout << "Congratulations" : std::cout << "Do not worry";

	return 0;
}

void getUserInput(double& averageGrade, double& experience)
{
	while (1)
	{
		do
		{
			std::cout << "Enter average grade: ";
			std::cin >> averageGrade;
		} while (averageGrade < 3.0 || averageGrade > 5.0);

		do
		{
			std::cout << "Enter experience in years: ";

			std::cin >> experience;
		} while (experience > 5.0);


		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}

		break;
	}
}