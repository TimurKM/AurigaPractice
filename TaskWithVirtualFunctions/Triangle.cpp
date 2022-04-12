#include "Triangle.h"


Triangle::Triangle(const Point& point1, const Point& point2, const Point& point3) : m_point1(point1), m_point2(point2), m_point3(point3)
{

}

std::ostream& Triangle::print(std::ostream& out) const
{
	out << "Triangle(" << m_point1 << ", " << m_point2 << ", " << m_point3 << ")" << std::endl;
	return out;
}