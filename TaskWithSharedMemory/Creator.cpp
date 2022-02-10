#include <windows.h>
#include <iostream>
#include <functional>

int main()
{
	HANDLE h = CreateFileMapping(
		INVALID_HANDLE_VALUE,
		NULL,
		PAGE_READWRITE,
		0,
		sizeof(DWORD),
		L"Global\\PidStore");

	if (NULL == h)
	{
		std::cout << "CreateFileMapping failed: " << GetLastError() << std::endl;
		return -1;
	}
	std::unique_ptr<void, std::function<void(HANDLE)>> hWrap(h, [](HANDLE h) { CloseHandle(h); });

	DWORD* view = (DWORD*)MapViewOfFile(h,
		FILE_MAP_ALL_ACCESS,
		0,
		0,
		sizeof(DWORD));

	if (NULL == view)
	{
		std::cout << "MapViewOfFile failed: " << GetLastError() << std::endl;
		return -1;
	}
	std::unique_ptr<DWORD, std::function<void(DWORD*)>> viewWrap(view, [](DWORD* p) { UnmapViewOfFile(p); });

	*view = GetCurrentProcessId();
	std::cout << "Pid of side A: " << *view << std::endl;

	HANDLE awareEvent = CreateEvent(NULL, TRUE, FALSE, L"Global\\SideBAwareEvent");
	if (NULL == awareEvent)
	{
		std::cout << "CreateEvent failed: " << GetLastError() << std::endl;
		return -1;
	}
	std::unique_ptr<void, std::function<void(HANDLE)>> awareEventWrap(awareEvent, [](HANDLE h) { CloseHandle(h); });

	std::cout << "[Waiting for the B side...]" << std::endl;
	DWORD ret = WaitForSingleObject(awareEvent, INFINITE);
	if (WAIT_OBJECT_0 != ret)
	{
		std::cout << "WaitForSingleObject failed: " << GetLastError() << std::endl;
		return -1;
	}

	std::cout << "Pid of side B: " << *view << std::endl;

	return 0;
}