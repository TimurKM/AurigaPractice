#pragma once
#include <iostream>
#include <atomic>

template <class T>
class MySharedPtr
{
public:
	T* get()
	{
		return m_ptr;
	}

	long use_count() const noexcept
	{
		return m_referencesCounter ? m_referencesCounter->load() : 0;
	}

	bool unique() const noexcept
	{
		return (1 == use_count());
	}

	void reset(T* p)
	{
		_reset();
		m_ptr = p;
		m_referencesCounter = new std::atomic_long(1);
	}

	T& operator*()
	{
		return *m_ptr;
	}

	MySharedPtr() = default;

	MySharedPtr(T* ptr) : m_ptr(ptr), m_referencesCounter(new std::atomic_long(1)) { }

	MySharedPtr(const MySharedPtr& obj) // copy constructor 
	{
		*this = obj;
	}

	MySharedPtr<T>& operator=(const MySharedPtr<T>& obj) // copy assignment
	{
		_reset();
		m_ptr = obj.m_ptr;
		m_referencesCounter = obj.m_referencesCounter;
		if (nullptr != m_referencesCounter)
		{
			(*m_referencesCounter)++;
		}
		return *this;
	}

	MySharedPtr<T>& operator=(MySharedPtr<T>&& obj) // move assignment 
	{
		_reset();
		m_ptr = obj.m_ptr;
		m_referencesCounter = obj.m_referencesCounter;
		obj.m_ptr = nullptr;
		obj.m_referencesCounter = nullptr;
		return *this;
	}

	MySharedPtr(MySharedPtr&& obj) // move constructor 
	{
		*this = obj;
	}

	~MySharedPtr()
	{
		_reset();
	}
private:
	void _reset()
	{
		if (nullptr != m_referencesCounter)
		{
			long val = m_referencesCounter->fetch_sub(1);
			if (1 == val)
			{
				delete m_ptr;
				delete m_referencesCounter;
			}
		}
	}

	T* m_ptr = nullptr;
	std::atomic_long* m_referencesCounter = nullptr;
	friend std::ostream& operator<<(std::ostream& os, MySharedPtr const& m);
};

template <class T>
std::ostream& operator<<(std::ostream& os, MySharedPtr<T> const& m)
{
	return m.m_ptr ? (os << m.m_ptr) : os;
}