#include <iostream>


int main()
{
	double* ptr = nullptr; // create a null pointer 
	std::cout << *ptr; // dereference a null pointer, exception will trigger
	return 0;
}
