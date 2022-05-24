#include "Student.h"

Student::Student(std::string& name, size_t math, size_t physics, size_t informatics) :
	m_name(name), m_math(math), m_physics(physics), m_informatics(informatics)
{

}

double Student::getAverage() const
{
	return static_cast<double>(m_math + m_physics + m_informatics) / 3;
}

std::istream& operator>> (std::istream& in, Student& student)
{
	in >> student.m_name;
	in >> student.m_math;
	in >> student.m_physics;
	in >> student.m_informatics;

	return in;
}

std::ostream& operator<< (std::ostream& out, const Student& student)
{
	out << student.m_name << " " << student.m_math << " " << student.m_physics << " " << student.m_informatics << std::endl;

	return out;
}

bool operator<(const Student& student1, const Student& student2)
{
	return student1.getAverage() < student2.getAverage();
}

bool operator>(const Student& student1, const Student& student2)
{
	return student1.getAverage() > student2.getAverage();
}