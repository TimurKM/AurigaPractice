#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

int main(int argc, char* argv[]) {

	WSADATA wsaData;
	int iResult;
	SOCKET ListenSocket = INVALID_SOCKET;
	SOCKET ClientSocket = INVALID_SOCKET;
	struct addrinfo* result = NULL;
	struct addrinfo hints;
	int iSendResult;
	const int default_buflen = 1024;
	const char* default_port = "8080";
	fd_set rset;

	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		std::cout << "WSAStartup failed: " << iResult << std::endl;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	iResult = getaddrinfo(NULL, default_port, &hints, &result);
	if (iResult != 0)
	{
		std::cout << "Getaddrinfo failed: " << iResult << std::endl;
	}

	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (ListenSocket == INVALID_SOCKET)
	{
		std::cout << "Error at socket(): " << WSAGetLastError() << std::endl;
	}

	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR)
	{
		std::cout << "Bind failed with error: " << WSAGetLastError() << std::endl;
	}

	freeaddrinfo(result);

	iResult = listen(ListenSocket, SOMAXCONN);
	if (iResult == SOCKET_ERROR)
	{
		std::cout << "Listen failed with error: " << WSAGetLastError() << std::endl;
	}

	FD_ZERO(&rset);
	char recvbuf[default_buflen];
	int recvbuflen = default_buflen;
	int maxfdp1 = ListenSocket + 1;
	for (;;)
	{
		FD_SET(ListenSocket, &rset);
		int nready = select(maxfdp1, &rset, NULL, NULL, NULL);
		if (FD_ISSET(ListenSocket, &rset))
		{
			ClientSocket = accept(ListenSocket, NULL, NULL);
			if (ClientSocket == INVALID_SOCKET)
			{
				std::cout << "Accept failed: " << WSAGetLastError() << std::endl;
				break;
			}

			ZeroMemory(recvbuf, sizeof(recvbuf));
			iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
			if (iResult > 0)
			{
				std::cout << "Bytes received: " << iResult << std::endl;
				puts(recvbuf);
			}
			else if (iResult == 0)
			{
				std::cout << "Connection closing..." << std::endl;
			}
			else
			{
				std::cout << "Recv failed: " << WSAGetLastError() << std::endl;
			}
		}
	}

	iResult = shutdown(ListenSocket, SD_SEND);
	if (iResult == SOCKET_ERROR)
	{
		std::cout << "Shutdown failed: %d\n" << WSAGetLastError() << std::endl;
	}

	closesocket(ListenSocket);
	WSACleanup();
	return 0;
};
