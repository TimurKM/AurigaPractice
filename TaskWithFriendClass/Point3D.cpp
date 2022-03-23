#include "Point3D.h"
#include "Vector3D.h"
#include <iostream>

Point3D::Point3D(double x, double y, double z)
	: m_x(x), m_y(y), m_z(z)
{

}

void Point3D::print()
{
	std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
}

void Point3D::moveByVector(const Vector3D& v)
{
	m_x += v.m_x;
	m_y += v.m_y;
	m_z += v.m_z;
}