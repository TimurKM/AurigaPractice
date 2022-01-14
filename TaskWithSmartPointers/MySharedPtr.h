#pragma once
#include <iostream>

template <class T>
class MySharedPtr
{
private:
	T* m_ptr = nullptr;
	long* m_referencesCounter = nullptr;
	friend std::ostream& operator<<(std::ostream& os, MySharedPtr const& m);
public:
	T* get()
	{
		return m_ptr;
	}

	long use_count() const noexcept
	{
		if (m_referencesCounter != nullptr)
		{
			return *m_referencesCounter;
		}
		else
			return 0;
	}

	bool unique() const noexcept
	{
		return (1 == use_count());
	}

	void reset(T* p)
	{
		if (m_referencesCounter != nullptr)
		{
			(*m_referencesCounter)--;
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
		m_ptr = nullptr;
		m_referencesCounter = nullptr;
	}

	MySharedPtr(T* ptr)
	{
		m_ptr = ptr;
		m_referencesCounter = new long(1);
	}

	MySharedPtr(MySharedPtr& obj) // copy constructor 
	{
		m_ptr = obj.m_ptr;
		m_referencesCounter = obj.m_referencesCounter;
		if (obj.m_ptr != nullptr)
		{
			(*m_referencesCounter)++;
		}
	}

	MySharedPtr<T>& operator=(MySharedPtr<T>& obj) // copy assignment
	{
		reset(obj.m_ptr);
		m_referencesCounter = obj.m_referencesCounter;
		if (obj.m_ptr != nullptr)
		{
			(*m_referencesCounter)++;
		}
		return *this;
	}

	MySharedPtr<T>& operator=(MySharedPtr<T>&& obj) = delete; // move assignment is deleted

	MySharedPtr(MySharedPtr&& obj) = delete; // move constructor is deleted

	~MySharedPtr()
	{
		if (m_referencesCounter != nullptr)
		{
			(*m_referencesCounter)--;
			if (*m_referencesCounter == 0)
			{
				delete m_ptr;
				delete m_referencesCounter;
			}
		}
	}
};

template <class T>
std::ostream& operator<<(std::ostream& os, MySharedPtr<T> const& m) {
	if (nullptr != m.m_ptr)
	{
		return os << m.m_ptr;
	}
	else
	{
		return os;
	}
}