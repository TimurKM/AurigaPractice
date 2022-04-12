#include "Circle.h"
#include <vector>

Circle::Circle(const Point& point, int radius) : m_point(point), m_radius(radius)
{

}

std::ostream& Circle::print(std::ostream& out) const
{
	out << "Circle(" << m_point << ", " << "radius " << m_radius << ")" << std::endl;
	return out;
}

int Circle::getRadius() const
{
	return m_radius;
}

