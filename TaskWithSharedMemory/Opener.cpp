#include <windows.h>
#include <conio.h>
#include <iostream>
#include <functional>

TCHAR szName[] = TEXT("Global\\MyFileMappingObject");

int main()
{
	HANDLE hMapFile;
	DWORD* pBuf;

	hMapFile = OpenFileMapping(
		FILE_MAP_ALL_ACCESS,
		FALSE,
		szName);

	if (hMapFile == NULL)
	{
		std::wcout << "Could not open file mapping object: " << GetLastError() << std::endl;
		return 1;
	}

	DWORD dwWaitResult;

	dwWaitResult = WaitForSingleObject(
		hMapFile,
		INFINITE);

	pBuf = (DWORD*)MapViewOfFile(hMapFile,
		FILE_MAP_ALL_ACCESS,
		0,
		0,
		sizeof(DWORD));

	if (pBuf == NULL)
	{
		std::wcout << "Could not map view of file: " << GetLastError() << std::endl;

		return 1;
	}

	DWORD pid = *reinterpret_cast<DWORD*>(pBuf);
	std::cout << pid << std::endl;
	_getch();
	UnmapViewOfFile(pBuf);

	std::unique_ptr<void, std::function<void(HANDLE)>> wrap(hMapFile, [](HANDLE h) { ::CloseHandle(h); });
	return 0;
}