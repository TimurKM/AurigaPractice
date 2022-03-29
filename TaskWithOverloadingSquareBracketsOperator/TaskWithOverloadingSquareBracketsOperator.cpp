#include <iostream>
#include <vector>

struct StudentGrade
{
	std::string name = "";
	char grade = 'A';
};

class GradeMap
{
private:
	std::vector<StudentGrade> m_map;
public:
	GradeMap()
	{

	}

	char& operator[] (const std::string& name);
};

char& GradeMap::operator[] (const std::string& name)
{
	for (auto& element : m_map)
	{
		if (element.name == name)
		{
			return element.grade;
		}
	}
	StudentGrade temp = { name, ' ' };

	m_map.push_back(temp);

	return m_map.back().grade;
}

int main()
{
	GradeMap grades;
	grades["John"] = 'A';
	grades["Martin"] = 'B';
	std::cout << "John has a grade of " << grades["John"] << '\n';
	std::cout << "Martin has a grade of " << grades["Martin"] << '\n';

	return 0;
}
