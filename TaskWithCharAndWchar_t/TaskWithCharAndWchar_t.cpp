#include <iostream>
#define COUNTOF(a) (sizeof(a) / sizeof(a[0]))

int main()
{
	const char str[] = "Hello, world!";
	const char* same_str = "Hello, world!";
	std::cout << "Our str: " << str << std::endl;
	std::cout << "Sizeof: " << sizeof(str) << std::endl;
	std::cout << "_countof for const char str[]: " << _countof(str) << std::endl;
	// std::cout << _countof(same_str) << std::endl; // such way of _countof does not work
	std::cout << "Own _countof for const char str[]: " << COUNTOF(str) << std::endl;
	std::cout << "Own _countof for const char* same_str: " << COUNTOF(same_str) << std::endl; // such way of _countof works with warning
	std::cout << "Strlen: " << strlen(str) << std::endl;

	const wchar_t str1[] = L"Hello, world!";
	const wchar_t* same_str1 = L"Hello, world!";
	std::wcout << "Our str1: " << str1 << std::endl;
	std::wcout << "Sizeof: " << sizeof(str1) << std::endl;
	std::wcout << "_countof for const wchar_t str1[]: " << _countof(str1) << std::endl;
	// std::cout << _countof(same_str1) << std::endl; // such way of _countof does not work
	std::wcout << "Own _countof for const wchar_t str1[]: " << COUNTOF(str1) << std::endl;
	std::wcout << "Own _countof for const wchar_t* same_str1: " << COUNTOF(same_str1) << std::endl; // such way of _countof works with warning
	std::wcout << "Strlen: " << wcslen(str1) << std::endl;
	return 0;
}