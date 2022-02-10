#include <windows.h>
#include <iostream>
#include <functional>

int main()
{
	HANDLE h = OpenFileMapping(
		FILE_MAP_ALL_ACCESS,
		FALSE,
		L"Global\\PidStore");

	if (NULL == h)
	{
		std::cout << "OpenFileMapping failed: " << GetLastError() << std::endl;
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

	HANDLE awareEvent = CreateEvent(NULL, TRUE, FALSE, L"Global\\SideBAwareEvent");
	if (NULL == awareEvent)
	{
		std::cout << "CreateEvent failed: " << GetLastError() << std::endl;
		return -1;
	}
	std::unique_ptr<void, std::function<void(HANDLE)>> awareEventWrap(awareEvent, [](HANDLE h) { CloseHandle(h); });

	std::cout << "Pid of Side A: " << *view << std::endl;
	*view = GetCurrentProcessId();
	std::cout << "Pid of Side B: " << *view << std::endl;

	if (!SetEvent(awareEvent))
	{
		std::cout << "SetEvent failed: " << GetLastError() << std::endl;
		return -1;
	}

	return 0;
}
