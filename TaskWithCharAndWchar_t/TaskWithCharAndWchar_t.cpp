#include <iostream>
#include <stdlib.h>
#include <string>

int main()
{
	const char* str = "Hello, world!"; // it works correctly
	std::cout << str << std::endl;
	char* p;
	p = const_cast<char*>(str);
	str = "Hello, new world!"; // changes work correctly
	std::cout << str << std::endl;
	std::cout << sizeof(str) << std::endl; // sizeof work correctly
	// std::cout << _countof(str) << std::endl; // it doesn't work, I haven't found how to connect it through the library

	const wchar_t* str1 = L"Hello, world!";
	std::wstring string(str1); // it does not work correctly, numbers are displayed instead of the phrase
	std::cout << str1 << std::endl;
	wchar_t* p1;
	p1 = const_cast<wchar_t*>(str1);
	str1 = L"Hello, new world!";
	std::wstring string1(str1); // it does not work correctly, numbers are displayed instead of the phrase, , but they have changed
	std::cout << str1 << std::endl;
	std::cout << sizeof(str1) << std::endl; // sizeof work correctly
	// std::cout << _countof(str1) << std::endl; // it doesn't work, I haven't found how to connect it through the library

	system("pause");
	return 0;
}