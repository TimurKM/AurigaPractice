#include "Socket.h"
#include <iostream>

int usage()
{
	std::cout << "Not all parametrs or wrong type" << std::endl;
	return -1;
}

int main(int argc, char* argv[]) {

	WSADATA wsaData;

	std::cout << "Input your name: ";
	std::string s;
	std::cin >> s;

	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		std::cout << "WSAStartup failed: " << iResult << std::endl;
		return -1;
	}

	{
		Socket socket{};
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
		socket.connect(argv[1], port, AF_INET);
		std::vector<char> v;
		std::copy(s.begin(), s.end(), std::back_inserter(v));
		v.push_back('\0');
		socket.send(v);
	}

	WSACleanup();
	return 0;
}