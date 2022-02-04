#include <windows.h>
#include <winreg.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main()
{
	unsigned char pszName[256];
	DWORD nNameLen = 256;
	HKEY hkResult, hStartKey = HKEY_LOCAL_MACHINE;
	long nResult = ERROR_SUCCESS;
	nResult = RegOpenKeyEx(hStartKey, L"SYSTEM\\CurrentControlSet\\Control\\ComputerName\\ActiveComputerName", 0L, KEY_READ, &hkResult);
	if (ERROR_SUCCESS == nResult)
	{
		nResult = RegQueryValueExA(hkResult, "ComputerName", 0, 0, pszName, &nNameLen);
		if (ERROR_SUCCESS == nResult)
		{
			std::cout << pszName << std::endl;
		}
	}
	RegCloseKey(hkResult);
}