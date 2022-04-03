#pragma once
#include "Point3D.h"

class Vector3D
{
private:
	double m_x = 0.0;
	double m_y = 0.0;
	double m_z = 0.0;

public:
	Vector3D(double x = 0.0, double y = 0.0, double z = 0.0);

	void print() const;

	friend void Point3D::moveByVector(const Vector3D& v);
};