#include "pch.h"
#include "MyString.h"

const char* String::c_str() const noexcept
{
	return m_str;
}

size_t String::length() const
{
	return m_len;
}

size_t String::size() const
{
	return m_len;
}

size_t String::capacity() const noexcept
{
	return m_capacity;
}

void String::resize(size_t n, char c)
{
	if (m_len > n)
	{
		m_str[n] = '\0';
		this->m_len = n;
	}
	else if (m_len < n)
	{
		char* mem = new char[n + 1];
		memcpy(mem, m_str, m_len);
		for (size_t i = m_len; i <= n - 1; i++)
		{
			mem[i] = c;
		}
		mem[n] = '\0';
		delete[] m_str;
		this->m_str = mem;
		if (c != '\0')
		{
			this->m_len = n;
		}
		this->m_capacity = n + 1;
	}
}

String& String::append(const String& str)
{
	if (str.length() == 0)
	{
		return *this;
	}
	size_t len = this->length() + str.length();
	char* mem = new char[len + 1];
	this->copy(mem, this->length());
	char* start = &mem[this->length()];
	str.copy(start, str.length());
	mem[len] = '\0';
	delete[] m_str;
	this->m_str = mem;
	this->m_len = len;
	this->m_capacity = len + 1;
	return *this;
}

String& String::operator=(const String& str)
{
	if (str.length() == 0)
	{
		return *this;
	}
	size_t len = this->length() + str.length();
	char* mem = new char[len + 1];
	this->copy(mem, this->length());
	char* start = &mem[this->length()];
	str.copy(start, str.length());
	mem[len] = '\0';
	delete[] m_str;
	this->m_str = mem;
	this->m_len = len;
	this->m_capacity = len + 1;
	return *this;
}

size_t String::copy(char* s, size_t len, size_t pos) const
{
	if (pos >= this->m_len)
	{
		throw std::out_of_range("invalid string position");
	}
	char* start = &this->m_str[pos];
	if (m_len < len + pos)
	{
		len = m_len;
	}
	std::memcpy(s, start, len - pos);
	return len;
}

const char& String::at(size_t pos) const
{
	if (pos < m_len)
	{
		return m_str[pos];
	}
	else
	{
		throw std::out_of_range("invalid string position");
	}
}

char& String::at(size_t pos)
{
	if (pos < m_len)
	{
		return m_str[pos];
	}
	else
	{
		throw std::out_of_range("invalid string position");
	}
}

const char& String::operator[](size_t pos) const
{
	return m_str[pos];
}

char& String::operator[](size_t pos)
{
	return m_str[pos];
}

String& String::operator= (const char* s)
{
	delete[] m_str;
	m_len = strlen(s);
	m_capacity = m_len + 1;
	m_str = new char[m_capacity];
	std::memcpy(m_str, s, m_len);
	m_str[m_len] = '\0';
	return *this;
}

bool String::operator== (const String& str) const
{
	if (strcmp(this->m_str, str.m_str) == 0)
	{
		return true;
	}
	else
		return false;
}

bool String::operator== (const char* s) const
{
	if (strcmp(this->m_str, s) == 0)
	{
		return true;
	}
	else
		return false;
}

bool String::empty() const noexcept
{
	return m_len == 0;
}

String::String()
{
	m_len = 0;
	m_capacity = 0;
	m_str = nullptr;
}

String::String(const std::string& str)
{
	m_len = str.length();
	m_capacity = m_len + 1;
	m_str = new char[m_capacity];
	str.copy(m_str, str.length());
	m_str[m_len] = '\0';
}

String::String(const String& str)
{
	m_len = str.length();
	m_capacity = m_len + 1;
	m_str = new char[m_capacity];
	str.copy(m_str, str.length());
	m_str[m_len] = '\0';
}

String::String(const String& str, size_t pos, size_t len)
{
	m_len = len;
	m_capacity = m_len + 1;
	m_str = new char[m_capacity];
	std::memcpy(m_str, &str.m_str[pos], m_len);
	m_str[m_len] = '\0';
}

String::String(const char* s)
{
	m_len = strlen(s);
	m_capacity = m_len + 1;
	m_str = new char[m_capacity];
	std::memcpy(m_str, s, m_len);
	m_str[m_len] = '\0';
}

String::String(const char* s, size_t n)
{
	m_len = n;
	m_capacity = m_len + 1;
	m_str = new char[m_capacity];
	std::memcpy(m_str, s, m_len);
	m_str[m_len] = '\0';
}

String::String(size_t n, char c)
{
	m_len = n;
	m_capacity = m_len + 1;
	m_str = new char[m_capacity];
	for (size_t i = 0; i < m_len; i++)
	{
		m_str[i] = c;
	}
	m_str[n] = '\0';
}

String::~String() {
	delete[] m_str;
}

std::ostream& operator<<(std::ostream& os, String const& m) {
	if (nullptr != m.m_str)
	{
		return os << m.m_str << ' ' << m.m_len;
	}
	else
	{
		return os;
	}
}

bool operator==(const char* s, const String& str) {
	return str == s;
}