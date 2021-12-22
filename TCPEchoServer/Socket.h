#pragma once
#include <WinSock2.h>
#include <string>
#include <vector>
class __declspec(dllexport) Socket
{
public:
	Socket();
	Socket(const Socket& other) = delete;
	Socket(Socket&& other) noexcept;
	int connect(const std::string& ip = "127.0.0.1", u_short port = 8080);
	int send(const std::vector<char>& v, int flags = NULL);
	int bind(const std::string& ip = "127.0.0.1", u_short port = 8080);
	int listen(int backlog = SOMAXCONN);
	static Socket accept(const Socket& s, sockaddr* addr = NULL, int* addrlen = NULL);
	int receive(std::vector<char>& buf, int flags = 0);
	SOCKET get() const;
	~Socket();
private:
	Socket(SOCKET s);

	SOCKET m_s;
};