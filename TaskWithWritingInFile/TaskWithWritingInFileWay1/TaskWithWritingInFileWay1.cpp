#include <iostream>
#include <fstream> 

int main()
{
	std::ofstream file;
	char name[] = "";
	std::cin >> name;
	file.open(name);
	file << "Hello world!";
	file.close();

	return 0;
}