#pragma once
#include "Student.h"
#include <array>
#include <algorithm>
#include <numeric>

class Data
{
private:
	std::array<Student, 5> m_students;
	size_t m_counter = 0;

public:
	Data() = default;

	void addStudent(const Student& student);

	double getCommonAverage() const;

	friend std::ostream& operator<< (std::ostream& out, const Data& data);
};