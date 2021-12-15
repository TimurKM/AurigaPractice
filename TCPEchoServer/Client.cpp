#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {

	WSADATA wsaData;
	int iResult;
	SOCKET ConnectSocket = INVALID_SOCKET;
	const int default_buflen = 1024;
	int recvbuflen = default_buflen;
	const char* default_port = "8080";
	std::string sendbuf;
	std::cout << "Input your name: ";
	std::getline(std::cin, sendbuf);
	const char* c = sendbuf.c_str();
	char recvbuf[default_buflen];
	ZeroMemory(recvbuf, sizeof(recvbuf));
	struct addrinfo* result = NULL, * ptr = NULL, hints;

	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		std::cout << "WSAStartup failed: " << iResult << std::endl;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	iResult = getaddrinfo(argv[1], default_port, &hints, &result);
	if (iResult != 0)
	{
		std::cout << "Getaddrinfo failed: " << iResult << std::endl;
	}

	for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {
		ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
		if (ConnectSocket == INVALID_SOCKET)
		{
			std::cout << "Socket failed with error: " << WSAGetLastError() << std::endl;
		}

		iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
		if (iResult == SOCKET_ERROR) {
			closesocket(ConnectSocket);
			ConnectSocket = INVALID_SOCKET;
			continue;
		}
		break;
	}

	freeaddrinfo(result);

	if (ConnectSocket == INVALID_SOCKET)
	{
		std::cout << "Unable to connect to server!" << std::endl;
	}

	iResult = send(ConnectSocket, c, (int)strlen(c) + 1, 0);
	if (iResult == SOCKET_ERROR)
	{
		std::cout << "Send failed: " << WSAGetLastError() << std::endl;
	}

	std::cout << "Bytes Sent: " << iResult << std::endl;

	iResult = shutdown(ConnectSocket, SD_SEND);
	if (iResult == SOCKET_ERROR)
	{
		std::cout << "Shutdown failed: " << WSAGetLastError() << std::endl;
	}

	closesocket(ConnectSocket);
	WSACleanup();
	return 0;
}