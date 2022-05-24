#pragma once
#include <string>
#include <array>
#include <iostream>
#include <numeric>

struct Student
{
	std::string m_name;
	size_t m_year = 0;
	std::array<size_t, 5> m_rating = { 0 };

	Student() = default;

	//Student(const std::string& name, const size_t year, const std::array<size_t, 5>& rating);

	double getAverage() const;

	friend std::ostream& operator<< (std::ostream& out, const Student& student);
};