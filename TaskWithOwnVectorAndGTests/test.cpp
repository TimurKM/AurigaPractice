#include "pch.h"
#include "MyVector.h"

typedef MyVector<int> VectorType;
//typedef std::vector<int> VectorType;

TEST(VectorTest, TestFront)
{
	VectorType myvector;
	myvector = { 1,2,3,4,5 };
	EXPECT_EQ(1, myvector.front());
}

TEST(VectorTest, TestBack)
{
	VectorType myvector;
	myvector = { 1,2,3,4,5 };
	EXPECT_EQ(5, myvector.back());
}

TEST(VectorTest, TestData)
{
	VectorType myvector;
	myvector = { 1,2,3,4,5 };
	int* p = myvector.data();
	EXPECT_EQ(p[0], myvector[0]);
	EXPECT_EQ(p[1], myvector[1]);
	EXPECT_EQ(p[2], myvector[2]);
	EXPECT_EQ(p[3], myvector[3]);
	EXPECT_EQ(p[4], myvector[4]);

	int a[] = { 1,2,3,4,5 };
	EXPECT_TRUE(0 == memcmp(a, p, sizeof(int) * 5));
}

TEST(VectorTest, TestSquareBracketsOperator)
{
	VectorType myvector;
	myvector = { 1,2,3,4,5 };
	EXPECT_EQ(1, myvector[0]);
	EXPECT_EQ(2, myvector[1]);
	EXPECT_EQ(3, myvector[2]);
	EXPECT_EQ(4, myvector[3]);
	EXPECT_EQ(5, myvector[4]);

	myvector[0] = 8;
	myvector[3] = 10;
	EXPECT_EQ(8, myvector[0]);
	EXPECT_EQ(10, myvector[3]);
}

TEST(VectorTest, TestAt)
{
	std::string what;
	VectorType myvector;

	myvector = { 1,2,3,4,5 };
	EXPECT_EQ(1, myvector.at(0));
	EXPECT_EQ(2, myvector.at(1));
	EXPECT_EQ(3, myvector.at(2));
	EXPECT_EQ(4, myvector.at(3));
	EXPECT_EQ(5, myvector.at(4));
	try
	{
		what = "";
		myvector.at(5);
	}
	catch (std::out_of_range const& exc)
	{
		what = exc.what();
	}
	EXPECT_EQ(std::string("invalid vector subscript"), what);
}

TEST(VectorTest, TestSize)
{
	VectorType myvector;
	EXPECT_EQ(0, myvector.size());

	myvector = { 1,2,3,4,5 };
	EXPECT_EQ(5, myvector.size());

	myvector = {};
	EXPECT_EQ(0, myvector.size());
}

TEST(VectorTest, TestCapacity)
{
	VectorType myvector;
	EXPECT_EQ(15, myvector.capacity());

	myvector = { 1,2,3,4,5 };
	EXPECT_EQ(5, myvector.capacity());

	myvector = {};
	EXPECT_EQ(5, myvector.capacity());
}

TEST(VectorTest, TestShrinkToFit)
{
	VectorType myvector;
	EXPECT_EQ(0, myvector.size());
	EXPECT_EQ(15, myvector.capacity());

	myvector.shrink_to_fit();
	EXPECT_EQ(0, myvector.size());
	EXPECT_EQ(0, myvector.capacity());

	VectorType myvector2;
	myvector2 = { 1,2,3,4,5 };
	EXPECT_EQ(5, myvector2.size());
	EXPECT_EQ(5, myvector2.capacity());

	myvector2.shrink_to_fit();
	EXPECT_EQ(5, myvector2.size());
	EXPECT_EQ(5, myvector2.capacity());
}

TEST(VectorTest, TestClear)
{
	VectorType myvector;

	myvector = { 1,2,3,4,5 };
	EXPECT_EQ(5, myvector.size());

	myvector.clear();
	EXPECT_EQ(0, myvector.size());
}

TEST(VectorTest, TestPushBack)
{
	VectorType myvector;

	myvector.push_back(1);
	EXPECT_EQ(1, myvector.size());
	EXPECT_EQ(1, myvector[0]);

	myvector.push_back(2);
	EXPECT_EQ(2, myvector.size());
	EXPECT_EQ(1, myvector[0]);
	EXPECT_EQ(2, myvector[1]);
	EXPECT_EQ(1, myvector.front());
	EXPECT_EQ(2, myvector.back());

	VectorType myvector2;

	myvector2 = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	EXPECT_EQ(15, myvector2.size());
	EXPECT_EQ(15, myvector2.capacity());
	myvector2.push_back(16);
	EXPECT_EQ(16, myvector2.size());
	EXPECT_EQ(30, myvector2.capacity());
}

TEST(VectorTest, TestPopBack)
{
	VectorType myvector;

	myvector = { 1,2,3,4,5 };
	EXPECT_EQ(5, myvector.size());
	myvector.pop_back();
	EXPECT_EQ(4, myvector.size());
}

TEST(VectorTest, TestResize)
{
	VectorType myvector;

	myvector = { 1,2,3,4,5 };
	EXPECT_EQ(5, myvector.size());

	myvector.resize(7, 100);
	EXPECT_EQ(100, myvector[5]);
	EXPECT_EQ(100, myvector[6]);
	EXPECT_EQ(7, myvector.size());

	myvector.resize(3);
	EXPECT_EQ(3, myvector.size());

	VectorType myvector2;
	EXPECT_EQ(15, myvector2.capacity());
	myvector2.resize(5);
	EXPECT_EQ(100, myvector2[0]);
	EXPECT_EQ(100, myvector2[1]);
	EXPECT_EQ(100, myvector2[2]);
	EXPECT_EQ(100, myvector2[3]);
	EXPECT_EQ(100, myvector2[4]);
}

TEST(VectorTest, TestDefaultConstructor)
{
	VectorType myvector;

	EXPECT_EQ(0, myvector.size());
	EXPECT_EQ(15, myvector.capacity());
}

TEST(VectorTest, TestCopyConstructor)
{
	VectorType myvector;
	myvector = { 1,2,3,4,5 };
	EXPECT_EQ(5, myvector.size());
	EXPECT_EQ(1, myvector.front());
	EXPECT_EQ(5, myvector.back());

	VectorType myvector2(myvector);
	EXPECT_EQ(5, myvector2.size());
	EXPECT_EQ(1, myvector2.front());
	EXPECT_EQ(5, myvector2.back());
}

TEST(VectorTest, TestCopyAssignment)
{
	VectorType myvector;
	myvector = { 1,2,3,4,5 };
	EXPECT_EQ(5, myvector.size());
	EXPECT_EQ(1, myvector.front());
	EXPECT_EQ(5, myvector.back());

	VectorType myvector2 = myvector;
	EXPECT_EQ(5, myvector2.size());
	EXPECT_EQ(1, myvector2.front());
	EXPECT_EQ(5, myvector2.back());
}


TEST(VectorTest, TestMoveConstructor)
{
	VectorType myvector;
	myvector = { 1,2,3,4,5 };
	EXPECT_EQ(5, myvector.size());
	EXPECT_EQ(1, myvector.front());
	EXPECT_EQ(5, myvector.back());

	VectorType myvector2;
	myvector2 = std::move(myvector);
	EXPECT_EQ(5, myvector2.size());
	EXPECT_EQ(1, myvector2.front());
	EXPECT_EQ(5, myvector2.back());
}
