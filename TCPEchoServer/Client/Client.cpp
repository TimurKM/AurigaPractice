#include "Socket.h"
#include "WSA.h"
#include <iostream>

int usage(const std::string &exe)
{
	std::cout << exe << ": <ip> <port>\n";
	std::cout << "Where:\n" << "ip - IP address to connect\n";
	std::cout << "port - Port to connect\n";
	std::cout << "\nExample:\n" << exe << " 127.0.0.1 1055" << std::endl;
	return -1;
}

int run(const std::string &ip, const int port)
{
	std::cout << "Input text: ";
	std::string s;
	std::cin >> s;

	Socket socket;

	if (SOCKET_ERROR == socket.connect(ip, port))
	{
		std::cout << "connect failed: " << WSA::getError() << std::endl;
		return -1;
	}

	std::vector<char> v;
	std::copy(s.begin(), s.end(), std::back_inserter(v));
	v.push_back('\0');

	if (SOCKET_ERROR == socket.send(v))
	{
		std::cout << "send failed: " << WSA::getError() << std::endl;
		return -1;
	}

	return 0;
}

int main(int argc, char* argv[])
{
	int port = -1;

	if (argc == 3)
	{	
		try
		{
			port = std::stoi(argv[2]);
		}
		catch (const std::invalid_argument&)
		{
		}
	}

	if (port < 0)
	{
		return usage(argv[0]);
	}

	WSA wsa;
	wsa.init();
	return run(argv[1], port);
}
