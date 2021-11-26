#include <windows.h>
#include <string>
#include <iostream>
#include <errhandlingapi.h>
int main()
{
	std::wstring name;
	std::getline(std::wcin, name);
	// Open a handle to the file
	HANDLE hFile = CreateFile(
		name.c_str(),     // Filename
		GENERIC_WRITE,          // Desired access
		NULL,        // Share mode
		NULL,                   // Security attributes
		CREATE_NEW,             // Creates a new file, only if it doesn't already exist
		FILE_ATTRIBUTE_NORMAL,  // Flags and attributes
		NULL);                  // Template file handle

	if (hFile == INVALID_HANDLE_VALUE)
	{
		// Failed to open/create file
		return GetLastError();
	}

	// Write data to the file
	std::string strText = "Hello new World!"; // For C use LPSTR (char*) or LPWSTR (wchar_t*)
	DWORD bytesWritten;
	BOOL eCode = WriteFile(
		hFile,            // Handle to the file
		strText.c_str(),  // Buffer to write
		strText.size(),   // Buffer size
		&bytesWritten,    // Bytes written
		nullptr);         // Overlapped
	if (!eCode)
	{
		return GetLastError();
	}
	// Close the handle once we don't need it.
	eCode = CloseHandle(hFile);
	if (!eCode)
	{
		return GetLastError();
	}

	return 0;
}