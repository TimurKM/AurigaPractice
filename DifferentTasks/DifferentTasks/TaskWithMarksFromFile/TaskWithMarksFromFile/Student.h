#pragma once
#include <string>
#include <fstream>

class Student
{
private:
	std::string m_name;

	size_t m_math = 1;

	size_t m_physics = 1;

	size_t m_informatics = 1;
public:
	Student() = default;

	Student(std::string& name, size_t math, size_t physics, size_t informatics);

	double getAverage() const;

	friend std::ostream& operator<< (std::ostream& out, const Student& student);

	friend std::istream& operator>> (std::istream& in, Student& student);

	friend bool operator<(const Student& student1, const Student& student2);

	friend bool operator>(const Student& student1, const Student& student2);
};