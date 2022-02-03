#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "pch.h"
#include <iostream>
#include "MySingleLinkedList.h"
#include <list>

typedef MySingleLinkedList<int> MySingleLinkedListType;
//typedef std::list<int> MySingleLinkedListType;

TEST(MySingleLinkedList, TestSize)
{
	MySingleLinkedListType mysinglelinkedlist;
	EXPECT_EQ(0, mysinglelinkedlist.size());

	MySingleLinkedListType mysinglelinkedlist2;
	mysinglelinkedlist2 = { 1,2,3,4,5 };
	EXPECT_EQ(5, mysinglelinkedlist2.size());
}

TEST(MySingleLinkedList, TestEmpty)
{
	MySingleLinkedListType mysinglelinkedlist;
	EXPECT_TRUE(0 == mysinglelinkedlist.size());

	MySingleLinkedListType mysinglelinkedlist2;
	mysinglelinkedlist2 = { 1,2,3,4,5 };
	EXPECT_FALSE(0 == mysinglelinkedlist2.size());
}

TEST(MySingleLinkedList, TestFront)
{
	MySingleLinkedListType mysinglelinkedlist;
	mysinglelinkedlist = { 1,2,3,4,5 };
	EXPECT_EQ(1, mysinglelinkedlist.front());
}

TEST(MySingleLinkedList, TestBack)
{
	MySingleLinkedListType mysinglelinkedlist;
	mysinglelinkedlist = { 1,2,3,4,5 };
	EXPECT_EQ(5, mysinglelinkedlist.back());
}

TEST(MySingleLinkedList, TestPushFront)
{
	MySingleLinkedListType mysinglelinkedlist;
	mysinglelinkedlist.push_front(1);
	EXPECT_EQ(1, mysinglelinkedlist.size());
	EXPECT_EQ(1, mysinglelinkedlist.front());
	EXPECT_EQ(1, mysinglelinkedlist.back());

	MySingleLinkedListType mysinglelinkedlist2;
	mysinglelinkedlist2 = { 1,2,3,4,5 };
	mysinglelinkedlist2.push_front(0);
	EXPECT_EQ(6, mysinglelinkedlist2.size());
	EXPECT_EQ(0, mysinglelinkedlist2.front());
	EXPECT_EQ(5, mysinglelinkedlist2.back());
}

TEST(MySingleLinkedList, TestPushBack)
{
	MySingleLinkedListType mysinglelinkedlist;
	mysinglelinkedlist.push_back(1);
	EXPECT_EQ(1, mysinglelinkedlist.size());
	EXPECT_EQ(1, mysinglelinkedlist.front());
	EXPECT_EQ(1, mysinglelinkedlist.back());

	MySingleLinkedListType mysinglelinkedlist2;
	mysinglelinkedlist2 = { 1,2,3,4,5 };
	mysinglelinkedlist2.push_back(6);
	EXPECT_EQ(6, mysinglelinkedlist2.size());
	EXPECT_EQ(1, mysinglelinkedlist2.front());
	EXPECT_EQ(6, mysinglelinkedlist2.back());
}

TEST(MySingleLinkedList, TestPopFront)
{
	MySingleLinkedListType mysinglelinkedlist;
	mysinglelinkedlist = { 1,2,3,4,5 };
	mysinglelinkedlist.pop_front();
	EXPECT_EQ(4, mysinglelinkedlist.size());
	EXPECT_EQ(2, mysinglelinkedlist.front());
	EXPECT_EQ(5, mysinglelinkedlist.back());
}

TEST(MySingleLinkedList, TestPopBack)
{
	MySingleLinkedListType mysinglelinkedlist;
	mysinglelinkedlist = { 1,2,3,4,5 };
	mysinglelinkedlist.pop_back();
	EXPECT_EQ(4, mysinglelinkedlist.size());
	EXPECT_EQ(1, mysinglelinkedlist.front());
	EXPECT_EQ(4, mysinglelinkedlist.back());
}

TEST(MySingleLinkedList, TestReverse)
{
	MySingleLinkedListType mysinglelinkedlist;
	mysinglelinkedlist = { 1,2,3,4,5,6 };
	mysinglelinkedlist.reverse();
	EXPECT_EQ(6, mysinglelinkedlist.front());
	EXPECT_EQ(1, mysinglelinkedlist.back());
}

TEST(MySingleLinkedList, TestResize)
{
	MySingleLinkedListType mysinglelinkedlist;
	mysinglelinkedlist = { 1,2,3,4,5,6 };
	mysinglelinkedlist.resize(4);
	EXPECT_EQ(1, mysinglelinkedlist.front());
	EXPECT_EQ(4, mysinglelinkedlist.back());

	MySingleLinkedListType mysinglelinkedlist2;
	mysinglelinkedlist2 = { 1,2,3,4,5,6 };
	mysinglelinkedlist2.resize(8);
	EXPECT_EQ(1, mysinglelinkedlist2.front());
	EXPECT_EQ(100, mysinglelinkedlist2.back());
}

TEST(MySingleLinkedList, TestDefaultConstructor)
{
	MySingleLinkedListType mysinglelinkedlist;
	EXPECT_EQ(0, mysinglelinkedlist.size());
}

TEST(MySingleLinkedList, TestCopyConstructor)
{
	MySingleLinkedListType mysinglelinkedlist;
	mysinglelinkedlist = { 1,2,3,4,5 };
	EXPECT_EQ(5, mysinglelinkedlist.size());

	MySingleLinkedListType mysinglelinkedlist2(mysinglelinkedlist);
	EXPECT_EQ(5, mysinglelinkedlist.size());
}

TEST(MySingleLinkedList, TestCopyAssignment)
{
	MySingleLinkedListType mysinglelinkedlist;
	mysinglelinkedlist = { 1,2,3,4,5 };
	EXPECT_EQ(5, mysinglelinkedlist.size());

	MySingleLinkedListType mysinglelinkedlist2;
	mysinglelinkedlist2 = mysinglelinkedlist;
	EXPECT_EQ(5, mysinglelinkedlist.size());
}

TEST(MySingleLinkedList, TestMoveConstructor)
{
	MySingleLinkedListType mysinglelinkedlist;
	mysinglelinkedlist = { 1,2,3,4,5 };
	EXPECT_EQ(5, mysinglelinkedlist.size());

	MySingleLinkedListType mysinglelinkedlist2;
	mysinglelinkedlist2 = std::move(mysinglelinkedlist);
	EXPECT_EQ(5, mysinglelinkedlist2.size());
}

TEST(MySingleLinkedList, TestMoveAssignment)
{
	MySingleLinkedListType mysinglelinkedlist;
	mysinglelinkedlist = { 1,2,3,4,5 };
	EXPECT_EQ(5, mysinglelinkedlist.size());

	MySingleLinkedListType mysinglelinkedlist2;
	mysinglelinkedlist2 = std::move(mysinglelinkedlist);
	EXPECT_EQ(5, mysinglelinkedlist2.size());
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	std::cout << "All tests are successful" << std::endl;
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtDumpMemoryLeaks();
	return RUN_ALL_TESTS();
}