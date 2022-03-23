#pragma once
#include "Point3D.h"

class Vector3D
{
private:
	double m_x, m_y, m_z;

public:
	Vector3D(double x = 0.0, double y = 0.0, double z = 0.0);

	void print();

	friend void Point3D::moveByVector(const Vector3D& v);
};