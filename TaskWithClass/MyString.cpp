#include "pch.h"
#include "MyString.h"

const char* MyString::c_str() const noexcept
{
	return m_str;
}

size_t MyString::length() const
{
	return m_len;
}

size_t MyString::size() const
{
	return length();
}

size_t MyString::capacity() const noexcept
{
	return m_capacity;
}

void MyString::resize(size_t n, char c)
{
	if (m_len > n)
	{
		m_str[n] = '\0';
		m_len = n;
	}
	else if (m_len < n)
	{
		if (m_capacity <= n)
		{
			m_capacity = n + 1;
			auto mem = new char[m_capacity];
			this->copy(mem, this->length());
			delete[] m_str;
			m_str = mem;
		}
		for (size_t i = m_len; i < n; i++)
		{
			m_str[i] = c;
		}
		m_str[n] = '\0';
		m_len = n;
	}
}

MyString& MyString::append(const MyString& str)
{
	if (str.length() == 0)
	{
		return *this;
	}
	size_t len = this->length() + str.length();
	if (len >= m_capacity)
	{
		m_capacity = len + 1;
		char* mem = new char[m_capacity];
		this->copy(mem, this->length());
		str.copy(&mem[this->length()], str.length());
		delete[] m_str;
		m_str = mem;
	}
	else
	{
		str.copy(&m_str[this->length()], str.length());
	}
	m_len = len;
	m_str[m_len] = '\0';
	return *this;
}

MyString& MyString::operator=(const MyString& str)
{
	m_len = str.length();
	if (m_capacity <= str.length())
	{
		delete[] m_str;
		m_capacity = m_len + 1;
		m_str = new char[m_capacity];
	}
	str.copy(m_str, m_len);
	m_str[m_len] = '\0';
	return *this;
}

size_t MyString::copy(char* s, size_t len, size_t pos) const
{
	if (pos > m_len)
	{
		throw std::out_of_range("invalid string position");
	}
	if (m_len < len + pos)
	{
		len = m_len - pos;
	}
	std::memcpy(s, &m_str[pos], len);
	return len;
}

const char& MyString::at(size_t pos) const
{
	if (pos >= m_len)
	{
		throw std::out_of_range("invalid string position");
	}
	return (*this)[pos];
}

char& MyString::at(size_t pos)
{
	if (pos >= m_len)
	{
		throw std::out_of_range("invalid string position");
	}
	return (*this)[pos];
}

const char& MyString::operator[](size_t pos) const
{
	return m_str[pos];
}

char& MyString::operator[](size_t pos)
{
	return m_str[pos];
}

MyString& MyString::operator= (const char* s)
{
	m_len = strlen(s);
	if (m_capacity <= m_len)
	{
		delete[] m_str;
		m_capacity = m_len + 1;
		m_str = new char[m_capacity];
	}
	std::memcpy(m_str, s, m_len);
	m_str[m_len] = '\0';
	return *this;
}

bool MyString::operator== (const MyString& str) const
{
	return *this == str.m_str;
}

bool MyString::operator== (const char* s) const
{
	return (strcmp(this->m_str, s) == 0);
}

bool MyString::empty() const noexcept
{
	return m_len == 0;
}

MyString::MyString()
{
	m_capacity = 15;
	m_str = new char[m_capacity];
	m_str[0] = '\0';
	m_len = 0;
}

MyString::MyString(const std::string& str)
{
	m_len = str.length();
	m_capacity = m_len + 1;
	m_str = new char[m_capacity];
	str.copy(m_str, str.length());
	m_str[m_len] = '\0';
}

MyString::MyString(const MyString& str) : MyString()
{
	*this = str;
}

MyString::MyString(const MyString& str, size_t pos, size_t len)
{
	m_capacity = str.capacity();
	m_str = new char[m_capacity];
	m_len = str.copy(m_str, len, pos);
	m_str[m_len] = '\0';
}

MyString::MyString(const char* s) : MyString()
{
	*this = s;
}

MyString::MyString(const char* s, size_t n) : MyString()
{
	*this = s;
	this->resize(n);
}

MyString::MyString(size_t n, char c) : MyString()
{
	this->resize(n, c);
}

MyString::~MyString()
{
	delete[] m_str;
}

std::ostream& operator<<(std::ostream& os, MyString const& m) {
	if (nullptr != m.m_str)
	{
		return os << m.m_str << ' ' << m.m_len;
	}
	else
	{
		return os;
	}
}

bool operator==(const char* s, const MyString& str)
{
	return str == s;
}