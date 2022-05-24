#include <iostream>
#include "Student.h"
#include "Data.h"

static std::string getStudentName();
static size_t getStudentYear();
static std::array<size_t, 5> getStudentGrades();

int main()
{
	auto students = std::make_unique<Data>();

	size_t countOfStudents = 5;

	std::cout << "Enter 5 students: " << std::endl;

	for (size_t i = 0; i < countOfStudents; i++)
	{
		Student student;

		std::cout << "Enter name of student" << i + 1 << " ";
		student.m_name = getStudentName();

		std::cout << "Enter year of student" << i + 1 << " ";
		student.m_year = getStudentYear();

		std::cout << "Enter 5 grades of student" << i + 1 << " ";
		student.m_rating = getStudentGrades();

		students->addStudent(student);
	}

	if (students != nullptr)
	{
		std::cout << *students;
	}

	return 0;
}

std::string getStudentName()
{
	std::string name;

	while (1)
	{
		std::cin >> std::ws;

		getline(std::cin, name);

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}

		break;
	}

	return name;
}

size_t getStudentYear()
{
	size_t year;

	while (1)
	{
		std::cin >> year;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Enter year again: ";
			continue;
		}

		std::cin.ignore(32767, '\n');
		if (std::cin.gcount() > 1)
		{
			continue;
		}

		break;
	}

	return year;
}

std::array<size_t, 5> getStudentGrades()
{
	std::array<size_t, 5> rating = { 0 };

	while (1)
	{
		for (auto& element : rating)
		{
			std::cin >> element;
		}

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Enter grades again: ";
			continue;
		}

		break;
	}

	return rating;
}