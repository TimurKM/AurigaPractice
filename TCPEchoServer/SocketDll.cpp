// SocketDll.cpp : Определяет экспортируемые функции для DLL.
//

#include "pch.h"
#include "framework.h"
#include "SocketDll.h"


// Пример экспортированной переменной
SOCKETDLL_API int nSocketDll=0;

// Пример экспортированной функции.
SOCKETDLL_API int fnSocketDll(void)
{
    return 0;
}

// Конструктор для экспортированного класса.
CSocketDll::CSocketDll()
{
    return;
}
