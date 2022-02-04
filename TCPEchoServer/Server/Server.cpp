#include "Socket.h"
#include "WSA.h"
#include <iostream>
#include <thread>

int usage(const std::string& exe)
{
	std::cout << exe << ": <ip> <port>\n";
	std::cout << "Where:\n" << "ip - IP address to bind\n";
	std::cout << "port - Port to listen\n";
	std::cout << "\nExample:\n" << exe << " 127.0.0.1 1055" << std::endl;
	return -1;
}

void handler(Socket& s, const unsigned id)
{
	std::vector<char> msg(256);

	std::cout << "Client " << id << ":";

	int ret = s.recv(msg);
	if (0 == ret)
	{
		std::cout << " Shutdown..." << std::endl;
	}
	else if (0 < ret)
	{
		std::cout << " Sent \"" << msg.data() << "\"" << std::endl;
	}
	else
	{
		std::cout << " recv failed " << WSA::getError() << std::endl;
	}
}


int run(const std::string& ip, const int port)
{
	std::shared_ptr<Socket> s = std::make_shared<Socket>();

	if (SOCKET_ERROR == s->bind(ip, port))
	{
		std::cout << "bind failed: " << WSA::getError() << std::endl;
		return -1;
	}

	if (SOCKET_ERROR == s->listen())
	{
		std::cout << "listen failed: " << WSA::getError() << std::endl;
		return -1;
	}

	std::cout << "Listening..." << std::endl;

	SocketSet rset = { s }, wset, exceptset;
	for (;;)
	{
		if (1 == select(rset, wset, exceptset, NULL))
		{
			static unsigned id = 0;
			//handler(s->accept(), id++);
			std::thread handlerThread(handler, s->accept(), id++);
			handlerThread.detach();
		}
		else
		{
			std::cout << "select failed: " << WSA::getError() << std::endl;
			return -1;
		}
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
};
