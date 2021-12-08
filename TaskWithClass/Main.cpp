#include <iostream>
#include <string>
#include "String.h"

bool TestAt()
{
	String my;
	std::string their;
	my.at(0);
	return true;
}

int main()
{
	/*String appendix(std::string("appendix"));
	String str(std::string("body"));
	String str2(std::string("somebody"));
	String copy(str);
	String resize(str);
	String at(str);
	String op(str);
	String c_str(str);
	String empty(str);
	char a[256] = { 0, };
	std::cout << empty.empty() << std::endl;
	std::cout << c_str.c_str() << std::endl;
	std::cout << at.at() << std::endl;
	std::cout << op.operator[](0) << std::endl;
	std::cout << copy.copy(a, 100, 0) << a << std::endl;
	resize.resize(6, '+');
	std::cout << resize << " " << resize.capacity() << std::endl;
	resize.resize(10);
	std::cout << resize << " " << resize.capacity() << std::endl;
	resize.resize(2);
	std::cout << resize << " " << resize.capacity() << std::endl;
	std::cout << appendix.append(str) << std::endl;
	std::cout << str.append(appendix) << std::endl;
	std::cout << str.operator=(str2) << std::endl;*/
	TestAt();
	return 0;
}

