#include <iostream>

int main()
{
	try
	{
		double* ptr = nullptr; // create a null pointer 
		std::cout << *ptr; // dereference a null pointer, exception will trigger
	}
	catch (const std::exception&) // catch does not work because dereferncing null pointer is undefined behaviour
	{
		std::cout << "It is nullptr" << std::endl;
	}

	return 0;
}
