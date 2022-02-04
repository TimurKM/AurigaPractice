#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "Socket.h"
#include <algorithm>

Socket::Socket(int af, int type, int protocol)
{
	m_s = socket(af, type, protocol);
}

Socket::Socket(SOCKET s)
{
	m_s = s;
}

Socket::Socket(Socket&& other) noexcept
{
	m_s = other.m_s;
	other.m_s = INVALID_SOCKET;
}

Socket& Socket::operator=(Socket&& other) noexcept
{
	SOCKET tmp = m_s;
	m_s = other.m_s;
	other.m_s = tmp;
	return *this;
}

Socket::~Socket()
{
	if (m_s != INVALID_SOCKET)
	{
		::shutdown(m_s, SD_SEND);
		::closesocket(m_s);
	}
}

int Socket::connect(const std::string& ip, const u_short port, int af)
{
	sockaddr_in hints;

	ZeroMemory(&hints, sizeof(hints));
	hints.sin_family = af;
	hints.sin_addr.s_addr = inet_addr(ip.c_str());
	hints.sin_port = htons(port);

	return ::connect(m_s, (SOCKADDR*)&hints, sizeof(hints));
}

int Socket::bind(const std::string& ip, const u_short port, int af)
{
	sockaddr_in hints;

	ZeroMemory(&hints, sizeof(hints));
	hints.sin_family = af;
	hints.sin_addr.s_addr = inet_addr(ip.c_str());
	hints.sin_port = htons(port);

	return ::bind(m_s, (SOCKADDR*)&hints, sizeof(hints));
}

int Socket::listen(int backlog)
{
	return ::listen(m_s, backlog);
}

int Socket::send(const std::vector<char>& v, int flags)
{
	return ::send(m_s, v.data(), static_cast<int>(v.size()), flags);
}

int Socket::recv(std::vector<char>& buf, int flags)
{
	return ::recv(m_s, buf.data(), static_cast<int>(buf.size()), flags);
}

Socket Socket::accept(sockaddr* addr, int* addrlen) const
{
	SOCKET s = ::accept(m_s, addr, addrlen);
	return std::move(Socket(s));
}

SOCKETDLL_API int select(SocketSet& rset, SocketSet& wset, SocketSet& exceptset, timeval* timeout)
{
	fd_set _rset, _wset, _exceptset;
	FD_ZERO(&_rset);
	FD_ZERO(&_wset);
	FD_ZERO(&_exceptset);

	int nfds = 0;
	if (!rset.empty())
	{
		int temp = static_cast<int>((*rset.rbegin())->m_s);
		nfds = (temp > nfds) ? temp : nfds;
	}
	if (!wset.empty())
	{
		int temp = static_cast<int>((*wset.rbegin())->m_s);
		nfds = (temp > nfds) ? temp : nfds;
	}
	if (!exceptset.empty())
	{
		int temp = static_cast<int>((*exceptset.rbegin())->m_s);
		nfds = (temp > nfds) ? temp : nfds;
	}
	nfds += 1;

	for (auto& it : rset) FD_SET(it->m_s, &_rset);
	for (auto& it : wset) FD_SET(it->m_s, &_wset);
	for (auto& it : exceptset) FD_SET(it->m_s, &_exceptset);

	int ret = select(
		nfds,
		rset.empty() ? nullptr : &_rset,
		wset.empty() ? nullptr : &_wset,
		exceptset.empty() ? nullptr : &_exceptset,
		timeout);

	SocketSet setOfWhatSet;
	for (auto& it : rset) if (FD_ISSET(it->m_s, &_rset)) setOfWhatSet.insert(it);
	rset = std::move(setOfWhatSet);
	setOfWhatSet.clear();
	for (auto& it : wset) if (FD_ISSET(it->m_s, &_wset)) setOfWhatSet.insert(it);
	wset = std::move(setOfWhatSet);
	setOfWhatSet.clear();
	for (auto& it : exceptset) if (FD_ISSET(it->m_s, &_exceptset)) setOfWhatSet.insert(it);
	exceptset = std::move(setOfWhatSet);

	return ret;
}
