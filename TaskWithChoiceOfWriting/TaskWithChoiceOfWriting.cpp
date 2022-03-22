#include <iostream>
#include <vector>
#include <ostream>
#include <fstream>

namespace
{
	using userVector = std::vector<int>&;

	void resultPrint(const userVector vector, std::ostream& destination)
	{
		for (size_t i = 0; i < vector.size(); ++i)
		{
			if ((i + 1) % 3 == 0)
			{
				destination << vector[i] << std::endl;
			}
			else
			{
				destination << vector[i] << ' ';
			}
		}
	}

	void printInConsole(const userVector vector)
	{
		resultPrint(vector, std::cout);
	}

	void writeInFile(const userVector vector)
	{
		std::ofstream output_file("Test1.txt");

		resultPrint(vector, output_file);
	}

	void selectWayOfWriting(const userVector vector, void (*wayPtr)(const userVector) = printInConsole)
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

	void getUserInput(userVector vector, int& userChoice)
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
	void (*fcnPtr)(const userVector) = nullptr;

	getUserInput(data, userChoice);

	if (userChoice == 1)
	{
		fcnPtr = printInConsole;
	}
	else if (userChoice == 2)
	{
		fcnPtr = writeInFile;
	}

	selectWayOfWriting(data, fcnPtr);

	return 0;
}
