#include "Student.h"

//Student::Student(const std::string& name, const size_t year, const std::array<size_t, 5>& rating) : m_name(name), m_year(year), m_rating(rating)
//{
//
//}

double Student::getAverage() const
{
	return std::accumulate(m_rating.begin(), m_rating.end(), 0.0) / m_rating.size();
}

std::ostream& operator<< (std::ostream& out, const Student& student)
{
	out << student.m_name << " " << student.m_year << " ";

	for (const auto& element : student.m_rating)
	{
		out << element << " ";
	}

	return out;
}