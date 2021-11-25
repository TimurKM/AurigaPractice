#include <iostream>

int strLength(const char* str) {
	int count = 0;
	while (str[count] != '\0')
	{
		count++;
	}

	return count;
}

int main()
{
	char str[] = "Hello World";

	std::cout << strLength(str) << std::endl;

	std::cout << strlen(str) << std::endl;

	str[sizeof(str) - 1] = 'd';

	std::cout << strLength(str) << std::endl; // expectation of undefined behaviour

	std::cout << strlen(str) << std::endl;

	return 0;
}
