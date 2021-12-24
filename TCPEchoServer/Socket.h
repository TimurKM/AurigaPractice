#pragma once
#include <WinSock2.h>
#include <string>
#include <vector>

#ifdef SOCKETDLL_EXPORTS
#define SOCKETDLL_API __declspec(dllexport)
#else
#define SOCKETDLL_API __declspec(dllimport)
#endif

class SOCKETDLL_API Socket
{
public:
	Socket(int af = AF_INET, int type = SOCK_STREAM, int protocol = IPPROTO_TCP);
	Socket(const Socket& other) = delete;
	Socket(Socket&& other) noexcept;
	Socket& operator=(const Socket& other) = delete;
	Socket& operator=(Socket&& other) noexcept;
	int connect(const std::string& ip = "127.0.0.1", const u_short port = 8080, int af = AF_INET);
	int send(const std::vector<char>& v, int flags = NULL);
	int bind(const std::string& ip = "127.0.0.1", const u_short port = 8080, int af = AF_INET);
	int listen(int backlog = SOMAXCONN);
	static Socket accept(const Socket& s, sockaddr* addr = NULL, int* addrlen = NULL);
	int receive(std::vector<char>& buf, int flags = 0);
	SOCKET get() const;
	~Socket();
private:
	Socket(SOCKET s);

	SOCKET m_s;
};