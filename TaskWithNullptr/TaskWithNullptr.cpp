#include <iostream>
#include <excpt.h>
int main()
{
	__try
	{
		double* ptr = nullptr; // create a null pointer 
		std::cout << *ptr; // dereference a null pointer, exception will trigger
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		std::cout << "It is nullptr" << std::endl;
	}

	return 0;
}
