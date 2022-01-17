#pragma once
#include <iostream>
// #include <atomic>
#include <mutex> 

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
		return m_referencesCounter ? *m_referencesCounter : 0;
	}

	bool unique() const noexcept
	{
		return (1 == use_count());
	}

	void reset(T* p)
	{
		if (m_referencesCounter != nullptr)
		{
			std::unique_lock<std::mutex> ulock(m_mtx);
			(*m_referencesCounter) -= 1;
			if (*m_referencesCounter == 0)
			{
				delete m_ptr;
				delete m_referencesCounter;
			}
		}
		m_ptr = p;
		m_referencesCounter = new long(1);
	}

	T& operator*()
	{
		return *(this->m_ptr);
	}

	MySharedPtr() // default constructor
	{

	}

	MySharedPtr(T* ptr)
	{
		m_ptr = ptr;
		m_referencesCounter = new long(1);
	}

	MySharedPtr(const MySharedPtr& obj) // copy constructor 
	{
		*this = obj;
	}

	MySharedPtr<T>& operator=(MySharedPtr<T>& obj) // copy assignment
	{
		m_ptr = obj.m_ptr;
		m_referencesCounter = obj.m_referencesCounter;
		std::unique_lock<std::mutex> ulock(m_mtx);
		if (obj.m_ptr != nullptr)
		{
			(*m_referencesCounter)++;
		}
		return *this;
	}

	MySharedPtr<T>& operator=(MySharedPtr<T>&& obj) // move assignment 
	{
		m_ptr = obj.m_ptr;
		m_referencesCounter = obj.m_referencesCounter;
		obj.m_ptr = nullptr;
		obj.m_referencesCounter = nullptr;
		return *this;
	}

	MySharedPtr(MySharedPtr&& obj) // move constructor 
	{
		m_ptr = obj.m_ptr;
		m_referencesCounter = obj.m_referencesCounter;
		obj.m_ptr = nullptr;
		obj.m_referencesCounter = nullptr;
	}

	~MySharedPtr()
	{
		if (m_referencesCounter != nullptr)
		{
			std::unique_lock<std::mutex> ulock(m_mtx);
			(*m_referencesCounter) -= 1;
			if (*m_referencesCounter == 0)
			{
				delete m_ptr;
				delete m_referencesCounter;
			}
		}
	}
private:
	T* m_ptr = nullptr;
	long* m_referencesCounter = nullptr;
	std::mutex m_mtx;
	// std::atomic<long*> m_referencesCounter = nullptr;
	friend std::ostream& operator<<(std::ostream& os, MySharedPtr const& m);
};

template <class T>
std::ostream& operator<<(std::ostream& os, MySharedPtr<T> const& m)
{
	return m.m_ptr ? (os << m.m_ptr) : os;
}