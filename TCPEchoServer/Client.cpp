#include "Socket.h"
#include <iostream>

int main(int argc, char* argv[]) {

	WSADATA wsaData;

	std::cout << "Input your name: ";
	std::string s;
	std::cin >> s;

	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		std::cout << "WSAStartup failed: " << iResult << std::endl;
	}

	{
		Socket socket{};
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
			socket.connect(argv[1], port = std::stoull(argv[2]));
		}
		catch (const std::invalid_argument& e)
		{
			std::cout << "Parse failed: " << e.what() << std::endl;
			std::cout << "Please, check the types of parametrs " << std::endl;
			return -1;
		}
		std::vector<char> v;
		std::copy(s.begin(), s.end(), std::back_inserter(v));
		v.push_back('\0');
		socket.send(v);
	}

	WSACleanup();
	return 0;
}