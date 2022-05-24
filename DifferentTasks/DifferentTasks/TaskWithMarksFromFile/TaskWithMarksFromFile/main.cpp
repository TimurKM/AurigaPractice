#include <iostream>
#include <fstream>
#include <memory>
#include "Student.h"
#include "Data.h"

int main()
{
	std::ifstream information("input_data.txt");

	auto students = std::make_unique<Data>(information);

	if (students != nullptr)
	{
		std::cout << *students;
	}

	return 0;
}
