#pragma once
#include <WinSock2.h>
#include <string>
#include <vector>
#include <set>
#include <memory>

#ifdef SOCKETDLL_EXPORTS
#define SOCKETDLL_API __declspec(dllexport)
#else
#define SOCKETDLL_API __declspec(dllimport)
#endif

class Socket;
using SocketSet = std::set<std::shared_ptr<Socket>>;

class SOCKETDLL_API Socket final
{
public:
	Socket(int af = AF_INET, int type = SOCK_STREAM, int protocol = IPPROTO_TCP);
	Socket(SOCKET s);
	Socket(const Socket& other) = delete;
	Socket& operator=(const Socket& other) = delete;
	Socket(Socket&& other) noexcept;
	Socket& operator=(Socket&& other) noexcept;
	~Socket();

	int connect(const std::string& ip = "127.0.0.1", const u_short port = 8080, int af = AF_INET);
	int bind(const std::string& ip = "127.0.0.1", const u_short port = 8080, int af = AF_INET);
	int listen(int backlog = SOMAXCONN);
	int send(const std::vector<char>& v, int flags = NULL);
	int recv(std::vector<char>& buf, int flags = 0);

	Socket accept(sockaddr* addr = NULL, int* addrlen = NULL) const;

	friend bool operator<(const std::shared_ptr<Socket>& left, const std::shared_ptr<Socket>& right) // for std::map
	{
		return (*left).m_s < (*right).m_s;
	}

private:
	SOCKET m_s;

	friend SOCKETDLL_API int select(SocketSet& rset, SocketSet& wset, SocketSet& exceptset, timeval* timeout);
};

SOCKETDLL_API int select(SocketSet& rset, SocketSet& wset, SocketSet& exceptset, timeval* timeout);
