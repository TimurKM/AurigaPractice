#include "Data.h"

void Data::addStudent(const Student& student)
{
	m_students[m_counter++] = student;

	std::sort(m_students.begin(), m_students.end(), [](const Student& s1, const Student& s2) { return s1.m_name < s2.m_name; });
}

double Data::getCommonAverage() const
{
	auto sum = 0.0;

	for (const auto& element : m_students)
	{
		sum += element.getAverage();
	}

	return sum / m_students.size();

}

std::ostream& operator<< (std::ostream& out, const Data& data)
{
	bool isHigher = false;

	for (const auto& element : data.m_students)
	{
		if (element.getAverage() > data.getCommonAverage())
		{
			out << element << std::endl;
			isHigher = true;
		}
	}

	if (isHigher == false)
	{
		out << "There are no students with average score higher than common average score";
	}

	return out;
}