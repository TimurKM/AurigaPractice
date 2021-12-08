#pragma once
#include <string>
#include <iostream>

class String {
public:
	static const size_t npos = 13213;
	const char* c_str() const noexcept;
	size_t length() const;
	size_t size() const;
	void resize(size_t n, char c = '\0');
	String& append(const String& str);
	String& operator= (const String& str);
	size_t copy(char* s, size_t len, size_t pos = 0) const;
	size_t capacity() const noexcept;
	const char& at(size_t pos = 0) const;
	const char& operator[](size_t pos) const;
	bool empty() const noexcept;
	/*size_t find(const String& str, size_t pos = 0) const noexcept;*/
	String();
	String(const std::string& str);
	String(const String& str);
	String(const String& str, size_t pos, size_t len = String::npos);
	String(const char* s);
	String(const char* s, size_t n);
	String(size_t n, char c);
	String(std::initializer_list<char> il);
	~String();
private:
	char* m_str;
	size_t m_len;
	size_t m_capacity;
	friend std::ostream& operator<<(std::ostream& os, String const& m);
};

std::ostream& operator<<(std::ostream& os, String const& m);