#include <iostream>
#include <string>
#include <windows.h>

static void getUserInput(std::string&);
static void printString(const std::string&);

int main()
{
	std::string string;

	getUserInput(string);

	printString(string);

	return 0;
}

void getUserInput(std::string& string)
{
	while (1)
	{
		do
		{
			std::cout << "Enter string: ";

			getline(std::cin, string);
		} while (string.length() < 0);

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}

		break;
	}
}

void printString(const std::string& string)
{
	for (const auto& element : string)
	{
		std::cout << element;
		Sleep(1000);
	}
}
