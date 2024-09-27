#include <iostream>
#include <algorithm>

namespace
{
	auto sortArray(std::string* array, int countNames)
	{
		std::sort(array, array + countNames);
	}

	auto printSortedArray(std::string* array, int countNames)
	{
		std::cout << "Here is your sorted array: " << std::endl;
		for (size_t i = 0; i < countNames; ++i)
		{
			std::cout << array[i] << std::endl;
		}
	}
}

int main()
{
	std::cout << "How many names would you like to enter ? ";
	auto countNames = 0;
	std::cin >> countNames;
	std::string* array = new std::string[countNames];
	for (size_t i = 0; i < countNames; ++i)
	{
		std::cout << "Enter name #" << i + 1 << ' ';
		std::cin >> array[i];
	}
	sortArray(array, countNames);
	printSortedArray(array, countNames);
	delete[] array;
	array = nullptr;
}

