#include <iostream>
#include <fstream> 

int main()
{
	std::ofstream file;
	std::string name = "";
	std::cin >> name;
	file.open(name);
	if (!(file.is_open())) {
		std::cout << "File is not found\n";
		return -1;
	}
	else {
		file << "Hello, world!";
	}
	file.close();

	return 0;
}