#include <iostream>
#include <fstream> 
#include <Windows.h>
#include <string>

using namespace std;

int main()
{
	FILE* f;
	f = fopen("D:\\Пользователь\\Testfile3.txt", "w");
	fprintf(f, "Multiplication table \n %d*%d=%d", 2, 2, 4);
	fclose(f);
	return 0;
}