#include <iostream>

int main()
{
	char a = 0;
	char b = '0';
	std::cout << "a: " << static_cast<int>(a) << std::endl;
	std::cout << b << " has ASCII code " << static_cast<int>(b) << std::endl;
}
