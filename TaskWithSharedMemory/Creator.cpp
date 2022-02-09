#include <windows.h>
#include <conio.h>
#include <iostream>
#include <functional>

TCHAR szName[] = TEXT("Global\\MyFileMappingObject");

int main()
{
	HANDLE hMapFile;
	DWORD* pBuf;

	hMapFile = CreateFileMapping(
		INVALID_HANDLE_VALUE,
		NULL,
		PAGE_READWRITE,
		0,
		sizeof(DWORD),
		szName);

	if (hMapFile == NULL)
	{
		std::wcout << "Could not create file mapping object: " << GetLastError() << std::endl;
		return 1;
	}

	SetEvent(hMapFile);

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

	DWORD pid = GetCurrentProcessId();
	std::cout << pid << std::endl;
	*pBuf = pid;
	_getch();

	UnmapViewOfFile(pBuf);

	std::unique_ptr<void, std::function<void(HANDLE)>> wrap(hMapFile, [](HANDLE h) { ::CloseHandle(h); });
	return 0;
}
