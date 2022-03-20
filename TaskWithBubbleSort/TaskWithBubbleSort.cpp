#include <iostream>

int main()
{
	const int length(9);
	int array[length] = { 7, 5, 6, 4, 9, 8, 2, 1, 3 };

	for (size_t i = 0; i < length - 1; ++i)
	{
		for (size_t currentIndex = 0; currentIndex < length - 1; ++currentIndex)
		{
			if (array[currentIndex] > array[currentIndex + 1])
			{
				std::swap(array[currentIndex], array[currentIndex + 1]);
			}
		}
	}
	/*for (size_t index = 0; index < length - 1; index++)
	{
		std::cout << array[index] << std::endl;
	}*/
	for (const auto& element : array)
	{
		std::cout << element << std::endl;
	}
}
