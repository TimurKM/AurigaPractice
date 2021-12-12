#include "pch.h"
#include "MyString.h"

TEST(StringTest, TestAt)
{
	std::string what;
	String s;

	try
	{
		what = "";
		s.at(0);

	}
	catch (std::out_of_range const& exc)
	{
		what = exc.what();
	}
	EXPECT_EQ(std::string("invalid string position"), what);

	s = "abcd";
	EXPECT_EQ('a', s.at(0));
	EXPECT_EQ('b', s.at(1));
	EXPECT_EQ('c', s.at(2));
	EXPECT_EQ('d', s.at(3));

	try
	{
		what = "";
		s.at(4);
	}
	catch (std::out_of_range const& exc)
	{
		what = exc.what();
	}
	EXPECT_EQ(std::string("invalid string position"), what);

	s.at(0) = 'd';
	s.at(2) = 'b';
	EXPECT_EQ("dbbd", s);
}

TEST(StringTest, TestElementAccessOperator)
{
	String s = "abcd";
	EXPECT_EQ('a', s.operator[](0));
	EXPECT_EQ('b', s.operator[](1));
	EXPECT_EQ('c', s.operator[](2));
	EXPECT_EQ('d', s.operator[](3));

	s.operator[](0) = 'd';
	s.operator[](2) = 'b';
	EXPECT_EQ("dbbd", s);
}

TEST(StringTest, TestEmpty)
{
	String s = "abcd";
	EXPECT_EQ(false, s.empty());

	s = "";
	EXPECT_EQ(true, s.empty());
}

TEST(StringTest, TestCStr) {
	String s = "abcd";
	s.c_str();
	EXPECT_EQ("abcd", s);

	s = "";
	s.c_str();
	EXPECT_EQ("", s);
}

TEST(StringTest, TestLength)
{
	String s = "abcd";
	EXPECT_EQ(4, s.length());

	s = "";
	EXPECT_EQ(0, s.length());
}

TEST(StringTest, TestSize)
{
	String s = "abcd";
	EXPECT_EQ(4, s.size());

	s = "";
	EXPECT_EQ(0, s.size());
}

TEST(StringTest, TestCapacity)
{
	String s = "abcd";
	EXPECT_EQ(5, s.capacity());

	s = "";
	EXPECT_EQ(1, s.capacity());
}

TEST(StringTest, TestCopy)
{
	String s = "abcd";
	std::string what;

	char a[256] = { 0, };
	s.copy(a, 100, 0);
	EXPECT_EQ('a', a[0]);
	EXPECT_EQ('b', a[1]);
	EXPECT_EQ('c', a[2]);
	EXPECT_EQ('d', a[3]);

	try
	{
		what = "";
		s.copy(a, 100, 100);
	}
	catch (std::out_of_range const& exc)
	{
		what = exc.what();
	}
	EXPECT_EQ(std::string("invalid string position"), what);

	try
	{
		what = "";
		s.copy(a, 60, 100);
	}
	catch (std::out_of_range const& exc)
	{
		what = exc.what();
	}
	EXPECT_EQ(std::string("invalid string position"), what);
}

TEST(StringTest, TestAppend)
{
	String s = "abcd";
	String s1 = "1234";
	std::string what;
	EXPECT_EQ("abcd1234", s.append(s1));

	s = "abcd";
	s1 = "";
	EXPECT_EQ("abcd", s.append(s1));

	s = "";
	s1 = "";
	EXPECT_EQ("", s.append(s1));

	s = "a";
	s1 = "1234";
	EXPECT_EQ("a1234", s.append(s1));

	try
	{
		what = "";
		s = "";
		s1 = "abcd";
		s.append(s1);
	}
	catch (std::out_of_range const& exc)
	{
		what = exc.what();
	}
	EXPECT_EQ(std::string("invalid string position"), what);
}

TEST(StringTest, TestResize)
{
	String s = "abcd";
	std::string what;

	EXPECT_EQ(s.capacity(), 5);

	s.resize(6, '+');
	EXPECT_EQ("abcd++", s);
	EXPECT_EQ(s.capacity(), 7);

	s = "abcd";
	s.resize(2);
	EXPECT_EQ("ab", s);
	EXPECT_EQ(s.capacity(), 5);


	s = "";
	s.resize(5, '+');
	EXPECT_EQ("+++++", s);
	EXPECT_EQ(s.capacity(), 6);

	try
	{
		what = "";
		s = "";
		s.resize(1000000000, '+');
	}
	catch (std::bad_alloc& exc)
	{
		what = exc.what();
	}
	EXPECT_EQ(std::string(""), what);
}

TEST(StringTest, TestDefaultConstructor)
{
	String s;

	EXPECT_EQ(0, s.length());
	EXPECT_EQ(0, s.capacity());
	EXPECT_EQ(NULL, s.c_str());
}

TEST(StringTest, TestConstructorWithStdString)
{
	std::string str = "abcd";
	String s(str);

	EXPECT_EQ(4, s.length());
	EXPECT_EQ(5, s.capacity());
	EXPECT_EQ("abcd", s);
}

TEST(StringTest, TestConstructorWithMyString)
{
	String str("abcdefg");
	String s(str);
	EXPECT_EQ(7, s.length());
	EXPECT_EQ(8, s.capacity());
	EXPECT_EQ("abcdefg", s);
}

TEST(StringTest, TestConstructorWithMyStringPosLen)
{
	const String str("abcdefg");

	String s(str, 2, 3);
	EXPECT_EQ("cde", s);

	String s1(str, 2, 10);
	EXPECT_EQ("cdefg", s1);

	String s2(str, 0, 3);
	EXPECT_EQ("abc", s2);
}

TEST(StringTest, TestConstructorWithCStr)
{
	String s("abcdefg");
	EXPECT_EQ(7, s.length());
	EXPECT_EQ(8, s.capacity());
	EXPECT_EQ("abcdefg", s);
}

TEST(StringTest, TestConstructorWithCStrAndN)
{
	String s("abcdefg", 4);
	EXPECT_EQ(4, s.length());
	EXPECT_EQ(5, s.capacity());
	EXPECT_EQ("abcd", s);
}

TEST(StringTest, TestCopyConstructorWithNC)
{
	String s(5, 'a');

	EXPECT_EQ(5, s.length());
	EXPECT_EQ(6, s.capacity());
	EXPECT_EQ(String("aaaaa"), s);
}