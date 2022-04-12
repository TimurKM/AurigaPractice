#pragma once
#include "Shape.h"
#include "Point.h"

class Circle : public Shape
{
private:
	Point m_point;
	int m_radius = 0;
public:
	Circle(const Point& point, int radius);

	virtual std::ostream& print(std::ostream& out) const override;

	int getRadius() const;

	virtual ~Circle() = default;
};