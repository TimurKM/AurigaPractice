#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include "Socket.h"
int main(int argc, char* argv[])
{

	WSADATA wsaData;

	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		std::cout << "WSAStartup failed: " << iResult << std::endl;
	}

	{
		Socket listenSocket{};
		if (argc == 0)
		{
			std::cout << "No command line arguments, please, define " << std::endl;
			return 1;
		}

		if (argc == 1)
		{
			std::cout << "Only one command line argument, please, define the second " << std::endl;
			return 1;
		}

		unsigned long long port;
		try
		{
			iResult = listenSocket.bind(argv[1], port = std::stoull(argv[2]));
		}
		catch (const std::invalid_argument& e)
		{
			std::cout << "Parse failed: " << e.what() << std::endl;
			std::cout << "Please, check the types of parametrs " << std::endl;
			return -1;
		}
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