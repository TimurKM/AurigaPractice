#include <iostream>
#include <vector>
#include "Shape.h"
#include "Point.h"
#include "Triangle.h"
#include "Circle.h"

int getLargestRadius(const std::vector<Shape*>& vector)
{
	auto largestRadius = 0;

	for (const auto& element : vector)
	{
		Circle* circle = dynamic_cast<Circle*>(element);

		if (circle != nullptr)
		{
			if (circle->getRadius() > largestRadius)
			{
				largestRadius = circle->getRadius();
			}
		}
	}

	return largestRadius;
}

int main()
{
	std::vector<Shape*> vector;
	vector.push_back(new Circle(Point(1, 2, 3), 7));
	vector.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
	vector.push_back(new Circle(Point(4, 5, 6), 3));

	for (const auto& element : vector)
	{
		std::cout << *element << std::endl;
	}

	std::cout << "The largest radius is: " << getLargestRadius(vector) << std::endl;

	for (const auto& element : vector)
	{
		delete element;
	}

	return 0;
}

