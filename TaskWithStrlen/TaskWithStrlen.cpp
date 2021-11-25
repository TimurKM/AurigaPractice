#include <iostream>

int strLength(char str[]) {
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

	for (int i = 0; i < sizeof(str); i++)
	{
		if (str[i] == '\0')
		{
			str[i] = 'd';
		}
	}

	std::cout << strLength(str) << std::endl;

	std::cout << strlen(str) << std::endl;

	return 0;
}
