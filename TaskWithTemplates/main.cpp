#include <iostream> 
#include "Pair.h"
#include "StringValuePair.h"

int main()
{
	Pair<int, double> pair1(6, 7.8);
	std::cout << "Pair: " << pair1.first() << ' ' << pair1.second() << std::endl;

	const Pair<double, int> pair2(3.4, 5);
	std::cout << "Pair: " << pair2.first() << ' ' << pair2.second() << std::endl;

	StringValuePair<int> svp("Amazing", 7);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << std::endl;

	return 0;
}
