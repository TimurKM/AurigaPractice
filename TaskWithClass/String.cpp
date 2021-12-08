#include "String.h"

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
		throw std::out_of_range("pos >= this->m_len");
	}
	char* start = &this->m_str[pos];
	if (m_len < len + pos)
	{
		len = m_len;
	}
	std::memcpy(s, start, len - pos);
	return len;
}
//size_t String::find(const String& str, size_t pos) const noexcept 
//{
//	for (size_t i = 0; i < m_len - str.length(); i++)
//	{
//		for (size_t j = 0; str[i + j] == m_str[j]; j++)
//		{
//
//		}
//	}
//}
size_t String::capacity() const noexcept
{
	return m_capacity;
}
const char& String::at(size_t pos) const
{
	for (size_t i = 0; i < m_len; i++)
	{
		std::cout << m_str[i];
	}
	return '\0';
}
const char& String::operator[](size_t pos) const
{
	for (size_t i = 0; i < m_len; i++)
	{
		std::cout << m_str[i];
	}
	return '\0';
}
bool String::empty() const noexcept
{
	if (m_str != NULL)
	{
		return true;
	}
	else
		return false;
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
//String::String(const String& str, size_t pos, size_t len)
//{
//	std::cout << "Substring constructor: " << std::endl; // substring constructor
//}
//String::String(const char* s)
//{
//	std::cout << "From c-string constructor: " << std::endl; // from c-string constructor
//}
//String::String(const char* s, size_t n)
//{
//	std::cout << "From buffer constructor: " << std::endl; // from buffer constructor
//}
//String::String(size_t n, char c)
//{
//	std::cout << "Fill constructor: " << std::endl; // fill constructor
//}
//String::String(std::initializer_list<char> il)
//{
//	std::cout << "Initializer list constructor: " << std::endl; // initializer list constructor
//}
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