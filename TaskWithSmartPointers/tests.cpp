#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <memory>
#undef NDEBUG
#include <cassert>
#include "MyUniquePtr.h"
#include "MySharedPtr.h"

using UniquePtrType = MyUniquePtr<int>;//std::unique_ptr<int>;
using SharedPtrType = MySharedPtr<int>;//std::shared_ptr<int>;

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
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// Here we go
	uniquePtrRoutine();
	sharedPtrRoutine();

	return 0;
}
