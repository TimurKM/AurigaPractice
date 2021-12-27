#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include "Socket.h"

int usage()
{
	std::cout << "Not all parametrs or wrong type" << std::endl;
	return -1;
}

int main(int argc, char* argv[])
{

	WSADATA wsaData;

	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		std::cout << "WSAStartup failed: " << iResult << std::endl;
		return -1;
	}

	{
		Socket listenSocket{};
		if (argc < 3)
		{
			usage();
			return 1;
		}

		unsigned long long port;
		try
		{
			port = std::stoull(argv[2]);
		}
		catch (const std::invalid_argument& e)
		{
			std::cout << "Parse failed: " << e.what() << std::endl;
			usage();
			return -1;
		}
		iResult = listenSocket.bind(argv[1], port, AF_INET);
		if (iResult == SOCKET_ERROR)
		{
			std::cout << "Bind failed with error: " << WSAGetLastError() << std::endl;
		}
		iResult = listenSocket.listen();
		if (iResult == SOCKET_ERROR)
		{
			std::cout << "Listen failed with error: " << WSAGetLastError() << std::endl;
		}
		fd_set rset;
		FD_ZERO(&rset);
		int maxfdp1 = listenSocket.get() + 1;
		for (;;)
		{
			FD_SET(listenSocket.get(), &rset);
			int nready = select(maxfdp1, &rset, NULL, NULL, NULL);
			if (FD_ISSET(listenSocket.get(), &rset))
			{
				Socket clientSocket = Socket::accept(listenSocket);
				std::vector<char> message(1024);
				iResult = clientSocket.receive(message);
				if (iResult > 0)
				{
					std::cout << "Bytes received: " << iResult << std::endl;
					std::cout << message.data() << std::endl;
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
	}

	WSACleanup();
	return 0;
};
