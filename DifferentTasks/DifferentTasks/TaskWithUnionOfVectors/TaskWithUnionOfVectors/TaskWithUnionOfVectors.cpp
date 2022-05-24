#include <iostream>
#include <vector>
#include <array>
#include<algorithm>

//using neccessaryType = std::vector<int>;
//
//static neccessaryType getUserInput();
//static neccessaryType unionOfVectors(const neccessaryType&, const neccessaryType&);
//
//int main()
//{
//	neccessaryType vector1;
//
//	neccessaryType vector2;
//
//	std::cout << "Enter first vector: ";
//	vector1 = getUserInput();
//
//	std::cout << "Enter second vector: ";
//	vector2 = getUserInput();
//
//	std::cout << "United vector: ";
//	auto resultVector = unionOfVectors(vector1, vector2);
//
//	for (const auto& element : resultVector)
//	{
//		std::cout << element << " ";
//	}
//
//	return 0;
//}
//
//neccessaryType getUserInput()
//{
//	auto a = 0;
//
//	neccessaryType vector;
//
//	while (std::cin >> a)
//	{
//		if (std::cin.fail())
//		{
//			std::cin.clear();
//			std::cin.ignore(32767, '\n');
//			continue;
//		}
//
//		vector.push_back(a);
//
//		char c = std::cin.get();
//
//		if (c == '\n')
//		{
//			break;
//		}
//	}
//
//	std::sort(vector.begin(), vector.end());
//
//	return vector;
//}
//
//neccessaryType unionOfVectors(const neccessaryType& vector1, const neccessaryType& vector2)
//{
//	neccessaryType resultVector;
//
//	//std::set_union(vector1.begin(), vector1.end(), vector2.begin(), vector2.end(), std::back_inserter(resultVector));
//
//	auto vectorSize1 = vector1.size();
//
//	auto vectorSize2 = vector2.size();
//
//	auto i = 0;
//
//	auto j = 0;
//
//	while (i < vectorSize1 && j < vectorSize2)
//	{
//		if (vector1[i] <= vector2[j])
//		{
//			resultVector.push_back(vector1[i]);
//			++i;
//		}
//		else
//		{
//			resultVector.push_back(vector2[j]);
//			++j;
//		}
//	}
//
//	return resultVector;
//}

void getUserInput(int* array, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		std::cin >> array[i];
	}

	std::sort(array, array + size);
}

int* unionArrays(int* array1, size_t size1, int* array2, size_t size2)
{
	auto i = 0;

	auto j = 0;

	auto k = 0;

	int* array3 = nullptr;

	if (array1 != nullptr && array2 != nullptr && size1 > 0 && size2 > 0)
	{
		const auto size3 = size1 + size2;

		array3 = new int[size3];

		while ((i < size1 || j < size2) && k < size3)
		{
			if (i < size1 && j < size2)
			{
				if (array1[i] <= array2[j])
				{
					array3[k++] = array1[i++];
				}
				else
				{
					array3[k++] = array2[j++];
				}
			}
			else if (j < size2)
			{
				array3[k++] = array2[j++];
			}
			else if (i < size1)
			{
				array3[k++] = array1[i++];
			}
		}
	}

	return array3;
}

int main()
{
	size_t size1 = 0;

	std::cout << "Enter first size: ";

	std::cin >> size1;

	int* array1 = new int[size1];

	getUserInput(array1, size1);

	size_t size2 = 0;

	std::cout << "Enter second size: ";

	std::cin >> size2;

	int* array2 = new int[size2];

	getUserInput(array2, size2);

	auto array3 = unionArrays(array1, size1, array2, size2);

	const size_t size3 = size1 + size2;

	if (array3 != nullptr)
	{
		for (size_t i = 0; i < size3; ++i)
		{
			std::cout << array3[i] << " ";
		}
	}

	delete[] array1;
	delete[] array2;
	delete[] array3;
}