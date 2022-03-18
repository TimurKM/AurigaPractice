#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>

namespace
{
	void printInConsole(const std::vector<int>& vector)
	{
		for (size_t i = 0; i < vector.size(); ++i)
		{
			if ((i + 1) % 3 == 0)
			{
				std::cout << vector[i] << std::endl;
			}
			else
			{
				std::cout << vector[i] << ' ';
			}
		}
	}

	void writeInFile(const std::vector<int>& vector)
	{
		std::ofstream output_file("Test1.txt");
		for (size_t i = 0; i < vector.size(); ++i)
		{
			if ((i + 1) % 3 == 0)
			{
				output_file << vector[i] << std::endl;
			}
			else
			{
				output_file << vector[i] << ' ';
			}
		}
	}

	void selectWayOfWriting(const std::vector<int>& vector, void (*wayPtr)(const std::vector<int>&) = printInConsole)
	{
		if (wayPtr)
		{
			wayPtr(vector);
		}
		else
		{
			std::cout << "WayPtr is nullptr" << std::endl;
		}
	}

	void getUserInput(std::vector<int>& vector, int& userChoice)
	{
		auto buffer = 0;

		std::cout << "Input Data: " << std::endl;

		while (std::cin >> buffer)
		{
			vector.push_back(buffer);
			char c = std::cin.get();
			if (c == '\n')
			{
				break;
			}
		}

		std::cout << "Input 1 or 2: " << std::endl;

		std::cin >> userChoice;
	}
}

int main()
{
	std::vector<int> data;
	auto userChoice = 0;
	void (*fcnPtr)(const std::vector<int>&) = nullptr;

	getUserInput(data, userChoice);

	if (userChoice == 1)
	{
		fcnPtr = printInConsole;
	}
	else if (userChoice == 2)
	{
		fcnPtr = writeInFile;
	}
	else
	{
		return 0;
	}

	if (fcnPtr)
	{
		selectWayOfWriting(data, fcnPtr);
	}
	else
	{
		std::cout << "FcnPtr is nullptr" << std::endl;
	}
}
