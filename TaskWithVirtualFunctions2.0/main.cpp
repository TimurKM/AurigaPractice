#include <iostream>
#include <vector>
#include "Shape.h"
#include "Point.h"
#include "Triangle.h"
#include "Circle.h"

//Circle* getLargestCircle(const std::vector<Shape*>& vector)
//{
//	Circle* largestCircle = nullptr;
//
//	for (const auto& element : vector)
//	{
//		Circle* circle = dynamic_cast<Circle*>(element);
//
//		if (circle != nullptr)
//		{
//			if (largestCircle == nullptr || circle->getRadius() > largestCircle->getRadius())
//			{
//				largestCircle = circle;
//			}
//		}
//	}
//
//	return largestCircle;
//}

std::vector<Circle*> getLargestCircle(const std::vector<Shape*>& vector)
{
	Circle* largestCircle = nullptr;

	std::vector<Circle*> largestCircles;

	for (const auto& element : vector)
	{
		Circle* circle = dynamic_cast<Circle*>(element);

		if (circle != nullptr)
		{
			if (largestCircle == nullptr || circle->getRadius() > largestCircle->getRadius())
			{
				largestCircle = circle;
			}
			else if (circle->getRadius() == largestCircle->getRadius())
			{
				largestCircles.push_back(circle);
			}
		}

	}
	largestCircles.push_back(largestCircle);

	return largestCircles;
}

int main()
{
	std::vector<Shape*> vector;
	vector.push_back(new Circle(Point(1, 2, 3), 7));
	vector.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
	vector.push_back(new Circle(Point(4, 5, 6), 3));
	vector.push_back(new Circle(Point(7, 8, 9), 6));
	vector.push_back(new Circle(Point(1, 5, 6), 2));
	vector.push_back(new Circle(Point(4, 9, 6), 5));
	vector.push_back(new Circle(Point(1, 2, 6), 7));
	vector.push_back(new Circle(Point(5, 5, 5), 5));
	vector.push_back(new Circle(Point(9, 1, 1), 7));
	vector.push_back(new Circle(Point(4, 2, 6), 3));
	vector.push_back(new Circle(Point(4, 5, 3), 3));

	for (const auto& element : vector)
	{
		std::cout << *element << std::endl;
	}

	/*Circle* largestCircle = getLargestCircle(vector);

	if (largestCircle != nullptr)
	{
		std::cout << "The largest circle is: " << *largestCircle << std::endl;
	}
	else
	{
		std::cout << "There are no circles in vector" << std::endl;
	}*/

	std::vector<Circle*> largestCircles = getLargestCircle(vector);

	if (largestCircles[0] != nullptr)
	{
		for (const auto& element : largestCircles)
		{
			std::cout << "The largest circle is: " << *element << std::endl;
		}
	}
	else
	{
		std::cout << "There are no circles in vector" << std::endl;
	}

	for (const auto& element : vector)
	{
		delete element;
	}

	return 0;
}
