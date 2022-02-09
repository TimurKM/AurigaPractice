#include <windows.h>
#include <vector>
#include <iostream>

int main()
{
	HKEY key;

	LPCWSTR keyName = L"SYSTEM\\CurrentControlSet\\Control\\ComputerName\\ActiveComputerName";
	long ret = RegOpenKeyEx(HKEY_LOCAL_MACHINE, keyName, 0, KEY_READ, &key);
	if (ERROR_SUCCESS != ret)
	{
		std::wcout << L"RegOpenKeyEx failed: " << ret << std::endl;
		return -1;
	}

	DWORD bufSize = 32;
	std::vector<BYTE> buf(bufSize);

	LPCWSTR valueName = L"ComputerName";
	ret = RegQueryValueEx(key, valueName, NULL, NULL, buf.data(), &bufSize);
	if (ERROR_MORE_DATA == ret)
	{
		buf.resize(bufSize);
		ret = RegQueryValueEx(key, valueName, NULL, NULL, buf.data(), &bufSize);
	}

	if (ERROR_SUCCESS == ret)
	{
		std::wcout << L"Computer Name: " << reinterpret_cast<LPCWSTR>(buf.data()) << std::endl;
	}
	else
	{
		std::wcout << L"RegQueryValueEx failed: " << ret << std::endl;
	}
	RegCloseKey(key);

	return 0;
}