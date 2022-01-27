#define _CRTDBG_MAP_ALOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <memory>
#undef NDEBUG
#include <cassert>
#include "MyUniquePtr.h"
#include "MySharedPtr.h"

typedef MyUniquePtr<int> UniquePtrType;
typedef MySharedPtr<int> SharedPtrType;

void uniquePtrRoutine()
{
	UniquePtrType one;
	assert(nullptr == one.get());
	assert(nullptr == one.release());

	UniquePtrType another(new int(1));
	assert(nullptr != another.get());
	assert(1 == *another);

	auto p = another.get();
	one = std::move(another);
	assert(p == one.get());
	assert(nullptr == another.get());

	one.reset(new int(2));
	assert(nullptr != one.get());
	assert(p != one.get());
	assert(2 == *one);

	p = one.release();
	assert(nullptr == one.get());
	delete p;
}

void sharedPtrRoutine()
{
	SharedPtrType one;
	assert(nullptr == one.get());
	assert(0 == one.use_count());

	SharedPtrType another(new int(1));
	assert(nullptr != another.get());
	assert(1 == *another);
	assert(1 == another.use_count());

	auto p = another.get();
	one = std::move(another);
	assert(p == one.get());
	assert(nullptr == another.get());
	assert(1 == one.use_count());
	assert(0 == another.use_count());

	one.reset(new int(2));
	assert(nullptr != one.get());
	assert(p != one.get());
	assert(2 == *one);
	assert(1 == one.use_count());

	assert(one.unique());
	another = one;
	assert(2 == one.use_count());
	assert(2 == another.use_count());
	assert(!one.unique());
	assert(!another.unique());
}

int main(int argc, char* argv[])
{
	uniquePtrRoutine();
	sharedPtrRoutine();
	int* buf = new int[10];
	buf[0] = 0;
	buf[1] = buf[0];
	std::cout << "Hello, World!\n" << buf[1];
	_CrtDumpMemoryLeaks();
	return 0;
}
