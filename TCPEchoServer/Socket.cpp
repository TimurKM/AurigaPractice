#include "pch.h"
#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <ws2tcpip.h>
#include "Socket.h"

Socket::Socket()
{
	m_s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
}

Socket::Socket(Socket&& other) noexcept
{
	m_s = other.m_s;
	other.m_s = INVALID_SOCKET;
};

Socket::Socket(SOCKET s)
{
	m_s = s;
}

int Socket::connect(const std::string& ip, u_short port)
{
	sockaddr_in hints;

	hints.sin_family = AF_INET;
	hints.sin_addr.s_addr = inet_addr(ip.c_str());
	hints.sin_port = htons(port);

	int iResult = ::connect(m_s, (SOCKADDR*)&hints, sizeof(hints));
	if (iResult == SOCKET_ERROR) {
		closesocket(m_s);
		m_s = INVALID_SOCKET;
		return WSAGetLastError();
	}
	return 0;
}

int Socket::send(const std::vector<char>& v, int flags)
{
	int iResult = ::send(m_s, v.data(), v.size(), flags);
	if (iResult == SOCKET_ERROR)
	{
		return WSAGetLastError();
	}
	return 0;
}

int Socket::bind(const std::string& ip, u_short port)
{
	sockaddr_in hints;

	ZeroMemory(&hints, sizeof(hints));
	hints.sin_family = AF_INET;
	hints.sin_addr.s_addr = inet_addr(ip.c_str());
	hints.sin_port = htons(port);

	int iResult = ::bind(m_s, (SOCKADDR*)&hints, sizeof(hints));
	if (iResult == SOCKET_ERROR)
	{
		return WSAGetLastError();
	}
	return 0;
}

int Socket::listen(int backlog)
{
	return ::listen(m_s, backlog);
}

SOCKET Socket::get() const
{
	return m_s;
}

Socket Socket::accept(const Socket& socket, sockaddr* addr, int* addrlen)
{
	SOCKET s = ::accept(socket.get(), addr, addrlen);
	return std::move(Socket(s));
}

int Socket::receive(std::vector<char>& buf, int flags)
{
	return ::recv(m_s, buf.data(), buf.size(), flags);
}

Socket::~Socket()
{
	if (m_s != INVALID_SOCKET)
	{
		::shutdown(m_s, SD_SEND);
		::closesocket(m_s);
	}
};
