#include <iostream>
#include <cmath>

class Point
{
private:
	double m_a = 0.0;
	double m_b = 0.0;
public:
	Point(double a = 0.0, double b = 0.0) : m_a(a), m_b(b)
	{

	}

	void print()
	{
		std::cout << "Point(" << m_a << ", " << m_b << ")" << std::endl;
	}

	friend double distanceFrom(const Point& firstPoint, const Point& secondPoint);
};

double distanceFrom(const Point& firstPoint, const Point& secondPoint)
{
	return sqrt((firstPoint.m_a - secondPoint.m_a) * (firstPoint.m_a - secondPoint.m_a) + (firstPoint.m_a - secondPoint.m_b) * (firstPoint.m_a - secondPoint.m_b));
}

int main()
{
	Point first;
	Point second(2.0, 5.0);
	first.print();
	second.print();
	std::cout << "Distance between two points: " << distanceFrom(first, second) << std::endl;

	return 0;
}

