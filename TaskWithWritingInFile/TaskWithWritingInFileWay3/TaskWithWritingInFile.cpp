#include <fstream>
int main()
{
	wchar_t str[100];
	scanf("%99ls", str);
	FILE* f = _wfopen(str, L"w");
	if (f == nullptr)
	{
		return -1;
	}
	int eCode = fprintf(f, "Multiplication table \n %d*%d=%d", 2, 2, 4);
	if (eCode < 0)
	{
		return -1;
	}
	eCode = fclose(f);
	if (eCode != 0)
	{
		return -1;
	}
	return 0;
}