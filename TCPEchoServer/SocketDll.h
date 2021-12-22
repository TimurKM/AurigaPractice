// Приведенный ниже блок ifdef — это стандартный метод создания макросов, упрощающий процедуру
// экспорта из библиотек DLL. Все файлы данной DLL скомпилированы с использованием символа SOCKETDLL_EXPORTS
// Символ, определенный в командной строке. Этот символ не должен быть определен в каком-либо проекте,
// использующем данную DLL. Благодаря этому любой другой проект, исходные файлы которого включают данный файл, видит
// функции SOCKETDLL_API как импортированные из DLL, тогда как данная DLL видит символы,
// определяемые данным макросом, как экспортированные.
#ifdef SOCKETDLL_EXPORTS
#define SOCKETDLL_API __declspec(dllexport)
#else
#define SOCKETDLL_API __declspec(dllimport)
#endif

// Этот класс экспортирован из библиотеки DLL
class SOCKETDLL_API CSocketDll {
public:
	CSocketDll(void);
	// TODO: добавьте сюда свои методы.
};

extern SOCKETDLL_API int nSocketDll;

SOCKETDLL_API int fnSocketDll(void);
