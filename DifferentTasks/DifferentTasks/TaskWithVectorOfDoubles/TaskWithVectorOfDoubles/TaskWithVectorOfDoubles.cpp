#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <numeric>

using neccessaryType = std::vector<double>;

//static void getUserInput(size_t&, neccessaryType&);
//static double findingMin(const neccessaryType&);
//static double findingMax(const neccessaryType&);
static double findingAverage(const neccessaryType&);
static neccessaryType getUserInput();

int main()
{
	size_t count = 0;

	std::cout << "Enter: ";

	neccessaryType vector = getUserInput();

	/*getUserInput(count, vector);

	std::sort(vector.begin(), vector.end());

	std::cout << findingMin(vector) << std::endl;

	std::cout << findingMax(vector) << std::endl;*/

	std::cout << findingAverage(vector) << std::endl;

	return 0;
}

neccessaryType getUserInput()
{
	neccessaryType vector;
	auto a = 0.0;
	std::string string;
	std::stringstream strStream;

	while (1)
	{
		getline(std::cin, string);

		bool bValid = true;
		for (size_t i = 0; i < string.length(); ++i)
		{
			if (!isdigit(string[i]) && !isspace(string[i]) && string[i] != '.')
			{
				bValid = false;
				break;
			}
		}

		if (!bValid)
		{
			continue;
		}

		strStream << string;
		while (!strStream.eof())
		{
			strStream >> a;
			strStream.ignore(32767, ' ');
			if (strStream.gcount() > 1)
			{
				bValid = false;
				break;
			}
			vector.push_back(a);
		}
		if (!bValid)
			continue;

		break;
	}

	return vector;
}

//void getUserInput(size_t& count, neccessaryType& vector)
//{
//	auto a = 0.0;
//
//	do
//	{
//		std::cout << "Enter count of elements: ";
//
//		std::cin >> count;
//
//		if (std::cin.fail())
//		{
//			std::cin.clear();
//			std::cin.ignore(32767, '\n');
//			continue;
//		}
//	} while (count < 0);
//
//	while (vector.size() < count)
//	{
//		std::cin >> a;
//
//		if (std::cin.fail())
//		{
//			std::cin.clear();
//			std::cin.ignore(32767, '\n');
//			continue;
//		}
//
//		vector.push_back(a);
//	}
//}
//
//double findingMin(const neccessaryType& vector)
//{
//	return vector[0];
//}
//
//double findingMax(const neccessaryType& vector)
//{
//	return vector.back();
//}

double findingAverage(const neccessaryType& vector)
{
	return std::accumulate(vector.begin(), vector.end(), 0.0) / vector.size();
}
