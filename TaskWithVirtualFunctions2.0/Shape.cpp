#include "Shape.h"

std::ostream& operator<<(std::ostream& out, const Shape& shape)
{
	return shape.print(out);
}