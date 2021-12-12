#pragma once
#include <string>
#include <iostream>

class String {
public:
	static const size_t npos = -1;
	const char* c_str() const noexcept;
	size_t length() const;
	size_t size() const;
	void resize(size_t n, char c = '\0');
	String& append(const String& str);
	String& operator= (const String& str);
	String& operator= (const char* s);
	bool operator== (const String& str) const;
	bool operator== (const char* s) const;
	size_t copy(char* s, size_t len, size_t pos = 0) const;
	size_t capacity() const noexcept;
	const char& at(size_t pos = 0) const;
	char& at(size_t pos = 0);
	const char& operator[](size_t pos) const;
	char& operator[](size_t pos);
	bool empty() const noexcept;
	String();
	String(const std::string& str);
	String(const String& str);
	String(const String& str, size_t pos, size_t len = String::npos);
	String(const char* s);
	String(const char* s, size_t n);
	String(size_t n, char c);
	~String();
private:
	char* m_str;
	size_t m_len;
	size_t m_capacity;
	friend std::ostream& operator<<(std::ostream& os, String const& m);
};

std::ostream& operator<<(std::ostream& os, String const& m);
bool operator==(const char* s, const String& str);