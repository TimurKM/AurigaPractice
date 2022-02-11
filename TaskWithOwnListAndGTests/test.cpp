#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "pch.h"
#include <iostream>
#include "MySingleLinkedList.h"
#include <list>

using MySinglyLinkedListType = MySinglyLinkedList<int>;
//using MySinglyLinkedListType = std::list<int>;

TEST(MySinglyLinkedList, TestSize)
{
	MySinglyLinkedListType mysinglelinkedlist;
	EXPECT_EQ(0, mysinglelinkedlist.size());

	MySinglyLinkedListType mysinglelinkedlist2;
	mysinglelinkedlist2 = { 1,2,3,4,5 };
	EXPECT_EQ(5, mysinglelinkedlist2.size());
}

TEST(MySinglyLinkedList, TestEmpty)
{
	MySinglyLinkedListType mysinglelinkedlist;
	EXPECT_TRUE(0 == mysinglelinkedlist.size());

	MySinglyLinkedListType mysinglelinkedlist2;
	mysinglelinkedlist2 = { 1,2,3,4,5 };
	EXPECT_FALSE(0 == mysinglelinkedlist2.size());
}

TEST(MySinglyLinkedList, TestFront)
{
	MySinglyLinkedListType mysinglelinkedlist;
	mysinglelinkedlist = { 1,2,3,4,5 };
	EXPECT_EQ(1, mysinglelinkedlist.front());
}

TEST(MySinglyLinkedList, TestBack)
{
	MySinglyLinkedListType mysinglelinkedlist;
	mysinglelinkedlist = { 1,2,3,4,5 };
	EXPECT_EQ(5, mysinglelinkedlist.back());
}

TEST(MySinglyLinkedList, TestPushFront)
{
	MySinglyLinkedListType mysinglelinkedlist;
	mysinglelinkedlist.push_front(1);
	EXPECT_EQ(1, mysinglelinkedlist.size());
	EXPECT_EQ(1, mysinglelinkedlist.front());
	EXPECT_EQ(1, mysinglelinkedlist.back());

	MySinglyLinkedListType mysinglelinkedlist2;
	mysinglelinkedlist2 = { 1,2,3,4,5 };
	mysinglelinkedlist2.push_front(0);
	EXPECT_EQ(6, mysinglelinkedlist2.size());
	EXPECT_EQ(0, mysinglelinkedlist2.front());
	EXPECT_EQ(5, mysinglelinkedlist2.back());
}

TEST(MySinglyLinkedList, TestPushBack)
{
	MySinglyLinkedListType mysinglelinkedlist;
	mysinglelinkedlist.push_back(1);
	EXPECT_EQ(1, mysinglelinkedlist.size());
	EXPECT_EQ(1, mysinglelinkedlist.front());
	EXPECT_EQ(1, mysinglelinkedlist.back());

	MySinglyLinkedListType mysinglelinkedlist2;
	mysinglelinkedlist2 = { 1,2,3,4,5 };
	mysinglelinkedlist2.push_back(6);
	EXPECT_EQ(6, mysinglelinkedlist2.size());
	EXPECT_EQ(1, mysinglelinkedlist2.front());
	EXPECT_EQ(6, mysinglelinkedlist2.back());
}

TEST(MySinglyLinkedList, TestPopFront)
{
	MySinglyLinkedListType mysinglelinkedlist;
	mysinglelinkedlist = { 1,2,3,4,5 };
	mysinglelinkedlist.pop_front();
	EXPECT_EQ(4, mysinglelinkedlist.size());
	EXPECT_EQ(2, mysinglelinkedlist.front());
	EXPECT_EQ(5, mysinglelinkedlist.back());
}

TEST(MySinglyLinkedList, TestPopBack)
{
	MySinglyLinkedListType mysinglelinkedlist;
	mysinglelinkedlist = { 1,2,3,4,5 };
	mysinglelinkedlist.pop_back();
	EXPECT_EQ(4, mysinglelinkedlist.size());
	EXPECT_EQ(1, mysinglelinkedlist.front());
	EXPECT_EQ(4, mysinglelinkedlist.back());
}

TEST(MySinglyLinkedList, TestReverse)
{
	MySinglyLinkedListType mysinglelinkedlist;
	mysinglelinkedlist = { 1,2,3,4,5,6 };
	mysinglelinkedlist.reverse();
	EXPECT_EQ(6, mysinglelinkedlist.front());
	EXPECT_EQ(1, mysinglelinkedlist.back());
}

TEST(MySinglyLinkedList, TestResize)
{
	MySinglyLinkedListType mysinglelinkedlist;
	mysinglelinkedlist = { 1,2,3,4,5,6 };
	mysinglelinkedlist.resize(4);
	EXPECT_EQ(1, mysinglelinkedlist.front());
	EXPECT_EQ(4, mysinglelinkedlist.back());

	MySinglyLinkedListType mysinglelinkedlist2;
	mysinglelinkedlist2 = { 1,2,3,4,5,6 };
	mysinglelinkedlist2.resize(8);
	EXPECT_EQ(1, mysinglelinkedlist2.front());
	EXPECT_EQ(0, mysinglelinkedlist2.back());
}

TEST(MySinglyLinkedList, TestDefaultConstructor)
{
	MySinglyLinkedListType mysinglelinkedlist;
	EXPECT_EQ(0, mysinglelinkedlist.size());
}

TEST(MySinglyLinkedList, TestCopyConstructor)
{
	MySinglyLinkedListType mysinglelinkedlist;
	mysinglelinkedlist = { 1,2,3,4,5 };
	EXPECT_EQ(5, mysinglelinkedlist.size());

	MySinglyLinkedListType mysinglelinkedlist2(mysinglelinkedlist);
	EXPECT_EQ(5, mysinglelinkedlist.size());
}

TEST(MySinglyLinkedList, TestCopyAssignment)
{
	MySinglyLinkedListType mysinglelinkedlist;
	mysinglelinkedlist = { 1,2,3,4,5 };
	EXPECT_EQ(5, mysinglelinkedlist.size());

	MySinglyLinkedListType mysinglelinkedlist2;
	mysinglelinkedlist2 = mysinglelinkedlist;
	EXPECT_EQ(5, mysinglelinkedlist.size());
}

TEST(MySinglyLinkedList, TestMoveConstructor)
{
	MySinglyLinkedListType mysinglelinkedlist;
	mysinglelinkedlist = { 1,2,3,4,5 };
	EXPECT_EQ(5, mysinglelinkedlist.size());

	MySinglyLinkedListType mysinglelinkedlist2;
	mysinglelinkedlist2 = std::move(mysinglelinkedlist);
	EXPECT_EQ(5, mysinglelinkedlist2.size());
}

TEST(MySinglyLinkedList, TestMoveAssignment)
{
	MySinglyLinkedListType mysinglelinkedlist;
	mysinglelinkedlist = { 1,2,3,4,5 };
	EXPECT_EQ(5, mysinglelinkedlist.size());

	MySinglyLinkedListType mysinglelinkedlist2;
	mysinglelinkedlist2 = std::move(mysinglelinkedlist);
	EXPECT_EQ(5, mysinglelinkedlist2.size());
}

int main(int argc, char** argv)
{
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}