#pragma once
#include <string>
#include <iostream>

class MyString {
public:
	static const size_t npos = -1;
	const char* c_str() const noexcept;
	size_t length() const;
	size_t size() const;
	void resize(size_t n, char c = '\0');
	MyString& append(const MyString& str);
	MyString& operator= (const MyString& str);
	MyString& operator= (const char* s);
	bool operator== (const MyString& str) const;
	bool operator== (const char* s) const;
	size_t copy(char* s, size_t len, size_t pos = 0) const;
	size_t capacity() const noexcept;
	const char& at(size_t pos = 0) const;
	char& at(size_t pos = 0);
	const char& operator[](size_t pos) const;
	char& operator[](size_t pos);
	bool empty() const noexcept;
	MyString();
	MyString(const std::string& str);
	MyString(const MyString& str);
	MyString(const MyString& str, size_t pos, size_t len = MyString::npos);
	MyString(const char* s);
	MyString(const char* s, size_t n);
	MyString(size_t n, char c);
	~MyString();
private:
	char* m_str;
	size_t m_len;
	size_t m_capacity;
	friend std::ostream& operator<<(std::ostream& os, MyString const& m);
};

std::ostream& operator<<(std::ostream& os, MyString const& m);
bool operator==(const char* s, const MyString& str);