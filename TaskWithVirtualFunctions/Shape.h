#pragma once
#include <iostream>

class Shape
{
public:
	virtual std::ostream& print(std::ostream& out) const = 0;

	friend std::ostream& operator<<(std::ostream& out, const Shape& shape);

	virtual ~Shape() = default;
};