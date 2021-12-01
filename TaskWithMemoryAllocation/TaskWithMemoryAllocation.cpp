#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		std::cout << "No command line arguments " << std::endl;
		return 1;
	}
	std::cout << argv[1] << std::endl;
	size_t num = std::stoul(argv[1]);
	int* p;
	try
	{
		p = new int[num];
	}
	catch (const std::bad_alloc& e)
	{
		std::cout << "Allocation failed: " << e.what() << std::endl;
		return -1;
	}
	std::cout << p << std::endl;
	delete[] p;
	return 0;
}
