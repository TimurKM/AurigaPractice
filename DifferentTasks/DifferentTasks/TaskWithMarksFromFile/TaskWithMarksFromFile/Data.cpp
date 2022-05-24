#include "Data.h"

Data::Data(std::ifstream& file)
{
	if (!file)
	{
		std::cerr << "File could not be opened for reading!" << std::endl;
		exit(1);
	}

	size_t length = 0;

	file >> length;

	std::string name;

	size_t math = 1;

	size_t physics = 1;

	size_t informatics = 1;

	while (file >> name >> math >> physics >> informatics)
	{
		for (size_t i = 0; i < length; ++i)
		{
			Student student(name, math, physics, informatics);
			m_students.insert(student);
		}
	}

	//m_students.resize(length);

	/*for (auto& element : m_students)
	{
		file >> element;
	}*/

	//std::sort(m_students.begin(), m_students.end(), [](const Student& s1, const Student& s2) { return s1.getAverage() > s2.getAverage(); });
}

std::ostream& operator<< (std::ostream& out, const Data& data)
{
	for (const auto& element : data.m_students)
	{
		out << element;
	}

	return out;
}