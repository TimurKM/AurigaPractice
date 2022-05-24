#pragma once
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include "Student.h"
#include <iostream>
#include <cstdlib>

class Data
{
private:
	//std::vector<Student> m_students;
	std::set<Student, std::greater<Student>> m_students;
public:
	Data(std::ifstream& file);

	friend std::ostream& operator<< (std::ostream& out, const Data& data);
};