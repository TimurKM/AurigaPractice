#include <iostream>

static void getUserInput(int&, double&);
static double getSpeed(int&, double&);

int main()
{
	auto distance = 0;

	auto time = 0.00;

	getUserInput(distance, time);

	std::cout << "Your speed is: " << getSpeed(distance, time) << " km/h" << std::endl;

	return 0;
}

void getUserInput(int& distance, double& time)
{
	while (1)
	{
		do
		{
			std::cout << "Enter distance: ";
			std::cin >> distance;
		} while (distance < 0);

		do
		{
			std::cout << "Enter time in minutes and seconds: ";
			std::cin >> time;

		} while (time < 0 || (time - static_cast<int>(time)) > 0.60);


		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}

		break;
	}
}

double getSpeed(int& distance, double& time)
{
	auto minutes = static_cast<int>(time);

	auto timeInSeconds = (time - static_cast<int>(time)) * 100;

	return (static_cast<double>(distance) / (60 * minutes + timeInSeconds)) * 3.6;
}
