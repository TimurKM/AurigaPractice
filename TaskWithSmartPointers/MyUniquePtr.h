#pragma once
#include <iostream>

template <class T>
class MyUniquePtr
{
private:
	T* m_ptr = nullptr;
	friend std::ostream& operator<<(std::ostream& os, MyUniquePtr const& m);
public:
	T* get() const noexcept
	{
		return m_ptr;
	}

	T* release() noexcept
	{
		T* p = m_ptr;
		m_ptr = nullptr;
		return p;
	}

	void reset(T* p) noexcept
	{
		delete m_ptr;
		m_ptr = p;
	}

	T& operator*()
	{
		return *(this->m_ptr);
	}

	MyUniquePtr() // default constructor
	{
		m_ptr = nullptr;
	}

	MyUniquePtr(T* ptr)
	{
		m_ptr = ptr;
	}

	MyUniquePtr(const MyUniquePtr& obj) = delete; // copy constructor is deleted

	MyUniquePtr& operator=(const MyUniquePtr& obj) = delete; // copy assignment is deleted

	MyUniquePtr<T>& operator=(MyUniquePtr<T>&& obj) noexcept // move assignment
	{
		this->m_ptr = obj.m_ptr;
		obj.m_ptr = nullptr;
		return *this;
	}

	MyUniquePtr(MyUniquePtr&& obj) // move constructor
	{
		this->m_ptr = obj.m_ptr;
		obj.m_ptr = nullptr;
	}

	~MyUniquePtr()
	{
		delete m_ptr;
	}
};


template <class T>
std::ostream& operator<<(std::ostream& os, MyUniquePtr<T> const& m) {
	if (nullptr != m.m_ptr)
	{
		return os << m.m_ptr;
	}
	else
	{
		return os;
	}
}