#include <iostream>
#include <map>
#include <array>
#include <windows.h>
#include <string>

static std::string getUserInput();
static void printDecodingString(const std::string&);

int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string string = getUserInput();

	printDecodingString(string);

	return 0;
}

std::string getUserInput()
{
	std::string string;

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

	return string;
}

void printDecodingString(const std::string& string)
{
	/*const std::map<char, std::string> map =
	{
		{'а', ".-"},
		{'б', "-..."},
		{'в', ".--"},
		{'г', "--."},
		{'д', "-.."},
		{'е', "."},
		{'ж', "...--"},
		{'з', "--.."},
		{'и', ".."},
		{'й', ".---"},
		{'к', "-.-"},
		{'л', ".-.."},
		{'м', "--"},
		{'н', "-."},
		{'о', "---"},
		{'п', ".--."},
		{'р', ".-."},
		{'с', "..."},
		{'т', "-"},
		{'у', "..-"},
		{'ф', "..-."},
		{'х', "...."},
		{'ц', "-.-."},
		{'ч', "---."},
		{'ш', "----"},
		{'щ', "--.-"},
		{'ъ', ".--.-."},
		{'ы', "-.--"},
		{'ь', "-..-"},
		{'э', "..-.."},
		{'ю', "..--"},
		{'я', ".-.-"},
		{' ', " "}
	};*/

	/*for (const auto& element : string)
	{
		if (map.find(element) != map.end())
		{
			std::cout << map.find(element)->second;
		}
		else
		{
			std::cout << "Symbol for " << element << " was not found";
			break;
		}
	}*/

	const std::string array[] =
	{
		".-",
		"-...",
		".--",
		"--.",
		"-..",
		".",
		"...--",
		"--..",
		"..",
		".---",
		"-.-",
		".-..",
		"--",
		"-.",
		"---",
		".--.",
		".-.",
		"...",
		"-",
		"..-",
		"..-.",
		"....",
		"-.-.",
		"---.",
		"----",
		"--.-",
		".--.-.",
		"-.--",
		"-..-",
		"..-..",
		"..--",
		".-.-",
		" "
	};

	for (const auto& element : string)
	{
		if (element >= 'а' && element <= ' ')
		{
			std::cout << array[static_cast<size_t>(element - 'а')] << ' ';
		}
		else
		{
			std::cout << "Symbol for " << element << " was not found";
			break;
		}
	}
}