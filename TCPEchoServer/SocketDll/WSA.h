#pragma once
#include <Winsock2.h>

class WSA
{
public:
    WSA() = default;

    ~WSA()
    {
        WSACleanup();
    }

    WSA(const WSA& one) = delete;

    WSA(WSA&& one) = delete;

    int init(DWORD major = 2, DWORD minor = 2)
    {
        WSADATA wsaData;
        return WSAStartup(MAKEWORD(major, minor), &wsaData);
    }

    static int getError()
    {
        return WSAGetLastError();
    }
};