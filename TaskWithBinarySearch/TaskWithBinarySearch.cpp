#include <iostream> 

int binarySearch(int* array, int target, int min, int max)
{
	// итеративный подход
	/*while (min <= max)
	{
		auto indexOfCentreElement = (min + max) / 2;

		if (target < array[indexOfCentreElement])
		{
			max = indexOfCentreElement - 1;
		}
		else if (target > array[indexOfCentreElement])
		{
			min = indexOfCentreElement + 1;
		}
		else
		{
			return indexOfCentreElement;
		}
	}*/

	// рекурсивный подход
	while (min <= max)
	{
		auto indexOfCentreElement = (min + max) / 2;

		if (target < array[indexOfCentreElement])
		{
			return binarySearch(array, target, min, indexOfCentreElement - 1);
		}
		else if (target > array[indexOfCentreElement])
		{
			return binarySearch(array, target, indexOfCentreElement + 1, max);
		}
		else
		{
			return indexOfCentreElement;
		}
	}

	return -1;
}

int main()
{
	int array[] = { 4, 7, 9, 13, 15, 19, 22, 24, 28, 33, 37, 41, 43, 47, 50 };

	std::cout << "Enter a number: ";
	int number;
	std::cin >> number;

	auto index = binarySearch(array, number, 0, 14);

	if (array[index] == number)
	{
		std::cout << "Good! Your value " << number << " is on position " << index << " in array!" << std::endl;
	}
	else
	{
		std::cout << "Fail! Your value " << number << " isn't in array!" << std::endl;
	}

	return 0;
}