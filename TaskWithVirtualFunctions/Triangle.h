#pragma once
#include "Shape.h"
#include "Point.h"

class Triangle : public Shape
{
private:
	Point m_point1;
	Point m_point2;
	Point m_point3;
public:
	Triangle(const Point& point1, const Point& point2, const Point& point3);

	virtual std::ostream& print(std::ostream& out) const override;

	virtual ~Triangle() = default;
};