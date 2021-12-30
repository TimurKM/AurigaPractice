#include "pch.h"
#include "MyString.h"

TEST(StringTest, TestAt)
{
	std::string what;
	MyString s;

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

TEST(StringTest, TestSquareBracketsOperator)
{
	MyString s = "abcd";
	EXPECT_EQ('a', s[0]);
	EXPECT_EQ('b', s[1]);
	EXPECT_EQ('c', s[2]);
	EXPECT_EQ('d', s[3]);

	s[0] = 'd';
	s[2] = 'b';
	EXPECT_EQ("dbbd", s);
}

TEST(StringTest, TestEmpty)
{
	MyString s = "abcd";
	EXPECT_FALSE(s.empty());

	s = "";
	EXPECT_TRUE(s.empty());
}

TEST(StringTest, TestCStr) {
	MyString s;
	EXPECT_TRUE(0 == strcmp("", s.c_str()));

	s = "abcd";
	EXPECT_TRUE(0 == strcmp("abcd", s.c_str()));

	s = "";
	EXPECT_TRUE(0 == strcmp("", s.c_str()));
}

TEST(StringTest, TestLength)
{
	MyString s;
	EXPECT_EQ(0, s.length());

	s = "abcd";
	EXPECT_EQ(4, s.length());

	s = "";
	EXPECT_EQ(0, s.length());
}

TEST(StringTest, TestSize)
{
	MyString s;
	EXPECT_EQ(0, s.size());

	s = "abcd";
	EXPECT_EQ(4, s.size());

	s = "";
	EXPECT_EQ(0, s.size());
}

TEST(StringTest, TestCapacity)
{
	MyString s;
	EXPECT_EQ(0, s.size());
	EXPECT_EQ(15, s.capacity());

	s = "abcd";
	EXPECT_EQ(4, s.size());
	EXPECT_EQ(5, s.capacity());

	s = "";
	EXPECT_EQ(0, s.size());
	EXPECT_EQ(1, s.capacity());
}

TEST(StringTest, TestCopy)
{
	MyString s = "abcd";
	MyString s1;
	std::string what;

	char a[256] = { 0, };
	size_t copied = s1.copy(a, 100, 0);
	EXPECT_EQ(copied, 0);
	EXPECT_TRUE(0 == strcmp("", a));

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

	s.copy(a, 0, 1);
	EXPECT_EQ('a', a[0]);
	EXPECT_EQ('b', a[1]);
	EXPECT_EQ('c', a[2]);
	EXPECT_EQ('d', a[3]);
}

TEST(StringTest, TestAppend)
{
	MyString s = "abcd";
	MyString s1 = "1234";
	MyString s2;
	MyString s3;
	MyString s4;
	MyString s5;
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

	s = "";
	s1 = "abcd";
	EXPECT_EQ("abcd", s.append(s1));

	s = "abcd";
	EXPECT_EQ("abcd", s.append(s2));

	s = "abcd";
	EXPECT_EQ("abcd", s3.append(s));

	EXPECT_EQ("", s4.append(s5));
}

TEST(StringTest, TestOperatorEquality)
{
	MyString s1 = "1234";
	MyString s = s1;
	EXPECT_EQ(s, s1);
}

TEST(StringTest, TestResize)
{
	MyString s = "abcd";
	std::string what;

	EXPECT_EQ(s.size(), 4);
	EXPECT_EQ(s.capacity(), 5);

	s.resize(6, '+');
	EXPECT_EQ("abcd++", s);
	EXPECT_EQ(s.size(), 6);
	EXPECT_EQ(s.capacity(), 7);

	s = "abcd";
	s.resize(6, '\0');
	EXPECT_EQ("abcd", s);
	EXPECT_EQ(s.size(), 6);
	EXPECT_EQ(s.capacity(), 7);

	s = "abcd";
	s.resize(2);
	EXPECT_EQ("ab", s);
	EXPECT_EQ(s.size(), 2);
	EXPECT_EQ(s.capacity(), 5);

	s = "abcd";
	s.resize(0);
	EXPECT_EQ("", s);
	EXPECT_EQ(s.size(), 0);
	EXPECT_EQ(s.capacity(), 5);

	s = "";
	s.resize(5, '+');
	EXPECT_EQ("+++++", s);
	EXPECT_EQ(s.size(), 5);
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
	MyString s;

	EXPECT_EQ(0, s.length());
	EXPECT_EQ(15, s.capacity());
	EXPECT_TRUE(0 == strcmp("", s.c_str()));
}

TEST(StringTest, TestConstructorWithStdString)
{
	std::string str = "abcd";
	MyString s(str);

	EXPECT_EQ(4, s.length());
	EXPECT_EQ(5, s.capacity());
	EXPECT_EQ("abcd", s);

	str = "";
	MyString s1(str);

	EXPECT_EQ(0, s1.length());
	EXPECT_EQ(1, s1.capacity());
	EXPECT_EQ("", s1);
}

TEST(StringTest, TestCopyConstructor)
{
	MyString str("abcdefg");
	MyString s(str);
	EXPECT_EQ(7, s.length());
	EXPECT_EQ(8, s.capacity());
	EXPECT_EQ("abcdefg", s);
}

TEST(StringTest, TestConstructorWithMyStringPosLen)
{
	const MyString str("abcdefg");
	std::string what;

	MyString s(str, 2, 3);
	EXPECT_EQ(MyString("cde"), s);

	MyString s1(str, 2, 10);
	EXPECT_EQ(MyString("cdefg"), s1);

	MyString s2(str, 0, 3);
	EXPECT_EQ(MyString("abc"), s2);

	try
	{
		MyString s3(str, 10, 1);
	}
	catch (std::out_of_range const& exc)
	{
		what = exc.what();
	}
	EXPECT_EQ(std::string("invalid string position"), what);
}

TEST(StringTest, TestConstructorWithCStr)
{
	MyString s("abcdefg");
	EXPECT_EQ(7, s.length());
	EXPECT_EQ(8, s.capacity());
	EXPECT_EQ("abcdefg", s);

	MyString s1("");
	EXPECT_EQ(0, s1.length());
	EXPECT_EQ(1, s1.capacity());
	EXPECT_EQ("", s1);
}

TEST(StringTest, TestConstructorWithCStrAndN)
{
	std::string what;
	MyString s("abcdefg", 4);
	EXPECT_EQ(4, s.length());
	EXPECT_EQ(8, s.capacity());
	EXPECT_EQ("abcd", s);

	MyString s1("abcdefg", 100);
	EXPECT_EQ(100, s1.length());
	EXPECT_EQ(101, s1.capacity());
	EXPECT_EQ("abcdefg", s1);

	MyString s2("", 0);
	EXPECT_EQ(0, s2.length());
	EXPECT_EQ(1, s2.capacity());
	EXPECT_EQ("", s2);

	MyString s3("", 2);
	EXPECT_EQ(2, s3.length());
	EXPECT_EQ(3, s3.capacity());
	EXPECT_EQ("", s3);
}

TEST(StringTest, TestCopyConstructorWithNC)
{
	MyString s(5, 'a');

	EXPECT_EQ(5, s.length());
	EXPECT_EQ(15, s.capacity());
	EXPECT_EQ(MyString("aaaaa"), s);

	MyString s2(0, '\0');

	EXPECT_EQ(0, s2.length());
	EXPECT_EQ(15, s2.capacity());
	EXPECT_EQ(MyString(""), s2);
}