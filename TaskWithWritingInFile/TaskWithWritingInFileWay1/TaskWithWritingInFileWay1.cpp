#include <iostream>
#include <fstream> 
#include <Windows.h>
#include <string>
using namespace std;

int main()
{
	ofstream file;
	file.open("D:\\Пользователь\\TestFile.txt");
	file << "Hello, world!";
	file.close();

	ofstream file("D:\\Пользователь\\TestFile.txt", ios::app);
	file << "Hello, new world!" << endl;
	file.close();

	return 0;
}