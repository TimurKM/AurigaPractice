#include <iostream>
#include <vector>

class Worker
{
private:
	std::string m_name;

public:
	Worker(std::string name) : m_name(name)
	{

	}

	std::string getName()
	{
		return m_name;
	}
};

class Department
{
private:
	std::vector<Worker*> m_worker;

public:
	Department(Worker* worker = nullptr)
	{

	}

	void add(Worker* worker)
	{
		m_worker.push_back(worker);
	}

	friend std::ostream& operator<< (std::ostream& out, const Department& department);
};

std::ostream& operator<< (std::ostream& out, const Department& department)
{
	for (int i = 0; i < department.m_worker.size(); ++i)
	{
		out << department.m_worker[i]->getName() << ' ' << std::endl;
	}

	return out;
}

int main()
{
	Worker* w1 = new Worker("Anton");
	Worker* w2 = new Worker("Ivan");
	Worker* w3 = new Worker("Max");

	{
		Department department;
		department.add(w1);
		department.add(w2);
		department.add(w3);

		std::cout << department;

	}

	std::cout << w1->getName() << " still exists!\n";
	std::cout << w2->getName() << " still exists!\n";
	std::cout << w3->getName() << " still exists!\n";

	delete w1;
	delete w2;
	delete w3;

	return 0;
}
